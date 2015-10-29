disableserialization;
_showCtrls = {
	params["_displayName","_showValues"];
	private["_display","_ctrlUSING","_ctrlCANUSE","_showUSING","_showCANUSE"];
	_display = uiNamespace getVariable _displayName;
	_ctrlUSING = _display displayCtrl 1;
	_ctrlCANUSE= _display displayCtrl 2;
	
	_showUSING = _showValues select 0;
	_showCANUSE = _showValues select 1;
	if(_showUSING &&  !(ctrlShown _ctrlUSING)) then
	{
		_ctrlUSING ctrlShow true;
	};
	if(!_showUSING &&  (ctrlShown _ctrlUSING)) then
	{
		_ctrlUSING ctrlShow false;
	};
	if(_showCANUSE &&  !(ctrlShown _ctrlCANUSE)) then
	{
		_ctrlCANUSE ctrlShow true;
	};
	if(!_showCANUSE &&  (ctrlShown _ctrlCANUSE)) then
	{
		_ctrlCANUSE ctrlShow false;
	};	
};

while {alive player} do {
    	
	if(true call canPill) then {
		["Pills_DISPLAY",[false,true]] call _showCtrls;
	} else {
		if(PillActive) then {
			["Pills_DISPLAY",[true,false]] call _showCtrls;
		} else {
			["Pills_DISPLAY",[false,false]] call _showCtrls;
		};
	};
	
	if(true call canBandage) then {
		["Bandage_DISPLAY",[false,true]] call _showCtrls;
	} else {
		if(bandageActive) then {
			["Bandage_DISPLAY",[true,false]] call _showCtrls;
		} else {
			["Bandage_DISPLAY",[false,false]] call _showCtrls;
		};
	};
	
	_display = uiNamespace getVariable "FirstAidKit_DISPLAY";
	_ctrl = _display displayCtrl 1;
	
	if(true call canMed) then {
		if !(ctrlShown _ctrl) then {
			_ctrl ctrlShow true;
		};
	}else{
		if (ctrlShown _ctrl) then {
			_ctrl ctrlShow false;
		};
	};
	
	uiSleep 0.1;
};