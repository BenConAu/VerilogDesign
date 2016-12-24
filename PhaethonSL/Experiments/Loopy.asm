mov r0, 1
loopBegin_1:
mov r1, 1
cmp r1, 0
je @loopEnd_1
mov r2, 1
shl r3, r0, r2
mov r0, r3
mov r3, 0
cmpe r2, r0, r3
cmp r2, 0
je @false_1
mov r0, 1
false_1:
dout r0
jmp @loopBegin_1
loopEnd_1:
stall
