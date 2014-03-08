	.text
	.globl main
main:
move $fp, $sp
subu $sp, $fp, 4
test3main:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 14
sw $t0, 0($sp)
subu $sp, $sp, 8 #DOUBLELITERAL
li.d $f0, 10.100000
sdc1 $f0, 0($sp)
subu $sp, $sp, 8 #VariableDeclarator a
lw $t0, -8($fp)
sw $t0, -24($fp)
subu $sp, $sp, 8 #VariableDeclarator b
lw $t0, -16($fp)
sw $t0, -32($fp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 6
sw $t0, 0($sp)
subu $sp, $sp, 8 #VariableDeclarator z
lw $t0, -36($fp)
sw $t0, -44($fp)
lw $t0, -24($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -44($fp) #fetchint0 start
div $t1, $t0
mflo $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
subu $sp, $sp, 8 #VariableDeclarator k
lw $t0, -48($fp)
sw $t0, -56($fp)
subu $sp, $sp, 8 #DOUBLELITERAL
li.d $f0, 1.100000
sdc1 $f0, 0($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 1
sw $t0, 0($sp)
subu $sp, $sp, 8 #VariableDeclarator s1
lw $t0, -68($fp)
sw $t0, -76($fp)
lw $t0, -44($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -24($fp) #fetchint0 start
add $t0, $t1, $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
subu $sp, $sp, 8 #VariableDeclarator s2
lw $t0, -80($fp)
sw $t0, -88($fp)
subu $sp, $sp, 4 #BTRUE
li $t0, 1
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator check
lw $t0, -92($fp)
sw $t0, -96($fp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 0
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator wow
lw $t0, -104($fp)
sw $t0, -108($fp)
LAB0loop: #WHILE start
subu $sp, $sp, 8 #DOUBLELITERAL
li.d $f0, 10.000000
sdc1 $f0, 0($sp)
lw $t0, -24($fp) #fetchint0 start
move $t1, $t0 #RelationalExpression
lw $t0, -116($fp) #fetchint0 start
subu $sp, $sp, 4
bgt $t1, $t0, LAB1true
li $t2, 0
j LAB1next
LAB1true:
li $t2, 1
LAB1next:
sw $t2, 0($sp)
lw $t0, -120($fp)
li $t1, 1
bne $t0, $t1, LAB0next
lw $s0, -24($fp) #PostDecrementExpression
move $t0, $s0
addi $t0, $t0, -1
sw $t0, -24($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
lw $s0, -44($fp) #PostIncrementExpression
move $t0, $s0
addi $t0, $t0, 1
sw $t0, -44($fp)
subu $sp, $sp, 4
sw $s0, 0($sp)
addu $sp, $sp, 20
j LAB0loop
LAB0next:
subu $sp, $sp, 8 #WHILE end
subu $sp, $sp, 4 #VariableDeclarator g
subu $sp, $sp, 8  #IF-THEN-ELSE start
sw $s7, ($sp)
sw $sp, 4($sp)
move $s7, $sp
lw $t0, -96($fp)
li $t1, 1
bne $t0, $t1, LAB2false
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 15
sw $t0, 0($sp)
subu $s0, $fp, 132  #Assignment
subu $s1, $fp, 144
lw $t0, 0($s1)
sw $t0, 0($s0)
j LAB2next
LAB2false:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 10
sw $t0, 0($sp)
subu $s0, $fp, 132  #Assignment
subu $s1, $fp, 144
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB2next: #IF-THEN-ELSE end a=144 b=144
lw $t0, 4($s7)
subu $sp, $t0, 4
lw $t0, ($s7)
move $s7, $t0
subu $sp, $sp, 8  #IF-THEN-ELSE start
sw $s7, ($sp)
sw $sp, 4($sp)
move $s7, $sp
lw $t0, -108($fp)
li $t1, 1
bne $t0, $t1, LAB3false
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 34
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator kac
lw $t0, -156($fp)
sw $t0, -160($fp)
j LAB3next
LAB3false:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 12
sw $t0, 0($sp)
subu $sp, $sp, 4 #VariableDeclarator x
lw $t0, -156($fp)
sw $t0, -160($fp)
LAB3next: #IF-THEN-ELSE end a=160 b=160
lw $t0, 4($s7)
subu $sp, $t0, 8
lw $t0, ($s7)
move $s7, $t0
jr $ra
test3func:
subu $sp, $sp, 4 #VariableDeclarator b
lw $t0, -8($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -8($fp) #fetchint0 start
mult $t1, $t0
mflo $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
lw $t0, -16($fp) #fetchint0 start
move $t1, $t0 #MultiplicativeExpression
lw $t0, -8($fp) #fetchint0 start
mult $t1, $t0
mflo $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
subu $s0, $fp, 12  #Assignment
subu $s1, $fp, 20
lw $t0, 0($s1)
sw $t0, 0($s0)
subu $t0, $fp, 12 #RETURN
sw $t0, 0($fp)
jr $ra
jr $ra
