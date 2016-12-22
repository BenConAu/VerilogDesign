mov r0, @MemoryInit
rcall r0, 1
mov r1, &__datasegmentend
dout r1
mov r2, @MemoryAlloc
mov r5, 100
rcall r2, 3
mov r1, r5
dout r1
stall
MemoryAlloc:
mov r2, &header
mov r1, r2->AllocationHeader::first
loopBegin_1:
mov r3, r1->Allocation::next
mov r4, 0
cmpne r5, r3, r4
cmp r5, 0
je @loopEnd_1
mov r1, r1->Allocation::next
jmp @loopBegin_1
loopEnd_1:
mov r3, 8
mov r4, r1->Allocation::length
add r6, r3, r4
add r3, r1, r6
mov r5, r3
mov r6, 8
add r4, r5, r6
mov r3, r4
mov r4, r5
mov r6, 0
mov r4->Allocation::next, r6
mov r4->Allocation::length, r0
mov r1->Allocation::next, r4
mov r0, r3
rret
MemoryFree:
rret
MemoryInit:
mov r0, &header
mov r1, &__datasegmentend
mov r0->AllocationHeader::first, r1
mov r1, r0->AllocationHeader::first
mov r2, 0
mov r1->Allocation::next, r2
mov r1, r0->AllocationHeader::first
mov r2, 0
mov r1->Allocation::length, r2
rret
