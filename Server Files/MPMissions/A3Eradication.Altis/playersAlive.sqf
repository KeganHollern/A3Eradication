totalPlayers = 0;
_endGameCheck = true;

_currentPlayers = {((alive _x) && (side _x != civilian))} count allPlayers;
while {true} do {
	waitUntil{({((alive _x) && (side _x != civilian))} count allPlayers) != _currentPlayers};
	
    _currentPlayers = {((alive _x) && (side _x != civilian))} count allPlayers;
    
    if(totalPlayers != _currentPlayers) then {
    	totalPlayers = _currentPlayers;
	};
	if(_currentPlayers <= 1 && _endGameCheck) exitWith{};
};

if(canWin) then {
	_winner = "";
	_winnerID = 0;
	{
		if ((!isNull _x) && (alive _x) && (side _x != civilian)) exitWith
		{
			_winner = name _x;
			_winnerID = owner _x;
			WD_PVAR = random 100;
			(owner _x) publicVariableClient "WD_PVAR";
		};
	} forEach allPlayers;
	
	uiSleep 5;
	if(_winner != "") then {
    	MD_PVAR = [format["CONGRATULATIONS %1! YOU WIN!",_winner],0,0.45,10,0,0,0];
    	publicVariable "MD_PVAR";	
    } else {
    	MD_PVAR = ["GAME OVER! YOU LOSE!",0,0.45,10,0,0,0];
    	publicVariable "MD_PVAR";
    };
	uiSleep 10;
	SERVERCOMMANDHERE serverCommand format["#kick %1",_winnerID];
	SERVERCOMMANDHERE serverCommand "#shutdown";
};
//basically i need to see the MPKilled Event Handler