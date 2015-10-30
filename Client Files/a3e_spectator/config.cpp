class CfgPatches{
    class Spectator
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[] = {};
    };
};

class RscMapControl;
class RscControlsGroup;
class RscText;
class RscStructuredText;

class RscDisplaySpectator
{
	onLoad = "[""Init"",_this,""RscDisplaySpectator"",'GUI'] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';";
	onUnload = "[""Exit"",_this,""RscDisplaySpectator"",'GUI'] call compile preprocessfilelinenumbers 'spectator\fn_camera.sqf';";
	idd = 18651;
	movingEnable = 0;
	enableSimulation = 1;
	iconCamera = "\A3\ui_f\data\GUI\Rsc\RscDisplayMissionEditor\iconCamera_ca.paa";
	class ControlsBackground
	{
		class Map: RscMapControl
		{
			idc = 3141;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
		};
		
		class Overlay: RscControlsGroup
		{
			idc = 3142;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
			class Controls
			{
				class CrossHorizontal: RscText
				{
					colorBackground[] = {0.75,0.75,0.75,0.75};
					x = "(safezoneW / 2) - (0.1 / 2)";
					y = "(safezoneH / 2)";
					w = 0.1;
					h = "0.001 * safezoneH";
				};
				class CrossVertical: CrossHorizontal
				{
					x = "(safezoneW / 2)";
					y = "(safezoneH / 2) - (0.1 / 2)";
					w = "0.001 * safezoneH";
					h = 0.1;
				};
			};
		};
		class MouseArea: RscText
		{
			idc = 3140;
			style = 16;
			x = "safezoneX";
			y = "safezoneY";
			w = "safezoneW";
			h = "safezoneH";
		};
	};
	class Controls
	{
		class Overlay: RscControlsGroup
		{
			idc = 3143;
			x = "safezoneX + safezoneW - 13 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y = "safezoneY + safezoneH - 5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w = "13 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SpectatorControls: RscStructuredText
		{
			idc = 3144;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			x = "safezoneX";
			y = "safezoneY + 0.015";
			w = "safezoneW";
			h = "safezoneH";
			font = "PuristaLight";
			sizeEx = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			shadow = 1;
		};
	};
};
