_pos = _this select 0;
_radius = _this select 1;

_cPos = getMarkerPos "center";

_carList = _cPos nearObjects ["LandVehicle",initRadius];
_boatList = _cPos nearObjects ["Ship",initRadius];
_lootList = _cPos nearObjects ["groundWeaponHolder",initRadius];
_lootList2 = _cPos nearObjects ["WeaponHolderSimulated",initRadius];

_countCar = count _carList;
_countBoat = count _boatList;
_countLoot = count _lootList;
_countLoot2 = count _lootList2;

if(_countCar > 0) then {
	for '_i' from 0 to (_countCar - 1) do {

		_vehicle = _carList select _i;
		_crew = crew _vehicle;
		_countCrew = count _crew;
		
		if((((getPos _vehicle) distance _pos) > _radius) && (_countCrew < 1)) then {
			deleteVehicle _vehicle;
		};
	};
	uiSLeep 0.01;
};

if(_countBoat > 0) then {
	for '_i' from 0 to (_countBoat - 1) do {

		_boat = _boatList select _i;
		_crew = crew _boat;
		_countCrew = count _crew;
		
		if((((getPos _boat) distance _pos) > _radius) && (_countCrew < 1)) then {
			deleteVehicle _boat;
		};
		uiSLeep 0.01;
	};
};

for '_i' from 0 to (_countLoot - 1) do {

	_loot = _lootList select _i;
	
	if(((getPos _loot) distance _pos) > _radius) then {
		deleteVehicle _loot;
	};
	uiSLeep 0.01;
};

for '_i' from 0 to (_countLoot2 - 1) do {

	_loot = _lootList2 select _i;
	
	if(((getPos _loot) distance _pos) > _radius) then {
		deleteVehicle _loot;
	};
	uiSLeep 0.01;
};