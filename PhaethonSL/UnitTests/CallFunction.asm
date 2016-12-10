mov r0, &fooVar
mov r1, 1337
mov r0->foo::a, r1
mov r1, @Func
mov r4, r0->foo::a
rcall r1, 2
stall
Func:
dout r0
rret
