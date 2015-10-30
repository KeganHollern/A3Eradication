class CfgPatches{
	class a3e_Items
	{
		units[]={"ItemBandages","ItemPainPills","ItemFirstAidKit"};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = {};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class A3E_Magazine: CA_Magazine {};
	class ItemBandages: A3E_Magazine {
		scope=2;
		count=1;
		type=256;
		displayName="Bandages";
		descriptionUse="A box of bandages.";
		model="\A3\Structures_F_EPA\Items\Medical\PainKillers_F.p3d";
		picture="\a3e_Items\paink.paa";
		descriptionShort="A box of bandages.";
		mass = 6;
	};
	class ItemPainPills: A3E_Magazine {
		scope=2;
		count=1;
		type=256;
		displayName="Pain Pills";
		descriptionUse="A bottle of pills.";
		model="\A3\Structures_F_EPA\Items\Medical\VitaminBottle_F.p3d";
		picture="\a3e_Items\pills.paa";
		descriptionShort="A bottle of pills.";
		mass= 6;
	};
	class ItemFirstAidKit: A3E_Magazine {
		scope=2;
		count=1;
		type=256;
		displayName="First Aid Kit";
		descriptionUse="Partially heals wounds.";
		model="\A3\Weapons_F\Items\FirstAidkit";
		picture="\A3\Weapons_F\Items\data\UI\gear_FirstAidKit_CA.paa";
		descriptionShort="Partially heals wounds.";
		mass= 6;
	};
};