struct Vector
  x
  y
  z
ends

struct Triangle
  v0
  v1
  v2
 ends

datasegment
  word     vcount 4
  Vector   v0     f0. f0. f0.
  Vector          f0. f1. f0.
  Vector          f2. f1. f0.
  Vector          f0. f1. f3.
  word     tcount 4
  Triangle t0     0 1 2
  Triangle t1     0 2 3
  Triangle t2     0 3 1
  Triangle t3     1 2 3
enddata

datasegment
  word     stack[64]
enddata

// Init stack
mov rsp, &stack
begin:
// First find extent of first box
mov r0, &vcount
mov r1, [r0]
mov r0, &v0
mov r2, [r0]->Vector::x  // r2-4 have min
mov r3, [r0]->Vector::y
mov r4, [r0]->Vector::z
mov r5, r2               // r5-7 have max
mov r6, r3
mov r7, r4
add r0, sizeof(Vector)
dec r1
extentloop:
mov r8, [r0]->Vector::x  // Get the coordinates
mov r9, [r0]->Vector::y
mov r10, [r0]->Vector::z
fmin r2, r8
fmin r3, r9
fmin r4, r10
fmax r5, r8
fmax r6, r9
fmax r7, r10
add r0, sizeof(Vector)
dec r1
cmp r1, 0
jne extentloop
dout r2
dout r3
dout r4
dout r5
dout r6
dout r7
jmp begin       // Go do it all again
