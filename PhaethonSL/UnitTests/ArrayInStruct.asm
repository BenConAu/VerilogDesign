mov r0, &global
add r1, r0, 0
mov r2, r1
mov r3, 0
lea r1, [r2:sizeof(foo)], r3
mov r2, 171
mov r1->foo::a, r2
add r1, r0, 0
mov r2, r1
mov r3, 5
lea r1, [r2:sizeof(foo)], r3
mov r2, 205
mov r1->foo::a, r2
add r1, r0, 0
mov r2, r1
mov r3, 0
lea r1, [r2:sizeof(foo)], r3
mov r2, r1->foo::a
dout r2
add r1, r0, 0
mov r2, r1
mov r3, 5
lea r1, [r2:sizeof(foo)], r3
mov r2, r1->foo::a
dout r2
exit
