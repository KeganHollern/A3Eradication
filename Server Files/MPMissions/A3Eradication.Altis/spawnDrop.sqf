_generatePositions = {
	_pos = _this select 0;
	_dist = [3,4];
	_sepAngle = 24;
	_list = [];
	_numPoints = floor(360/_sepAngle);
	_count = count _dist;
	
	for '_j' from 0 to (_count - 1) do {
		for '_i' from 0 to (_numPoints - 1) do {
			_angle = (_i * _sepAngle);
			_loc = [_pos,(_dist select _j),_angle,0] call SHK_pos;
			_list = _list + [_loc];
		};
	};
	_list
};

_randomizeLoot = {
   
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

private ["_chutetype","_carePackagetype","_airdropStart","_airdropplane","_randomlootpiles","_lootpiles","_chute","_carePackage","_smoke","_flare","_pos"];

_showPackage = false;

_chutetype = _this select 0;
_carePackagetype = _this select 1;
_airdropStart	= _this select 2;
_airdropplane	= _this select 3;

_chute = createVehicle [_chutetype,_airdropStart,[],0,"CAN_COLLIDE"];
_chute setPos [(getPos _airdropplane select 0), (getPos _airdropplane select 1), (getPos _airdropplane select 2) - 10];

_carePackage = createVehicle [_carePackagetype,_airdropStart,[],0,"CAN_COLLIDE"];
_carePackage setPos [(getPos _airdropplane select 0), (getPos _airdropplane select 1), (getPos _airdropplane select 2) - 10];
_carePackage attachTo [_chute, [0, 0, 0]];

_pos = [];

_time = time + 45;
waitUntil {(((getPos _carePackage) select 2) < 1) || (time > _time)};
detach _carePackage;
_carePackage setPos [(getPos _carePackage select 0), (getPos _carePackage select 1), 0];
_carePackage setVectorUp surfaceNormal position _carePackage;
_carePackage setVariable ["packageLanded",true,true];
deleteVehicle _chute;
uiSleep 1;

_pos = [getPos _carePackage select 0, getPos _carePackage select 1, 0];

_depth = (ASLtoATL _pos) select 2;

if(_depth > 0) then {
	_newPos = [_pos,100,(random(360)),0] call SHK_pos;
	deleteVehicle _carePackage;
    _carePackage = _carePackagetype createVehicle (_newPos);
	_pos = _newPos;
};

_smoke = "SmokeShellRed"  createVehicle ([_pos select 0, _pos select 1, (_pos select 2) + 150]);
_chemPos = [_pos,2,180,0] call SHK_pos;
_chemlight = "Chemlight_red" createVehicle (_chemPos);
_chemPos = [_pos,2,0,0] call SHK_pos;
_chemlight = "Chemlight_red" createVehicle (_chemPos);
_flare = "F_40mm_Red" createVehicle ([_pos select 0, _pos select 1, (_pos select 2) + 150]);
_flare = "F_40mm_Red" createVehicle ([_pos select 0, _pos select 1, (_pos select 2) + 140]);
_flare = "F_40mm_Red" createVehicle ([_pos select 0, _pos select 1, (_pos select 2) + 130]);

if (_showPackage) then {
	_id=format ["%1",_pos];
	_debug = createMarker [_id,_pos];
	_debug setMarkerShape "ICON";
	_debug setMarkerType "hd_dot";
	_debug setMarkerColor "ColorGreen";
};

_lootType = ["SniperPackage","ARPackage","LMGPackage"]  call BIS_fnc_selectRandom;

_weaponArray = getArray(missionConfigFile >> _lootType >> "Weapon" >> "items");
_equipArray = getArray(missionConfigFile >> _lootType >> "Equipment" >> "items");
_itemArray = getArray(missionConfigFile >> _lootType >> "Item" >> "items");

_countWeap = floor(random(1)) + 2;
_countEquip = floor(random(1)) + 2;
_countItem = floor(random(4)) + 3;

_listPos = [_pos] call _generatePositions;

for '_j' from 0 to _countWeap do {

	_weapon = [_weaponArray] call _randomizeLoot;
	_lootPos = _listPos call BIS_fnc_selectRandom;
	_listPos = _listPos - [_lootPos];
	
	_weaponHolder = createVehicle ["groundWeaponHolder", _lootPos, [], 0, "CAN_COLLIDE"];
	
     _weaponHolder addWeaponCargoGlobal [_weapon,1];
     _mags = getArray(configFile >> "CfgWeapons" >> _weapon >> "magazines");
            _magsCount = count _mags;
            if (_magsCount > 0) then {
				_mag = _mags select floor(random(_magsCount));
				_weaponHolder addMagazineCargoGlobal [_mag,(round(random 1)) + 2];						
			};
	{
		_x reveal [_weaponHolder,4];
	} forEach allPlayers;
};

for '_j' from 0 to _countEquip do {

	_equip = [_equipArray] call _randomizeLoot;
	_lootPos = _listPos call BIS_fnc_selectRandom;
	_listPos = _listPos - [_lootPos];
	
	_weaponHolder = createVehicle ["groundWeaponHolder", _lootPos, [], 0, "CAN_COLLIDE"];
	
    _weaponHolder addItemCargoGlobal [_equip,1];
	
	{
		_x reveal [_weaponHolder,4];
	} forEach allPlayers;
  
};

for '_j' from 0 to _countItem do {

	_itemDrop = [_itemArray] call _randomizeLoot;
	_lootPos = _listPos call BIS_fnc_selectRandom;
	_listPos = _listPos - [_lootPos];
	
	_weaponHolder = createVehicle ["groundWeaponHolder", _lootPos, [], 0, "CAN_COLLIDE"];
	
    _weaponHolder addItemCargoGlobal [_itemDrop,1];
    
	{
		_x reveal [_weaponHolder,4];
	} forEach allPlayers;
};
    
    