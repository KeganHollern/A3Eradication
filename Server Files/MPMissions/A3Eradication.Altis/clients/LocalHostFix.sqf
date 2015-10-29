if(isServer) then {
	[] spawn {
		_oldVar = "";
		waitUntil{!isNil "MD_PVAR"};
		while{true} do {
			waitUntil{str(MD_PVAR) != _oldVar};
			_oldVar = str(MD_PVAR);
			MD_PVAR spawn BIS_fnc_dynamicText
		};
	};
	[] spawn {
		waitUntil{!isNil "game_started"};
		_oldVar = str(game_started);
		while{true} do {
			waitUntil{str(game_started) != _oldVar};
			_oldVar = str(game_started);
			showGPS false;
			showMap false;
			showHUD false;
			("Keybinds_Layer" call BIS_fnc_rscLayer) cutFadeOut 1;
		};
	};
	[] spawn {
		waitUntil{!isNil "deploy_players"};
		_oldVar = str(deploy_players);
		while{true} do {
			waitUntil{str(deploy_players) != _oldVar};
			_oldVar = str(deploy_players);
			[] spawn A3E_Para;
		};
	};
};