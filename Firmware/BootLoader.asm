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
je @false_2
pack r3, r5, r2
mov r8, 1
add r9, r2, r8
mov r2, r9
mov r9, 4
cmpe r8, r2, r9
cmp r8, 0
je @false_1
mov r2, 0
mov r9, 1
add r10, r3, r9
mov r3, r10
false_1:
false_2:
jmp @loopBegin_1
loopEnd_1:
stall
