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
mov r0, 10
loopBegin_2:
mov r2, 0
cmpgt r3, r0, r2
cmp r3, 0
je @loopEnd_2
dout r0
mov r2, 1
sub r1, r0, r2
mov r0, r1
jmp @loopBegin_2
loopEnd_2:
dout r0
stall
