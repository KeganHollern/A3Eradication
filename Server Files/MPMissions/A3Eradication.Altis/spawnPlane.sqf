//private["_type","dropInit","_loc_drop","_loc_final","_local_start","_plane","_plane_pilot","_wp","_data"];

params[["_altitude",200]];

_dropInit = (getMarkerSize blackCircle) select 0;
_center = getMarkerPos blackCircle;

_dir = random 360;
_loc_drop = [_center,(floor (random 2001)),_dir,1] call SHK_pos;
_loc_final = [_center,3500,random 360,1] call SHK_pos;

_loc_start = [((_loc_drop select 0) + (sin(_dir) * 4000)),((_loc_drop select 1) + (cos(_dir) * 4000)), _altitude];

_plane = createVehicle ["C130J",_loc_start, [], 0, "FLY"];
_plane setPosASL [((getPosASL _plane) select 0), ((getPosASL _plane) select 1),_altitude];
_plane engineOn true;
_plane flyInHeight _altitude;
_plane forceSpeed 140;
_plane setspeedmode "FULL";
_plane setVehicleLock "locked";
_plane_group = creategroup east;
_plane_pilot = _plane_group createUnit ["C_man_w_worker_F",getPos _plane,[],0,"FORM"];
_plane_pilot moveInDriver _plane;
_plane_pilot assignAsDriver _plane;
_plane setdir (_dir + 180);
_plane setvelocity [(140 * (sin (getdir _plane))), (140 * (cos (getdir _plane))), 0];
clearItemCargoGlobal _plane;
clearMagazineCargoGlobal _plane;
clearBackpackCargoGlobal _plane;
clearWeaponCargoGlobal _plane;

_wp = _plane_group addWaypoint [_loc_drop,0];
_wp setWaypointType "MOVE";
_wp setWaypointBehaviour "CARELESS";

_wp = _plane_group addWaypoint [_loc_final,1];
_wp setWaypointType "MOVE";
_wp setWaypointBehaviour "CARELESS";

_data = [_plane,_plane_pilot,_loc_drop,_loc_final];
_data;