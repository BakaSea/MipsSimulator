#read integer
li $v0, 5
syscall
#print integer
move $a0, $v0
li $v0, 1
syscall
li $v0, 11
li $a0, 10
syscall
#read character
li $v0, 12
syscall
#print character
move $a0, $v0
li $v0, 11
syscall
li $v0, 11
li $a0, 10
syscall
#read string
li $v0, 8
li $a0, 0x2000
li $a1, 256
syscall
#print string
li $v0, 4
li $a0, 0x2000
syscall
li $v0, 11
li $a0, 10
syscall