#define CT_STATIC           0
#define CT_MAP_MAIN         101

#define ST_CENTER         0x02
#define ST_PICTURE        0x30

class CfgPatches {
	class a3e_client {
		requiredVersion = 0.1;
		requiredAddons[] = {"a3_ui_f","a3_data_f","a3_map_altis_scenes", "a3_map_vr_scenes", "a3_map_stratis_scenes","wake"};
		units[] = {"Player_F"};
	};
};
//--- Mod Settings
class CfgSettings {
	isdev = 1;
	statkey = "BibleThump_Kappa";
	tracks[] = {"MAD","SkyNet","Wasteland","Track01_Proteus","Defcon"};
};
//--- Player Unit Definition
class CfgVehicles {
	class B_Soldier_base_F; // External class reference
	
	class Player_F : B_Soldier_base_F {
		author = "EradicationStudios";
		_generalMacro = "Player_F";
		scope = 2;
		
		//--- Unit Model & Textures
		model = "\A3\Characters_F\Civil\c_poloshirt";
		modelSides[] = {3};
		hiddenSelections[] = {"Camo","insignia"};
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_3_co.paa"};
		
		class Wounds {
			tex[] = {};
			mat[] = {"A3\Characters_F\Civil\Data\c_cloth1.rvmat","A3\Characters_F\Civil\Data\c_cloth1_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth1_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth2.rvmat","A3\Characters_F\Civil\Data\c_cloth2_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth2_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth3.rvmat","A3\Characters_F\Civil\Data\c_cloth3_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth3_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth4.rvmat","A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat","A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat","A3\characters_f\civil\data\c_poloshirt.rvmat","A3\Characters_F\Civil\Data\c_poloshirt_injury.rvmat","A3\Characters_F\Civil\Data\c_poloshirt_injury.rvmat","A3\characters_f\common\data\coveralls.rvmat","A3\Characters_F\Common\Data\coveralls_injury.rvmat","A3\Characters_F\Common\Data\coveralls_injury.rvmat","A3\Characters_F\Civil\Data\hunter.rvmat","A3\Characters_F\Civil\Data\hunter_injury.rvmat","A3\Characters_F\Civil\Data\hunter_injury.rvmat","A3\Characters_F\Civil\Data\c_poloshirtpants.rvmat","A3\Characters_F\Civil\Data\c_poloshirtpants_injury.rvmat","A3\Characters_F\Civil\Data\c_poloshirtpants_injury.rvmat","A3\Characters_F\Civil\Data\priest.rvmat","A3\Characters_F\Civil\Data\priest_injury.rvmat","A3\Characters_F\Civil\Data\priest_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat","A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"};
		};
		
		
		//--- AI Items?
		accuracy = 1.6;
		camouflage = 1.2;
		threat[] = {0,0,0};
		primaryAmmoCoef = 0.4;
		secondaryAmmoCoef = 0.2;
		handgunAmmoCoef = 0.1;
		minFireTime = 7;
		canCarryBackPack = 1;
		armor = 2;
		armorStructural = 5;
		
		displayName = "Player";
		//--- Identity?
		nakedUniform = "U_BasicBody";
		
		//--- Starting Uniform
		uniformClass = "U_C_Poloshirt_stripped";
		
		//--- Items
		Items[] = {};
		respawnItems[] = {};
		
		//--- Weapons
		weapons[] = {"Throw", "Put"};
		respawnWeapons[] = {"Throw", "Put"};
		
		//--- Magazines
		magazines[] = {};
		respawnMagazines[] = {};
		
		//--- Linked Items (Include Vests Here)
		linkedItems[] = {"ItemMap", "ItemCompass", "ItemWatch", "ItemGPS"};
		respawnlinkedItems[] = {"ItemMap", "ItemCompass", "ItemWatch", "ItemGPS"};
		
		//--- Event Handlers
		class EventHandlers {
			init = "";
		};
		
		
		
		
		
	};
};
//--- Music duration patches (omg arma why are these not in game)
class CfgMusic {
	class MAD {
		duration = 198;
	};
	class Defcon {
		duration = 193;
	};
	class SkyNet {
		duration = 234;
	};
	class Wasteland {
		duration = 195;
	};
};
//--- Remove weapon cursor from all difficulty levels
class CfgDifficulties {
	class Mercenary {
		class Flags {
			weaponCursor[] = {0,0};
		};
	};
	class Recruit {
		class Flags {
			weaponCursor[] = {0,0};
		};
	};
	class Regular {
		class Flags {
			weaponCursor[] = {0,0};
		};
	};
	class Veteran {
		class Flags {
			weaponCursor[] = {0,0};
		};
	};
};
//--- Intro mission init
class CfgMissions {
	class Cutscenes {
		class A3EIntro {
			directory = "a3e_client\mission\A3EIntro.VR";
		};
	};
};
class CfgWorlds {
	class CAWorld;
	
