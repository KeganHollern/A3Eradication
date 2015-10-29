#define DIK_T               0x14
#define DIK_Y               0x15
#define DIK_H               0x23

disableSerialization;

isBandaging = false;
bandageActive = false;
isPilling = false;
pillActive = false;
isMedding = false;
	
("Pills_Layer" call BIS_fnc_rscLayer) cutRsc ["Pills_HUD","PLAIN"];
_display = uiNamespace getVariable "Pills_DISPLAY";
_ctrl1 = _display displayCtrl 1;
_ctrl2 = _display displayCtrl 2;
_ctrl1 ctrlShow false;
_ctrl2 ctrlShow false;
("Bandage_Layer" call BIS_fnc_rscLayer) cutRsc ["Bandage_HUD","PLAIN"];
_display = uiNamespace getVariable "Bandage_DISPLAY";
_ctrl1 = _display displayCtrl 1;
_ctrl2 = _display displayCtrl 2;
_ctrl1 ctrlShow false;
_ctrl2 ctrlShow false;
("FirstAidKit_Layer" call BIS_fnc_rscLayer) cutRsc ["FirstAidKit_HUD","PLAIN"];
_display = uiNamespace getVariable "FirstAidKit_DISPLAY";
_ctrl = _display displayCtrl 1;
_ctrl ctrlShow false;


doBandage = {
    private["_item","_success"];
    if !(call canBandage) exitWith {isBandaging = false;};
	isBandaging = true;
	if(vehicle player != player) exitWith {isBandaging = false;};
	_item = "ItemBandages";
	if !(_item in (magazines player)) exitWith {isBandaging = false;};
	_success =[5,_item] call doAnim;
	if !(_success) exitWith {isBandaging = false;};
	isBandaging = false;
	player removeMagazine _item;
	player call bandageEffect;
};

doPill = {
    private["_item","_success"];
    if !(call canPill) exitWith {isPilling = false;};
	isPillinging = true;
	if(vehicle player != player) exitWith {isPilling = false;};
	_item = "ItemPainPills";
	if !(_item in (magazines player)) exitWith {isPilling = false;};
	_success = [4,_item] call doAnim;
	if !(_success) exitWith {isPilling = false;};
	isPilling = false;
	player removeMagazine _item;
	player call pillEffect;
};

doMed = {
    private["_item","_success"];
    if !(call canMed) exitWith {isMedding = false;};
	isMedding = true;
	if(vehicle player != player) exitWith {isMedding = false;};
	_item = "ItemFirstAidKit";
	if !(_item in (magazines player)) exitWith {isMedding = false;};
	_success = [7,_item] call doAnim;
	if !(_success) exitWith {isMedding = false;};
	isMedding = false;
	player removeMagazine _item;
	player call medEffect;
};

bandageEffect = {
	
	private["_damage","_head","_chest","_hands","_legs"];
	
	bandageActive = true;
	_bandageCount = 40;
	
	for '_i' from 0 to (_bandageCount-1) do {
		uiSleep 1;
		_head = ((player getHitPointDamage "hitHead") - 0.01) max 0;
		_chest = ((player getHitPointDamage "hitBody") - 0.01) max 0;
		_hands = ((player getHitPointDamage "hitHands") - 0.01) max 0;
		_legs = ((player getHitPointDamage "hitLegs") - 0.01) max 0;
		_damage = damage player;
		player setDamage (_damage - 0.0025);
		player setHitPointDamage ["hitLegs",_legs];
		player setHitPointDamage ["hitHead",_head];
		player setHitPointDamage ["hitBody",_chest];
		player setHitPointDamage ["hitHands",_hands];
	};
	
	bandageActive = false;
};

pillEffect = {
	private["_damage","_head","_chest","_hands","_legs"];

	pillActive = true;
	
	_bandageCount = 20;
	
	for '_i' from 0 to (_bandageCount-1) do {
		uiSleep 1;
		_head = ((player getHitPointDamage "hitHead") - 0.01) max 0;
		_chest = ((player getHitPointDamage "hitBody") - 0.01) max 0;
		_hands = ((player getHitPointDamage "hitHands") - 0.01) max 0;
		_legs = ((player getHitPointDamage "hitLegs") - 0.01) max 0;
		_damage = damage player;
		player setDamage (_damage - 0.0025);
		player setHitPointDamage ["hitLegs",_legs];
		player setHitPointDamage ["hitHead",_head];
		player setHitPointDamage ["hitBody",_chest];
		player setHitPointDamage ["hitHands",_hands];
	};
	
	pillActive = false;
};

medEffect = {
	player setDamage 0.25;
};

"anim_cancel" addPublicVariableEventHandler {
	((_this select 1) select 0) switchmove ((_this select 1) select 1);
	anim_cancel = nil;
};

