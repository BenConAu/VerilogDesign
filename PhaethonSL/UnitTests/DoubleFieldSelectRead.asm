mov r0, &fooVar
mov r1, 1
mov r0->foo::value, r1
mov r1, &other
mov r0->foo::next, r1
mov r1, r0->foo::next
mov r2, 2
mov r1->foo::value, r2
mov r1, r0->foo::next
mov r2, 0
mov r1->foo::next, r2
stall
