	.text
	.globl main
main:
move $fp, $sp
subu $sp, $fp, 4
Test4main:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator i
lw $t0, -8($fp)
sw $t0, -12($fp)
subu $sp, $sp, 4 #BFALSE
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 8  #IF-THEN-ELSE start
sw $s7, ($sp)
sw $sp, 4($sp)
move $s7, $sp
lw $t0, -16($fp)
li $t1, 1
bne $t0, $t1, LAB0false
subu $sp, $sp, 4 #BFALSE
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 8  #IF-THEN-ELSE start
sw $s7, ($sp)
sw $sp, 4($sp)
move $s7, $sp
lw $t0, -28($fp)
li $t1, 1
bne $t0, $t1, LAB1false
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 5
sw $t0, 0($sp)
subu $s0, $fp, 12  #Assignment
subu $s1, $fp, 40
lw $t0, 0($s1)
sw $t0, 0($s0)
j LAB1next
LAB1false:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 6
sw $t0, 0($sp)
subu $s0, $fp, 12  #Assignment
subu $s1, $fp, 40
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB1next: #IF-THEN-ELSE end a=40 b=40
lw $t0, 4($s7)
subu $sp, $t0, 4
lw $t0, ($s7)
move $s7, $t0
j LAB0next
LAB0false:
subu $sp, $sp, 4 #BTRUE
li $t0, 1
sw $t0, 0($sp)
subu $sp, $sp, 8  #IF-THEN-ELSE start
sw $s7, ($sp)
sw $sp, 4($sp)
move $s7, $sp
lw $t0, -28($fp)
li $t1, 1
bne $t0, $t1, LAB2false
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 7
sw $t0, 0($sp)
subu $s0, $fp, 12  #Assignment
subu $s1, $fp, 40
lw $t0, 0($s1)
sw $t0, 0($s0)
j LAB2next
LAB2false:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 8
sw $t0, 0($sp)
subu $s0, $fp, 12  #Assignment
subu $s1, $fp, 40
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB2next: #IF-THEN-ELSE end a=40 b=40
lw $t0, 4($s7)
subu $sp, $t0, 4
lw $t0, ($s7)
move $s7, $t0
LAB0next: #IF-THEN-ELSE end a=40 b=40
lw $t0, 4($s7)
subu $sp, $t0, 16
lw $t0, ($s7)
move $s7, $t0
LAB3loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 10
sw $t0, 0($sp)
lw $t0, -12($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -44($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB4true
li $t2, 0
j LAB4next
LAB4true:
li $t2, 1
LAB4next:
sw $t2, 0($sp)
lw $t0, -48($fp)
li $t1, 1
bne $t0, $t1, LAB3next
lw $s0, -12($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -12($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
lw $t0, -12($fp) #fetchint0 start
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB5:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB5
sw $t0, 0($sp)
lw $a0, -56($fp)
li $v0, 4
syscall
addu $sp, $sp, 16
j LAB3loop
LAB3next:
subu $sp, $sp, 8 #WHILE end
LAB6body: #DO start
lw $s0, -12($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -12($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
lw $t0, -12($fp) #fetchint0 start
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB7:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB7
sw $t0, 0($sp)
lw $a0, -64($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -12($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -68($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB8true
li $t2, 0
j LAB8next
LAB8true:
li $t2, 1
LAB8next:
sw $t2, 0($sp)
lw $t0, -72($fp)
li $t1, 1
addu $sp, $sp, 16
beq $t0, $t1, LAB6body
subu $sp, $sp, 16
LAB6next: #DO end
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 23
sw $t0, 0($sp)
subu $s0, $fp, 12  #Assignment
subu $s1, $fp, 76
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB9loop: #FOR start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -12($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -80($fp) #fetchint0 start
subu $sp, $sp, 4
ble $t1, $t0, LAB10true
li $t2, 0
j LAB10next
LAB10true:
li $t2, 1
LAB10next:
sw $t2, 0($sp)
lw $t0, -84($fp)
li $t1, 1
bne $t0, $t1, LAB9next
lw $t0, -12($fp) #fetchint0 start
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB11:	.asciiz " "
	.text
subu $sp, $sp, 4
la $t0, LAB11
sw $t0, 0($sp)
lw $a0, -88($fp)
li $v0, 4
syscall
lw $s0, -12($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -12($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 16
j LAB9loop
LAB9next:
subu $sp, $sp, 8 #FOR end
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $s0, $fp, 12  #Assignment
subu $s1, $fp, 96
lw $t0, 0($s1)
sw $t0, 0($s0)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator j
lw $t0, -100($fp)
sw $t0, -104($fp)
LAB12loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 20
sw $t0, 0($sp)
lw $t0, -12($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -108($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB13true
li $t2, 0
j LAB13next
LAB13true:
li $t2, 1
LAB13next:
sw $t2, 0($sp)
lw $t0, -112($fp)
li $t1, 1
bne $t0, $t1, LAB12next
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $s0, $fp, 104  #Assignment
subu $s1, $fp, 116
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB14loop: #WHILE start
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 8
sw $t0, 0($sp)
lw $t0, -104($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -120($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB15true
li $t2, 0
j LAB15next
LAB15true:
li $t2, 1
LAB15next:
sw $t2, 0($sp)
lw $t0, -124($fp)
li $t1, 1
bne $t0, $t1, LAB14next
	.data #STRINGLITERAL
LAB16:	.asciiz "("
	.text
subu $sp, $sp, 4
la $t0, LAB16
sw $t0, 0($sp)
lw $a0, -128($fp)
li $v0, 4
syscall
lw $t0, -12($fp) #fetchint0 start
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB17:	.asciiz ","
	.text
subu $sp, $sp, 4
la $t0, LAB17
sw $t0, 0($sp)
lw $a0, -132($fp)
li $v0, 4
syscall
lw $t0, -104($fp) #fetchint0 start
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB18:	.asciiz ") "
	.text
subu $sp, $sp, 4
la $t0, LAB18
sw $t0, 0($sp)
lw $a0, -136($fp)
li $v0, 4
syscall
lw $s0, -104($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -104($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 24
j LAB14loop
LAB14next:
subu $sp, $sp, 16 #WHILE end
	.data #STRINGLITERAL
LAB19:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB19
sw $t0, 0($sp)
lw $a0, -144($fp)
li $v0, 4
syscall
lw $s0, -12($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -12($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 44
j LAB12loop
LAB12next:
subu $sp, $sp, 36 #WHILE end
	.data #STRINGLITERAL
LAB20:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB20
sw $t0, 0($sp)
lw $a0, -152($fp)
li $v0, 4
syscall
jr $ra
