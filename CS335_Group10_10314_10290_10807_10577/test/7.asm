	.text
	.globl main
main:
move $fp, $sp
subu $sp, $fp, 4
Arraymain:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
li $t0, 1
lw $t1, -8($fp)
multu $t0, $t1
mflo $t0
lw $t1, -12($fp)
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
lw $t0, -16($fp)
sw $t0, -20($fp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator i
lw $t0, -24($fp)
sw $t0, -32($fp)
subu $sp, $sp, 4 #VariableDeclarator j
lw $t0, -28($fp)
sw $t0, -36($fp)
LAB0loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -32($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -40($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB1true
li $t2, 0
j LAB1next
LAB1true:
li $t2, 1
LAB1next:
sw $t2, 0($sp)
lw $t0, -44($fp)
li $t1, 1
bne $t0, $t1, LAB0next
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $s0, $fp, 36  #Assignment
subu $s1, $fp, 48
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB2loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -36($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -52($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB3true
li $t2, 0
j LAB3next
LAB3true:
li $t2, 1
LAB3next:
sw $t2, 0($sp)
lw $t0, -56($fp)
li $t1, 1
bne $t0, $t1, LAB2next
li $s0, 1
lw $t1, -0($fp)
multu $s0, $t1
mflo $s0
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -32($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -20($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -36($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -60($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, 0($sp)
lw $t0, -36($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -32($fp) #fetchint0 start
add $t0, $t1, $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
lw $s0, -64($fp) #Assignment
subu $s1, $fp, 68
lw $t0, 0($s1)
sw $t0, 0($s0)
lw $s0, -36($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -36($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 24
j LAB2loop
LAB2next:
subu $sp, $sp, 16 #WHILE end
lw $s0, -32($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -32($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 40
j LAB0loop
LAB0next:
subu $sp, $sp, 32 #WHILE end
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $s0, $fp, 32  #Assignment
subu $s1, $fp, 80
lw $t0, 0($s1)
sw $t0, 0($s0)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $s0, $fp, 36  #Assignment
subu $s1, $fp, 84
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB4loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -32($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -88($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB5true
li $t2, 0
j LAB5next
LAB5true:
li $t2, 1
LAB5next:
sw $t2, 0($sp)
lw $t0, -92($fp)
li $t1, 1
bne $t0, $t1, LAB4next
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $s0, $fp, 36  #Assignment
subu $s1, $fp, 96
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB6loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -36($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -100($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB7true
li $t2, 0
j LAB7next
LAB7true:
li $t2, 1
LAB7next:
sw $t2, 0($sp)
lw $t0, -104($fp)
li $t1, 1
bne $t0, $t1, LAB6next
li $s0, 1
lw $t1, -0($fp)
multu $s0, $t1
mflo $s0
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -32($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -20($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, ($sp)
li $s0, 1
li $t1, 4
multu $s0, $t1
mflo $s0
lw $t0, -36($fp) #fetchint0 start
multu $s0, $t0
mflo $s0
lw $t0, -108($fp)
addu $t0, $t0, $s0
subu $sp, $sp, 4
sw $t0, 0($sp)
lw $t7, -112($fp) #fetchint0 start
lw $t0, 0($t7)
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB8:	.asciiz " "
	.text
subu $sp, $sp, 4
la $t0, LAB8
sw $t0, 0($sp)
lw $a0, -116($fp)
li $v0, 4
syscall
lw $s0, -36($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -36($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 24
j LAB6loop
LAB6next:
subu $sp, $sp, 16 #WHILE end
lw $s0, -32($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -32($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
	.data #STRINGLITERAL
LAB9:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB9
sw $t0, 0($sp)
lw $a0, -128($fp)
li $v0, 4
syscall
addu $sp, $sp, 44
j LAB4loop
LAB4next:
subu $sp, $sp, 36 #WHILE end
jr $ra
