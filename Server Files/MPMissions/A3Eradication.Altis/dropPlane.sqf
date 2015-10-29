_explode = {
	private ["_bomb","_objects","_explo"];
	_bomb = _this select 1;
	_objects = [];
	waitUntil {((getPosATL _bomb select 2) < 2);};
	_bomb enableSimulation false;
	_objects = nearestObjects [_bomb, [], 15];
	_explo = createVehicle ["M_Mo_82mm_AT", _bomb, [], 0, "NONE"];
	{
		_x setDamage 1;
	} forEach _objects;
	deleteVehicle _bomb;
};

private ["_preWaypoints","_preWaypointPos","_airdropStart","_airdropModel","_aigroup","_droppilot","_dropplane","_pos","_lootpiles","_frequency","_variance","_waypoints","_randomWP","_actualWP","_chutetype","_boxtype","_bomb","_airdropInit"];

_randomWP	= 4;
_actualWP	= 7;
_chutetype = "B_Parachute_02_F";
_boxtype = "Land_CargoBox_V1_F";
_airdropModel = "B_Plane_CAS_01_F";
_currentCircle = _this select 0;
_airdropInit = (getMarkerSize _currentCircle) select 0;
_airDrop = true;
_chance = [40,30,20,10,0,0,0,0];

while {_airDrop} do {
    
	_preWaypoints = (round(random _randomWP)) + _actualWP;
 
	_airdropStart = [getMarkerPos _currentCircle,_airdropInit,random 360,1] call SHK_pos;
   
	_dropplane = createVehicle [_airdropModel,_airdropStart, [], 0, "FLY"];    
	_dropplane engineOn true;
	_dropplane flyInHeight 200;
	_dropplane forceSpeed 140;
	_dropplane setSpeedMode "FULL";    
	_aigroup = createGroup east;
	_droppilot = _aigroup createUnit ["C_man_w_worker_F",getPos _dropplane,[],0,"FORM"];
	_droppilot moveInDriver _dropplane;
	_droppilot assignAsDriver _dropplane;
	_droppilot disableAI "AUTOTARGET";
	_droppilot disableAI "TARGET";
	_droppilot disableAI "SUPPRESSION";
    
	uiSleep 0.5;  
    
	_waypoints = [];
    
	for "_x" from 1 to _preWaypoints do {
		_preWaypointPos = [getMarkerPos _currentCircle,random _airdropInit,random 360,1] call SHK_pos;
		_waypoints = _waypoints + [_preWaypointPos];
	};
    
	 for "_x" from 0 to ((count _waypoints)-1) do {
        
        _wp = _aigroup addWaypoint [(_waypoints select _x), 0];
        _wp setWaypointType "MOVE";
        _wp setWaypointBehaviour "CARELESS";
		
		waitUntil {(_dropplane distance2D (_waypoints select _x)) <= 300 || !alive _dropplane};
		if(!alive _dropplane) exitWith{};
        
		if(random(100) < (_chance select numCircles)) then {
		
			nul = [_chutetype, _boxtype, _airdropStart, _dropplane] spawn A3E_Drop;
			uiSleep 3;
        };
		
		if(random(100) < 40) then {
			for [{_z=1},{_z<=20},{_z=_z+1}] do {		
				_bomb = createVehicle ["Land_WaterBarrel_F", [(getPos _dropplane select 0) + 500, (getPos _dropplane select 1) + 500, (getPos _dropplane select 2) + 500], [], 0, "NONE"];
				_bomb attachTo [_dropplane, [-5,-4,-3]];
				_bomb setVectorDirAndUp [[random(2)-1,random(2)-1,random(2)-1],[random(2)-1,random(2)-1,random(2)-1]];
				uiSleep 0.01;
				detach _bomb;
				uiSleep 0.1;
				[0.1, _bomb] spawn _explode;
			};
		};	
    };
    
    _wp = _aigroup addWaypoint [_airdropStart, 0];
    _wp setWaypointType "MOVE";
    _wp setWaypointBehaviour "CARELESS";
    
    waitUntil {(_dropplane distance2D _airdropStart) <= 500 || !alive _dropplane};
 
	if(alive _dropplane) then {
	    deleteVehicle _dropplane;
	};
	deleteVehicle _droppilot;
	_airDrop = false;
};