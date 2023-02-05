echo Ingresa el tiempo para el shutdow
set /p t=
pause
shutdown -s -t %t%
echo La computadora se apagara en %t% segundos
TIMEOUT /T 10
shutdown -a
echo shutdown abortado
pause