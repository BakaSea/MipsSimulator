.data
str: .ascii "Helloworld"

.text
li $v0, 4
la $a0, str
syscall