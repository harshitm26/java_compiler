	.text
	.globl main
main:
move $fp, $sp
subu $sp, $fp, 4
BubbleSortmain:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
li $t0, 1
lw $t1, -8($fp)
multu $t0, $t1
mflo $t0
li $t1, 4
multu $t0, $t1
mflo $t0
move $a0, $t0
li $v0, 9
syscall
subu $sp, $sp, 4
sw $v0, ($sp)
subu $sp, $sp, 4 #VariableDeclarator a
lw $t0, -12($fp)
sw $t0, -16($fp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator i
lw $t0, -20($fp)
sw $t0, -24($fp)
LAB0loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -24($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -28($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB1true
li $t2, 0
j LAB1next
LAB1true:
li $t2, 1
LAB1next:
sw $t2, 0($sp)
lw $t0, -32($fp)
li $t1, 1
bne $t0, $t1, LAB0next
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -24($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -16($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
lw $t0, -24($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -24($fp) #fetchint0 start
mult $t1, $t0
mflo $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
lw $s0, -36($fp) #Assignment
subu $s1, $fp, 40
lw $t0, 0($s1)
sw $t0, 0($s0)
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -24($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -16($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
lw $t7, -44($fp) #fetchint0 start
lw $t0, 0($t7)
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB2:	.asciiz " "
	.text
subu $sp, $sp, 4
la $t0, LAB2
sw $t0, 0($sp)
lw $a0, -48($fp)
li $v0, 4
syscall
lw $s0, -24($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -24($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 28
j LAB0loop
LAB0next:
subu $sp, $sp, 20 #WHILE end
	.data #STRINGLITERAL
LAB3:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB3
sw $t0, 0($sp)
lw $a0, -56($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator j
lw $t0, -60($fp)
sw $t0, -64($fp)
subu $sp, $sp, 4 #VariableDeclarator temp
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $s0, $fp, 24  #Assignment
subu $s1, $fp, 72
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB4loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -24($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -76($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB5true
li $t2, 0
j LAB5next
LAB5true:
li $t2, 1
LAB5next:
sw $t2, 0($sp)
lw $t0, -80($fp)
li $t1, 1
bne $t0, $t1, LAB4next
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 1
sw $t0, 0($sp)
lw $t0, -24($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -84($fp) #fetchint0 start
add $t0, $t1, $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
subu $s0, $fp, 64  #Assignment
subu $s1, $fp, 88
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB6loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -64($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -92($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB7true
li $t2, 0
j LAB7next
LAB7true:
li $t2, 1
LAB7next:
sw $t2, 0($sp)
lw $t0, -96($fp)
li $t1, 1
bne $t0, $t1, LAB6next
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -24($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -16($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -64($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -16($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
lw $t7, -100($fp) #fetchint0 start
lw $t0, 0($t7)
move $t1, $t0 #RelationalExpression
lw $t7, -104($fp) #fetchint0 start
lw $t0, 0($t7)
subu $sp, $sp, 4
blt $t1, $t0, LAB8true
li $t2, 0
j LAB8next
LAB8true:
li $t2, 1
LAB8next:
sw $t2, 0($sp)
subu $sp, $sp, 8  #IF-THEN-ELSE start
sw $s7, ($sp)
sw $sp, 4($sp)
move $s7, $sp
lw $t0, -108($fp)
li $t1, 1
bne $t0, $t1, LAB9false
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -24($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -16($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
subu $s0, $fp, 68  #Assignment
lw $s1, -120($fp)
lw $t0, 0($s1)
sw $t0, 0($s0)
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -24($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -16($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -64($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -16($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
lw $s0, -124($fp) #Assignment
lw $s1, -128($fp)
lw $t0, 0($s1)
sw $t0, 0($s0)
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -64($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -16($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
lw $s0, -132($fp) #Assignment
subu $s1, $fp, 68
lw $t0, 0($s1)
sw $t0, 0($s0)
lw $s0, -64($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -64($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
j LAB9next
LAB9false:
lw $s0, -64($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -64($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
LAB9next: #IF-THEN-ELSE end a=136 b=120
lw $t0, 4($s7)
subu $sp, $t0, 20
lw $t0, ($s7)
move $s7, $t0
addu $sp, $sp, 48
j LAB6loop
LAB6next:
subu $sp, $sp, 40 #WHILE end
lw $s0, -24($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -24($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 68
j LAB4loop
LAB4next:
subu $sp, $sp, 60 #WHILE end
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $s0, $fp, 24  #Assignment
subu $s1, $fp, 144
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB10loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -24($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -148($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB11true
li $t2, 0
j LAB11next
LAB11true:
li $t2, 1
LAB11next:
sw $t2, 0($sp)
lw $t0, -152($fp)
li $t1, 1
bne $t0, $t1, LAB10next
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -24($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -16($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
lw $t7, -156($fp) #fetchint0 start
lw $t0, 0($t7)
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB12:	.asciiz " "
	.text
subu $sp, $sp, 4
la $t0, LAB12
sw $t0, 0($sp)
lw $a0, -160($fp)
li $v0, 4
syscall
lw $s0, -24($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -24($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 20
j LAB10loop
LAB10next:
subu $sp, $sp, 12 #WHILE end
jr $ra
