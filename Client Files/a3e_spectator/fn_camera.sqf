#define DIK_ESCAPE          0x01
#define DIK_MINUS           0x0C    /* - on main keyboard */
#define DIK_EQUALS          0x0D
#define DIK_BACK            0x0E    /* backspace */
#define DIK_TAB             0x0F
#define DIK_Q               0x10
#define DIK_W               0x11
#define DIK_E               0x12
#define DIK_R               0x13
#define DIK_T               0x14
#define DIK_Y               0x15
#define DIK_U               0x16
#define DIK_I               0x17
#define DIK_O               0x18
#define DIK_P               0x19
#define DIK_LBRACKET        0x1A
#define DIK_RBRACKET        0x1B
#define DIK_RETURN          0x1C    /* Enter on main keyboard */
#define DIK_LCONTROL        0x1D
#define DIK_A               0x1E
#define DIK_S               0x1F
#define DIK_D               0x20
#define DIK_F               0x21
#define DIK_G               0x22
#define DIK_H               0x23
#define DIK_J               0x24
#define DIK_K               0x25
#define DIK_L               0x26
#define DIK_GRAVE           0x29    /* accent grave */
#define DIK_LSHIFT          0x2A
#define DIK_BACKSLASH       0x2B
#define DIK_Z               0x2C
#define DIK_X               0x2D
#define DIK_C               0x2E
#define DIK_V               0x2F
#define DIK_B               0x30
#define DIK_N               0x31
#define DIK_M               0x32
#define DIK_RSHIFT          0x36
#define DIK_MULTIPLY        0x37    /* * on numeric keypad */
#define DIK_LMENU           0x38    /* left Alt */
#define DIK_SPACE           0x39
#define DIK_CAPITAL         0x3A
#define DIK_NUMLOCK         0x45
#define DIK_SCROLL          0x46    /* Scroll Lock */
#define DIK_NUMPAD7         0x47
#define DIK_NUMPAD8         0x48
#define DIK_NUMPAD9         0x49
#define DIK_SUBTRACT        0x4A    /* - on numeric keypad */
#define DIK_NUMPAD4         0x4B
#define DIK_NUMPAD5         0x4C
#define DIK_NUMPAD6         0x4D
#define DIK_ADD             0x4E    /* + on numeric keypad */
#define DIK_DECIMAL         0x53    /* . on numeric keypad */
#define DIK_OEM_102         0x56    /* < > | on UK/Germany keyboards */
#define DIK_F11             0x57
#define DIK_NUMPADENTER     0x9C    /* Enter on numeric keypad */

disableserialization;


//--- Function called before display - create display and terminate
if (count _this <= 1) exitwith {

	//_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
	//if !(isnull _cam) exitwith {};

	if (count _this > 0 ||true) then {
		_displayMission = [] call (uinamespace getvariable "bis_fnc_displayMission");
		_parent = if (isnull _displayMission) then {
			_displays = uinamespace getvariable ["GUI_displays",[]];
			_classes = uinamespace getvariable ["GUI_classes",[]];
			
			{
				if (isnull _x) then {
					_classes set [_foreachindex,-1];
				};
			} foreach _displays;
			_displays = _displays - [displaynull];
			_classes = _classes - [-1];

			if (count _displays > 0 && count _displays == count _classes) then {
				if ((_classes select (count _classes - 1)) == "RscDisplayDebug") then {
					//--- Debug console is open - use the display below it (otherwise you couldn't access the console while in the viewer)
					_displays select (count _displays - 2)
				} else {
					//--- Open the viewer from the last open display
					_displays select (count _displays - 1)
				};
			} else {

				//--- No displays are tracked - cannot open
				displaynull
			};
		} else {

			//--- Mission display is present - use it as parent
			_displayMission
		};
		_parent createdisplay "RscDisplaySpectator";
	} else {
		createdialog "RscDisplaySpectator"
	};
};

disableserialization;
_mode = [_this,0,"Init",[displaynull,""]] call bis_fnc_param;
_this = [_this,1,[]] call bis_fnc_param;

