uinamespace setVariable ["A3E_InGame",true];

player addBackpack "B_Parachute";
if(vehicle player != player) then {
	player action ["getout", vehicle player];
	waitUntil{player == vehicle player};
	player allowDamage true;
	[] spawn A3E_ParaFix;
	[] spawn {
		_objs = [];
		_objsV = [];
		while{vehicle player == player} do {
			{	
				_v = vehicle _x;
				if !(_v in _objs) then {
					player disableCollisionWith _v;
					_objs pushBack _v;
				};
			} forEach allplayers;
			uiSleep 0.1;
		};
		while{vehicle player != player} do {
			{	
				_v = vehicle _x;
				if !(_v in _objsV) then {
					(vehicle player) disableCollisionWith _v;
					_objsV pushBack _v;
				};
			} forEach allplayers;
			uiSleep 0.1;
		};
		{
			if (!isNull _x) then {
				player enableCollisionWith _x;
			};
		} forEach _objs;
    };
};

showGPS true;
showHUD true;
showMap true;

[] spawn A3E_InitPlayAreaDamage;


