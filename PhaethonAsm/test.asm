begin:
mov r0, 3      // Load some numbers
mov r1, 5
mov r2, 7
fconv r0       // Convert to float
fconv r1
fconv r2
fmuladd r0, r1, r2
mov [64], r0   // Put result into location 64
mov r0, 0      // Clear out register
mov r0, [64]   // Put result back into register from 64
jmp begin      // Go do it all again
