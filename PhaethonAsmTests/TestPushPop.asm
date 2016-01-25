datasegment
  word     stack[8]
enddata

mov rsp, &stack
dout rsp
mov r0, 456
dout r0
push r0
mov r0, 789
dout r0
push r0
pop r1
dout r1
pop r1
dout r1
endlabel:
jmp endlabel
