li $v0, 5
syscall
add $t0, $v0, $zero
li $v0, 5
syscall
add $t1, $v0, $zero
add $a0, $t0, $t1
li $v0, 1
syscall