mov r0, &TestVar
mov r1, 1337
mov r0->TestStruct::Member, r1
mov r1, r0
mov r3, @Func
mov r6, r1
rcall r3, 4
mov r2, r6
mov r6, r2->TestStruct::Member
dout r6
exit
Func:
rret
