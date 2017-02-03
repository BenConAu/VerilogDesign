mov r0, 0
loopBegin_1:
mov r1, 10
cmplt r2, r0, r1
cmp r2, 0
je @loopEnd_1
mov r1, 2
readport r3, r1
mov r1, 1
cmpe r4, r3, r1
cmp r4, 0
je @false_1
mov r3, 3
mov r1, 123
writeport r3, r1
dout r0
mov r3, 1
add r1, r0, r3
mov r0, r1
false_1:
jmp @loopBegin_1
loopEnd_1:
stall
