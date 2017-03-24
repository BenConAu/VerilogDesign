mov r0, &pageTable
add r1, r0, 0
mov r2, r1
mov r3, 0
lea r1, [r2:sizeof(PTEntry)], r3
mov r2, 1073741824
mov r1->PTEntry::virtPage, r2
add r1, r0, 0
mov r2, r1
mov r3, 0
lea r1, [r2:sizeof(PTEntry)], r3
mov r2, 0
mov r1->PTEntry::physPage, r2
add r1, r0, 0
mov r2, r1
mov r3, 2
lea r1, [r2:sizeof(PTEntry)], r3
mov r2, 2
mov r1->PTEntry::virtPage, r2
add r1, r0, 0
mov r2, r1
mov r3, 2
lea r1, [r2:sizeof(PTEntry)], r3
mov r2, 15
mov r1->PTEntry::physPage, r2
mov r1, 61440
mov r2, r1
mov r3, 0
mov r4, 2748
mov [r2:sizeof(Word)], r3, r4
mov r2, r1
mov r3, 0
mov r4, [r2:sizeof(Word)], r3
dout r4
add r3, r0, 0
mov r2, r3
mov r68, r2
mov r69, r2
vpenable
mov r3, 8192
mov r5, r3
mov r6, 0
mov r4, [r5:sizeof(Word)], r6
dout r4
mov r5, r3
mov r6, 0
mov r7, 3567
mov [r5:sizeof(Word)], r6, r7
mov r5, r3
mov r6, 0
mov r4, [r5:sizeof(Word)], r6
dout r4
exit
