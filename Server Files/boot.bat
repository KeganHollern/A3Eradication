@echo off
title ArmA 3 Eradication @ 2302
:RESTART
echo Server Started
arma3server.exe -profiles=C:\Users\Administrator\Desktop\Better -name=server -ip=72.46.131.122 -port=2302 -cfg=basic.cfg -config=CONFIG_SERVER.cfg -mod=@Eradication 
cls
goto RESTART