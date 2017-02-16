mov r0, &fooVar
add r1, r0, 0
mov r2, r1
mov r3, 0
mov r1, 37
mov [r2:sizeof(Word)], r3, r1
add r3, r0, 0
mov r2, r3
mov r1, 0
mov r3, [r2:sizeof(Word)], r1
dout r3
mov r1, &foo2Var
mov r2, 1
mov r1->foo2::a, r2
mov r2, r1->foo2::a
dout r2
stall
