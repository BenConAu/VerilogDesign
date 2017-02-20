mov r0, @MemoryInit
rcall r0, 1
mov r1, &header
mov r2, r1->AllocationHeader::first
dout r2
mov r2, r1->AllocationHeader::first
mov r3, r2->Allocation::next
dout r3
mov r2, r1->AllocationHeader::first
mov r3, r2->Allocation::length
dout r3
exit
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
