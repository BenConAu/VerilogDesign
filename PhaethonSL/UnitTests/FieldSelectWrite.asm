mov r0, &fooVar
mov r1, 1
mov r0->foo::a, r1
mov r1, 2
mov r0->foo::b, r1
mov r1, r0->foo::a
dout r1
mov r1, r0->foo::b
dout r1
exit
TestFunction:
mov r1, &fooVar
mov r1->foo::b, r0
rret
