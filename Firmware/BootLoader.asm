mov r0, &globalData
add r1, r0, 0
mov r64, r1
mov r1, 0
mov r2, 0
mov r3, 0
mov r4, 0
mov r5, &__datasegmentend
loopBegin_1:
mov r6, 1
cmplt r7, r1, r6
cmp r7, 0
je @loopEnd_1
mov r8, 1
readport r9, r8
mov r6, r9
mov r9, 255
cmpgt r8, r6, r9
jz r8, @false_5
pack r4, r6, r2
mov r9, 1
add r10, r2, r9
mov r2, r10
mov r10, 4
cmpe r9, r2, r10
jz r9, @false_4
dout r4
mov r10, r5
mov [r10:sizeof(Word)], r3, r4
mov r2, 0
mov r10, 1
add r11, r3, r10
mov r3, r11
mov r11, 2
cmpgt r10, r3, r11
jz r10, @false_3
mov r11, r5
mov r12, 0
mov r13, 322420463
mov r14, [r11:sizeof(Word)], r12
cmpe r15, r13, r14
jz r15, @false_2
mov r11, 2
sub r12, r3, r11
mov r11, r5
mov r13, 1
mov r14, [r11:sizeof(Word)], r13
cmpe r16, r12, r14
jz r16, @false_1
push r0
push r1
push r2
push r3
push r4
push r5
push r7
push r6
push r8
push r9
push r10
push r15
push r16
mov r12, 251711968
dout r12
mov r12, 8
add r11, r5, r12
exec r11
pop r16
pop r15
pop r10
pop r9
pop r8
pop r6
pop r7
pop r5
pop r4
pop r3
pop r2
pop r1
pop r0
mov r3, 0
false_1:
false_2:
false_3:
false_4:
false_5:
jmp @loopBegin_1
loopEnd_1:
stall
