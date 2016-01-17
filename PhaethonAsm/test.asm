struct Vector
  x
  y
ends

begin:
mov r0, 128
mov r1, 3
fconv r1
mov [r0]->Vector::x, r1
mov r1, 5
fconv r1
mov [r0]->Vector::y, r1
mov r1, [r0]->Vector::x
mov r2, [r0]->Vector::y
fmin r0, r1, r2 // Find min
jmp begin       // Go do it all again
