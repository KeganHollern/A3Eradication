_allowedBoats = ["B_Boat_Transport_01_F","B_SDV_01_F","O_SDV_01_F","C_Boat_Civil_01_F","B_Boat_Armed_01_minigun_F",
				"C_Boat_Civil_01_rescue_F","I_Boat_Transport_01_F","ZodiacCRRCboat","B_G_Boat_Transport_01_F",
				"C_Boat_Civil_01_police_F","C_Rubberboat","O_Lifeboat","B_Lifeboat"
				];

_spawnArea = "center";
_center = getMarkerPos _spawnArea;

_minVehDistance = 100;
_numberBoats = 32;

_showBoat =false;
_waterCheck = false;

//Check for water in circle
for '_k' from 0 to 359 do {
	
	_xloc = (_center select 0) + (sin(_k)*(initRadius - 1000));
	_yloc = (_center select 1) + (cos(_k)*(initRadius - 1000));
	
	_d = (ASLtoATL [_xloc,_yloc,0]) select 2;
	
	if(_d > 0) exitWith {_waterCheck = true;};
	
};

systemchat "Spawning Boats";

//Spawn Boats
if (_waterCheck) then {

	for '_i' from 1 to _numberBoats do {
	
		_type = _allowedBoats select floor(random(count(_allowedBoats)));
		_dir = random(360);
		_fail = 0;
		
		while{true} do {
			
			_pos = [_spawnArea,2] call SHK_pos;
		
			_depth = (ASLtoATL [_pos select 0,_pos select 1,0]) select 2;
			
			_list = _pos nearObjects["Ship",_minVehDistance];
			
			if((count(_list) == 0) && (_depth > 0.6) && (_depth < 7)) exitWith {
				
				_boat = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];		
				_boat setdir _dir;
				_boat setVectorUp (surfaceNormal _pos);
				_boat setposASL _pos;

				if (_showBoat) then {			
					_id=format ["%1",_pos];
					_debug = createMarker [_id,_pos];
					_debug setMarkerShape "ICON";
					_debug setMarkerType "hd_dot";
					_debug setMarkerColor "ColorGreen";
				};
				
				clearBackpackCargoGlobal _boat;
				clearWeaponCargoGlobal _boat;
				clearItemCargoGlobal _boat;
				clearMagazineCargoGlobal _boat;
				_boat setFuel (random(1) max 0.5);
				_boat setVehicleAmmo 0;
			};
			if((count(_list) != 0))then {
				_fail = _fail + 1;
			};
			
			if(_fail > 10) exitWith {};
			uiSleep 0.02;
		};
		uiSleep 0.1;
	};
};
systemchat "Boats Done!";