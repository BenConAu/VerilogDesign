mov r0, 0
mov r1, @Func
mov r4, r0
rcall r1, 2
stall
Func:
dout r0
rret
