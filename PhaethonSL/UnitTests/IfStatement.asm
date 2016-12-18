mov r0, 1
cmp r0, 0
je @false_1
mov r1, 1
dout r1
false_1:
mov r1, 1
cmp r1, 0
je @false_2
mov r2, 2
dout r2
jmp @true_2
false_2:
mov r2, 3
dout r2
true_2:
mov r2, 0
cmp r2, 0
je @false_3
mov r3, 2
dout r3
jmp @true_3
false_3:
mov r3, 3
dout r3
true_3:
stall
