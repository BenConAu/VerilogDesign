mov r0, 0
loopBegin_1:
mov r1, 10
cmplt r2, r0, r1
cmp r2, 0
je @loopEnd_1
mov r3, 2
readport r4, r3
mov r5, 1
cmpe r6, r4, r5
jz r6, @false_1
mov r7, 3
mov r8, 123
writeport r7, r8
dout r0
mov r9, 1
add r10, r0, r9
mov r0, r10
false_1:
jmp @loopBegin_1
loopEnd_1:
exit
