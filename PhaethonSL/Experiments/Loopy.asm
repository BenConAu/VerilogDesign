mov r0, 0
loopBegin_1:
mov r1, 10
cmplt r2, r0, r1
cmp r2, 0
je @loopEnd_1
mov r1, 1
add r3, r0, r1
mov r0, r3
dout r0
jmp @loopBegin_1
loopEnd_1:
stall
