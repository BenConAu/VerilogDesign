mov r0, 0
loopBegin_1:
mov r1, 40
cmplt r2, r0, r1
cmp r2, 0
je @loopEnd_1
dout r0
mov r1, 1
add r3, r0, r1
mov r0, r3
jmp @loopBegin_1
loopEnd_1:
dlen r2
dout r2
mov r0, 0
loopBegin_2:
mov r3, 32
cmplt r1, r0, r3
cmp r1, 0
je @loopEnd_2
din r3
mov r4, 1
add r5, r0, r4
mov r0, r5
jmp @loopBegin_2
loopEnd_2:
dlen r2
dout r2
exit
