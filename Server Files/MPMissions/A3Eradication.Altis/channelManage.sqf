while{!deploy_players && !(serverCommandAvailable "#kick")} do {
	if(currentChannel != 3) then {
	    setCurrentChannel 3;
	};
	uiSleep 0.1;
};