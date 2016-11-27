mov r0, 1
mov r1, 2
mov r2, &fooVar
mov r3, r0
fmul r3, r1
mov r2->foo::a, r3
mov r3, r2->foo::a
mov r4, r3
fmul r4, r0
mov r2->foo::b, r4
mov r4, r2->foo::b
mov r3, r1
fmul r3, r4
mov r2->foo::c, r3
stall
