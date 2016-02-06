struct foo
  a
  b
  c
ends

datasegment
  word val1 456
  word val2 789
  foo val3 1 2 3
enddata

mov r0, 123          // Test reg, const
dout r0
mov r1, r0           // Test reg, reg
dout r1
mov r2, &val3        // Test reg, constant
dout r2
mov r3, [r2]         // Test reg, deref reg
dout r3
mov r4, [0]          // Test reg, deref const
dout r4
mov r5, r2->foo::c   // Test reg, deref reg+const
dout r5
mov r6, val1         // Test reg, deref const with symbol
dout r6
mov val2, r0         // Test deref const, reg
mov r7, val2
dout r7
mov r2->foo::b, r0   // Test deref reg + const, reg
mov r8, r2->foo::b
dout r8
endlabel:
jmp @endlabel
