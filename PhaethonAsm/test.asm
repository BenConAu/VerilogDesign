struct Vector
  x
  y
  z
ends

datasegment 128
  Vector 3 6 9
  Vector f1.5 f2.57 f1.04
enddata

begin:
mov r0, 140
mov r1, [r0]->Vector::x
mov r2, [r0]->Vector::y
fmin r0, r1, r2 // Find min
dout r0
jmp begin       // Go do it all again
