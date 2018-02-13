set name=travel
for /L %%x in (1,1,5) do (
	mkdata.exe
	%name%.exe
	del %name%%%x.in
	ren %name%.in %name%%%x.in
	del %name%%%x.out
	ren %name%.out %name%%%x.out
)
pause

