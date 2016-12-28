mov r0, &fooVar
add r1, r0, 0
mov r2, r1
mov r3, 0
mov r1, 37
mov r2[], r3, r1
add r2, r0, 0
mov r3, r2
mov r1, 0
mov r2, r3[], r1
dout r2
mov r3, &foo2Var
mov r1, 1
mov r3->foo2::a, r1
add r1, r3, 4
mov r2, r1
mov r4, 0
mov r1, 2
mov r2[], r4, r1
mov r2, r3->foo2::a
dout r2
add r2, r3, 4
mov r4, r2
mov r1, 0
mov r2, r4[], r1
dout r2
stall
