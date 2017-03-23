mov r0, 61440
mov r1, r0
mov r2, 0
mov r3, 4009754626
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 1
mov r3, 4096
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 2
mov r3, 4009754881
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 3
mov r3, 4009755138
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 4
mov r3, 0
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 5
mov r3, 4009820930
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 6
mov r3, 1
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 7
mov r3, 50462985
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 8
mov r3, 4
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 9
mov r3, 4013162754
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 10
mov r3, 4660
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 11
mov r3, 4025418031
mov [r1:sizeof(Word)], r2, r3
mov r1, r0
mov r2, 12
mov r3, 4025478965
mov [r1:sizeof(Word)], r2, r3
mov r1, 1
dout r1
mov r1, 0
loopBegin_1:
mov r2, 4
cmplt r3, r1, r2
cmp r3, 0
je @loopEnd_1
mov r4, &pageTable
add r5, r4, 0
mov r6, r5
lea r7, [r6:sizeof(PTEntry)], r1
mov r8, 1073741824
add r9, r8, r1
mov r7->PTEntry::virtPage, r9
add r10, r4, 0
mov r11, r10
lea r12, [r11:sizeof(PTEntry)], r1
mov r12->PTEntry::physPage, r1
mov r13, 1
add r14, r1, r13
mov r1, r14
jmp @loopBegin_1
loopEnd_1:
mov r3, 2
dout r3
add r3, r4, 0
mov r2, r3
mov r5, 2
lea r3, [r2:sizeof(PTEntry)], r5
mov r2, 2
mov r3->PTEntry::virtPage, r2
add r3, r4, 0
mov r2, r3
mov r5, 2
lea r3, [r2:sizeof(PTEntry)], r5
mov r2, 15
mov r3->PTEntry::physPage, r2
add r2, r4, 0
mov r3, r2
mov r68, r3
vpenable
mov r2, 22136
dout r2
mov r2, 8192
push r0
push r1
push r4
push r3
push r2
exec r2
pop r2
pop r3
pop r4
pop r1
pop r0
mov r5, 43981
dout r5
exit
