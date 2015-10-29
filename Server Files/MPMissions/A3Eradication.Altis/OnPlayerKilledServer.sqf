_uid = getplayeruid _dead;
if !(_uid in activeSpectators) then {
	
	_showMsg = {
		params["_msg","_name1",["_name2",""]];
		uiSleep 0.5;
		MD_PVAR = [format[_msg,_name1,_name2,({(side _x != civilian) && (alive _x) && isPlayer(_x)}count playableUnits)],0,-0.4,5,0];
		publicVariable "MD_PVAR";
	};

	_messageCheck = true;
	if(!isNull _killer) then {
		if(isPlayer(_killer)) then {
			if(_killer != _dead) then {
				_kills = _killer getVariable ["kills",0];
				_killer setVariable ["kills",_kills + 1,true];
				["%1 was killed by %2. %3 Remain",(name _dead),(name _killer)] spawn _showMsg;
				_messageCheck = false;
			};
			if(_killer == _dead) then {
				["%1 has committed suicide. %3 Remain",(name _dead)] spawn _showMsg;
				_messageCheck = false;
			};
		};
	};
	if(_messageCheck) then {
		["%1 has died. %3 Remain",(name _dead)] spawn _showMsg;
	};
	_isSpectator = false;
	if((getplayeruid _dead) in spectatorList) then {
		_isSpectator = true;
	};
	if(!spectatorWhitelist) then {_isSpectator = true;};
	if(!_isSpectator) then {
		(owner _dead) spawn {
			uiSleep 3;
			SERVERCOMMANDHERE serverCommand format["#kick %1",_this];
		};
	} else {
		//--- Tis a spectator
		if !((getplayeruid _dead) in activeSpectators) then {
			activeSpectators pushBack (getplayeruid _dead);
			(owner _dead) publicVariableClient "spectatorUnitPositions";
		};
	};
};