	class Altis : CAWorld {
		cutscenes[] = {"A3EIntro"};
	};
	class Stratis : CAWorld {
		cutscenes[] = {"A3EIntro"};
	};
	class wake : Stratis {
		cutscenes[] = {"A3EIntro"};
	};
	class Pianosa_aut : Stratis {
		cutscenes[] = {"A3EIntro"};
	};
	class VR : CAWorld {
		cutscenes[] = {"A3EIntro"};
	};
	initWorld = "VR";
	demoWorld = "VR";
};

//--- UI Elements Included Below Here
class RscStandardDisplay;
class RscDisplayEmpty;
class RscVignette;
class RscControlsGroupNoScrollbars;
class RscControlsGroupNoHScrollbars;
class RscFrame;
class RscPicture;
class RscPictureKeepAspect;
class RscTitle;
class RscButtonMenu;
class RscText;
class RscStructuredText;
class RscHTML;
class RscButtonMenuOK;
class RscListBox;
class RscBackgroundGUI;
class RscControlsGroup;
//--- Game Hud
class RscTitles {
	class TextHud {
		access = 0;
		type = CT_STATIC;
		style = ST_CENTER;
		idc = -1;
		colorBackground[] = {0,0,0,0};
		colorText[] = {1,1,1,0.8};
		text = "";
		fixedWidth = 0;
		x = 0;
		y = 0;
		h = 0;
		w = 0;
		shadow = 2;
		font = "puristaMedium";
		sizeEx = "0.035";  

	};
	class PicHUD {
		access = 0;
		type = 0;
		style = 0x30 + 0x800;
		idc = -1;
		colorBackground[] = {0,0,0,0};
		text = "";
		fixedWidth = 0;
		font = "puristaMedium";
		sizeEx = "0.035";  
		shadow = 0;
		colorText[] = {1,1,1,1};
		x = 0;
		y = 0;
		w = 0.2;
		h = 0.15;
		tooltipColorText[] = {1,1,1,1};
		tooltipColorBox[] = {1,1,1,1};
		tooltipColorShade[] = {0,0,0,0.65};
	};
	class STextHud {
		access = 0;
		colorText[] = {1,1,1,1};
		deletable = 0;
		fade = 0;
		h = 0.035;
		idc = -1;
		shadow = 1;
		size = (((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25) * 1);
		style = 0;
		text = "";
		type = 13;
		w = 0.1;
		x = 0;
		y = 0;
		class Attributes 
		{
			align = "left";
			color = "#ffffff";
			colorLink = "#D09B43";
			font = "PuristaMedium";
			shadow = 1;
		};
	};
	class A3E_HUD {
		idd = -1; 
		duration = 1e+1000; 
		fadeIn = 0; 
		fadeOut = 0; 
		onLoad = "uiNamespace setVariable ['A3E_DISPLAY', _this select 0];"; 
			   
		class Controls 
		{
			class HUD_HEALTH : TextHud
			{
				text = "";
				idc = 520502;
				sizeEx = "0.02 / (getResolution select 5)";
				x = 0.945 * safezoneW + safezoneX;
				y = 0.8525 * safezoneH + safezoneY;
				w = 0.035  * safezoneW;
				h = 0.025  * safezoneH;
			};			
			class HUD_KillS : TextHud
			{
				text = "";
				idc = 520503;
				sizeEx = "0.02 / (getResolution select 5)";
				x = 0.945 * safezoneW + safezoneX;
				y = 0.9025 * safezoneH + safezoneY;
				w = 0.035  * safezoneW;
				h = 0.025  * safezoneH;
			};	
			class HUD_Alive : TextHud
			{
				text = "";
				idc = 520504;
				sizeEx = "0.02 / (getResolution select 5)";
				x = 0.945 * safezoneW + safezoneX;
				y = 0.9525 * safezoneH + safezoneY;
				w = 0.035  * safezoneW;
				h = 0.025  * safezoneH;
			};		
			class HUD_HEALTH_PIC : PicHUD
			{
				text = "a3e_client\images\hp.paa";
				idc = -1;
				x = 0.97 * safezoneW + safezoneX;
				y = 0.85 * safezoneH + safezoneY;
				w = 0.030 * safezoneW;
				h = 0.030 * safezoneH;
			};			
			class HUD_KILLS_PIC : PicHUD
			{
				text = "a3e_client\images\killcountsmall.paa";
				idc = -1;
				x = 0.97 * safezoneW + safezoneX;
				y = 0.9 * safezoneH + safezoneY;
				w = 0.030 * safezoneW;
				h = 0.030 * safezoneH;
			};	
			class HUD_PLAYERS_PIC : PicHUD
			{
				text = "a3e_client\images\playersalivesmall.paa";
				idc = -1;
				x = 0.97 * safezoneW + safezoneX;
				y = 0.95 * safezoneH + safezoneY;
				w = 0.030 * safezoneW;
				h = 0.030 * safezoneH;
			};
		};

	}; 
	class Earplugs_HUD {
		idd = -1; 
		duration = 1e+1000; 
		fadeIn = 0; 
		fadeOut = 0; 
		onLoad = "uiNamespace setVariable ['Earplugs_DISPLAY', _this select 0];"; 
			   
