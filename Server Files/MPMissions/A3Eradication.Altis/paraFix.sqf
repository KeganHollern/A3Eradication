
_para = true;

while {_para && alive player} do {

	if(typeOf (vehicle player) isEqualTo "Steerable_Parachute_F")then
	{
	    _eject = false;
	    _objs = lineIntersectsObjs [ATLToASL(player modelToWorld [0,0,0]), ATLToASL(player modelToWorld [0,0,-1.5])];
	    if(count(_objs) > 1) then {
			{
				if(_x isKindOf "House" || _x isKindOf "Building") exitWith {
					_eject = true;
				};
			} forEach _objs;
	    } else {
    		if(((getPosATL player) select 2) < 1.5 || ((getPosASL player) select 2) < 1.5) then {
    		    _eject = true;
    		};
		};
		if(_eject) then {
		    deleteVehicle (vehicle player);
			_vel = velocity player;
			player switchMove "";
			if((_vel select 2) > -5.5) then {
			player setvelocity [((_vel select 0) * (sin (getdir player))), ((_vel select 1)* (cos (getdir player))), -0.25];
			};
			_para = false;
		};
	};
	
	uiSleep 0.01;
};