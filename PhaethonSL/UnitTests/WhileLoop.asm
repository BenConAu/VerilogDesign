mov r0, 10
loopBegin_1:
mov r1, 0
cmpne r2, r0, r1
cmp r2, 0
je @loopEnd_1
dout r0
mov r3, 1
sub r4, r0, r3
mov r0, r4
jmp @loopBegin_1
loopEnd_1:
mov r0, 10
loopBegin_2:
mov r2, 0
cmpgt r1, r0, r2
cmp r1, 0
je @loopEnd_2
dout r0
mov r3, 1
sub r4, r0, r3
mov r0, r4
jmp @loopBegin_2
loopEnd_2:
dout r0
exit
