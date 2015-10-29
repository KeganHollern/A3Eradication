#define DIK_U               0x16

(findDisplay 46) displayAddEventHandler ["KeyDown", {
	_success = false;
	_keys = (ActionKeys "User4");
	if(count(_keys) == 0) then {_keys = [DIK_U];};
	if((_this select 1) in _keys) then {
		_success = true;
		if(soundVolume != 1) then {
			1 fadeSound 1;
			disableSerialization;
			("Earplugs_Layer" call BIS_fnc_rscLayer) cutFadeOut 0;
		} else {
			1 fadeSound 0.25;
			disableSerialization;
			("Earplugs_Layer" call BIS_fnc_rscLayer) cutRsc ["Earplugs_HUD","PLAIN"];
		};
	};
	_success;
}];
