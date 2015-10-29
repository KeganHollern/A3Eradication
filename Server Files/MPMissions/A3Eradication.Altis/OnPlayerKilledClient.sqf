if(_dead == player) then { 
	group_lock = false;	
	[] spawn {
	    if(!isNil "Spectator_Started") exitWith {};
	    Spectator_Started = true;
		
	    [player] joinSilent spectatorGroup;
		call A3E_AddDeath;
		
		Spectator_OrigPos = position player;
		[] spawn {
			while{true} do {
				{
				   if(_x getVariable ["packageLanded",false]) then {
						_pos = getpos _x;
						_id = str(random(10000));
						/*if !(_id in allMapMarkers) then {
    						if(!isServer) then {
    							_debug = createMarkerLocal [_id,_pos];
    							_debug setMarkerShapeLocal "ICON";
    							_debug setMarkerTypeLocal "hd_dot";
    							_debug setMarkerColorLocal "ColorRed";
    						};
						};*/
					};
				} forEach (allMissionObjects "Land_CargoBox_V1_F");
				uiSleep 1; 
			};
		};
		waitUntil{alive player};
		if(isNil "spectatorUnitPositions") then {spectatorUnitPositions = [0,0,0];};
		player setPos [(spectatorUnitPositions select 0) - 10 + floor(random(20)),(spectatorUnitPositions select 1) - 10 + floor(random(20)),0];
		[] spawn {_pos = getpos player;while{true} do {player setpos _pos;sleep 3;};};
		[player] joinSilent spectatorGroup;
		createDialog "RscDisplaySpectator";
	};
} else {
	if(_killer == player) then {
		call A3E_AddKill;
	};
};