mov r0, 21    // Load 21 to r0
mov r1, 35    // Load 35 to r1
fconv r0      // Convert r0 to float
fconv r1      // Convert r1 to float
fadd r0, r1   // Add r1 to r0
mov [64], r0   // Put result into location 64
mov r0, 0      // Clear out register
mov r0, [64]   // Put result back into register from 64
