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
mov r7, 4025478964
mov [r5:sizeof(Word)], r6, r7
exec r4
stall
