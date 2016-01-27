mov r0, f1.0
mov r1, f2.0
fmax r0, r1
dout r0
mov r0, f2.0
mov r1, f1.0
fmax r0, r1
dout r0
endlabel:
jmp @endlabel
