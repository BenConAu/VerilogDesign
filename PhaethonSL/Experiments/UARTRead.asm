mov r0, 0
loopBegin_1:
mov r1, 1
cmplt r2, r0, r1
cmp r2, 0
je @loopEnd_1
mov r3, 1
readport r4, r3
mov r1, r4
mov r4, 255
cmpgt r3, r1, r4
cmp r3, 0
je @false_1
dout r1
false_1:
jmp @loopBegin_1
loopEnd_1:
stall
