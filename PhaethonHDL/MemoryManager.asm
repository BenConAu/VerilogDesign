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

mov r0, @memAlloc
mov r3, 100
rcall r0, 1
dout r3
endLoop:
jmp @endLoop

memAlloc:
mov r1, &desc
mov r2, r1->HeapDescriptor::firstAllocation
cmp r2, 0
jne @memAllocNotFirst                        // If there is an allocation
mov r3, &desc
mov r4, &heap
mov r3->HeapDescriptor::firstAllocation, r4  // First allocation is beginning of heap
mov r3->HeapDescriptor::lastAllocation, r4   // Last allocation is the same now
mov r5, r4
add r5, sizeof(Allocation)
mov r4->Allocation::start, r5                // Location of actual memory
mov r6, r5                                   // Save location to return
add r5, r0                                   // Allocation size
mov r3->HeapDescriptor::nextAllocation, r5   // Location of next allocation
mov r4->Allocation::size, r0                 // Size of memory
mov r5, 0
mov r4->Allocation::next, r5                 // Next allocation is not there yet
mov r0, r6                                   // Ready to return
jmp @memAllocComplete
memAllocNotFirst:
memAllocComplete:
rret
