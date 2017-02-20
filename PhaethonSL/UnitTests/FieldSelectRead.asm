mov r0, &fooVar
mov r1, 1
mov r0->foo::a, r1
mov r1, 2
mov r0->foo::b, r1
mov r1, r0->foo::a
mov r2, r0->foo::b
dout r1
dout r2
exit
TestFunction:
mov r1, &fooVar
mov r0, r1->foo::a
rret
