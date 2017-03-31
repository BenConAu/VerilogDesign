mov r0, &fooVar
mov r1, &foo2Var
add r2, r0, 0
mov r3, r2
mov r4, 0
mov r2, 37
mov [r3:sizeof(Word)], r4, r2
add r3, r0, 0
mov r4, r3
mov r2, 0
mov r3, [r4:sizeof(Word)], r2
dout r3
mov r4, 1
mov r1->foo2::a, r4
add r4, r1, 4
mov r2, r4
mov r3, 0
mov r4, 2
mov [r2:sizeof(Word)], r3, r4
add r2, r1, 4
mov r3, r2
mov r4, 4
mov r2, 3
mov [r3:sizeof(Word)], r4, r2
mov r3, 4
mov r1->foo2::c, r3
mov r3, r1->foo2::a
dout r3
add r3, r1, 4
mov r4, r3
mov r2, 0
mov r3, [r4:sizeof(Word)], r2
dout r3
add r4, r1, 4
mov r2, r4
mov r3, 4
mov r4, [r2:sizeof(Word)], r3
dout r4
mov r2, r1->foo2::c
dout r2
exit
