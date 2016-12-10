mov r0, &fooVar
mov r1, 1
mov r0->foo::a, r1
stall
Func:
dout r0
rret
