struct Allocation
  word start
  word size
  word next
ends

struct HeapDescriptor
  word firstAllocation
  word lastAllocation
  word nextAllocation
ends

 datasegment
  HeapDescriptor desc 0 0 0
  word heap[256]
 enddata

mov r0, &desc
dout r0                                      // Write out location of data segment
mov r0, @memAlloc
mov r3, 100
rcall r0, 1                                  // Allocate 100 bytes
mov r3, 200
rcall r0, 1                                  // Allocate 200 bytes
mov r0, @memHeapWalk
rcall r0, 1                                  // Walk the heap
endLoop:
jmp @endLoop

memAlloc:
mov r1, &desc
mov r2, r1->HeapDescriptor::firstAllocation
cmp r2, 0
jne @memAllocNotFirst                        // If there is an allocation
mov r3, &heap
mov r1->HeapDescriptor::firstAllocation, r3  // First allocation is beginning of heap
mov r1->HeapDescriptor::lastAllocation, r3   // Last allocation is the same now
jmp @memAllocFillAllocation
memAllocNotFirst:
mov r2, r1->HeapDescriptor::lastAllocation
mov r3, r1->HeapDescriptor::nextAllocation
mov r2->Allocation::next, r3                 // Chain to next allocation
memAllocFillAllocation:
mov r1->HeapDescriptor::lastAllocation, r3   // Store location of last allocation
mov r4, r3                                   // r3 has next allocation from both paths
add r4, sizeof(Allocation)
mov r3->Allocation::start, r4                // Location of actual memory we will return
mov r5, r4                                   // Save location to return
add r4, r0                                   // Allocation size
mov r1->HeapDescriptor::nextAllocation, r4   // Location of next allocation
mov r3->Allocation::size, r0                 // Size of memory
mov r4, 0
mov r3->Allocation::next, r4                 // Next allocation is not there yet
mov r0, r5                                   // Ready to return
rret

memHeapWalk:
mov r1, 4660
dout r1
mov r1, &desc
mov r2, r1->HeapDescriptor::firstAllocation
memHeapWalkLoop:
cmp r2, 0
je @memHeapWalkDone
mov r3, r2->Allocation::start
dout r3
mov r3, r2->Allocation::size
dout r3
mov r2, r2->Allocation::next
jmp @memHeapWalkLoop
memHeapWalkDone:
mov r1, 22136
rret
