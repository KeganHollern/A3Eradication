group_lock = true;
while{group_lock} do {
	_units = units (group player);
	setGroupIconsVisible [false,false];
	if(count _units > 1) then {
		_grp = group player;
		[player] joinSilent (creategroup (side player));
		deletegroup _grp;
	};
};