/*
	ArmA 3 Intro Mission
	Credits: Exile Team (Thanks Grim! ~Ryan)
*/

cutText ["", "BLACK FADED", 69]; 

enableEnvironment false;
showCinemaBorder false;

[] spawn {
	while{isNull (findDisplay 46)} do {
		_tracks = getArray(configFile >> "CfgSettings" >> "tracks");
		_newTracks = [];
		_stop = count(_tracks)-1;
		for "_i" from 0 to _stop do {
			_newTracks pushBack (_tracks deleteAt floor(random(count(_tracks))));
		};
		0 fadeMusic 0;
		{
			_duration = (configFile >> "CfgMusic" >> _x >> "duration") call BIS_fnc_GetCfgData;
			if(isNil {_duration}) then {_duration = 200;};
			playMusic _x;
			5 fadeMusic 1;
			uiSleep (_duration - 5);
			5 fadeMusic 0;
			uiSleep 5;
		} forEach _newTracks;
	};
};