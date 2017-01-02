mov r0, @MemoryInit
rcall r0, 1
mov r1, &__datasegmentend
dout r1
mov r2, @MemoryAlloc
mov r5, 100
rcall r2, 3
mov r1, r5
dout r1
mov r3, @MemoryAlloc
mov r6, 200
rcall r3, 4
mov r5, r6
dout r5
mov r4, @MemoryAlloc
mov r9, 1000
rcall r4, 7
mov r6, r9
dout r6
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
mov r4, r1->AllocationBlock::Count
mov r5, 1
add r3, r4, r5
mov r1->AllocationBlock::Count, r3
mov r0, r1->AllocationBlock::pLastStart
rret
MemoryFree:
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
