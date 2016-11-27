mov r1, &fooVar
mov r0, r1->foo::a
mov r2, r1->foo::b
dout r0
dout r2
TestFunction:
mov r1, &fooVar
mov r0, r1->foo::a
rret
