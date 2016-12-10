mov r0, &fooVar
mov r1, 1
mov r0->foo::a, r1
mov r1, 0
mov r4, r0->foo::a
rcall r1, 1
stall
Func:
dout r0
rret
