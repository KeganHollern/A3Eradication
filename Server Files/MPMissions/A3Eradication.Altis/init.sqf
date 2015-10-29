/*
	A3 Eradication
	File: Init.sqf
	
*/
call compile preprocessFileLineNumbers "VARIABLES.sqf";
call compile preprocessFileLineNumbers "CONFIG.sqf";
call compile preprocessFileLineNumbers "SHK_pos\shk_pos_init.sqf";
call compile preprocessFileLineNumbers "COMPILE.sqf";

if !(isDedicated) then {
	onPreloadFinished {
		call A3E_LocalHostFix;
		
		"MD_PVAR" addPublicVariableEventHandler {
			(_this select 1) spawn BIS_fnc_dynamicText;
		};
		
		"WD_PVAR" addPublicVariableEventHandler A3E_AddWin;
		
		"game_started" addPublicVariableEventHandler {
			showGPS false;
			showMap false;
			showHUD false;
			("Keybinds_Layer" call BIS_fnc_rscLayer) cutFadeOut 1;
		};
		"deploy_players" addPublicVariableEventHandler {
			[] spawn A3E_Para;
		};

		enableRadio false;
		enableSentences false;
		
		player enableFatigue false;	
		player allowDamage false;
		
		"TP_PVAR" addPublicVariableEventHandler {
			if(vehicle player == player) then {
				player moveInCargo (_this select 1);
				player assignAsCargoIndex (_this select 1);
			};
			TP_PVAR = nil;
		};
		
		//showChat false;

		[] spawn A3E_LockStart;
		[] spawn A3E_EarPlugs;
		[] spawn A3E_SetLoadout;
		[] spawn A3E_Medical;
		[] spawn A3E_ChannelManage;
		
		
		[] spawn {
			disableserialization;
			("Keybinds_Layer" call BIS_fnc_rscLayer) cutRsc ["Keybinds_HUD","PLAIN"];
			_display = uiNamespace getVariable "Keybinds_DISPLAY";
			_ctrl = _display displayCtrl 3120;
			_getKey = {
				params["_custom","_default"]; 
				private["_keys","_text"];
				_keys = actionKeysNamesArray  [_custom,1]; 
				_text = if(count(_keys) == 0) then {_default} else {_keys select 0};
				_text
			};
			_ctrl ctrlSetStructuredText parseText  ("<t size='1.3'>ArmA 3 Eradication Keybinds</t><br/>" + (["User1","T"] call _getKey) + " - Use Bandage<br/>" + (["User2","Y"] call _getKey) + " - Use Pain Pills<br/>" + (["User3","H"] call _getKey) + " - Use First Aid Kit<br/>" + (["User4","Y"] call _getKey) + " - Toggle Earplugs<br/>Run + " + (["getOver","V"] call _getKey) + " - Jump<br/>" + (["MiniMapToggle","RCtrl + M"] call _getKey) + " - GPS");


		};
		[] spawn {
			while{true} do {
				_view = cameraView;
				player setVariable ["CamView",_view,true];
				waitUntil{cameraView != _view};
			};
		};
		
		[] spawn {
			waitUntil {deploy_players};
			[] spawn A3E_JumpEvent;
			[] spawn A3E_GroupLock;
			call A3E_HUD;
		};
		
		player setVariable ["loaded",true,true];
	};
};

if (isServer) then {
	call compile preprocessFileLineNumbers "game_init.sqf";
};


