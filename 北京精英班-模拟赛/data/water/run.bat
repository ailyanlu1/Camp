set name=water
for /l %%x in (6,1,10) do (
	mkdata.exe
	%name%.exe
	del %name%%%x.in
	ren %name%.in %name%%%x.in
	del %name%%%x.out
	ren %name%.out %name%%%x.out
)
pause