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
  Triangle        0 2 3
  Triangle        0 3 1
  Triangle        1 2 3
enddata

datasegment
  word     stack[16]
enddata

// Init stack
mov rsp, &stack
begin:
// First find extent of first box
mov r0, @calcExtent
call r0
dout r2
dout r3
dout r4
dout r5
dout r6
dout r7
jmp @begin       // Go do it all again
// Function to calculate extent of mesh
// Stomps on r0..r10
// Returns extent in r2..r7
calcExtent:
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
jne @extentloop
ret
// Function to average points of triangle
// Takes array of points address in r0
// Returns average in r0..r2
// Stomps up to r11
calcCentroid:
mov r5, r0                     // Save the points address
mov r0, 0                      // Setup sum
mov r1, 0
mov r2, 0
mov r3, 0
mov r4, 3                      // Setup counter
calcCentroidLoop:
mov r6, [r5]                   // Load index
mov r7, &v0                    // Load base vertex
muladd r7, r6, sizeof(Vector)  // Offset to index
mov r8, [r7]->Vector::x        // Load vertex
mov r9, [r7]->Vector::y
mov r10, [r7]->Vector::z
mov r11, 0
vfadd r0, r8                   // Add to sum
add r5, 4                      // Move along point list
dec r4
dout r4
cmp r4, 0
jne @calcCentroidLoop
ret
