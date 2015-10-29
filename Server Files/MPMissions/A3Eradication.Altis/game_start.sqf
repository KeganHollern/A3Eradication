//--- Game Start Script
[] spawn A3E_LootHandler; 
waitUntil{scriptDone boatsThread};
waitUntil{scriptDone carsThread};
call A3E_LobbyCleanUp;

{
	if(_x getVariable ["loaded",false]) then {
		_x setVariable ["safe",true];
	};
} forEach allPlayers;

uiSleep 10;

game_started = true;
publicVariable "game_started";

//--- Move Players to Plane
[] spawn A3E_MoveToPlane;

waitUntil{deploy_players};

MD_PVAR = ["LET THE GAME BEGIN!",0,0.5,2,1];
publicVariable "MD_PVAR";

activeSpectators = []; //--- list of player uids that are in spectator
[] spawn {
	while{true} do {
		spectatorGroup = createGroup civilian;
		publicVariable "spectatorGroup";
		waitUntil{isNull spectatorGroup};
	};
};
addMissionEventHandler ["HandleDisconnect",{
    _unit = _this select 0;
    _id = _this select 1;
    _uid = _this select 2;
    _name = _this select 3;
	
    [_unit] joinSilent spectatorGroup;
	
    _index = activeSpectators find _uid;
    if(_index >= 0) then {
        activeSpectators deleteAt _index;
    } else {
		if(!isNull _unit) then {
			MD_PVAR = [format["%1 has disconnected. %2 Remain",_name,({(side _x != civilian) && (alive _x) && isPlayer(_x)}count playableUnits)],0,-0.4,5,0];
			publicVariable "MD_PVAR";
		};
	};
    false
}];
//--- Multiplayer Killed Event Handler for tracking kills and kicking dead players

{
	_x addMPEventHandler ["MPKilled", {
		_dead = _this select 0;
		_killer = _this select 1;
		
		diag_log "PLAYER DIED";
		diag_log format["DATA: DEAD %1 KILLER %2",_dead,_killer];
		
		if(!isNull _killer) then {
		    _killer = driver _killer;
		};
		
		if(isServer) then {
		    
		    call A3E_OnPlayerKilledServer;
			
		}; 
		if(!isDedicated) then {
			
			call A3E_OnPlayerKilledClient;
			
		};
	}];
} forEach allPlayers;

//--- Spawn Server Time Function
elapsedTime = 0;

[] spawn {
    while {elapsedTime < 2400} do 
    {
        elapsedTime = elapsedTime + 1;
        uiSleep 1;
    };
};

//Begin Game Functions
[] spawn A3E_InitLoadout;
[] spawn A3E_PlayersAlive;
[] spawn A3E_ZoneHandler;

