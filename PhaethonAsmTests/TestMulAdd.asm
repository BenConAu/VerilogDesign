struct TestStruct
  word first
  word second
ends

datasegment
  TestStruct ts 1 2
  TestStruct 3 4
  TestStruct 5 6
  word       w 7
enddata

mov r0, &ts
mov r1, 0
muladd r0, r1, sizeof(TestStruct)
mov r1, [r0]
dout r0
dout r1
mov r0, &ts
mov r1, 2
muladd r0, r1, sizeof(TestStruct)
mov r1, [r0]
dout r0
dout r1
endlabel:
jmp @endlabel
