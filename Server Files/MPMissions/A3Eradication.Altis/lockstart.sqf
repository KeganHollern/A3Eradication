private ["_curPos","_initPos"];
 
_initPos = getPos Start;

while{!game_started} do {
	
    _curPos = position player;
   
    if (_initPos distance _curPos > startLock) then {
		
        player setPos [((( _initPos) select 0)- 5 + (floor random 11)),(((_initPos) select 1) - 5 + (floor random 11)), ((_initPos) select 2)];
    };
    uiSleep 3;
 
};