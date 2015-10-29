{
	removeAllWeapons _x;
	removeUniform _x;
	removeVest _x;
	removeHeadgear _x;
	_x addWeaponGlobal "ItemGPS";
	_x addVest "V_Rangemaster_belt";
	_x addUniform "U_OG_Guerilla2_1";
	//_vest = vestContainer _x;
	//_vest addMagazineCargoGlobal ["9Rnd_45ACP_Mag",1];
	//_vest addWeaponCargoGlobal ["hgun_ACPC2_F",1];
}forEach allPlayers;
