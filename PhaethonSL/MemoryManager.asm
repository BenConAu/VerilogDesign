stall
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
MemoryAlloc:
mov r2, &header
mov r1, r2->AllocationHeader::next
mov r1->Allocation::length, r0
mov r3, 0
mov r1->Allocation::next, r3
mov r3, r2->AllocationHeader::next
mov r4, 12
mov r5, r3
fadd r5, r4
mov r1->Allocation::value, r5
mov r5, r2->AllocationHeader::last
mov r5->Allocation::next, r1
mov r5, r2->AllocationHeader::next
mov r3, 12
mov r4, r5
fadd r4, r3
mov r5, r4
fadd r5, r0
mov r2->AllocationHeader::next, r5
rret
MemoryFree:
rret
