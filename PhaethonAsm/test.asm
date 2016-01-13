begin:
mov r1, 3       // Load some numbers
mov r2, 5
fconv r1        // Convert to float
fconv r2
fmin r0, r2, r1 // Find min
jmp begin       // Go do it all again
