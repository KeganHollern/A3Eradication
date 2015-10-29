waitUntil {!isNull player};
if (!local Player) exitWith {};

disableSerialization;
("A3E_Layer" call BIS_fnc_rscLayer) cutRsc ["A3E_HUD","PLAIN"];

_display = uiNamespace getVariable "A3E_DISPLAY"; 
_ctrlHps = _display displayCtrl 520502;
_ctrlKil = _display displayCtrl 520503;
_ctrlPls = _display displayCtrl 520504;

while {!isNull _display} do {

	uiSleep 0.1;
	
	_ctrlHps ctrlSetText format ["%1%2", round((1 - (damage player)) * 100), "%"];
	_ctrlKil ctrlSetText format ["%1", (player getVariable ["kills",0])];	
	_ctrlPls ctrlSetText format ["%1", ({(side _x != civilian) && (alive _x)}count playableUnits)];	

};

diag_log "EXITING HUD";