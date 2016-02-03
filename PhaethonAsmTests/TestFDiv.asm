mov r0, f10.0
dout r0
mov r1, f5.0
dout r1
fdiv r0, r1
dout r0
endlabel:
jmp @endlabel
