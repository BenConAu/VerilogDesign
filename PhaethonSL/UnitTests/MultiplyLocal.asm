mov r0, &fooVar
mov r1, 1065353216
mov r2, 1073741824
fmul r3, r1, r2
mov r0->foo::a, r3
mov r3, r0->foo::a
fmul r4, r3, r2
mov r0->foo::b, r4
mov r4, r0->foo::b
fmul r3, r2, r4
mov r0->foo::c, r3
mov r2, r0->foo::c
dout r2
exit
