disableserialization;
_display = findDisplay 0;
_kills = profilenamespace getVariable ["A3E_Kills" + getText(configFile >> "CfgSettings" >> "statkey"),0];
_wins = profilenamespace getVariable ["A3E_Wins" + getText(configFile >> "CfgSettings" >> "statkey"),0];
_deaths = profilenamespace getVariable ["A3E_Deaths" + getText(configFile >> "CfgSettings" >> "statkey"),0];
_winRate = round((_wins/(_deaths+_wins))*10000)/100;

_text = "<t color='#FFFFFF'>Kills: </t>" + str(_kills) + "<br/>";
_text = _text + "<t color='#FFFFFF'>Wins: </t>" + str(_wins) + "<br/>";
_text = _text + "<t color='#FFFFFF'>Deaths: </t>" + str(_deaths) + "<br/>";
_text = _text + "<t color='#FFFFFF'>Win Rate: </t>" + str(_winRate) + "%<br/>";

_control = _display displayCtrl 1341;
_control ctrlSetStructuredText (parseText _text);
_control ctrlCommit 0;