doAnim = {
    private["_time","_success","_mags","_item","_lastanim","_cancel"];
    params["_animLength","_animItem"];
	_time = time + _animLength;
	_success = true;
	_mags = magazines player;
	_item = _animItem;
	_lastanim = animationState player;
	player playAction "Medic";
	cancelAnim = false;
	_cancel = (findDisplay 46) displayAddEventHandler ["KeyDown",{
		_keys = (actionKeys "MoveForward") + (actionKeys "MoveBack") + (actionKeys "TurnRight") + (actionKeys "TurnLeft");
		if((_this select 1) in _keys) then {
			cancelAnim = true;
		};
		false;
	}];
	waitUntil{time >= _time || cancelAnim || !(_item in (magazines player))};
	anim_cancel = [player,_lastanim];
	publicVariable "anim_cancel";
	player switchMove _lastanim;
	(findDisplay 46) displayRemoveEventHandler ["KeyDown",_cancel];
	if(cancelAnim || !(_item in (magazines player))) then {
		_success = false;
	};
	_success;
};	

canBandage = {
	params[["_isUI",false,[false]]];
	_mags = magazines player;
	_good = false;
	if(("ItemBandages" in _mags) && !bandageActive && ((!isPilling && !isBandaging && !isMedding) || _isUI) && (vehicle player == player) && ((damage player) > 0)) then {
		_good = true;
	};
	_good;
};

canPill = {
	params[["_isUI",false,[false]]];
	_mags = magazines player;
	_good = false;
	if(("ItemPainPills" in _mags) && !pillActive && ((!isPilling && !isBandaging && !isMedding) || _isUI) && (vehicle player == player) && ((damage player) > 0)) then {
		_good = true;
	};
	_good;
};

canMed = {
	params[["_isUI",false,[false]]];
	_mags = magazines player;
	_good = false;
	if(("ItemFirstAidKit" in _mags) && ((!isPilling && !isBandaging && !isMedding) || _isUI) && (vehicle player == player) && (((damage player) > 0.25) || ((player getHitPointDamage "hitHands") > 0.25) || ((player getHitPointDamage "hitLegs") > 0.25) || ((player getHitPointDamage "hitHead") > 0.25) || ((player getHitPointDamage "hitBody") > 0.25))) then {
		_good = true;
	};
	_good;
};

item_dblClick = {
	disableserialization;
	_index = _this select 0;
	_type = _this select 1;
	_itemArray = [];
	_itemText = "";
	_itemType = "";

	switch(_type) do {
		case 0: { //Uniform
			_itemArray = uniformItems player;
			_itemText =  lbText[633,_index];
		};
		case 1: { //Vest
			_itemArray = vestItems player;
			_itemText =  lbText[638,_index];
		};
		case 2: { //Backpack
			_itemArray = backpackItems player;
			_itemText =  lbText[619,_index];
		};
	};
	//Find item from config
	{
		_name = getText(configFile >> "cfgWeapons" >> _x >> "DisplayName");
		if(_name == "") then {_name = getText(configFile >> "cfgMagazines" >> _x >> "DisplayName");};
		if(_name == _itemText) exitWith {_itemType = _x;};			
	} forEach _itemArray;
	
	if(_itemType == "ItemPainPills") then {
		if( (call canPill) ) then {
	        [] spawn doPill;
	    };
	};
	if(_itemType == "ItemBandages") then {
	    if( (call canBandage) ) then {
	        [] spawn doBandage;
	    };
	};
	if(_itemType == "ItemFirstAidKit") then {
	    if( (call canMed) ) then {
	        [] spawn doMed;
	    };
	};
};

(findDisplay 46) displayAddEventHandler ["KeyDown", {
	_success = false;
	_key = _this select 1;
	
	_keysBandage = (ActionKeys "User1");
	_keysPills = (ActionKeys "User2");
	_keysFirstAid = (ActionKeys "User3");
	
	if(count(_keysBandage) == 0) then {_keysBandage = [DIK_T];};
	if(count(_keysPills) == 0) then {_keysPills = [DIK_Y];};
	if(count(_keysFirstAid) == 0) then {_keysFirstAid = [DIK_H];};
	
	if(_key in _keysBandage) then {
    	if(call canBandage) then {
			[] spawn doBandage;
			_success = true;
		};
	};
	if(_key in _keysPills) then {
	    if(call canPill) then {
			[] spawn doPill;
			_success = true;
		};
	};
	if(_key in _keysFirstAid) then {
	    if(call canMed) then {
			[] spawn doMed;
			_success = true;
		};
	};
	_success
}];

[] spawn A3E_medicalDisplay;

[] spawn {
	disableserialization;	
	cursor_pos = [0,0];
	while{true} do {
		waitUntil{!isNull (findDisplay 602)};
		_display = (findDisplay 602);

		_display displayAddEventHandler ["MouseButtonDown",{cursor_pos = [_this select 2,_this select 3];}];

		_ctrl = _display displayCtrl 633;
		_ctrl ctrlAddEventHandler ["LBDblClick",{[_this select 1,0] spawn item_dblClick;}];

		_ctrl = _display displayCtrl 638;
		_ctrl ctrlAddEventHandler ["LBDblClick",{[_this select 1,1] spawn item_dblClick;}];

		_ctrl = _display displayCtrl 619;
		_ctrl ctrlAddEventHandler ["LBDblClick",{[_this select 1,2] spawn item_dblClick;}];

		waitUntil{isNull (findDisplay 602)};
	};
};