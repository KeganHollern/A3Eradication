_altitude = floor(random(501)) + 1000;

_numPlanes = 2; //ceil((count allPlayers) / 16);
_planes = [];
_pilots = [];
_locDrop = [];
_locFinal = [];
_indexData = [];

for "_i" from 0 to _numPlanes - 1 do {

	_data = [_altitude] call A3E_SpawnPlane;
	
	_planes pushBack (_data select 0);
	_indexData pushBack [];
	_pilots pushBack (_data select 1);
	_locDrop pushBack (_data select 2);
	_locFinal pushBack (_data select 3);
	
	_altitude = _altitude + (random(25) + 25);
};

{
	//--- Get plane
	_index = _forEachIndex mod _numPlanes;
	_plane = _planes select _index;
	//--- Get Index Data for plane
	_array = _indexData select _index;
	//--- Get Player Target Position
	_playerIndex = count(_array);
	//--- Add Item To Array TO INCREMENT
	_array pushBack _x;
	//--- Update
	_indexData set[_index,_array];
	//--- Move to plane at index
	TP_PVAR = [_plane,_playerIndex];
	(owner _x) publicVariableClient "TP_PVAR";
} forEach allPlayers;
/*
{
	TP_PVAR = [(_planes select 0),_forEachIndex];
	(owner _x) publicVariableClient "TP_PVAR";
} forEach allPlayers;
*/

waitUntil{ _drop = false; { _loc_drop = _locDrop select _forEachIndex;if((getPos _x) distance2D _loc_drop <= 1000) exitWith {_drop = true;};} forEach _planes; _drop};


{
	if(vehicle _x == _x) then {
		//--- Get plane
		_index = _forEachIndex mod _numPlanes;
		_plane = _planes select _index;
		//--- Get Index Data for plane
		_array = _indexData select _index;
		//--- Get Player Target Position
		_playerIndex = count(_array);
		//--- Add Item To Array TO INCREMENT
		_array pushBack _x;
		//--- Update
		_indexData set[_index,_array];
		//--- Move to plane at index
		TP_PVAR = [_plane,_playerIndex];
		(owner _x) publicVariableClient "TP_PVAR";
	};
} forEach allPlayers;

/*
_start = count(crew (_planes select 0)) - 1;
{
	TP_PVAR = [(_planes select 0),_start + _forEachIndex];
	(owner _x) publicVariableClient "TP_PVAR";
} forEach allPlayers;
*/

waitUntil{_drop = false; { _loc_drop = _locDrop select _forEachIndex;if((getPos _x) distance2D _loc_drop <= 500) exitWith {_drop = true;};} forEach _planes; _drop};

//--- kick anyone not in the plane cause they were fucking late to the game
{
	if !(_x getVariable ["safe",false]) then {
		SERVERCOMMANDHERE serverCommand format["#kick %1",(owner _x)];
	};
} forEach allPlayers;
//--- deploy players

deploy_players = true;
publicVariable "deploy_players";

waitUntil{_drop = false; { _loc_final = _locFinal select _forEachIndex;if((getPos _x) distance2D _loc_final <= 500) exitWith {_drop = true;};} forEach _planes; _drop};

for "_k" from 0 to (count _planes) -1 do {

    _plane = _planes select _k;
    _plane_pilot = _pilots select _k;

    if(count (crew _plane) > 1) then {
    	{
    		if(isPlayer _x) then {
    			_x action ["getout", vehicle _x];
    		};
    	} forEach (crew _plane);
    };
    
    deleteVehicle _plane_pilot;
    deleteVehicle _plane;

};