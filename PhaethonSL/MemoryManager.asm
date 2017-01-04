mov r0, @MemoryInit
rcall r0, 1
mov r1, &__datasegmentend
dout r1
mov r2, @MemoryAlloc
mov r5, 100
rcall r2, 3
mov r1, r5
dout r1
mov r5, @DumpHeap
rcall r5, 3
mov r4, @MemoryAlloc
mov r8, 200
rcall r4, 6
mov r3, r8
dout r3
mov r8, @DumpHeap
rcall r8, 6
mov r7, @MemoryAlloc
mov r11, 1000
rcall r7, 9
mov r6, r11
dout r6
mov r11, @DumpHeap
rcall r11, 9
stall
MemoryAlloc:
mov r2, &Header
mov r1, r2->AllocationHeader::First
mov r3, r1->AllocationBlock::Available
cmplt r4, r3, r0
cmp r4, 0
je @false_1
mov r0, 0
rret
false_1:
neg r4, r0
mov r3, r1->AllocationBlock::pLastStart
add r5, r3, r4
mov r1->AllocationBlock::pLastStart, r5
mov r5, r1->AllocationBlock::Available
sub r4, r5, r0
mov r1->AllocationBlock::Available, r4
add r4, r1, 16
mov r5, r4
mov r3, r1->AllocationBlock::Count
mov [r5:sizeof(Word)], r3, r0
mov r5, r1->AllocationBlock::Count
mov r3, 1
add r4, r5, r3
mov r1->AllocationBlock::Count, r4
mov r0, r1->AllocationBlock::pLastStart
rret
MemoryFree:
rret
DumpHeap:
mov r1, &Header
mov r0, r1->AllocationHeader::First
mov r2, 0
loopBegin_1:
mov r3, r0->AllocationBlock::Count
cmplt r4, r2, r3
cmp r4, 0
je @loopEnd_1
add r3, r0, 16
mov r5, r3
mov r3, [r5:sizeof(Word)], r2
dout r3
mov r5, 1
add r3, r2, r5
mov r2, r3
jmp @loopBegin_1
loopEnd_1:
rret
MemoryInit:
mov r0, &Header
mov r1, &__datasegmentend
mov r0->AllocationHeader::First, r1
mov r1, r0->AllocationHeader::First
mov r2, 0
mov r1->AllocationBlock::Next, r2
mov r1, r0->AllocationHeader::First
mov r2, 512
mov r3, 20
sub r4, r2, r3
mov r2, 4
add r3, r4, r2
mov r1->AllocationBlock::Available, r3
mov r1, r0->AllocationHeader::First
mov r3, 0
mov r1->AllocationBlock::Count, r3
mov r1, r0->AllocationHeader::First
mov r3, &__datasegmentend
mov r4, 512
add r2, r3, r4
mov r1->AllocationBlock::pLastStart, r2
mov r1, &__datasegmentend
mov r2, 512
add r3, r1, r2
mov r0->AllocationHeader::NextBlockAddr, r3
rret
