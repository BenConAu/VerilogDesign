mov r0, 10
loopBegin_1:
mov r1, 0
cmpne r2, r0, r1
cmp r2, 0
je @loopEnd_1
dout r0
mov r1, 1
sub r3, r0, r1
mov r0, r3
jmp @loopBegin_1
loopEnd_1:
dout r0
stall
