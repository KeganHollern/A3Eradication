_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		_display = _params select 0;
		_disableCtrl = {	
			params ["_idc","_display"];
			(_display displayCtrl _idc) ctrlSetFade 1;
			(_display displayCtrl _idc) ctrlCommit 0;
			(_display displayCtrl _idc) ctrlEnable false;
		};
		//Be sure chat is hidden so we don't cover up parts of the MP display
		showChat false;
		
		//--- set player's name
		(_display displayctrl 701) ctrlSetText profileName;
		[_display, 701] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//toUpper Title
		_control = _display displayctrl 1000;
		_control ctrlSetText (toUpper (ctrlText _control));
		
		//Count players
		_display displayaddeventhandler
		[
			"mousemoving",
			"
				_display = _this select 0;
				(_display displayctrl 1015) ctrlsettext str (lbsize (_display displayctrl 114));	
			"
		];
		
		//Disable unused controls
		[105,_display] call _disableCtrl;
		[106,_display] call _disableCtrl;
		[104,_display] call _disableCtrl;
		[107,_display] call _disableCtrl;
		[132,_display] call _disableCtrl;
		[118,_display] call _disableCtrl;
		[117,_display] call _disableCtrl;
		[128,_display] call _disableCtrl;
		[130,_display] call _disableCtrl;
		[116,_display] call _disableCtrl;
		[121,_display] call _disableCtrl;
		[1004,_display] call _disableCtrl;
		[103,_display] call _disableCtrl;
		[1008,_display] call _disableCtrl;
		[1084,_display] call _disableCtrl;
		[1082,_display] call _disableCtrl;
		
		//Random Background

		_ctrlsMAIN = [(findDisplay 0) displayCtrl 1515,(findDisplay 0) displayCtrl 1516,(findDisplay 0) displayCtrl 1517];
		_ctrls = [_display displayCtrl 1515,_display displayCtrl 1516,_display displayCtrl 1517];
		for "_i" from 0 to count(_ctrls)-1 do {
			(_ctrls select _i) ctrlShow (ctrlShown (_ctrlsMAIN select _i));
		};
				
		//Move focus to Roles, since OK button is disabled. We don't want to move focus to Disconnect button on client. (basically select a role)
		ctrlSetFocus (_display displayctrl 109); 
		
		//Autoclick OK button once a role is selected (removed as it is bugged)
		/*
		uiNamespace setVariable ["RDMS",_display];
		[] spawn {
			disableserialization;
			_display = uiNamespace getVariable ["RDMS",displayNull];
			waitUntil{isNull _display || ctrlEnabled (_display displayCtrl 1)};
			if(!isNull _display) then {
				ctrlActivate (_display displayCtrl 1);
			};
		};
		*/
	};
	
	case "onUnload": {

		//Hide chat to be sure it's hidden when returning back to Create Game
		showChat false;
	};
	
};