switch _mode do {

	///////////////////////////////////////////////////////////////////////////////////////////
	case "Init": {
		with uinamespace do {
		    Get_Target = {
            	params["_camera",["_checkDist",1000]];
            	_dir = vectorDir _camera;
            	_agl = _camera modelToWorld [0,0,0];
            	_target = objNull;
            	_exit = false;
            	for _i from 1 to _checkDist step 2 do {
            		_offset = _dir vectorMultiply _i;
            		_checkPos = _agl vectorAdd _offset;
            		_ents = _checPos nearEntities ["C_MAN_1", 1.5];
            		if(count(_ents) > 0) then {
            			{
            				if(side _x != side civilian) exitWith {
            					_target = _x;
            					_exit = true;
            				};
            			} forEach _ents;
            		};
            		if(_exit) exitWith {};
            	};
            	_target;
            };
            View = 0;
            View_Target = objNull;
            ADS_Thread = scriptNull;
            Change_View = {
            	disableserialization;
            	params["_target"];
            	//--- Select what view to go into 
            	if(View == 0) then {
            		View = 1;
            	} else {
            		if(View == 1) then {
            			View = 2;
            			if(difficulty == 3) then {
            				View = 0;
            			};
            		};
            	};
            	
            	//--- 
            	if(View == 0) then {
            		//--- ReEnter Spectator
            		if(!isNull ADS_Thread) then {terminate ADS_Thread;};
            		View_Target = objNull;
            		(missionNamespace getVariable "BIS_fnc_camera_cam") cameraeffect ["internal","back"];
            	} else {
            		View_Target = _target;
            		if(isNull ADS_Thread) then {
                		ADS_Thread = [] spawn {
                			while{!isNull View_Target} do {
                				_view = View_Target getVariable ["CamView","INTERNAL"];
                				if(_view != "GUNNER") then {
                					if(View == 1) then {
                						if(cameraView != "INTERNAL") then {
                							View_Target switchCamera "INTERNAL";
                						};
                					} else {
                						if(cameraView != "EXTERNAL") then {
                							View_Target switchCamera "EXTERNAL";
                						};
                					};
                				} else {
                					if(cameraView != "GUNNER") then {
                						View_Target switchCamera "GUNNER";
                					};
                				};
                			};
                		};
            		};
            	};
            };
            

		
			BIS_fnc_camera_draw3D = addmissioneventhandler ["draw3d","with (uinamespace) do {['Draw3D',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];

			_camPos = [
				(position cameraon select 0),
				(position cameraon select 1),
				(position cameraon select 2) + 2
			];
			if(count(missionNamespace getVariable["Spectator_OrigPos",[]]) > 0) then {
			    
			    _camPos = [(missionNamespace getVariable "Spectator_OrigPos") select 0,(missionNamespace getVariable "Spectator_OrigPos") select 1,((missionNamespace getVariable "Spectator_OrigPos") select 2) + 2];
			   missionNamespace setVariable ["Spectator_OrigPos",nil];
			    
			};
			_cam = missionnamespace getvariable ["BIS_fnc_camera_cam","camera" camcreate _camPos];
			_cam cameraeffect ["internal","back"];
			cameraEffectEnableHUD true;
			vehicle cameraon switchcamera cameraview;

			//--- Declare variables
			missionnamespace setvariable ["BIS_fnc_camera_cam",_cam];
			missionnamespace setvariable ["BIS_fnc_camera_acctime",missionnamespace getvariable ["BIS_fnc_camera_acctime",acctime]];

			BIS_fnc_camera_LMB = false;
			BIS_fnc_camera_RMB = false;
			BIS_fnc_camera_keys = [];
			BIS_fnc_camera_LMBclick = [0,0];
			BIS_fnc_camera_RMBclick = [0,0];
			BIS_fnc_camera_pitchbank = [0,0];
			BIS_fnc_camera_fov = 0.7;
			BIS_fnc_camera_iconCamera = gettext (configfile >> "RscDisplayCamera" >> "iconCamera");
			BIS_fnc_camera_vision = 0;
			BIS_fnc_camera_visibleHUD = true;
			BIS_fnc_camera_cameraView = cameraview;
			toggleHudControl = 0;
			toggleNameControl = 0;

			cameraon switchcamera "internal";
			showCinemaBorder false;
			
			_DIKcodes = true call bis_fnc_keyCode;
			_DIKlast = _DIKcodes select (count _DIKcodes - 1);
			for "_k" from 0 to (_DIKlast - 1) do {
				BIS_fnc_camera_keys set [_k,false];
			};

			_display = _this select 0;
			BIS_fnc_camera_display = _display;
			
			_display displayaddeventhandler ["keydown","with (uinamespace) do {['KeyDown',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];
			_display displayaddeventhandler ["keyup","with (uinamespace) do {['KeyUp',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];
			_display displayaddeventhandler ["mousebuttondown","with (uinamespace) do {['MouseButtonDown',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];
			_display displayaddeventhandler ["mousebuttonup","with (uinamespace) do {['MouseButtonUp',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];
			_display displayaddeventhandler ["mousezchanged","with (uinamespace) do {['MouseZChanged',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];

			_ctrlMouseArea = _display displayctrl 3140;
			_ctrlMouseArea ctrladdeventhandler ["mousemoving","with (uinamespace) do {['Mouse',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];
			_ctrlMouseArea ctrladdeventhandler ["mouseholding","with (uinamespace) do {['Mouse',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];
			ctrlsetfocus _ctrlMouseArea;

			_ctrlMap = _display displayctrl 3141;
			_ctrlMap ctrlenable false;
			_ctrlMap ctrlshow false;
			_ctrlMap ctrladdeventhandler ["draw","with (uinamespace) do {['MapDraw',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];
			_ctrlMap ctrladdeventhandler ["mousebuttonclick","with (uinamespace) do {['MapClick',_this] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';};"];

			_ctrlOverlay = _display displayctrl 3142;
			_ctrlOverlay ctrlenable false;
			(_display displayctrl 3142) ctrlshow true;
			
			_ctrlSpecControls = (_display displayctrl 3144);
			_ctrlSpecControls ctrlenable false;
			_getKey = {
				params["_custom","_default"]; 
				private["_keys","_text"];
				_keys = actionKeysNamesArray  [_custom,1]; 
				_text = if(count(_keys) == 0) then {_default} else {_keys select 0};
				_text
			};
			_text = parseText ("<t size='1.3'>Spectator Keybinds</t><br/>" + (["MoveForward","W"] call _getKey) + "," + (["TurnLeft","A"] call _getKey) + "," + (["MoveBack","S"] call _getKey) + "," + (["TurnRight","D"] call _getKey)+" - Forward,Left,Back,Right<br/>Q - Move Upwards<br/>Z - Move Downwards<br/>LMB - Move Camera<br/>RMB - Rotate Camera<br/>Scroll Wheel - Zoom In/Out<br/>Left Shift - Accelerate<br/>Left Alt - Decelerate<br/>N - Toggle Nightvision/Thermal<br/>H - Toggle HUD<br/>B - Toggle Name Display");
			_ctrlSpecControls ctrlSetStructuredText _text;
            
			BIS_fnc_camera_showPositions = {
				disableserialization;
				_display = _this;
				_text = "";
				{
					_text = _text + str _foreachindex + ": ";
					if (isnil "_x") then {
						_text = _text + format ["[ Ctrl + %1 ]",_foreachindex];
					} else {
						_params = _positions select _foreachindex;
						_text = _text + format [
							"%1",
							mapgridposition (_params select 1)
							//[(_params select 5),"HH:MM:SS"] call bis_fnc_timetostring
						]
					};
					_text = _text + "\n";
				} foreach _positions;
			};
			_display call BIS_fnc_camera_showPositions;

			//--- Disable menu chromatic aberration
			[] call bis_fnc_guiEffectTiles;

			//--- Remove mission overlay
			_displayMission = [] call (uinamespace getvariable "bis_fnc_displayMission");
			_control = _displayMission displayctrl 11400;
			_control ctrlsetfade 1;
			_control ctrlcommit 0;

			//--- Remove overlays
			cuttext ["","plain"];
			titletext ["","plain"];
			_layers = missionnamespace getvariable ["bis_fnc_rscLayer_list",[]];

			for "_l" from 0 to (count _layers - 1) step 2 do {
				if (((_layers select _l) find "bis_fnc_unitPlay") == 0) then {(_layers select _l) cuttext ["","plain"];};
			};
			clearradio;
			enableradio false;
		};
	};
	///////////////////////////////////////////////////////////////////////////////////////////
	case "Mouse": {
		_display = ctrlparent (_this select 0);
		_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
		_pitchbank = BIS_fnc_camera_pitchbank;
		_pitch = _pitchbank select 0;
		_bank = _pitchbank select 1;

		if (BIS_fnc_camera_LMB || BIS_fnc_camera_RMB) then {
			_mX = _this select 1;
			_mY = _this select 2;

			if (BIS_fnc_camera_LMB) then {

				_defX = BIS_fnc_camera_LMBclick select 0;
				_defY = BIS_fnc_camera_LMBclick select 1;

				_camZ = (getposatl _cam select 2) max 1 min 256;
				_dX = (_mX - _defX) * _camZ / 2;
				_dY = -(_mY - _defY) * _camZ / 2;

				_camPos = getposasl _cam;
				_camPos = [_camPos,_dY,direction _cam] call bis_fnc_relpos;
				_camPos = [_camPos,_dX,direction _cam + 90] call bis_fnc_relpos;
				_cam setposasl _camPos;
			} else {

				_defX = BIS_fnc_camera_RMBclick select 0;
				_defY = BIS_fnc_camera_RMBclick select 1;

				_dX = (_mX - _defX) * 180;
				_dY = -(_mY - _defY) * 180;

				_cam setdir (direction _cam + _dX);
				_pitch = (_pitch + _dY) max -90 min +90;
				[
					_cam,
					_pitch,
					_bank
				] call bis_fnc_setpitchbank;
				BIS_fnc_camera_RMBclick = [_mX,_defY];
			};

		};		

		//--- Cursortarget
		_pos = screentoworld [0.5,0.5];
		_intersectCam = getposasl _cam;
		_intersectTarget = [_pos select 0,_pos select 1,getterrainheightasl _pos];
		_objects = lineIntersectsObjs [
			_intersectCam,
			_intersectTarget,
			objnull,
			objnull,
			true
		];
		_object = objnull;
		if (count _objects > 0) then {
			_ctrlOverlay = _display displayctrl 3142;
			_object = _objects select (count _objects - 1);
			missionnamespace setvariable ["BIS_fnc_camera_target",_object];
		} else {
			missionnamespace setvariable ["BIS_fnc_camera_target",objnull];
		};

		_camDir = direction _cam;
		_cardinalDir = round (_camDir / 45);
		_cardinalDirText = [
			"str_move_n",
			"str_move_ne",
			"str_move_e",
			"str_move_se",
			"str_move_s",
			"str_move_sw",
			"str_move_w",
			"str_move_nw"
		] select _cardinalDir;
		_cardinalDirText = localize _cardinalDirText;

		//--- Nelson's solution for key lag
		_camMove = {
			_dX = _this select 0;
			_dY = _this select 1;
			_dZ = _this select 2;
			_pos = getposasl _cam;
			_dir = (direction _cam) + _dX * 90;
			_camPos = [
				(_pos select 0) + ((sin _dir) * _coef * _dY),
				(_pos select 1) + ((cos _dir) * _coef * _dY),
				(_pos select 2) + _dZ * _coef
			];
			_camPos set [2,(_camPos select 2) max (getterrainheightasl _camPos)];
			_cam setposasl _camPos;
		};
		_camRotate = {
			_dX = _this select 0;
			_dY = _this select 1;
			_pitchbank = _cam call bis_fnc_getpitchbank;
			_cam setdir (direction _cam + _dX);
			[
				_cam,
				(_pitchbank select 0) + _dY,
				0
			] call bis_fnc_setpitchbank;
		};

		_coef = 1;
		if (BIS_fnc_camera_keys select DIK_LMENU) then {_coef = _coef / 5;};
		if (BIS_fnc_camera_keys select DIK_LSHIFT) then {_coef = _coef * 10;};
		if (BIS_fnc_camera_keys select DIK_RSHIFT) then {_coef = _coef / 10;};

		if (BIS_fnc_camera_keys select ((actionKeys "MoveForward") select 0)) then {[0,1,0] call _camMove;};
		if (BIS_fnc_camera_keys select ((actionKeys "MoveBack")select 0)) then {[0,-1,0] call _camMove;};
		if (BIS_fnc_camera_keys select ((actionKeys "TurnLeft")select 0)) then {[-1,1,0] call _camMove;};
		if (BIS_fnc_camera_keys select ((actionKeys "TurnRight")select 0)) then {[1,1,0] call _camMove;};

		if (BIS_fnc_camera_keys select DIK_Q) then {[0,0,1] call _camMove;};
		if (BIS_fnc_camera_keys select DIK_Z) then {[0,0,-1] call _camMove;};

		if (BIS_fnc_camera_keys select DIK_NUMPAD1) then {[-1,-1] call _camRotate;};
		if (BIS_fnc_camera_keys select DIK_NUMPAD1) then {[-1,-1] call _camRotate;};
		if (BIS_fnc_camera_keys select DIK_NUMPAD2) then {[+0,-1] call _camRotate;};
		if (BIS_fnc_camera_keys select DIK_NUMPAD3) then {[+1,-1] call _camRotate;};
		if (BIS_fnc_camera_keys select DIK_NUMPAD4) then {[-1,+0] call _camRotate;};
		if (BIS_fnc_camera_keys select DIK_NUMPAD6) then {[+1,+0] call _camRotate;};
		if (BIS_fnc_camera_keys select DIK_NUMPAD7) then {[-1,+1] call _camRotate;};
		if (BIS_fnc_camera_keys select DIK_NUMPAD8) then {[+0,+1] call _camRotate;};
		if (BIS_fnc_camera_keys select DIK_NUMPAD9) then {[+1,+1] call _camRotate;};

		if (BIS_fnc_camera_keys select DIK_ADD) then {
			BIS_fnc_camera_fov = (BIS_fnc_camera_fov - 0.01) max 0.01;
			_cam campreparefov BIS_fnc_camera_fov;
			_cam camcommitprepared 0;
		};
		if (BIS_fnc_camera_keys select DIK_SUBTRACT) then {
			BIS_fnc_camera_fov = (BIS_fnc_camera_fov + 0.01) min 1;
			_cam campreparefov BIS_fnc_camera_fov;
			_cam camcommitprepared 0;
		};
	};

	case "MouseButtonDown": {
		_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
		_button = _this select 1;
		_mX = _this select 2;
		_mY = _this select 3;
		_shift = _this select 4;
		_ctrl = _this select 5;
		_alt = _this select 6;

		if (_button > 0) then {
			BIS_fnc_camera_RMB = true;
			BIS_fnc_camera_RMBclick = [_mX,_mY];
		} else {
			BIS_fnc_camera_LMB = true;
			BIS_fnc_camera_LMBclick = [_mX,_mY];
		};
		BIS_fnc_camera_pitchbank set [0,(_cam call bis_fnc_getpitchbank) select 0];
	};

	///////////////////////////////////////////////////////////////////////////////////////////
	case "MouseButtonUp": {
		_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
		_button = _this select 1;
		if (_button > 0) then {
			BIS_fnc_camera_RMB = false;
			BIS_fnc_camera_RMBclick = [0,0];
		} else {
			BIS_fnc_camera_LMB = false;
			BIS_fnc_camera_LMBclick = [0,0];
		};

		BIS_fnc_camera_pitchbank set [0,(_cam call bis_fnc_getpitchbank) select 0];
	};

	///////////////////////////////////////////////////////////////////////////////////////////
	case "MouseZChanged": {
		_display = _this select 0;
		_ctrlMap = _display displayctrl 3141;
		if !(ctrlenabled _ctrlMap) then {

			_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
			_camVector = vectordir _cam;

			_dZ = (_this select 1) * 10;
			_vX = (_camVector select 0) * _dZ;
			_vY = (_camVector select 1) * _dZ;
			_vZ = (_camVector select 2) * _dZ;

			_camPos = getposasl _cam;
			_camPos = [
				(_camPos select 0) + _vX,
				(_camPos select 1) + _vY,
				(_camPos select 2) + _vZ
			];
			_camPos set [2,(_camPos select 2) max (getterrainheightasl _camPos)];
			_cam setposasl _camPos;
		};
	};

	///////////////////////////////////////////////////////////////////////////////////////////
	case "KeyDown": {
		_display = _this select 0;
		_key = _this select 1;
		_shift = _this select 2;
		_ctrl = _this select 3;
		_alt = _this select 4;
		_return = false;

		BIS_fnc_camera_keys set [_key,true];

		_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
		_camSave = {
			_positions = profilenamespace getvariable ["BIS_fnc_camera_positions",[]];
			if (_ctrl) then {
				_positions set [
					_this,
					_camParams
				];
				profilenamespace setvariable ["BIS_fnc_camera_positions",_positions];
				saveprofilenamespace;	

				_display call BIS_fnc_camera_showPositions;
			} else {
				_params = _positions select _this;
				if !(isnil "_params") then {
					["Paste",_params] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';
				};
			};
			_return = true;
		};
		_camParams = [
			worldname,
			position _cam,
			direction _cam,
			BIS_fnc_camera_fov,
			BIS_fnc_camera_pitchbankd
		];

		switch (_key) do {
		
			case (DIK_NUMPAD5): {
				BIS_fnc_camera_pitchbank = [0,0];
				[0,0] call _camRotate;
				BIS_fnc_camera_fov = 0.7;
				_camPos = position _cam;
				_camDir = direction _cam;
				_cam cameraeffect ["terminate","back"];
				camdestroy _cam;
				_cam = "camera" camcreate _camPos;
				_cam cameraeffect ["internal","back"];
				_cam setdir _camDir;
				missionnamespace setvariable ["BIS_fnc_camera_cam",_cam];
			};

			case (DIK_M): {
				_ctrlMouseArea = _display displayctrl 3140;
				_ctrlMap = _display displayctrl 3141;
				if (ctrlenabled _ctrlMap) then {
					_ctrlMouseArea ctrlenable true;
					_ctrlMap ctrlenable false;
					ctrlsetfocus _ctrlMap;
					_ctrlMap ctrlshow false;
					_ctrlMap ctrlcommit 0;
				} else {
					_ctrlMouseArea ctrlenable false;
					_ctrlMap ctrlenable true;
					ctrlsetfocus _ctrlMap;
					_ctrlMapPos = [
						safezoneX,
						safezoneY,
						safezoneW,
						safezoneH
					];
					_ctrlMap ctrlsetposition _ctrlMapPos;
					_ctrlMap ctrlshow true;
					_ctrlMap ctrlcommit 0;
					_ctrlMap ctrlmapanimadd [0,0.1,position _cam];
					ctrlmapanimcommit _ctrlMap;
					{player reveal [_x,4]} foreach allunits;
				};
			};
			
			case (DIK_B): {
				if(toggleNameControl == 2) then {
					toggleNameControl = 0; //name only
					
				} else {
					if(toggleNameControl == 0) then {
						toggleNameControl = 1;//on
						
					} else {
						toggleNameControl = 2;//off
						
					};
				};
			};
			
			case (DIK_H): {
				_ctrlOverlays = [_display displayctrl 3142,_display displayctrl 3143,_display displayctrl 3144];
				if(toggleHudControl == 2) then {
					toggleHudControl = 0; //on
					{_x ctrlsetfade 0;} forEach _ctrlOverlays;
					(_display displayctrl 3142) ctrlshow true;
					(_display displayctrl 3144) ctrlshow true;
					
				} else {
					if(toggleHudControl == 0) then {
						toggleHudControl = 1;//town only
						{_x ctrlsetfade 1;}forEach _ctrlOverlays;
						(_display displayctrl 3142) ctrlshow false;
						(_display displayctrl 3144) ctrlshow false;
					} else {
						toggleHudControl = 2;//off
					};
				};
			};
			
			case (DIK_N): {
				BIS_fnc_camera_vision = BIS_fnc_camera_vision + 1;
				_vision = BIS_fnc_camera_vision % 4;
				switch (_vision) do {
					case 0: {
						camusenvg false;
						false SetCamUseTi 0;
					};
					case 1: {
						camusenvg true;
						false SetCamUseTi 0;
					};
					case 2: {
						camusenvg false;
						true SetCamUseTi 0;
					};
					case 3: {
						camusenvg false;
						true SetCamUseTi 1;
					};
				};
			};

			
            case (DIK_I): {
            	
            	_target = [(missionNamespace getVariable "BIS_fnc_camera_cam")] call Get_Target;
            	if(!isNull _target) then {
            		createGearDialog [_target, "RscDisplayInventory"];
            	};
            };
            
            
            
            
            
            case (DIK_V): {
                _target = View_Target;
                if(isNull (_target)) then {
                	_target = [(missionNamespace getVariable "BIS_fnc_camera_cam")] call Get_Target;
                	if(!isNull _target) then {
                		[_target] call Change_View;
                	};
            	};
            };
			
			case (DIK_ESCAPE): {
				_return = true;
				_this spawn {
					disableserialization;
					_display = _this select 0;
					_message = [
						"Do you really want to exit spectator?",
						"SPECTATOR CAMERA",
						nil,
						true,
						_display
					] call bis_fnc_guimessage;
					if (_message) then {
						_display closedisplay 2;
					};
				};
			};
			default {};
		};
		_return
	};
	
	
	case "KeyUp": {
		BIS_fnc_camera_keys set [_this select 1,false];
	};

	case "Draw3D": {
		if(toggleHudControl !=2) then {
			_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
			_locations = nearestlocations [position _cam,["nameVillage","nameCity","nameCityCapital"],2000];
			{
				_pos = locationposition _x;
				_pos set [2,0];
				drawicon3d [
					"#(argb,8,8,3)color(0,0,0,0)",
					[0.4,1,1,1],
					_pos,
					0,
					0,
					0,
					text _x,
					1
				];
			} foreach _locations;
		};
		if(toggleNameControl != 2) then {
    		{
    			_doPlayer = true;
    			if(side _x == civilian) then {
    				_doPlayer = false;
    			};
    			if(_doPlayer) then {
    			
    				_pweapon = primaryWeapon _x;
    				_sweapon = handgunweapon _x;
    				_cfgPWeapon = configfile >> "CfgWeapons" >> _pweapon;
    				_cfgSWeapon = configfile >> "CfgWeapons" >> _sweapon;
    				_pName = gettext (_cfgPWeapon >> "displayname");							
    				_sName = gettext (_cfgSWeapon >> "displayname");
    				if(_pName == "") then {_pName = "-";};
    				if(_sName == "") then {_sName = "-";};
    				
    				_info = magazinesAmmoFull _x;
    				_primaryWeaponMagCount = 0;
    				_primaryWeaponCurrentAmmo = 0;
    				_handgunWeaponMagCount = 0;
    				_handgunWeaponCurrentAmmo = 0;
    
    				_hgunMags = getArray(_cfgSWeapon >> "Magazines");
    				_pgunMags = getArray(_cfgPWeapon >> "Magazines");
    				{
    					_mag = _x select 0;
    					_ammoCount = _x select 1;
    					_isLoaded = _x select 2;
    					_holder = _x select 4;
    					if(_mag in _hgunMags) then {
    						_handgunWeaponMagCount = _handgunWeaponMagCount + 1;
    					};
    					if(_mag in _pgunMags) then {
    						_primaryWeaponMagCount = _primaryWeaponMagCount + 1;
    						
    					};
    					if(_isLoaded) then {
    						if(_holder == _pweapon) then {
    							_primaryWeaponCurrentAmmo = _ammoCount;
    						};
    						if(_holder == _sweapon) then {
    							_handgunWeaponCurrentAmmo = _ammoCount;
    						};	
    					};
    				} forEach _info;
    
    				_handgunWeaponMagCount = (_handgunWeaponMagCount - 1) max 0;
    				_primaryWeaponMagCount = (_primaryWeaponMagCount - 1) max 0;
    				_HP = (100 - ceil((damage _x) * 100));
    					
    				_playername = name _x;
    				_cpos = (positionCameraToWorld [0,0,0]);
    				_posU = getPos _x;
    				_dist = round(_cpos distance _posU);
    				_iconPos = ASLtoAGL (eyepos _x);
    				_iconPos1 = _iconPos vectorAdd [0,0,0.6];
					_iconPos2 = _iconPos vectorAdd [0,0,0.5];
					_iconPos3 = _iconPos vectorAdd [0,0,0.6];
					_iconPos4 = _iconPos vectorAdd [0,0,0.5];
    				
					_text = format["%1 - %2 M - %3 HP",_playername,_dist,_HP];
    				_color = [0.835,0.835,0.835,0];
					
    				if(toggleNameControl == 1) then {
						_text = format["%1 - %2 [%3-%4]",_playername,_pName,_primaryWeaponCurrentAmmo,_primaryWeaponMagCount];
    				};
					if(_dist <= 1500) then {
						drawicon3d[
							"#(argb,8,8,3)color(0,0,0,0)",
							[1,1,1,1],
							_iconPos1,
							0,
							0,
							0,
							_text,
							1
						];
					};
    			};
    			
    		} forEach allPlayers;
		};
	};
	
	///////////////////////////////////////////////////////////////////////////////////////////
	case "MapDraw": {
		_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
		_ctrlMap = _this select 0;
		_ctrlMap drawIcon [
			BIS_fnc_camera_iconCamera,
			[0,1,1,1],
			position _cam,
			32,
			32,
			direction _cam,
			"",
			1
		];
		{
		   if(_x getVariable ["packageLanded",false]) then {
				_ctrlMap drawIcon[
					gettext (configfile >> "CfgMarkers" >> "Mil_Box" >> "Icon"),
					[1,0,0,1],
					getpos _x,
					16,
					16,
					getdir _x,
					"",
					1
				];
			};
		} forEach ((markerPos "center") nearObjects ["Land_CargoBox_V1_F",(markerSize "center") select 0]);
		{
		    if(side _x != civilian) then {
		        _ctrlMap drawIcon[
        		    gettext (configfile >> "CfgMarkers" >> "Mil_Start" >> "Icon"),
        		    [0,0,0,1],
    		    	getpos _x,
        			16,
        			16,
        			getdir _x,
        			name _x,
        			1
        		];
		    };
		} forEach allPlayers;
		//[texture, color, position, width, height, angle, text, shadow]
	};

	///////////////////////////////////////////////////////////////////////////////////////////
	case "MapClick": {
		_ctrlMap = _this select 0;
		_button = _this select 1;
		_posX = _this select 2;
		_posY = _this select 3;
		if (_button == 0) then {
			_worldPos = _ctrlMap ctrlmapscreentoworld [_posX,_posY];
			_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
			_cam setpos [
				_worldPos select 0,
				_worldPos select 1,
				getposatl _cam select 2
			];
		};
	};

	///////////////////////////////////////////////////////////////////////////////////////////
	case "Paste": {
		_this spawn {
			disableserialization;
			[] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';
			waituntil {!isnull (uinamespace getvariable ["BIS_fnc_camera_display",displaynull])};
			with uinamespace do {
				_worldname =	[_this,0,"",[""]] call bis_fnc_paramIn;
				if (_worldname != worldname) exitwith {["Camera params are for world ""%1"", you're currently on ""%2""",_worldname,worldname] call bis_fnc_error;};
				_pos =		[_this,1,position player,[[]],[3]] call bis_fnc_paramIn;
				_dir =		[_this,2,direction player,[0]] call bis_fnc_paramIn;
				_fov =		[_this,3,BIS_fnc_camera_fov,[0]] call bis_fnc_paramIn;
				_pitchbank =	[_this,4,[0,0],[[]],[2]] call bis_fnc_paramIn;
				_pitch =	[_pitchbank,0,0,[0]] call bis_fnc_paramIn;
				_bank =		[_pitchbank,1,0,[0]] call bis_fnc_paramIn;

				_display = uinamespace getvariable ["BIS_fnc_camera_display",displaynull];
				_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
				_cam setpos _pos;
				_cam setdir _dir;
				BIS_fnc_camera_fov = _fov;
				[
					_cam,
					_pitch,
					_bank
				] call bis_fnc_setpitchbank;

				_cam campreparefov BIS_fnc_camera_fov;
				_cam camcommitprepared 0;
				BIS_fnc_camera_pitchbank = _pitchbank;
			};
		};
	};

	///////////////////////////////////////////////////////////////////////////////////////////
	case "Exit": {
		with uinamespace do {
			setacctime (missionnamespace getvariable ["BIS_fnc_camera_acctime",1]);
			setaperture -1;
			enableradio true;

			with missionnamespace do {
				_cam = missionnamespace getvariable ["BIS_fnc_camera_cam",objnull];
				_cam cameraeffect ["terminate","back"];
				camdestroy _cam;

				BIS_fnc_camera_cam = nil;
				BIS_fnc_camera_target = nil;
				BIS_fnc_camera_acctime = nil;
			};

			cameraon switchcamera BIS_fnc_camera_cameraView;

			BIS_fnc_camera_display = nil;
			BIS_fnc_camera_LMB = nil;
			BIS_fnc_camera_RMB = nil;
			BIS_fnc_camera_keys = nil; 
			BIS_fnc_camera_LMBclick = nil;
			BIS_fnc_camera_RMBclick = nil;
			BIS_fnc_camera_pitchbank = nil;
			BIS_fnc_camera_fov = nil;
			BIS_fnc_camera_iconCamera = nil;
			BIS_fnc_camera_vision = nil;
			BIS_fnc_camera_visibleHUD = nil;
			BIS_fnc_camera_cameraView = nil;

			removemissioneventhandler ["draw3d",BIS_fnc_camera_draw3D];
			BIS_fnc_camera_draw3D = nil;

			camusenvg false;
			false SetCamUseTi 0;

			if ((productVersion select 4) == "Development") then {
				_displayMission = [] call (uinamespace getvariable "bis_fnc_displayMission");
				_control = _displayMission displayctrl 11400;
				_control ctrlsetfade 0;
				_control ctrlcommit 0;
			};
			hint "Press TAB To Re-Enter Spectator";
			ReAddSpect = (findDisplay 46) displayAddEventHandler ["KeyDown", {
			    _keys = (ActionKeys "User5") + [DIK_TAB];
			    _suc = false;
			    if((_this select 1) in _keys) then {
			        [] spawn {
			            (findDisplay 46) displayRemoveEventHandler ["KeyDown",uiNamespace getVariable ["ReAddSpect",-1]];
			            createDialog "RscDisplaySpectator";
		            };
		            _suc = true;
			    };
			   _suc;
			}];
		};
	};
};