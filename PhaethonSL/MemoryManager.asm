mov r1, @MemoryAlloc
mov r4, 100
rcall r1, 2
mov r0, r4
stall
MemoryAlloc:
mov r2, &header
mov r1, r2->AllocationHeader::next
mov r1->Allocation::length, r0
mov r3, 0
mov r1->Allocation::next, r3
mov r3, r2->AllocationHeader::next
mov r4, 12
add r5, r3, r4
mov r1->Allocation::value, r5
mov r5, r2->AllocationHeader::last
mov r5->Allocation::next, r1
mov r5, 12
add r3, r5, r0
mov r5, r2->AllocationHeader::next
add r4, r5, r3
mov r2->AllocationHeader::next, r4
rret
MemoryFree:
rret
MemoryInit:
mov r0, &firstAlloc
mov r1, 0
mov r0->Allocation::value, r1
mov r1, 0
mov r0->Allocation::length, r1
mov r1, 0
mov r0->Allocation::next, r1
mov r1, &header
mov r1->AllocationHeader::first, r0
mov r1->AllocationHeader::last, r0
mov r1->AllocationHeader::next, r2
rret
