_display = (_this select 1) select 0;

_ctrlsMAIN = [(findDisplay 0) displayCtrl 1515,(findDisplay 0) displayCtrl 1516,(findDisplay 0) displayCtrl 1517];
_ctrls = [_display displayCtrl 1515,_display displayCtrl 1516,_display displayCtrl 1517];
for "_i" from 0 to count(_ctrls)-1 do {
	if(isNull (findDisplay 46)) then {
		(_ctrls select _i) ctrlShow (ctrlShown (_ctrlsMAIN select _i));
	} else {
		(_ctrls select _i) ctrlShow false;
	};
};

_this call (uinamespace getvariable 'BIS_fnc_initDisplay');