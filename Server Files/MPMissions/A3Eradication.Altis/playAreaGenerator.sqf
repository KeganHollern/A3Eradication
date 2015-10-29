		_marker = "playArea";
		_posM = getMarkerPos _marker;
		_radiusM = (getMarkerSize _marker) select 0;
		_newRadius = _this select 0;

		_pos = [_posM,random(_radiusM - _newRadius),random 360,0] call SHK_pos;
		
		deleteMarker _marker;
		
		_playArea = createMarker ["playArea", _posM];
		_playArea setMarkerColor "ColorOPFOR";
		_playArea setMarkerShape "ELLIPSE";
		_playArea setMarkerBrush "BORDER";
		_playArea setMarkerSize [_radiusM,_radiusM];
		
		_newPlayArea = createMarker ["newPlayArea", _pos];
		_newPlayArea setMarkerColor "ColorBlue";
		_newPlayArea setMarkerShape "ELLIPSE";
		_newPlayArea setMarkerBrush "BORDER";
		_newPlayArea setMarkerSize [_newRadius,_newRadius];