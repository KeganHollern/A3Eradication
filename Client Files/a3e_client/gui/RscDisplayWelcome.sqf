_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		//Format and set welcome message
		diag_log "Welcome Loading";
		private ["_shown","_display", "_colorHighlight", "_colorWarning", "_bullet", "_message", "_text1", "_text2", "_buttonSpoiler", "_textSpoiler","_positionText1", "_yText1", "_hText1", "_positionSpoilerButton","_hSpoilerButton","_positionSpoilerText"];
		_display = _params select 0;
		_colorHighlight = "#790000";
		_colorWarning = "#A40000";
		
		_bullet = "<t size='0.5' color='" + _colorHighlight + "'><img image='A3\Ui_f\data\IGUI\RscIngameUI\RscHint\indent_square' /></t>";

		_text1 = _display displayCtrl 1100;
		_buttonSpoiler = _display displayctrl 2400;
		_textSpoiler = _display displayctrl 1101;
		_text2 = _display displayCtrl 1102;
		
		diag_log "Variables Created";
		
		_message = "";
		_message = _message + "<t align='center' size='8' shadow='0'><img image='a3e_client\images\main_bg_1.paa' /></t><br />";

		_message = _message + "<t color='" + _colorHighlight + "'>TITLE SECTION</t><br />";
		_message = _message + "<br />Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam leo lorem, efficitur quis risus a, fermentum gravida mi.<br />";
		_message = _message + _bullet + " Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut consectetur ligula augue. <br />";
		_message = _message + _bullet + " Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut consectetur ligula augue. <br />";
		_message = _message + _bullet + " Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut consectetur ligula augue. <br />";
		_message = _message + _bullet + " Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut consectetur ligula augue. <br /><br />";
		_message = _message + "<a href='http://google.com/' color='" + _colorWarning + "'>URL HERE</a><br /><br />";
	
		_message = _message + "<t color='" + _colorHighlight + "'>TITLE SECTION</t><br />";
		_message = _message + "<br /><br />";
		_message = _message + _bullet + " <br />";
		_message = _message + _bullet + " <br />";
		_message = _message + _bullet + " <br />";
		_message = _message + _bullet + " <br /><br />";
		_message = _message + "<br />";
		
		_message = _message + "<t color='" + _colorHighlight + "'>CHANGE LOG</t><br />";
		_message = _message + "<br /><br />";
		_message = _message + _bullet + " <t color='" + _colorHighlight + "'>Added</t> - Specatator System<br />";
		_message = _message + _bullet + " <t color='" + _colorHighlight + "'>Added</t> - New UI System<br />";
		_message = _message + _bullet + " <t color='" + _colorHighlight + "'>Fixed</t> - Something<br />";
		_message = _message + _bullet + " <t color='" + _colorHighlight + "'>Fixed</t> - Something<br />";
		_message = _message + _bullet + " <t color='" + _colorHighlight + "'>Changed</t> - Something<br /><br />";
		
		_message = _message + "<br />";
		
		_message = _message + "<a href='http://battleroyalegames.com/' color='" + _colorWarning + "'></a><br />";
		
		_message = _message + "<br /><br />";

		diag_log "Message Defined";
		
		_tText1 = (parseText _message);
		//Fill only the first text
		_text1 ctrlSetStructuredText _tText1;
	
		//Resize StructuredText component to display the scrollbar if needed
		_positionText1 = ctrlPosition _text1;
		_hText1 = ctrlTextHeight _text1;
		_pText1 = [_positionText1 select 0, _positionText1 select 1, _positionText1 select 2, _hText1];
		_text1 ctrlSetPosition _pText1;
		_text1 ctrlcommit 0;
		
		diag_log ("Text Height: " + str(_hText1));
		diag_log ("Text Position: " + str(_pText1));
		
		//Hide second text, spoiler text and button
		_buttonSpoiler ctrlSetFade 1;
		_buttonSpoiler ctrlCommit 0;
		_buttonSpoiler ctrlEnable false;
		
		diag_log "Button Hidden";
		
		_textSpoiler ctrlSetFade 1;
		_textSpoiler ctrlCommit 0;
		
		diag_log "HTML Hidden";
		
		_text2 ctrlSetFade 1;
		_text2 ctrlCommit 0;
		
		diag_log "text2 hidden";
		
		_disableCtrl = {	
			params ["_idc","_display"];
			(_display displayCtrl _idc) ctrlSetFade 1;
			(_display displayCtrl _idc) ctrlCommit 0;
			(_display displayCtrl _idc) ctrlEnable false;
		};
		[1001,_display] call _disableCtrl;
		[2400,_display] call _disableCtrl;
		[1101,_display] call _disableCtrl;
		[1102,_display] call _disableCtrl;
		
		diag_log "Controls Disabled";
	};
};