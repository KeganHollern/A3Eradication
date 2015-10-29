SERVERCOMMANDHERE = "qwerty";
canWin = true;

//--- Set Time
_game_date = [2012, 5, 4, (floor random 24), (floor random 60)];
//_game_date = [2012, 5, 4, 12, (floor random 60)];
setDate _game_date;

//--- Initialize Play Zone (wait for zone to be selected before anything else starts)
call A3E_InitPlayArea;

//--- Start Spawning The Vehicles
boatsThread = [] spawn A3E_BoatHandler;
carsThread = [] spawn A3E_VehicleHandler;

//--- Check Player Count
_timeCount = 0;

while{true} do {
    _numPlayers = {_x getVariable ["loaded",false] && (side _x != civilian) && (alive _x)} count allPlayers;
    if(_numPlayers >= playersToStart) exitWith {};
	
    if(_timeCount == 15) then {
		_delta = playersToStart - _numPlayers;
		MD_PVAR = [format["WAITING FOR %1 MORE PLAYER(S).",_delta],0,0.7,5,0];
		publicVariable "MD_PVAR";
        _timeCount = 0;
    };
    _timeCount = _timeCount +1;
    uiSleep 1;
};

//--- Messages as game begins
uiSleep 10;
MD_PVAR = ["MINIMUM PLAYER COUNT REACHED!",0,0.5,2,1];
publicVariable "MD_PVAR";

uiSleep 5;
MD_PVAR = ["WAITING 30 SECONDS FOR MORE PLAYERS!",0,0.5,2,1];
publicVariable "MD_PVAR";

uiSleep 30;
SERVERCOMMANDHERE serverCommand "#lock";
MD_PVAR = ["GAME BEGINNING SOON!",0,0.5,2,1];
publicVariable "MD_PVAR";
call A3E_GameStart;