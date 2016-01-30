mov r0, f1.0
mov r1, f2.0
mov r2, f4.0
mov r3, f9.0
mov r4, f7.0
mov r5, f8.0
mov r6, f9.0
mov r7, f10.0
vfadd r0, r4
dout r0
dout r1
dout r2
dout r3
endlabel:
jmp @endlabel
