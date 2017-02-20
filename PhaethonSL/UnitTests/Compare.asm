mov r0, 1
mov r1, 2
mov r2, 3
mov r3, 4
cmplt r4, r0, r1
jz r4, @false_1
mov r5, 1
dout r5
jmp @true_1
false_1:
mov r5, 2
dout r5
true_1:
cmpgt r4, r0, r1
jz r4, @false_2
mov r5, 3
dout r5
jmp @true_2
false_2:
mov r5, 4
dout r5
true_2:
cmplt r4, r2, r3
jz r4, @false_3
mov r5, 5
dout r5
jmp @true_3
false_3:
mov r5, 6
dout r5
true_3:
cmpgt r4, r2, r3
jz r4, @false_4
mov r5, 7
dout r5
jmp @true_4
false_4:
mov r5, 8
dout r5
true_4:
exit
