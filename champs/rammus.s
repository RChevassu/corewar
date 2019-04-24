.name    "Rammus"
.comment "ok."

sti r1,%:lol,%1
st r2, -5

lol:
	live	%1
	ld %71, r2
	aff r2
	ld %69, r2
	aff r2
	ld %84, r2
	aff r2
	ld %32, r2
	aff r2
	ld %82, r2
	aff r2
	ld %69, r2
	aff r2
	ld %75, r2
	aff r2
	ld %84, r2
	aff r2
	ld %0, r2
	aff r2
	zjmp %:lol
