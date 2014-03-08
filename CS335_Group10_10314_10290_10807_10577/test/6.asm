	.text
	.globl main
Fibonaccifactorial:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 1
sw $t0, 0($sp)
lw $t0, -8($fp) #fetchint0 start
move $t1, $t0 #EqualityExpression
lw $t0, -12($fp) #fetchint0 start
subu $sp, $sp, 4
beq $t1, $t0, LAB0true
li $t2, 0
j LAB0next
LAB0true:
li $t2, 1
LAB0next:
sw $t2, 0($sp)
subu $sp, $sp, 8  #IF-THEN-ELSE start
sw $s7, ($sp)
sw $sp, 4($sp)
move $s7, $sp
lw $t0, -16($fp)
li $t1, 1
bne $t0, $t1, LAB1false
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 1
sw $t0, 0($sp)
subu $t0, $fp, 28 #RETURN
sw $t0, 0($fp)
jr $ra
j LAB1next
LAB1false:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 1
sw $t0, 0($sp)
lw $t0, -8($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -28($fp) #fetchint0 start
sub $t0, $t1, $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
subu $sp, $sp, 4 #CALL factorial
subu $sp, $sp, 4
sw $fp, ($sp)
subu $sp, $sp, 4
sw $ra, ($sp)
subu $sp, $sp, 8
lw $t1, -4($fp)
sw $t1, ($sp)
addu $s0, $sp, 4
subu $sp, $sp, 4
lw $t0, -32($fp) #fetchint0 start
sw $t0, ($sp)
move $fp, $s0
jal Fibonaccifactorial
lw $t0, 0($fp)
lw $t0, 0($t0)
addu $t1, $fp, 12
sw $t0, 0($t1)
addu $t0, $fp, 4
lw $ra, 0($t0)
addu $t0, $fp, 12
move $sp, $t0
addu $t0, $fp, 8
lw $fp, 0($t0)
lw $t0, -8($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -36($fp) #fetchint0 start
mult $t1, $t0
mflo $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
subu $t0, $fp, 40 #RETURN
sw $t0, 0($fp)
jr $ra
LAB1next: #IF-THEN-ELSE end a=28 b=40
lw $t0, 4($s7)
subu $sp, $t0, 16
lw $t0, ($s7)
move $s7, $t0
jr $ra
main:
move $fp, $sp
subu $sp, $fp, 4
Fibonaccimain:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 1
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator i
lw $t0, -8($fp)
sw $t0, -16($fp)
subu $sp, $sp, 4 #VariableDeclarator j
lw $t0, -12($fp)
sw $t0, -20($fp)
LAB2loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 500
sw $t0, 0($sp)
lw $t0, -20($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -24($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB3true
li $t2, 0
j LAB3next
LAB3true:
li $t2, 1
LAB3next:
sw $t2, 0($sp)
lw $t0, -28($fp)
li $t1, 1
bne $t0, $t1, LAB2next
lw $t0, -16($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -20($fp) #fetchint0 start
add $t0, $t1, $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator k
lw $t0, -32($fp)
sw $t0, -36($fp)
subu $s0, $fp, 16  #Assignment
subu $s1, $fp, 20
lw $t0, 0($s1)
sw $t0, 0($s0)
subu $s0, $fp, 20  #Assignment
subu $s1, $fp, 36
lw $t0, 0($s1)
sw $t0, 0($s0)
lw $t0, -20($fp) #fetchint0 start
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB4:	.asciiz " "
	.text
subu $sp, $sp, 4
la $t0, LAB4
sw $t0, 0($sp)
lw $a0, -40($fp)
li $v0, 4
syscall
addu $sp, $sp, 20
j LAB2loop
LAB2next:
subu $sp, $sp, 12 #WHILE end
	.data #STRINGLITERAL
LAB5:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB5
sw $t0, 0($sp)
lw $a0, -44($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 1
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator l
lw $t0, -48($fp)
sw $t0, -52($fp)
LAB6loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 10
sw $t0, 0($sp)
lw $t0, -52($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -56($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB7true
li $t2, 0
j LAB7next
LAB7true:
li $t2, 1
LAB7next:
sw $t2, 0($sp)
lw $t0, -60($fp)
li $t1, 1
bne $t0, $t1, LAB6next
subu $sp, $sp, 4 #CALL factorial
subu $sp, $sp, 4
sw $fp, ($sp)
subu $sp, $sp, 4
sw $ra, ($sp)
subu $sp, $sp, 8
lw $t1, -4($fp)
sw $t1, ($sp)
addu $s0, $sp, 4
subu $sp, $sp, 4
lw $t0, -52($fp) #fetchint0 start
sw $t0, ($sp)
move $fp, $s0
jal Fibonaccifactorial
lw $t0, 0($fp)
lw $t0, 0($t0)
addu $t1, $fp, 12
sw $t0, 0($t1)
addu $t0, $fp, 4
lw $ra, 0($t0)
addu $t0, $fp, 12
move $sp, $t0
addu $t0, $fp, 8
lw $fp, 0($t0)
lw $t0, -64($fp) #fetchint0 start
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB8:	.asciiz " "
	.text
subu $sp, $sp, 4
la $t0, LAB8
sw $t0, 0($sp)
lw $a0, -68($fp)
li $v0, 4
syscall
lw $s0, -52($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -52($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 20
j LAB6loop
LAB6next:
subu $sp, $sp, 12 #WHILE end
	.data #STRINGLITERAL
LAB9:	.asciiz "\nPrinting a float: "
	.text
subu $sp, $sp, 4
la $t0, LAB9
sw $t0, 0($sp)
lw $a0, -76($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #FLOATLITERAL
li.s $f0, 23.450001
s.s $f0, ($sp)
lwc1 $f12, -80($fp)
li $v0, 2
syscall
jr $ra
