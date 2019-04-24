.name "je me replique"
.comment "B J rR"


home:
sti r1, %:ld, %1
ldi %:ld, %1, r4
ld: live %1
sti r4, %:launcher, %1
sti r4, %:allo, %1
sti r4, %:rep, %1

bjr: ld %124, r7
ld %10, r9
add r7, r9, r7
sti r7, %:home, %0

allo: live %1
add r7, r9, r7
fork %:allo

rep: live %1
fork %:test2
test: fork %:loader1
loader2:
	ldi %4, %:launcher, r2
	ld %144, r3
	add r8, r8, r8
	zjmp %:launcher

test2: fork %:loader3
loader4:
	ldi %2, %:home, r2
	ld %152, r3
	add r8, r8, r8
	zjmp %:launcher

loader1:
	ldi %0, %:launcher, r2
	ld %140, r3
	add r8, r8, r8
	zjmp %:launcher
loader3:
	ldi %8, %:launcher, r2
	ld %148, r3
	add r8, r8, r8
	zjmp %:launcher
launcher:
	live %1
	sti r2, %0, r3
	zjmp %134
