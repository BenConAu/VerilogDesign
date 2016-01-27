datasegment
  word     stack[8]
enddata

mov rsp, &stack
dout rsp
mov r0, 123
mov r1, @testfunc
call r1
dout r0
endlabel:
jmp @endlabel
testfunc:
dout r0
mov r0, 456
ret
