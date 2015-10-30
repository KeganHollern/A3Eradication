if(_dead == player) then { 
	group_lock = false;	
	//--- Killed, Show killer POV (temp until we add our own Camera object to handle this)
	if(isPlayer(_killer)) then {
		_killer switchCamera "External";
	};
	[] spawn {
	    if(!isNil "Spectator_Started") exitWith {};
	    Spectator_Started = true;
		
	    [player] joinSilent spectatorGroup;
		call A3E_AddDeath;
		
		Spectator_OrigPos = position player;
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