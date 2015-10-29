_allowedCars = ["C_Hatchback_01_sport_F","C_Hatchback_01_F","C_Offroad_01_F","B_G_Offroad_01_F","C_Van_01_box_F",
				"C_Quadbike_01_F","B_G_Quadbike_01_F","C_Van_01_transport_F","I_Truck_02_covered_F",
				"O_Truck_02_covered_F","C_SUV_01_F"];
				
_minVehDistance = 250;
_numberCars = 75;
_showCar = false;
_center = getMarkerPos "center";

_roads = _center nearRoads initRadius; //--- im thinking this is taking way to long

systemchat "Spawning Cars";

for '_i' from 1 to _numberCars do {
	

	_type = _allowedCars select floor(random(count(_allowedCars)));
	_dir = random(360);
	
	_exit = false;
	while{true} do {
		if(count(_roads) == 0) exitWith {_exit = true;};
		
		_roadIndex = floor(random(count(_roads)));
		
		_road = _roads deleteAt _roadIndex; //--- Never select the same roadsegment again
		_pos = ASLtoATL(AGLToASL(_road modeltoWorld [0,0,0]));
		
		_pos = _pos vectorAdd [(random(3) - 1),(random(3) - 1),0];
		
		_list = _pos nearObjects["LandVehicle",_minVehDistance];
		if(count(_list) == 0) exitWith {
			_car = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];	
			_car setdir _dir;
			_car setVectorUp (surfaceNormal _pos);

			if (_showCar) then {
				_id=format ["%1",_pos];
				_debug = createMarker [_id,_pos];
				_debug setMarkerShape "ICON";
				_debug setMarkerType "hd_dot";
				_debug setMarkerColor "ColorBlue";
			};
					
			clearBackpackCargoGlobal _car;
			clearWeaponCargoGlobal _car;
			clearItemCargoGlobal _car;
			clearMagazineCargoGlobal _car;
			_car setFuel (random(1) max 0.5);
			_car setVehicleAmmo 0;
		};
	};
	
	if(_exit) exitWith {};
};
systemchat "Cars Done!";