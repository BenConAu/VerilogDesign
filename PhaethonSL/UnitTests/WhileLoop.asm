mov r0, 10
loopBegin_1:
cmp r0, 0
je @loopEnd_1
dout r0
mov r1, 1
sub r2, r0, r1
mov r0, r2
jmp @loopBegin_1
loopEnd_1:
dout r0
stall
