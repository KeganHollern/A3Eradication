_wins = profilenamespace getVariable ["A3E_Wins" + getText(configFile >> "CfgSettings" >> "statkey"),0];
profilenamespace setVariable ["A3E_Wins" + getText(configFile >> "CfgSettings" >> "statkey"),_wins+1];
saveprofilenamespace; 
uinamespace setVariable ["A3E_InGame",false];
call A3E_UpdateMain;