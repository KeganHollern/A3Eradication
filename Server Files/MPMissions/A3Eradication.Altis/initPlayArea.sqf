// Set Initial Play Area
_Area = createMarker ["RandomArea", [15500,15000,0]];
_Area setMarkerColor "ColorBlack";
_Area setMarkerShape "RECTANGLE";
_Area setMarkerBrush "BORDER";
_Area setMarkerSize [14000,9000];
_Area setMarkerAlpha 0;

while{true} do{
	
	_houseList = [];
	_pos = ["RandomArea",0] call shk_pos;

	_houseList= _pos nearObjects ["House",initRadius];
	
	if (count _houseList >= ((floor random(751))+750)) exitWith {
		_gameArea = createMarker ["center", _pos];
		_gameArea setMarkerColor "ColorBlack";
		_gameArea setMarkerShape "ELLIPSE";
		_gameArea setMarkerBrush "Border";
		_gameArea setMarkerSize [initRadius,initRadius];
	};
};