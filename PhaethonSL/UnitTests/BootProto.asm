mov r0, 0
mov r1, 0
mov r2, 0
mov r3, 0
mov r4, &__datasegmentend
mov r5, r4
mov r6, 0
mov r7, 4010016770
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 1
mov r7, 44
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 2
mov r7, 4022075650
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 3
mov r7, 2748
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 4
mov r7, 4009820168
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 5
mov r7, 0
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 6
mov r7, 4009754884
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 7
mov r7, 0
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 8
mov r7, 4025418031
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 9
mov r7, 4025478965
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
exit
