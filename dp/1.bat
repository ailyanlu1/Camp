:loop
	mkdata
	coin
	coin__
	fc coin.out coin__.out
	if errorlevel == 1 pause
goto loop