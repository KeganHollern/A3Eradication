#include "\A3\ui_f\hpp\defineCommonGrids.inc"
#define WelcomeVar "A3E_Welcome090"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	
	//--- Display load
	case "onLoad": {
		diag_log "UI INIT";
		
		private ["_display","_ehCode","_ehMoving","_ehHolding"];
		
		//--- Color Init
		_display = _params select 0;
		_ehKeyDown = _display displayaddeventhandler ["keydown","with uinamespace do {['keyDown',_this,''] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayMain.sqf"";};"];
		_display displayaddeventhandler ["ChildDestroyed","with uinamespace do {['childDestroyed',_this,''] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayMain.sqf"";};"];

		//--- Hide player's name if Stream Friendly UI is on. It is shown via RscDisplayGameOptions.sqf
		[_display, 109] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//--- Assign default values
		with uinamespace do {

			//--- Get colors and grids
			true call bis_fnc_displayColorGet;
			false call bis_fnc_guiGridToProfile;

			//--- Apply colors to main menu
			[configfile >> _class,_display] call bis_fnc_displayColorSet;
		};

		//--- Disable listbox used for alphabetical sorting
		(_display displayctrl 1555) ctrlenable false;

		//Set title text toUpper
		_control = _display displayctrl 1003;
		_control ctrlSetText (toUpper (ctrlText _control));

		//--- Disable Unused Controls
		_disableCtrl = {	
			params ["_idc","_display"];
			(_display displayCtrl _idc) ctrlSetFade 1;
			(_display displayCtrl _idc) ctrlCommit 0;
			(_display displayCtrl _idc) ctrlEnable false;
		};
		[104,_display] call _disableCtrl;
		[118,_display] call _disableCtrl; 
		[146,_display] call _disableCtrl;
		[147,_display] call _disableCtrl;
		[148,_display] call _disableCtrl;
		[138,_display] call _disableCtrl;
		[1555,_display] call _disableCtrl;
		[144,_display] call _disableCtrl;
		[145,_display] call _disableCtrl;
		[141,_display] call _disableCtrl;
		[121,_display] call _disableCtrl;
		[2300,_display] call _disableCtrl;
		[2405,_display] call _disableCtrl;
		[2422,_display] call _disableCtrl;
		[143,_display] call _disableCtrl;
		[2421,_display] call _disableCtrl;
		[152,_display] call _disableCtrl;
		[149,_display] call _disableCtrl;
		[2423,_display] call _disableCtrl;
		if(getNumber(configFile >> "CfgSettings" >> "isdev") == 0) then {
			[142,_display] call _disableCtrl;
		} else {
			(_display displayCtrl 142) ctrlSetPosition [0,0,1,0.5];
			(_display displayCtrl 142) ctrlSetText "OPEN EDITOR @ DEV MODE";
		};
		[151,_display] call _disableCtrl;
		[150,_display] call _disableCtrl;
		[101,_display] call _disableCtrl;
		
		//--- Random Background Selector
		_ctrls = [_display displayCtrl 1515,_display displayCtrl 1516,_display displayCtrl 1517];
		for "_i" from 2 to count(_ctrls) do {
			_ctrl = _ctrls deleteAt (floor(random(count(_ctrls))));
			_ctrl ctrlShow false;
		};
		(_ctrls select 0) ctrlShow true;
		
		0 fadeSound  0;
		playMusic "MAD";
		//0 fadeMusic 0;
		
		//--- Setup Leaderboards Data
		_kills = profilenamespace getVariable ["A3E_Kills" + getText(configFile >> "CfgSettings" >> "statkey"),0];
		_wins = profilenamespace getVariable ["A3E_Wins" + getText(configFile >> "CfgSettings" >> "statkey"),0];
		_deaths = profilenamespace getVariable ["A3E_Deaths" + getText(configFile >> "CfgSettings" >> "statkey"),0];
		_winRate = round((_wins/(_deaths+_wins))*10000)/100;
		
		_text = "<t color='#FFFFFF'>Kills: </t>" + str(_kills) + "<br/>";
		_text = _text + "<t color='#FFFFFF'>Wins: </t>" + str(_wins) + "<br/>";
		_text = _text + "<t color='#FFFFFF'>Deaths: </t>" + str(_deaths) + "<br/>";
		_text = _text + "<t color='#FFFFFF'>Win Rate: </t>" + str(_winRate) + "%<br/>";
		
		_control = _display displayCtrl 1341;
		_control ctrlSetStructuredText (parseText _text);
		_control ctrlCommit 0;
		
		//[1337,_display] call _disableCtrl;
		
		//--- Options button
		_button = _display displayctrl 102;
		_button ctrladdeventhandler ["buttonclick","with uinamespace do {['optionsButton',_this,''] spawn (compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayMain.sqf"");};"];

		//TODO - implementovat promennou, ktera si bude pamatovat stav akordeonu (je potreba pri navratu z jineho dialogu do main menu)
		(_display displayctrl 301) ctrlSetFade 1;	//Video
		(_display displayctrl 302) ctrlSetFade 1;	//Audio
		(_display displayctrl 303) ctrlSetFade 1;	//Controls
		(_display displayctrl 307) ctrlSetFade 1;	//Game Options
		(_display displayctrl 1001) ctrlSetFade 1;	//Profile
		(_display displayctrl 140) ctrlSetFade 1;	//Expansions

		(_display displayctrl 301) ctrlCommit 0;
		(_display displayctrl 302) ctrlCommit 0;
		(_display displayctrl 303) ctrlCommit 0;
		(_display displayctrl 307) ctrlCommit 0;
		(_display displayctrl 1001) ctrlCommit 0;
		(_display displayctrl 140) ctrlCommit 0;

		//--- Hide all buttons from Options - must be here to enable proper focusing
		(_display displayctrl 301) ctrlEnable false;	//Video
		(_display displayctrl 302) ctrlEnable false;	//Audio
		(_display displayctrl 303) ctrlEnable false;	//Controls
		(_display displayctrl 307) ctrlEnable false;	//Game Options
		(_display displayctrl 1001) ctrlEnable false;	//Profile
		(_display displayctrl 140) ctrlEnable false;	//Expansions

		

		_productVersionArray = productversion;
		_versionNameAndNumber = (_display displayctrl 1008);
		_versionNr = ctrltext (_display displayctrl 118);

		if (_productVersionArray select 4 == "Development") then
		{
			_versionNameAndNumber ctrlSetText format ["%1 - %2", localize "STR_A3_RSCDISPLAY_LOADING_DEV", _versionNr];
		}
		else
		{
			_versionNameAndNumber ctrlSetText _versionNr;
		};

		if(_productVersionArray select 5) then
		{
			_versionNameAndNumber ctrlSetPosition [(SafezoneX + SafezoneW - (15.3 * GUI_GRID_W)), (23 * GUI_GRID_H + GUI_GRID_Y)];
			_versionNameAndNumber ctrlCommit 0;
		};

		//Variables for tracking state of accordions (expanded/collapsed)-----------------------------------------------------------------

		if(uiNamespace getVariable ["BIS_MainMenu_isOptionsExpanded", false]) then
		{
			uiNamespace setVariable ["BIS_MainMenu_isOptionsExpanded", false];
			['optionsButton', [_display displayctrl 102], ''] spawn (compile preprocessfilelinenumbers "a3e_client\gui\RscDisplayMain.sqf"); //simulate click on Options button
			waitUntil{!(uiNamespace getVariable "BIS_MainMenu_isOptionsExpanded")}; //Wait until Options collapse
		}
		else
		{
			uiNamespace setVariable ["BIS_MainMenu_isOptionsExpanded", false];
		};
		//Variables for tracking state of accordions (expanded/collapsed)-----------------------------------------------------------------

		//Welcome Screen
		if(!isAutotest) then
		{
			if ((profileNamespace getVariable [WelcomeVar, 0]) <= 0) then
			{
				//If any welcome was not already shown to any profile this session, show it.
				if (!(uiNamespace getVariable [WelcomeVar, false])) then
				{
					_display createDisplay "RscDisplayWelcome";
				};
				private ["_shown"];
				_shown = profileNamespace getVariable [WelcomeVar, 0];
				_shown = _shown + 1;
				profileNamespace setVariable [WelcomeVar, _shown];
				saveProfileNamespace;
			};
		};
	};

	//--- Options button
	case "optionsButton": {

		disableserialization;
		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;


		//if options are expanded (Video Options button is shown), collapse it and vice versa
		//if(ctrlFade (_display displayCtrl 301) < 0.5) then
		_upperPartTime = 0.3;	//0.04 for each button + 0.06 pause
		_buttonsTime = 0.04;	//to have upper time same as in Play

		if(uiNamespace getvariable "BIS_MainMenu_isOptionsExpanded") then
		{
			//hide buttons and collapse accordion
			//move down - background, title, player's name, play, editor, profile, options
			
			//Game Logo
			_control = _display displayctrl 1202;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12.4 * GUI_GRID_H + GUI_GRID_Y)];//9.3 //_offset
			_control ctrlCommit _upperPartTime;

			//Title background
			_control = _display displayctrl 1050;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];//13.1 //_offset
			_control ctrlCommit _upperPartTime;

			//Title
			_control = _display displayctrl 1003;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];//13.1 //_offset
			_control ctrlCommit _upperPartTime;

			//Player's name
			_control = _display displayctrl 109;
			_control ctrlSetPosition [(8.5 * GUI_GRID_W + GUI_GRID_X), (16.4 * GUI_GRID_H + GUI_GRID_Y)];//13.1 //_offset
			_control ctrlCommit _upperPartTime;

			//Singleplayer button
			_control = _display displayctrl 103;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (17.5 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;

			//Multiplayer button
			_control = _display displayctrl 105;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (18.6 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;


			//Options button
			_control = _display displayctrl 102;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (19.7 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;

			(_display displayctrl 301) ctrlSetFade 1;	//Video
			(_display displayctrl 302) ctrlSetFade 1;	//Audio
			(_display displayctrl 303) ctrlSetFade 1;	//Controls
			(_display displayctrl 307) ctrlSetFade 1;	//Game Options
			(_display displayctrl 1001) ctrlSetFade 1;	//Profile
			(_display displayctrl 140) ctrlSetFade 1;	//Expansions

			(_display displayctrl 301) ctrlCommit _buttonsTime;
			uiSleep _buttonsTime;
			(_display displayctrl 302) ctrlCommit _buttonsTime;
			uiSleep _buttonsTime;
			(_display displayctrl 303) ctrlCommit _buttonsTime;
			uiSleep _buttonsTime;
			(_display displayctrl 307) ctrlCommit _buttonsTime;
			uiSleep _buttonsTime;
			(_display displayctrl 1001) ctrlCommit _buttonsTime;
			uiSleep _buttonsTime;
			(_display displayctrl 140) ctrlCommit _buttonsTime;

			(_display displayctrl 301) ctrlEnable false;	//Video
			(_display displayctrl 302) ctrlEnable false;	//Audio
			(_display displayctrl 303) ctrlEnable false;	//Controls
			(_display displayctrl 307) ctrlEnable false;	//Game Options
			(_display displayctrl 1001) ctrlEnable false;	//Profile
			(_display displayctrl 140) ctrlEnable false;	//Expansions

			uiNamespace setVariable ["BIS_MainMenu_isOptionsExpanded", false];
			//set focus to Options button
			ctrlSetFocus (_display displayctrl 102);
		}
		else
		{
			//expand accordion and show buttons

			//Game Logo
			_control = _display displayctrl 1202;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (5.8 * GUI_GRID_H + GUI_GRID_Y)];//2.7 //_offset
			_control ctrlCommit _upperPartTime;

			//Title background
			_control = _display displayctrl 1050;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];//6.5 //_offset
			_control ctrlCommit _upperPartTime;

			//Title
			_control = _display displayctrl 1003;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];//6.5 //_offset
			_control ctrlCommit _upperPartTime;

			//Player's name
			_control = _display displayctrl 109;
			_control ctrlSetPosition [(8.5 * GUI_GRID_W + GUI_GRID_X), (9.8 * GUI_GRID_H + GUI_GRID_Y)];//6.5 //_offset
			_control ctrlCommit _upperPartTime;
			
			//Singleplayer button
			_control = _display displayctrl 103;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (10.9 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;

			//Multiplayer button
			_control = _display displayctrl 105;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (12 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;

			//Options button
			_control = _display displayctrl 102;
			_control ctrlSetPosition [(1 * GUI_GRID_W + GUI_GRID_X), (13.1 * GUI_GRID_H + GUI_GRID_Y)];
			_control ctrlCommit _upperPartTime;


			//when not in demo, enable buttons
			(_display displayctrl 301) ctrlEnable true;	//Video
			(_display displayctrl 302) ctrlEnable true;	//Audio
			(_display displayctrl 303) ctrlEnable true;	//Controls
			(_display displayctrl 307) ctrlEnable true;	//Game Options
			(_display displayctrl 1001) ctrlEnable true;	//Profile
			(_display displayctrl 140) ctrlEnable true;	//Expansions

			//--- Show all buttons from Options
			(_display displayctrl 301) ctrlSetFade 0;	//Video
			(_display displayctrl 302) ctrlSetFade 0;	//Audio
			(_display displayctrl 303) ctrlSetFade 0;	//Controls
			(_display displayctrl 307) ctrlSetFade 0;	//Game Options
			(_display displayctrl 1001) ctrlSetFade 0;	//Profile
			(_display displayctrl 140) ctrlSetFade 0;	//Expansions

			uiSleep 0.05;

			//From bottom to top
			(_display displayctrl 140) ctrlCommit 0.1;	//Expansions
			uiSleep _buttonsTime;
			(_display displayctrl 1001) ctrlCommit 0.1;	//Profile
			uiSleep _buttonsTime;
			(_display displayctrl 307) ctrlCommit 0.1;	//Game Options
			uiSleep _buttonsTime;
			(_display displayctrl 303) ctrlCommit 0.1;	//Controls
			uiSleep _buttonsTime;
			(_display displayctrl 302) ctrlCommit 0.1;	//Audio
			uiSleep _buttonsTime;
			(_display displayctrl 301) ctrlCommit 0.1;	//Video

			uiNamespace setVariable ["BIS_MainMenu_isOptionsExpanded", true];
			//set focus to Options button
			ctrlSetFocus (_display displayctrl 102);
		};
	};

	//--- Display onload
	case "onUnload": {

	};

	//--- Display onload
	case "keyDown":
	{
		_display = _params select 0;
		_key = _params select 1;
		_shift = _params select 2;
		_ctrlKey = _params select 3;
		_alt = _params select 4;


	};

	case "childDestroyed":
	{
		_exit = _params select 2;

		if (
			_exit == 7
			&&
			(
				!isnil {uiNameSpace getvariable "BIS_fnc_arsenal_defaultClass"}
				||
				!isnil {uiNameSpace getvariable "BIS_fnc_garage_defaultClass"}
			)
		) then {
			playMission['','\A3\Missions_F_Bootcamp\Scenarios\Arsenal.VR'];
		};
	};

	//--- Nothing
	default {};
};