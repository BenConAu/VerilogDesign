mov r0, &globalData
add r1, r0, 0
mov r64, r1
mov r1, 0
mov r2, 0
mov r3, &__datasegmentend
loopBegin_5:
mov r4, 1
cmplt r5, r1, r4
cmp r5, 0
je @loopEnd_5
mov r6, @ReadWord
rcall r6, 7
mov r4, r9
mov r9, r3
mov [r9:sizeof(Word)], r2, r4
mov r9, 1
add r7, r2, r9
mov r2, r7
mov r7, 2
cmpgt r9, r2, r7
jz r9, @false_4
mov r7, r3
mov r8, 0
mov r10, 322420463
mov r11, [r7:sizeof(Word)], r8
cmpe r12, r10, r11
jz r12, @false_3
mov r7, 2
sub r8, r2, r7
mov r7, r3
mov r10, 1
mov r11, [r7:sizeof(Word)], r10
cmpe r13, r8, r11
jz r13, @false_2
push r0
push r1
push r2
push r3
push r5
push r4
push r6
push r9
push r12
push r13
mov r8, 8
add r7, r3, r8
exec r7
pop r13
pop r12
pop r9
pop r6
pop r4
pop r5
pop r3
pop r2
pop r1
pop r0
mov r7, 0
dlen r7
mov r8, @WriteWord
mov r12, r7
rcall r8, 10
mov r10, 0
loopBegin_4:
cmplt r11, r10, r7
cmp r11, 0
je @loopEnd_4
din r14
mov r15, @WriteWord
mov r18, r14
rcall r15, 16
mov r16, 1
add r17, r10, r16
mov r10, r17
jmp @loopBegin_4
loopEnd_4:
mov r2, 0
false_2:
false_3:
false_4:
jmp @loopBegin_5
loopEnd_5:
stall
WriteWord:
mov r1, 0
loopBegin_3:
mov r2, 4
cmplt r3, r1, r2
cmp r3, 0
je @loopEnd_3
loopBegin_2:
mov r2, 2
readport r4, r2
mov r2, 1
cmpne r5, r4, r2
cmp r5, 0
je @loopEnd_2
jmp @loopBegin_2
loopEnd_2:
mov r5, 3
writeport r5, r0
mov r5, 8
shr r4, r0, r5
mov r0, r4
mov r4, 1
add r5, r1, r4
mov r1, r5
jmp @loopBegin_3
loopEnd_3:
rret
ReadWord:
mov r0, 0
mov r1, 0
mov r2, 0
loopBegin_1:
mov r3, 4
cmplt r4, r0, r3
cmp r4, 0
je @loopEnd_1
mov r5, 1
readport r6, r5
mov r3, r6
mov r6, 255
cmpgt r5, r3, r6
jz r5, @false_1
pack r1, r3, r0
mov r6, 1
add r7, r0, r6
mov r0, r7
false_1:
jmp @loopBegin_1
loopEnd_1:
mov r0, r1
rret