		class Controls 
		{
			class EarPlugs_PIC : PicHUD
			{
				text = "a3e_client\images\earbuds.paa";
				idc = -1;
				x = 0.95 * safezoneW + safezoneX;
				y = 0.8 * safezoneH + safezoneY;
				w = 0.040 * safezoneW;
				h = 0.040 * safezoneH;
			};
		};		
	};
	class FirstAidKit_HUD {
		idd = -1;
		duration = 1e+1000;
		fadeIn = 0;
		fadeOut = 0;
		onLoad = "uiNamespace setVariable ['FirstAidKit_DISPLAY', _this select 0];";
			   
		class Controls
		{
			class FirstAidKit_PIC : PicHUD
			{
				text = "\A3\Weapons_F\Items\data\UI\gear_FirstAidKit_CA.paa";
				idc = 1;
				x = 0.9 * safezoneW + safezoneX;
				y = 0.83 * safezoneH + safezoneY;
				w = 0.050 * safezoneW;
				h = 0.050 * safezoneH;
			};
		};
	};
	class Bandage_HUD {
		idd = -1;
		duration = 1e+1000;
		fadeIn = 0;
		fadeOut = 0;
		onLoad = "uiNamespace setVariable ['Bandage_DISPLAY', _this select 0];";
			   
		class Controls
		{
			class Bandage_PIC1 : PicHUD
			{
				text = "a3e_client\images\paink2.paa";
				idc = 1;
				x = 0.9 * safezoneW + safezoneX;
				y = 0.93 * safezoneH + safezoneY;
				w = 0.050 * safezoneW;
				h = 0.050 * safezoneH;
			};
			class Bandage_PIC2 : PicHUD
			{
				text = "a3e_client\images\paink.paa";
				idc = 2;
				x = 0.9 * safezoneW + safezoneX;
				y = 0.93 * safezoneH + safezoneY;
				w = 0.050 * safezoneW;
				h = 0.050 * safezoneH;
			};	
		};
	};
	class Keybinds_HUD {
		idd = -1;
		duration = 1e+1000;
		fadeIn = 0;
		fadeOut = 0;
		onLoad = "uiNamespace setVariable ['Keybinds_DISPLAY', _this select 0];";
			   
		class Controls
		{
			class UserKeybinds: STextHud
			{
				idc = 3120;
				colorText[] = {1,1,1,1};
				colorBackground[] = {0,0,0,0};
				x = "safezoneX";
				y = "safezoneY + 0.7";
				w = "safezoneW";
				h = "safezoneH";
				font = "PuristaLight";
				sizeEx = "1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				shadow = 1;
			};
		};
	};
	class Pills_HUD {
		idd = -1;
		duration = 1e+1000;
		fadeIn = 0;
		fadeOut = 0;
		onLoad = "uiNamespace setVariable ['Pills_DISPLAY', _this select 0];";
			   
		class Controls
		{
			class Pills_PIC1 : PicHUD
			{
				text = "a3e_client\images\pills2.paa";
				idc = 1;
				x = 0.9 * safezoneW + safezoneX;
				y = 0.88 * safezoneH + safezoneY;
				w = 0.050 * safezoneW;
				h = 0.050 * safezoneH;
			};
			class Pills_PIC2 : PicHUD
			{
				text = "a3e_client\images\pills.paa";
				idc = 2;
				x = 0.9 * safezoneW + safezoneX;
				y = 0.88 * safezoneH + safezoneY;
				w = 0.050 * safezoneW;
				h = 0.050 * safezoneH;
			};
		};
	};
};
//--- ArmA UI Redefinitions
class RscDisplayStart: RscStandardDisplay{
	class controls {
		class LoadingStart : RscControlsGroup {
			idc = 2310;
			x = "0 * safezoneW + safezoneX";
			y = "0 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			
			class controls {
				class Black : RscText {
					idc = 1000;
					x = "0 * safezoneW";
					y = "0 * safezoneH";
					w = "1 * safezoneW";
					h = "1 * safezoneH";
					colorBackground[] = {0, 0, 0, 1};
				};
				
