_roundTime = 2520;
_zoneStart = 9;
_zoneLock = 14;
_shrinkWarning = 16;
_shrinkLock = 18;
_finalWarning = 38;
numCircles = 0;
publicVariable "numCircles";
[] spawn {
	while{true} do {
		_circles = numCircles;
		waitUntil{numCircles != _circles};
		publicVariable "numCircles";
	};
};


_circleSizing = [1900,1500,1100,700,400,200,75];

while {elapsedTime < _roundTime} do {

	_time = elapsedTime;
	_time_minutes = floor(_time / 60);
	_time_seconds = floor(_time) - (60 * _time_minutes);

	if((_time_minutes == (_zoneStart - 5)) && (_time_seconds < 1)) then {
        MD_PVAR = ["THE PLAY AREA WILL APPEAR IN 5 MINUTES!",0,0.9,10,0];
		publicVariable "MD_PVAR";
	};
		
	if((_time_minutes == (_zoneStart - 3)) && (_time_seconds < 1)) then {
        MD_PVAR = ["THE PLAY AREA WILL APPEAR IN 3 MINUTES!",0,0.9,10,0];
		publicVariable "MD_PVAR";
	}; 

	if((_time_minutes == (_zoneStart - 1)) && (_time_seconds < 1)) then {
        MD_PVAR = ["THE PLAY AREA WILL APPEAR IN 1 MINUTE!",0,0.9,10,0];
		publicVariable "MD_PVAR";
	}; 
	
	if((_time_minutes == (_zoneStart)) && (_time_seconds < 1)) then {
		_marker = "center";
		_posM = getMarkerPos _marker;

		_pos = [_posM,random (initRadius - (_circleSizing select numCircles)),random 360,0] call SHK_pos;
		
		_playArea = createMarker ["playArea", _pos];
		_playArea setMarkerColor "ColorBlue";
		_playArea setMarkerShape "ELLIPSE";
		_playArea setMarkerBrush "BORDER";
		_playArea setMarkerSize [(_circleSizing select numCircles),(_circleSizing select numCircles)];
		
		MD_PVAR = ["IN 5 MINUTES, PLAY WILL BE RESTRICTED TO THE BLUE CIRCLE!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		["center"] spawn A3E_DropPlane; 
	};
	
	if((_time_minutes == (_zoneLock - 2)) && (_time_seconds < 1)) then {
		
		MD_PVAR = ["IN 2 MINUTES, PLAY WILL BE RESTRICTED!",0,0.9,10,0];
		publicVariable "MD_PVAR";
	};

	if((_time_minutes == (_zoneLock - 1)) && (_time_seconds < 1)) then {
		
		MD_PVAR = ["IN 1 MINUTE, PLAY WILL BE RESTRICTED!",0,0.9,10,0];
		publicVariable "MD_PVAR";
	};
	
	if((_time_minutes == (_zoneLock)) && (_time_seconds < 1)) then {
		
		MD_PVAR = ["THE PLAY ZONE IS NOW RESTRICTED!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		numCircles = numCircles + 1;
		zone_started = true;
		publicVariable "zone_started";
	};
	
	if((_time_minutes == (_shrinkWarning)) && (_time_seconds < 1) && numCircles < 7) then {
		
		MD_PVAR = ["IN 2 MINUTES, THE PLAYZONE WILL BE FURTHER RESTRICTED! CHECK YOUR MAP!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		
		[(_circleSizing select numCircles)] spawn A3E_PlayAreaGenerator; 
		
		_shrinkWarning = _shrinkWarning + 4;		
	};
	
	if((_time_minutes == (_shrinkLock - 1)) && (_time_seconds < 1) && numCircles < 7) then {
		
		MD_PVAR = ["IN 1 MINUTE, THE PLAYZONE WILL BE FURTHER RESTRICTED!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		
	};
	
	if((_time_minutes == (_shrinkLock)) && (_time_seconds < 1) && numCircles < 7) then {
		
		MD_PVAR = ["THE PLAY ZONE IS NOW RESTRICTED!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		
		_shrinkLock = _shrinkLock + 4;
		numCircles = numCircles + 1;
		
		_a = (getMarkerPos "playArea");
		_b = ((getMarkerSize "playArea") select 0);
		
		deleteMarker "playArea";
		
		_marker = "newPlayArea";
		_posM2 = getMarkerPos _marker;
		_radiusM2 = (getMarkerSize _marker) select 0;
		
		deleteMarker _marker;
		
		_playArea = createMarker ["playArea", _posM2];
		_playArea setMarkerColor "ColorBlue";
		_playArea setMarkerShape "ELLIPSE";
		_playArea setMarkerBrush "BORDER";
		_playArea setMarkerSize [_radiusM2,_radiusM2];
		
		if(numCircles < 4) then {
			[_a,_b] spawn A3E_ZoneCleanUp; 
			["playArea"] spawn A3E_DropPlane;
		};		
	};
	
	if((_time_minutes == (_finalWarning)) && (_time_seconds < 1) && (numCircles == 7)) then {
		MD_PVAR = ["THE GAME WILL END IN 2 MINUTES!",0,0.9,10,0];
		publicVariable "MD_PVAR";
	};
	
	if((_time_minutes == (_finalWarning + 1)) && (_time_seconds < 1) && (numCircles == 7)) then {
		MD_PVAR = ["THE GAME WILL END IN 1 MINUTE!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		
		uiSleep 30;
		
		MD_PVAR = ["THE GAME WILL END IN 30 SECONDS!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		
		uiSleep 25;
		MD_PVAR = ["5!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		uiSleep 1;
		MD_PVAR = ["4!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		uiSleep 1;
		MD_PVAR = ["3!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		uiSleep 1;
		MD_PVAR = ["2!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		uiSleep 1;
		MD_PVAR = ["1!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		uiSleep 1;
		MD_PVAR = ["GAME OVER! DETERMINING WINNER!",0,0.9,10,0];
		publicVariable "MD_PVAR";
		if (totalplayers > 1) then {
			canWin = false;
			MD_PVAR = ["MORE THAN 1 PLAYER ALIVE!",0,0.7,10,0,0,0];
			publicVariable "MD_PVAR";
			uiSleep 3;
			MD_PVAR = ["YOU LOSE!",0,0.7,10,0,0,0];
			publicVariable "MD_PVAR";
			uiSleep 5;
			{
				SERVERCOMMANDHERE serverCommand format["#kick %1",owner _x];
			}forEach allPlayers;
			
			uisleep 3;
			SERVERCOMMANDHERE serverCommand "#shutdown";
		};
	};
	
	uiSleep 1;
};