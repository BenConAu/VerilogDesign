mov r0, f1.0
mov r1, f2.0
fmax r2, r0, r1
dout r2
mov r0, f2.0
mov r1, f1.0
fmax r2, r0, r1
dout r2
endlabel:
jmp endlabel
