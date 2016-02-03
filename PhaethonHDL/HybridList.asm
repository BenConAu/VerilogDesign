struct ListNode
  word items[7]
  word next
ends

struct List
  word count
  word items[6]
  word next
 ends

 datasegment
   ListNode listNodePool[256]
   int listNodeIndex 0
   List listPool[64]
   int listPoolIndex 0
 enddata

 datasegment
   word     stack[16]
 enddata

datasegment
   word numTestItems 5
   word testItems 4
   word 7
   word 10
   word 12
   word 22
enddata

// Init stack
mov rsp, &stack

// Make a list
call @createList

// Now add items
mov r3, [&numTestItems]
mov r2, &testItems
addItemLoop:
mov r1, [r2]
call @appendToList
dec r3
cmp r3, 0
jne @addItemLoop

// Returns next list pointer in r0
// Stomps on r0..r1
createList:

// Allocate list
mov r0, &listPool
mov r1, [&listIndex]
muladd r0, r1, sizeof(List)

// Increment list index
inc r1
mov [&listIndex], r1

// Fill in data
mov [r0]->List::count, 0
mov [r0]->List::next, 0
ret

// Appends item in r1 to list at r0
appendToList:

// Check for room
mov r2, [r1]->List::count
cmp r2, 6
je @atlSmallList

// Loop until we find the end

atlSmallList:
mov


// Returns next list node in r0
// Stomps on r0..r1
createListNode:

// Allocate list node
mov r0, &listNodePool
mov r1, [&listNodeIndex]
muladd r0, r1, sizeof(List)

// Increment list index
inc r1
mov [&listNodeIndex], r1

// Fill in data
mov [r0]->ListNode::next, 0
ret
