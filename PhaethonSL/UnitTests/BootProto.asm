mov r0, &kernelPageTable
mov r1, &userPageTable
add r2, r0, 0
mov r3, r2
mov r4, 0
lea r2, [r3:sizeof(PTEntry)], r4
mov r3, 0
mov r2->PTEntry::virtPage, r3
add r2, r0, 0
mov r3, r2
mov r4, 0
lea r2, [r3:sizeof(PTEntry)], r4
mov r3, 0
mov r2->PTEntry::physPage, r3
add r2, r1, 0
mov r3, r2
mov r4, 0
lea r2, [r3:sizeof(PTEntry)], r4
mov r3, 0
mov r2->PTEntry::virtPage, r3
add r2, r1, 0
mov r3, r2
mov r4, 0
lea r2, [r3:sizeof(PTEntry)], r4
mov r3, 1
mov r2->PTEntry::physPage, r3
mov r2, 4096
mov r3, r2
mov r4, 0
mov r5, 4010016770
mov [r3:sizeof(Word)], r4, r5
mov r3, r2
mov r4, 1
mov r5, 44
mov [r3:sizeof(Word)], r4, r5
mov r3, r2
mov r4, 2
mov r5, 4022075650
mov [r3:sizeof(Word)], r4, r5
mov r3, r2
mov r4, 3
mov r5, 2748
mov [r3:sizeof(Word)], r4, r5
mov r3, r2
mov r4, 4
mov r5, 4009820168
mov [r3:sizeof(Word)], r4, r5
mov r3, r2
mov r4, 5
mov r5, 0
mov [r3:sizeof(Word)], r4, r5
mov r3, r2
mov r4, 6
mov r5, 4009754884
mov [r3:sizeof(Word)], r4, r5
mov r3, r2
mov r4, 7
mov r5, 0
mov [r3:sizeof(Word)], r4, r5
mov r3, r2
mov r4, 8
mov r5, 4025418031
mov [r3:sizeof(Word)], r4, r5
mov r3, r2
mov r4, 9
mov r5, 4025478965
mov [r3:sizeof(Word)], r4, r5
add r4, r0, 0
mov r3, r4
add r5, r1, 0
mov r4, r5
mov r68, r3
mov r69, r4
vpenable
mov r5, 1
dout r5
push r0
push r1
push r2
push r3
push r4
exec r2
pop r4
pop r3
pop r2
pop r1
pop r0
mov r5, 2
dout r5
exit