				class Noise : RscPicture {
					idc = 1201;
					text = "\A3\Ui_f\data\IGUI\RscTitles\SplashArma3\arma3_splashNoise_ca.paa";
					x = "0 * safezoneW";
					y = "0 * safezoneH";
					w = "1 * safezoneW";
					h = "1 * safezoneH";
				};
				
				class Logo : RscPicture {
					idc = 1200;
					text = "\a3e_client\images\splash.paa";
					x = "0 * safezoneW";
					y = "0 * safezoneH";
					w = "1 * safezoneW";
					h = "1 * safezoneH";
				};
			};
		};
	};
};
class RscDisplayModLauncher: RscStandardDisplay {
	onLoad = "[""onLoad"",_this,""RscDisplayModLauncher"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayModLauncher.sqf"";";
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class TitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class LeftBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "13.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class PictureBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1082;
			x = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "24 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "12 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class OverviewTextBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1083;
			x = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "14.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "24 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "8.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayLogin: RscStandardDisplay {
	onLoad = "[""onLoad"",_this,""RscDisplayLogin"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayLogin.sqf"";";	
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class TitleBackground: RscText
		{
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class ListBoxBackground: RscText
		{
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "13.9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.7};
		};
		class MainBackground: RscText
		{
			idc = 1082;
			x = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "24 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.7};
		};
		class HeadBackground: RscText
		{
			idc = 1083;
			x = "31.2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "7.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0.5,0.5,0.5,0.5};
		};
	};
};
class RscDisplayCustomizeController {
	onLoad = "[""onLoad"",_this,""RscDisplayCustomizeController"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayCustomizeController.sqf"";";
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class RscTitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MainBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayIPAddress: RscStandardDisplay {
	onLoad = "[""onLoad"",_this,""RscDisplayIPAddress"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayIPAddress.sqf"";";
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class TitleBackground: RscText
		{
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class MainBackground: RscText
		{
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.7};
		};
	};
	
};
class RscDisplayGameOptions {
	onLoad = "[""onLoad"",_this,""RscDisplayGameOptions"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayGameOptions.sqf"";";
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundDisable: RscText{};
		class BackgroundDisableTiles: RscText{};
		class BackgroundImage1 : RscPicture {
			idc = 15150;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 15160;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 15170;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class TitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TabsBackground: RscText
		{
			colorBackground[] = {0,0,0,1};
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MainBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1082;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "3.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "19.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayFilter: RscStandardDisplay {
	onLoad = "[""onLoad"",_this,""RscDisplayFilter"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayFilter.sqf"";";
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class TitleBackground: RscText
		{
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class MainBackground: RscText
		{
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.7};
		};
	};
	
	
};
class RscDisplayPassword : RscStandardDisplay {
	onLoad = "[""onLoad"",_this,""RscDisplayPassword"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayPassword.sqf"";";
	class controlsbackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class TitleBackground: RscText
		{
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class MainBackground: RscText
		{
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "6.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.7};
		};
	};
	
};
class RscDisplayConfigureControllers {
	onLoad = "[""onLoad"",_this,""RscDisplayConfigureControllers"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayConfigureControllers.sqf"";";
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundDisable: RscText{};
		class BackgroundDisableTiles: RscText{};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class RscTitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MainBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
	
};
class RscDisplayConfigureAction {
	onLoad = "[""onLoad"",_this,""RscDisplayConfigureAction"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayConfigureAction.sqf"";";
	class ControlsBackground
	{
		delete Background;
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundDisable: RscText{};
		class BackgroundDisableTiles: RscText{};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class TitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class LeftBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayConfigure {
	onLoad = "[""onLoad"",_this,""RscDisplayConfigure"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayConfigure.sqf"";";
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundDisable: RscText{};
		class BackgroundDisableTiles: RscText{};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class TitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MainBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "3.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "19.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TabsBackground: RscText
		{
			colorBackground[] = {0,0,0,1};
			idc = 1082;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
	
};
class RscDisplayOptionsAudio {
	onLoad = "[""onLoad"",_this,""RscDisplayOptionsAudio"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayOptionsAudio.sqf"";";
	class controlsBackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundDisable: RscText{};
		class BackgroundDisableTiles: RscText{};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class RscTitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MainBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1082;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayOptionsVideo {
	onLoad = "[""onLoad"",_this,""RscDisplayOptionsVideo"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayOptionsVideo.sqf"";";
	class ControlsBackground {
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class TitleBackground: RscText
		{
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class OverallQualityBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1082;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class MainBackground: RscText
		{
			colorBackground[] = {0,0,0,0.7};
			idc = 1083;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "3.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "19.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TabsBackgroundLeft: RscText
		{
			colorBackground[] = {0,0,0,1};
			idc = 1081;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "3.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class RscDisplayMultiplayer: RscStandardDisplay {
	onLoad = "[""onLoad"",_this,""RscDisplayMultiplayer"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayMultiplayer.sqf"";";
	class controlsbackground
	{
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
	};
};
class RscDisplaySingleMission: RscStandardDisplay {
	onLoad = "[""onLoad"",_this,""RscDisplaySingleMission"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplaySingleMission.sqf"";";
	class controlsBackground {
		class Vignette: RscVignette
		{
			idc = 114998;
		};
		class TileGroup: RscControlsGroupNoScrollbars
		{
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			class Controls
			{
				class TileFrame: RscFrame
				{
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0,0,0,1};
				};
				class Tile_0_0: RscText
				{
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_1: RscText
				{
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_2: RscText
				{
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_3: RscText
				{
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_4: RscText
				{
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_0_5: RscText
				{
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_0: RscText
				{
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_1: RscText
				{
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_2: RscText
				{
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_3: RscText
				{
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_4: RscText
				{
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_1_5: RscText
				{
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_0: RscText
				{
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_1: RscText
				{
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_2: RscText
				{
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_3: RscText
				{
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_4: RscText
				{
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_2_5: RscText
				{
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_0: RscText
				{
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_1: RscText
				{
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_2: RscText
				{
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_3: RscText
				{
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_4: RscText
				{
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_3_5: RscText
				{
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_0: RscText
				{
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_1: RscText
				{
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_2: RscText
				{
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_3: RscText
				{
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_4: RscText
				{
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_4_5: RscText
				{
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_0: RscText
				{
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_1: RscText
				{
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_2: RscText
				{
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_3: RscText
				{
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_4: RscText
				{
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
				class Tile_5_5: RscText
				{
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0,0,0,0.1};
				};
			};
		};
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class TitleBackground: RscText
		{
			idc = 1080;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "SafezoneY + (1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "38 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class PictureBackground: RscText
		{
			idc = 1081;
			x = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "SafezoneY + (2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "22 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "13 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.7};
		};
		class NameAndAuthorBackground: RscText
		{
			idc = 1082;
			x = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "SafezoneY + (2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "22 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0,0,0,0.7};
		};
		class OverviewTextBackground: RscText
		{
			idc = 1083;
			x = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "SafezoneY + (15.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "22 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "7.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (1 * (safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2)))";
			colorBackground[] = {0,0,0,0.7};
		};
	};
};
class RscDisplayMission : RscDisplayEmpty {
	onUnload = "[""onUnload"",_this,""RscDisplayMission"",'GUI'] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayMission.sqf"";";
};
class RscDisplayMultiplayerSetup : RscStandardDisplay {
	onLoad = "[""onLoad"",_this,""RscDisplayMultiplayerSetup""] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayMultiplayerSetup.sqf"";";
	class controlsbackground {
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		class RolesBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.3};
			idc = 1085;
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			w = "(18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "(13.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 0.7*(safezoneH - 				(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
	};
	class Controls {
		class CA_ValueRoles : RscListBox {
			idc = 109;
			colorPlayer[] = {1, 1, 0, 1};
			colorAI[] = {1, 0, 0, 1};
			colorNobody[] = {1, 1, 1, 0.25};
			enabledAI = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\enabledAI_ca.paa";
			disabledAI = "A3\ui_f\data\gui\rsc\RscDisplayMultiplayerSetup\disabledAI_ca.paa";
			rowHeight = "1.75 * 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			w = "(18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			h = "SafezoneH - (9.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorSelectBackground[] = {1, 1, 1, 0.3};
			colorSelectBackground2[] = {1, 1, 1, 0.3};
			y = "6.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
		};
		class TextRole : RscText {
			idc = 108;
			sizeEx = "(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			w = "(18.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)) + 0.45*(safezoneW - 				((safezoneW / safezoneH) min 1.2))";
			text = "Roles for Eradication:";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(SafezoneX)";
			y = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY)";
			h = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[] = {0, 0, 0, 1};
		};
	};
};
class RscDisplayWelcome {
	idd = 999999;
	scriptName = "RscDisplayWelcome";
	scriptPath = GUI;
	onLoad = "[""onLoad"",_this,""RscDisplayWelcome""] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayWelcome.sqf"";";
	onUnload = "[""onUnload"",_this,""RscDisplayWelcome""] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayWelcome.sqf"";";
	
	class controlsBackground {
		class Vignette : RscVignette {
			idc = 114998;
		};
		
		class TileGroup : RscControlsGroupNoScrollbars {
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			
			class Controls {
				class TileFrame : RscFrame {
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0, 0, 0, 1};
				};
				
				class Tile_0_0 : RscText {
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_1 : RscText {
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_2 : RscText {
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_3 : RscText {
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_4 : RscText {
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_5 : RscText {
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_0 : RscText {
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_1 : RscText {
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_2 : RscText {
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_3 : RscText {
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_4 : RscText {
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_5 : RscText {
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_0 : RscText {
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_1 : RscText {
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_2 : RscText {
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_3 : RscText {
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_4 : RscText {
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_5 : RscText {
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_0 : RscText {
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_1 : RscText {
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_2 : RscText {
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_3 : RscText {
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_4 : RscText {
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_5 : RscText {
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_0 : RscText {
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_1 : RscText {
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_2 : RscText {
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_3 : RscText {
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_4 : RscText {
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_5 : RscText {
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_0 : RscText {
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_1 : RscText {
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_2 : RscText {
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_3 : RscText {
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_4 : RscText {
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_5 : RscText {
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
			};
		};
		
		class TitleBackground : RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
			idc = 1080;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class RightBackground : RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = 1081;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
	
	class controls {
		class Title : RscTitle {
			style = 0;
			idc = 1000;
			text = "Welcome To ArmA 3 Eradication!";
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class ButtonContinue : RscButtonMenuOK {
			text = "$STR_A3_RscDisplayWelcome_ButtonContinue";
			x = "32.75 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "23 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class MainControlsGroup : RscControlsGroupNoHScrollbars {
			idc = 2300;
			x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "38 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			
			class controls {
				class WelcomeStructuredText1 : RscStructuredText {
					idc = 1100;
					x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "37 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "7.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				
				class WelcomeHTML : RscHTML {
					idc = 1001;
					x = "0.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "37 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				
				class ButtonSpoiler : RscButtonMenu {
					idc = 2400;
					text = $STR_A3_RSCDISPLAYWELCOME_BUTTONSPOILER_SHOW;
					x = "0.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "6.25 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				
				class SpoilerText : RscStructuredText {
					idc = 1101;
					x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "9.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "37 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				
				class WelcomeStructuredText2 : RscStructuredText {
					idc = 1102;
					x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "14 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "37 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
	};
};
class RscDisplayMain : RscStandardDisplay {
	idd = 0;
	movingEnable = 0;
	scriptName = "RscDisplayMain";
	scriptPath = GUI;
	onLoad = "[""onLoad"",_this,""RscDisplayMain""] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayMain.sqf"";";
	onUnload = "[""onUnload"",_this,""RscDisplayMain""] call compile preprocessfilelinenumbers ""a3e_client\gui\RscDisplayMain.sqf"";";
	
	class controlsBackground {
		class Mainback {};
		class CA_ARMA2 {};
		
		class Vignette : RscVignette {
			idc = 114998;
		};
		
		class TileGroup : RscControlsGroupNoScrollbars {
			idc = 115099;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			disableCustomColors = 1;
			
			class Controls {
				class TileFrame : RscFrame {
					idc = 114999;
					x = 0;
					y = 0;
					w = "safezoneW";
					h = "safezoneH";
					colortext[] = {0, 0, 0, 1};
				};
				
				class Tile_0_0 : RscText {
					idc = 115000;
					x = "(0 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_1 : RscText {
					idc = 115001;
					x = "(0 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_2 : RscText {
					idc = 115002;
					x = "(0 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_3 : RscText {
					idc = 115003;
					x = "(0 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_4 : RscText {
					idc = 115004;
					x = "(0 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_0_5 : RscText {
					idc = 115005;
					x = "(0 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_0 : RscText {
					idc = 115010;
					x = "(1 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_1 : RscText {
					idc = 115011;
					x = "(1 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_2 : RscText {
					idc = 115012;
					x = "(1 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_3 : RscText {
					idc = 115013;
					x = "(1 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_4 : RscText {
					idc = 115014;
					x = "(1 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_1_5 : RscText {
					idc = 115015;
					x = "(1 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_0 : RscText {
					idc = 115020;
					x = "(2 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_1 : RscText {
					idc = 115021;
					x = "(2 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_2 : RscText {
					idc = 115022;
					x = "(2 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_3 : RscText {
					idc = 115023;
					x = "(2 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_4 : RscText {
					idc = 115024;
					x = "(2 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_2_5 : RscText {
					idc = 115025;
					x = "(2 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_0 : RscText {
					idc = 115030;
					x = "(3 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_1 : RscText {
					idc = 115031;
					x = "(3 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_2 : RscText {
					idc = 115032;
					x = "(3 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_3 : RscText {
					idc = 115033;
					x = "(3 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_4 : RscText {
					idc = 115034;
					x = "(3 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_3_5 : RscText {
					idc = 115035;
					x = "(3 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_0 : RscText {
					idc = 115040;
					x = "(4 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_1 : RscText {
					idc = 115041;
					x = "(4 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_2 : RscText {
					idc = 115042;
					x = "(4 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_3 : RscText {
					idc = 115043;
					x = "(4 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_4 : RscText {
					idc = 115044;
					x = "(4 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_4_5 : RscText {
					idc = 115045;
					x = "(4 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_0 : RscText {
					idc = 115050;
					x = "(5 * 1/6) * safezoneW";
					y = "(0 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_1 : RscText {
					idc = 115051;
					x = "(5 * 1/6) * safezoneW";
					y = "(1 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_2 : RscText {
					idc = 115052;
					x = "(5 * 1/6) * safezoneW";
					y = "(2 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_3 : RscText {
					idc = 115053;
					x = "(5 * 1/6) * safezoneW";
					y = "(3 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_4 : RscText {
					idc = 115054;
					x = "(5 * 1/6) * safezoneW";
					y = "(4 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
				
				class Tile_5_5 : RscText {
					idc = 115055;
					x = "(5 * 1/6) * safezoneW";
					y = "(5 * 1/6) * safezoneH";
					w = "1/6 * safezoneW";
					h = "1/6 * safezoneH";
					colorBackground[] = {0, 0, 0, 0.1};
				};
			};
		};
		
		class BackgroundImage1 : RscPicture {
			idc = 1515;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_1.paa";
		};
		class BackgroundImage2 : RscPicture {
			idc = 1516;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_2.paa";
		};
		class BackgroundImage3 : RscPicture {
			idc = 1517;
			x = "safeZoneX";
			y = "safeZoneY";
			w = "safeZoneW";
			h = "safeZoneH";
			text = "a3e_client\images\main_bg_3.paa";
		};
		
		class TitleBackground : RscText {
			idc = 1050;
			colorBackground[] = {0, 0, 0, 1};
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "17.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "18 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class ModIconsBackground : RscPicture {
			idc = 147;
			text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayMain\ModIconsBackground_ca.paa";
			x = "20 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "17.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "8.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class OwnedDLCIconsBackground : RscPicture {
			idc = 148;
			text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayMain\OwnedDLCIconsBackground_ca.paa";
			x = "20 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "19.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "8.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class DLCIconsBackground : RscPicture {
			idc = 146;
			y = "safezoneY + (1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayMain\DLCIconsBackground_ca.paa";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			w = "8.4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "2.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
	};
	
	class controls {
		class B_Player {};
		class B_SinglePlayer {};
		class B_SingleMission {};
		class B_MultiPlayer {};
		class B_MissionEditor {};
		class B_Credits {};
		class B_Quit {};
		class B_Campaign {};
		class B_Expansions {};
		class B_Options {};
		class Date {};
		class Version {};
		class Modlist {};
		class CA_ARMA2 {};
		class CA_PlayerName {};
		class CA_Version {};
		class CA_SinglePlayer {};
		class CA_Editor {};
		class CA_PlayerProfile {};
		class CA_MP {};
		class CA_Options {};
		class CA_Expansions {};
		class CA_Exit {};
		class CA_MenuBack {};
		class CA_TitleBack {};
		class CA_BottomBack {};
		class Mainback {};
		class TrafficLight {};
		
		class GameLogo : RscPicture {
			idc = 1202;
			text = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "12.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "7.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "3.75 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class Title : RscTitle {
			idc = 1003;
			style = 0;
			shadow = 0;
			text = "$STR_A3_RscDisplayMain_Title";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "7.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class PlayersName : RscTitle {
			idc = 109;
			style = 1;
			shadow = 0;
			text = "$STR_A3_RscDisplayMain_PlayersName";
			x = "8.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "10.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};

		class ButtonScenarios: RscButtonMenu {
			idc = 103;
			onbuttonclick = "uinamespace setvariable ['RscDisplaySingleMission_title', toUpper (localize 'STR_A3_RSCDISPLAYMAIN_BUTTONSCENARIOS')];";
			text = "SINGLEPLAYER";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "17.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "18 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Start a singleplayer game";
		};
		class ButtonMultiplayer : RscButtonMenu {
			idc = 105;
			text = "MULTIPLAYER";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "18.6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "18 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Join a multiplayer match";
		};
		
		class ButtonOptions : RscButtonMenu {
			idc = 102;
			text = "$STR_A3_RscDisplayMain_ButtonOptions";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "19.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "18 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = $STR_TOOLTIP_MAIN_OPTIONS_A3;
		};
		
		class ButtonVideo : RscButtonMenu {
			idc = 301;
			text = "$STR_A3_RscDisplayMain_ButtonVideo";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "14.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = $STR_TOOLTIP_MAIN_VIDEO;
		};
		
		class ButtonAudio : RscButtonMenu {
			idc = 302;
			text = "$STR_A3_RscDisplayMain_ButtonAudio";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "15.3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = $STR_TOOLTIP_MAIN_AUDIO;
		};
		
		class ButtonControls : RscButtonMenu {
			idc = 303;
			text = "$STR_A3_RscDisplayMain_ButtonControls";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = $STR_TOOLTIP_MAIN_CONTROLS;
		};
		
		class ButtonGame : RscButtonMenu {
			idc = 307;
			text = "$STR_A3_RscDisplayMain_ButtonGame";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "17.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = $STR_TOOLTIP_MAIN_GAME;
		};
		
		class ButtonProfile : RscButtonMenu {
			idc = 1001;
			onButtonClick = "_display = ctrlParent (_this select 0);	_ctrl109 =_display displayCtrl 109; ctrlActivate _ctrl109; debuglog _ctrl109";
			text = "$STR_A3_RscDisplayMain_ButtonProfile";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "18.6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = $STR_TOOLTIP_MAIN_PLAYER;
		};
		
		class ButtonExpansions : RscButtonMenu {
			idc = 140;
			text = "$STR_A3_RscDisplayMain_ButtonExpansions";
			x = "2 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "19.7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "17 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = $STR_TOOLTIP_MAIN_EXPANSIONS;
		};
		
		class ButtonExit : RscButtonMenu {
			idc = 106;
			shortcuts[] = {0x00050000 + 3};
			text = "$STR_A3_RscDisplayMain_ButtonExit";
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "20.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "18 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = $STR_TOOLTIP_MAIN_EXIT;
		};
		
		class ButtonAllMissions : RscButtonMenu {
			shortcuts[] = {0x00050000 + 3};
			idc = 104;
			text = "$STR_A3_RscDisplayMain_ButtonAllMissions";
			x = "9.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "21.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "9.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class CopyrightText : RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			w = "safezoneW - 2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			shadow = 0;
			font = "PuristaLight";
			idc = 1006;
			text = $STR_COPYRIGHT_DISCLAIMER;
			x = "1 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "23 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		
		class VersionNameAndNumber : RscText {
			style = 1;
			x = "safezoneX + safezoneW - 14.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			shadow = 0;
			font = "PuristaLight";
			idc = 1008;
			y = "23 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "13.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx = "0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	
		//--- Leaderboards Data Preview
		class Leaderboards : RscControlsGroupNoScrollbars {
			idc = 1337;
			x = "safezoneX + safezoneW - (16 * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			y = "safezoneY + (1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "16.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls {
				class LeaderboardsTitle : RscText {
					colorBackground[] = {0, 0, 0, 0.8};
					idc = 1338;
					x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text = "Arma 3 Eradication Statistics";
				};
				class LeaderboardsSubtitle : RscText {
					idc = 1339;
					x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "1.1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0, 0, 0, 0.6};
					text = "Your Game Stats";
				};
				class LeaderboardsBackground : RscText {
					idc = 1340;
					x = "0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[] = {0, 0, 0, 0.4};
				};
				class LeaderboardsData : RscStructuredText {
					idc = 1341;
					shadow = 0;
					x = "0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};				
			};
		};
	
	};
};