_pos = getPos Start;
_dist = 600;
_list = _pos nearObjects ["LandVehicle",_dist];

_count = count _list;

deleteVehicle VehRespawn;

for '_i' from 0 to (_count-1) do {

	_vehicle = _list select _i;
	_vehicle enableSimulationGlobal false;
	_vehicle setVelocity [0,0,0];
	_crew = crew _vehicle;
	
	_countCrew = count _crew;
	
	for '_j' from 0 to (_countCrew - 1) do {
			_unit = (_crew select _j);
			if((isPlayer _unit) && (alive _unit)) then {
				_unit action ["getout", vehicle _unit];
			};
	};
	
	deleteVehicle _vehicle;
	
};

lobby_cleaned = true;