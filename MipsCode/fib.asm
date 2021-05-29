li $v0, 5
syscall
add $t0, $v0, $zero #n
li $t2, 0x2000
li $t3, 1
sw $t3, ($t2) #a[0]
addi $t2, $t2, 4
li $t4, 1
sw $t4, ($t2) #a[1]
addi $t2, $t2, 4
li $t1, 2 #i
loop:
lw $t3, -8($t2) #a[i-2]
lw $t4, -4($t2) #a[i-1]
add $t4, $t3, $t4 #a[i]=a[i-1]+a[i-2]
sw $t4, ($t2)
addi $t2, $t2, 4
addi $t1, $t1, 1
ble $t1, $t0, loop
li $v0, 1
lw $a0, -4($t2)
syscall