mov r0, &kernelPageTable
mov r1, &userPageTable
mov r2, &stack
add r4, r2, 0
mov r3, r4
mov r64, r3
mov r4, 61440
mov r5, r4
mov r6, 0
mov r7, 4009754626
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 1
mov r7, 4096
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 2
mov r7, 4009754881
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 3
mov r7, 4009755138
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 4
mov r7, 0
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 5
mov r7, 4009820930
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 6
mov r7, 1
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 7
mov r7, 50462985
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 8
mov r7, 4
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 9
mov r7, 4013162754
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 10
mov r7, 4660
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 11
mov r7, 4025418031
mov [r5:sizeof(Word)], r6, r7
mov r5, r4
mov r6, 12
mov r7, 4025478965
mov [r5:sizeof(Word)], r6, r7
mov r5, 1
dout r5
mov r5, 0
loopBegin_1:
mov r6, 4
cmplt r7, r5, r6
cmp r7, 0
je @loopEnd_1
add r8, r0, 0
mov r9, r8
lea r10, [r9:sizeof(PTEntry)], r5
mov r11, 1073741824
add r12, r11, r5
mov r10->PTEntry::virtPage, r12
add r13, r0, 0
mov r14, r13
lea r15, [r14:sizeof(PTEntry)], r5
mov r15->PTEntry::physPage, r5
mov r16, 1
add r17, r5, r16
mov r5, r17
jmp @loopBegin_1
loopEnd_1:
mov r5, 0
loopBegin_2:
mov r7, 4
cmplt r6, r5, r7
cmp r6, 0
je @loopEnd_2
add r8, r1, 0
mov r9, r8
lea r11, [r9:sizeof(PTEntry)], r5
mov r12, 1073741824
add r10, r12, r5
mov r11->PTEntry::virtPage, r10
add r13, r1, 0
mov r14, r13
lea r15, [r14:sizeof(PTEntry)], r5
mov r16, 0
mov r15->PTEntry::physPage, r16
mov r17, 1
add r18, r5, r17
mov r5, r18
jmp @loopBegin_2
loopEnd_2:
add r6, r1, 0
mov r7, r6
mov r8, 0
lea r6, [r7:sizeof(PTEntry)], r8
mov r7, 0
mov r6->PTEntry::virtPage, r7
add r6, r1, 0
mov r7, r6
mov r8, 0
lea r6, [r7:sizeof(PTEntry)], r8
mov r7, 15
mov r6->PTEntry::physPage, r7
mov r6, 2
dout r6
add r7, r0, 0
mov r6, r7
add r8, r1, 0
mov r7, r8
mov r68, r6
mov r69, r7
vpenable
mov r8, 22136
dout r8
mov r8, 16384
push r0
push r1
push r2
push r3
push r4
push r5
push r6
push r7
push r8
exec r8
pop r8
pop r7
pop r6
pop r5
pop r4
pop r3
pop r2
pop r1
pop r0
mov r9, 43981
dout r9
exit
