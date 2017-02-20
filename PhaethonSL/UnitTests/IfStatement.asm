mov r0, 1
jz r0, @false_1
mov r1, 1
dout r1
false_1:
mov r1, 1
jz r1, @false_2
mov r2, 2
dout r2
jmp @true_2
false_2:
mov r2, 3
dout r2
true_2:
mov r2, 0
jz r2, @false_3
mov r3, 2
dout r3
jmp @true_3
false_3:
mov r3, 3
dout r3
true_3:
exit
