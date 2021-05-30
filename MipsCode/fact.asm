li $v0, 5
syscall
move $a0, $v0
jal fact
move $a0, $v0
li $v0, 1
syscall
li $v0, 10
syscall

fact:
sub $sp, $sp, 4
sw $ra, ($sp)
bgt $a0, 1, if
li $v0, 1
lw $ra, ($sp)
add $sp, $sp, 4
jr $ra
if:
sub $sp, $sp, 4
sw $a0, ($sp)
sub $a0, $a0, 1
jal fact
lw $a0, ($sp)
add $sp, $sp, 4
mul $v0, $a0, $v0
lw $ra, ($sp)
add $sp, $sp, 4
jr $ra