mov r0, 0
mov r1, 0
mov r2, 0
mov r3, 0
mov r4, &__datasegmentend
mov r5, r4
mov r6, 0
mov r7, 4022075394
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 1
mov r7, 2748
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 2
mov r7, 4025417775
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 3
mov r7, 4025478966
mov [r5:sizeof(Word)], r6, r7
mov r5, 1
dout r5
push r0
push r1
push r2
push r3
push r4
exec r4
pop r4
pop r3
pop r2
pop r1
pop r0
mov r5, 2
dout r5
stall