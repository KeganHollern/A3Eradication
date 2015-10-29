_randomLoot = {
	_total = 0;
	_items = [];
	_item = "";
	_i = 0;

	_gearArray = _this select 0;
	
	{
		_total = _total + (_x select 1);
	} forEach _gearArray;
	
	_value = random(_total);
	{
		_newI = _i + (_x select 1);
			if(_value >= _i && _value < _newI) exitWith {
				_item = _x select 0;
			};
		_i = _newI;
	} forEach _gearArray;
	_item
};

_house = _this;

_type = toLower(typeof _house);
_buildingType = "Residential";
_positions = [];

_index = res_buildings find _type;
if(_index != -1) then {
	_buildingType = "Residential";
	_positions = res_positions select _index;
} else {
	_index = mil_buildings find _type;
	if(_index != -1) then {
		_buildingType = "Military";
		_positions = mil_positions select _index;
	} else {
		_index = ind_buildings find _type;
		if(_index != -1) then {
			_buildingType = "Industrial";
			_positions = ind_positions select _index;
		};
	};
};

_positionCount = count(_positions);

if(_positionCount == 0) exitWith {};

_cfg = missionConfigFile >> "CfgLoot" >> _buildingType;

_chance = getNumber(_cfg >> "spawnChance");

_typeChances = getArray(_cfg >> "typeChance");
_hv = _typeChances select 0;
_mv = _typeChances select 1;
_lv = _typeChances select 2;

_gearChances = getArray(_cfg >> "gearChance");
_weapon = _gearChances select 0;
_magazine = _gearChances select 1;
_gear = _gearChances select 2;
_clothing = _gearChances select 3;
_backpack = _gearChances select 4;

_lootChance = getNumber(_cfg >> "lootChance");

if(random(100) < _chance) then {
	for "_p" from 0 to _positionCount-1 do {
		if(random(100) < _lootChance) then {
			_usedTypes = [];
			
			_pos = _house modelToWorld (_positions select _p);
			_object = "groundWeaponHolder" createVehicle _pos;
			_object setPosASL (AGLToASL _pos);
			
			scopeName "ExitLoop";
			
			for "_i" from 1 to ((floor random(3)) + 1) do {
				
				_value = "HV";
				_rand = random(100);
				_total = _lv;
				if(_rand < _total) then {
					_value = "LV";
				} else {
					_total = _total + _mv;
					if(_rand < _total) then {
						_value = "MV";
					};
				};
				
				//--- What kind of loot? (protip: it cant be in our used types list)
				_gearType = "weapons";
				while{true} do {
					_rand = random(100);
					_total = _magazine;
					if(_rand < _total) then {
						_gearType = "magazines";
					} else {
						_total = _total + _gear;
						if(_rand < _total) then {
							_gearType = "gear";
						} else {
							_total = _total + _clothing;
							if(_rand < _total) then {
								_gearType = "clothing";
							} else {
								_total = _total + _backpack;
								if(_rand < _total) then {
									_gearType = "backpacks";
								};
							};
						};
					};
					if !(_gearType in _usedTypes) exitWith {
						_usedTypes pushBack _gearType;
					};
				};
				
				//--- If we are not spawning a weapon then dont ever allow one to spawn in this pile
				if !("weapons" in _usedTypes) then {
					_usedTypes pushBack "weapons";
				};
				
				_gearArray = getArray(missionConfigFile >> "CfgLoot" >> _value >> _gearType);
				
				_item = [_gearArray] call _randomLoot;
				
				switch(_gearType) do {
					
					case "weapons": {
						_object addWeaponCargoGlobal [_item,1];
						_mags = getArray(ConfigFile >> "CfgWeapons" >> _item >> "magazines");
						_magsCount = count _mags;
						if (_magsCount > 0) then {
							_mag = _mags select floor(random(_magsCount));
							while{_mag in excludedMagazines} do {
								_mag = _mags select (floor(random(_magsCount)));
							};
							_object addMagazineCargoGlobal [_mag,(floor(random 2)) + 1];
						};
						breakTo "ExitLoop";
					};
					case "magazines": {
						for "_j" from 1 to (floor(random(3)) + 1) do {
							_object addMagazineCargoGlobal [_item,1];
							_item = [_gearArray] call _randomLoot;
						};
					};	
					case "gear": {
						for "_k" from 1 to (floor(random(2)) + 1) do {
							_object addItemCargoGlobal [_item,1];
							_item = [_gearArray] call _randomLoot;
						};
					};
					case "backpacks": {
						_object addBackpackCargoGlobal [_item,1];
					};
					case "clothing": {
						for "_h" from 1 to (floor(random(2)) + 1) do {
							_object addItemCargoGlobal [_item,1];
							_item = [_gearArray] call _randomLoot;
						};
					};
				};
			};
			
			{
				_x reveal [_object,4];
			} forEach allPlayers;
		};
	};
};




