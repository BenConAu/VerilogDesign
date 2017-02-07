mov r0, 0
mov r1, 0
mov r2, 0
mov r3, 0
mov r4, &__datasegmentend
loopBegin_1:
mov r5, 1
cmplt r6, r0, r5
cmp r6, 0
je @loopEnd_1
mov r7, 1
readport r8, r7
mov r5, r8
mov r8, 255
cmpgt r7, r5, r8
cmp r7, 0
je @false_5
pack r3, r5, r2
mov r8, 1
add r9, r2, r8
mov r2, r9
mov r9, 4
cmpe r8, r2, r9
cmp r8, 0
je @false_4
mov r2, 0
mov r9, 1
add r10, r3, r9
mov r3, r10
mov r10, 2
cmpgt r9, r3, r10
cmp r9, 0
je @false_3
mov r10, r4
mov r11, 0
mov r12, 322420463
mov r13, [r10:sizeof(Word)], r11
cmpe r14, r12, r13
cmp r14, 0
je @false_2
mov r10, 2
add r11, r3, r10
mov r10, r4
mov r12, 1
mov r13, [r10:sizeof(Word)], r12
cmpe r15, r11, r13
cmp r15, 0
je @false_1
exec r4
mov r3, 0
false_1:
false_2:
false_3:
false_4:
false_5:
jmp @loopBegin_1
loopEnd_1:
stall
