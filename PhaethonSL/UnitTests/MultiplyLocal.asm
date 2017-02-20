mov r0, 1065353216
mov r1, 1073741824
mov r2, &fooVar
fmul r3, r0, r1
mov r2->foo::a, r3
mov r3, r2->foo::a
fmul r4, r3, r1
mov r2->foo::b, r4
mov r4, r2->foo::b
fmul r3, r1, r4
mov r2->foo::c, r3
mov r1, r2->foo::c
dout r1
exit
