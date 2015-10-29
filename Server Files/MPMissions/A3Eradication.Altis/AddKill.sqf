_kills = profilenamespace getVariable ["A3E_Kills" + getText(configFile >> "CfgSettings" >> "statkey"),0];
profilenamespace setVariable ["A3E_Kills" + getText(configFile >> "CfgSettings" >> "statkey"),_kills+1];
saveprofilenamespace; 
call A3E_UpdateMain;