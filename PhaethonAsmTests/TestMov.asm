datasegment 64
  word val1 456
  word val2 789
enddata

mov r0, 123     // Test reg, const
mov r1, &val1   // Test reg, addressof
mov r2, [r1]    // Test reg, regaddr
mov r3, [64]    // Test reg, constarr
dout r0
dout r1
dout r2
dout r3
endlabel:
jmp endlabel
