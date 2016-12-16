mov r0, &fooVar
mov r1, 1337
mov r0->foo::a, r1
mov r2, @Func
mov r5, r0->foo::a
rcall r2, 3
mov r1, r5
dout r1
stall
Func:
dout r0
mov r0, 1338
rret
