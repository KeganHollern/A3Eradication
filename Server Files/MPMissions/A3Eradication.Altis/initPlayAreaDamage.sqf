_enableDamage = true;
_outSideZone = false;
_punishDelay = 10;
_circleDamage = [0.1,0.125,0.15,0.2,0.225,0.25,0.55];

while {!zone_started && _enableDamage && (alive player) && (side player != civilian)} do {
	
	_marker = "center";
	_posM = getMarkerPos _marker;
	_timeCount = 0;
	    
    if((player distance _posM > initRadius) && (str(side player) != "CIV")) then {
        ["YOU ARE OUTSIDE THE PLAY AREA!",0,0.7,5,0] spawn bis_fnc_dynamictext;
		_outsideZone = true;
	};
	
	while {_outsideZone} do {
		if(_timeCount == _punishDelay) then {
			_damage = damage player;
			_legs = player getHitPointDamage "hitLegs";
			_head = player getHitPointDamage "hitHead";
			_chest = player getHitPointDamage "hitBody";
			_hands = player getHitPointDamage "hitHands";
			player setDamage (_damage + (_circleDamage select 0));
			player setHitPointDamage ["hitHands",(_hands+(_circleDamage select 0))];
			player setHitPointDamage ["hitHead",(_head+(_circleDamage select 0))];
			player setHitPointDamage ["hitBody",(_chest+(_circleDamage select 0))];
			player setHitPointDamage ["hitLegs",(_legs+(_circleDamage select 0))];
			["YOU ARE STILL OUTSIDE THE PLAY AREA!",0,0.7,10,0] spawn bis_fnc_dynamictext; 
			_timeCount = 0;
		};
	
		if(player distance _posM < initRadius) then {
			["YOU ARE BACK INSIDE THE PLAY AREA!",0,0.7,10,0] spawn bis_fnc_dynamictext;
			_outSideZone = false;
		};
		
		_timeCount = _timeCount + 1;
		uiSleep 1;
	};         
	uiSleep 1;
};

while {zone_started && _enableDamage && (alive player) && (side player != civilian)} do {
	
	_marker = "playArea";
	_posM = getMarkerPos _marker;
    _radius = (getMarkerSize _marker) select 0;
	_timeCount = 0;
	    
    if((player distance _posM > _radius) && (str(side player) != "CIV")) then {
        ["YOU ARE OUTSIDE THE PLAY AREA!",0,0.7,5,0] spawn bis_fnc_dynamictext;
		_outsideZone = true;
	};
	
	while {_outsideZone} do {
		if((_timeCount == _punishDelay)) then {
			_damage = damage player;
			_legs = player getHitPointDamage "hitLegs";
			_head = player getHitPointDamage "hitHead";
			_chest = player getHitPointDamage "hitBody";
			_hands = player getHitPointDamage "hitHands";
			player setDamage (_damage + (_circleDamage select ((numCircles-1) max 0)));
			player setHitPointDamage ["hitHands",(_hands+(_circleDamage select ((numCircles-1) max 0)))];
			player setHitPointDamage ["hitHead",(_head+(_circleDamage select ((numCircles-1) max 0)))];
			player setHitPointDamage ["hitBody",(_chest+(_circleDamage select ((numCircles-1) max 0)))];
			player setHitPointDamage ["hitLegs",(_legs+(_circleDamage select ((numCircles-1) max 0)))];
			["YOU ARE STILL OUTSIDE THE PLAY AREA!",0,0.7,10,0] spawn bis_fnc_dynamictext; 
		
			_timeCount = 0;
		};
	
		if(player distance _posM < _radius) then {
			["YOU ARE BACK INSIDE THE PLAY AREA!",0,0.7,10,0] spawn bis_fnc_dynamictext;
			_outSideZone = false;
		};
		
		_timeCount = _timeCount + 1;
		uiSleep 1;
	};         
	uiSleep 1;
};