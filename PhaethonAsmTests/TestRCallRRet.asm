mov r1, 128          // Something to save away (r2 and r3 used as stack)
mov r4, 256          // Something to pass to the first function
dout r1
dout r4
mov r0, @testfunc1
rcall r0, 2          // Save r0 and r1 away, store in r2 and r3, r4 becomes r0
dout r1              // Should still be 128
endlabel:
jmp @endlabel

testfunc1:
dout r0              // Print out the first argument
mov r1, @testfunc2   // Another function to call
mov r2, 512          // Another thing to save away (r3 and r4 used as stack)
mov r5, 1024         // Argument for another function
mov r6, 2048         // Second argument
rcall r1, 3          // Save up to r2
dout r2              // Should still be 512
rret

testfunc2:
dout r0              // Print first arg
dout r1              // Print second arg
rret
