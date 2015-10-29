//--- Parse Loot Config File
mil_positions = [];
mil_buildings = [];
ind_positions = [];
ind_buildings = [];
res_positions = [];
res_buildings = [];
all_buildings = [];
{
	mil_positions pushBack (_x select 1);
	mil_buildings pushBack toLower(_x select 0);
} forEach getArray(missionConfigFile >> "CfgBuildingTypes" >> "military");
{
	ind_positions pushBack (_x select 1);
	ind_buildings pushBack toLower(_x select 0);
} forEach getArray(missionConfigFile >> "CfgBuildingTypes" >> "industrial");
{
	res_positions pushBack (_x select 1);
	res_buildings pushBack toLower(_x select 0);
} forEach getArray(missionConfigFile >> "CfgBuildingTypes" >> "residential");

all_buildings = mil_buildings + ind_buildings + res_buildings;

while{true} do {
	{
		if(alive _x && side _x != civilian) then {
			_building = nearestObject [_x,"House"];
			_hasVar = _building getVariable ["SpawnedLoot",false];
			if !(_hasVar) then {
				_building setVariable ["SpawnedLoot",true];
				if(toLower(typeof _building) in all_buildings) then {
					[_building,A3E_SpawnLoot] execFSM 'fsm\call.fsm';
				};
			};
		};
	} forEach allPlayers;
};

