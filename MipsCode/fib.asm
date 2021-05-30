li $v0, 5
syscall
add $t0, $v0, $zero #n
li $t2, 0x2000
li $t3, 1
sw $t3, ($t2) #a[0]
li $t4, 1
sw $t4, 4($t2) #a[1]
li $t1, 2 #i
loop:
sub $t5, $t1, 2
mul $t5, $t5, 4
add $t5, $t2, $t5
lw $t3, ($t5) #a[i-2]
sub $t5, $t1, 1
mul $t5, $t5, 4
add $t5, $t2, $t5
lw $t4, ($t5) #a[i-1]
add $t4, $t3, $t4 #a[i]=a[i-1]+a[i-2]
mul $t5, $t1, 4
add $t5, $t2, $t5
sw $t4, ($t5)
addi $t1, $t1, 1
ble $t1, $t0, loop
li $v0, 1
mul $t5, $t0, 4
add $t5, $t2, $t5
lw $a0, ($t5)
syscall