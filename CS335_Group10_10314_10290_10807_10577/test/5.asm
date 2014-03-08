	.text
	.globl main
AnimalAnimal:
subu $sp, $sp, 4 #Something
lw $t0, -4($fp)
subu $t0, $t0, 4
sw $t0, ($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 1
sw $t0, 0($sp)
lw $s0, -8($fp) #Assignment
subu $s1, $fp, 12
lw $t0, 0($s1)
sw $t0, 0($s0)
jr $ra
 #AnimalAnimal constructor end
Animalspeak:
	.data #STRINGLITERAL
LAB0:	.asciiz "Foo\n"
	.text
subu $sp, $sp, 4
la $t0, LAB0
sw $t0, 0($sp)
lw $a0, -8($fp)
li $v0, 4
syscall
jr $ra
DogDog:
subu $sp, $sp, 4 #Something
lw $t0, -4($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
lw $s0, -12($fp) #Assignment
subu $s1, $fp, 8
lw $t0, 0($s1)
sw $t0, 0($s0)
LAB1loop: #WHILE start
subu $sp, $sp, 4 #Something
lw $t0, -4($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 10
sw $t0, 0($sp)
lw $t7, -16($fp) #fetchint0 start
lw $t0, 0($t7)
move $t1, $t0 #RelationalExpression
lw $t0, -20($fp) #fetchint0 start
subu $sp, $sp, 4
blt $t1, $t0, LAB2true
li $t2, 0
j LAB2next
LAB2true:
li $t2, 1
LAB2next:
sw $t2, 0($sp)
lw $t0, -24($fp)
li $t1, 1
bne $t0, $t1, LAB1next
subu $sp, $sp, 4 #Something
lw $t0, -4($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #Something
lw $t0, -4($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 2
sw $t0, 0($sp)
lw $t7, -32($fp) #fetchint0 start
lw $t0, 0($t7)
move $t1, $t0 #MultiplicativeExpression
lw $t0, -36($fp) #fetchint0 start
add $t0, $t1, $t0
subu $sp, $sp, 4
sw $t0, 0($sp)
lw $s0, -28($fp) #Assignment
subu $s1, $fp, 40
lw $t0, 0($s1)
sw $t0, 0($s0)
subu $sp, $sp, 4 #Something
lw $t0, -4($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
lw $t7, -44($fp) #fetchint0 start
lw $t0, 0($t7)
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB3:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB3
sw $t0, 0($sp)
lw $a0, -48($fp)
li $v0, 4
syscall
addu $sp, $sp, 36
j LAB1loop
LAB1next:
subu $sp, $sp, 24 #WHILE end
jr $ra
 #DogDog constructor end
Dogspeak:
	.data #STRINGLITERAL
LAB4:	.asciiz "Bau wau!\n"
	.text
subu $sp, $sp, 4
la $t0, LAB4
sw $t0, 0($sp)
lw $a0, -8($fp)
li $v0, 4
syscall
jr $ra
CatCat:
subu $sp, $sp, 4 #Something
lw $t0, -4($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 2
sw $t0, 0($sp)
lw $s0, -8($fp) #Assignment
subu $s1, $fp, 12
lw $t0, 0($s1)
sw $t0, 0($s0)
jr $ra
 #CatCat constructor end
Catspeak:
	.data #STRINGLITERAL
LAB5:	.asciiz "Meow!\n"
	.text
subu $sp, $sp, 4
la $t0, LAB5
sw $t0, 0($sp)
lw $a0, -8($fp)
li $v0, 4
syscall
jr $ra
CowCow:
subu $sp, $sp, 4 #Something
lw $t0, -4($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 2
sw $t0, 0($sp)
lw $s0, -8($fp) #Assignment
subu $s1, $fp, 12
lw $t0, 0($s1)
sw $t0, 0($s0)
jr $ra
 #CowCow constructor end
Cowspeak:
	.data #STRINGLITERAL
LAB6:	.asciiz "Moo Moo!\n"
	.text
subu $sp, $sp, 4
la $t0, LAB6
sw $t0, 0($sp)
lw $a0, -8($fp)
li $v0, 4
syscall
jr $ra
PomerianPomerian:
subu $sp, $sp, 4 #Something
lw $t0, -4($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
lw $s0, -12($fp) #Assignment
subu $s1, $fp, 8
lw $t0, 0($s1)
sw $t0, 0($s0)
jr $ra
 #PomerianPomerian constructor end
Pomerianspeak:
	.data #STRINGLITERAL
LAB7:	.asciiz "Pomerian Bau wau!\n"
	.text
subu $sp, $sp, 4
la $t0, LAB7
sw $t0, 0($sp)
lw $a0, -8($fp)
li $v0, 4
syscall
jr $ra
main:
move $fp, $sp
subu $sp, $fp, 4
Zoomain:
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 12
sw $t0, 0($sp)
li $a0, 8
li $v0, 9
syscall
addu $v0, $v0, 8
subu $sp, $sp, 4 #NEW Dog
sw $v0, 0($sp)
move $s0, $v0
subu $sp, $sp, 4
sw $fp, 0($sp)
subu $sp, $sp, 4
sw $ra, 0($sp)
subu $sp, $sp, 8
sw $s0, 0($sp)
addu $s0, $sp, 4
subu $sp, $sp, 4
lw $t0, -8($fp) #fetchint0 start
sw $t0, 0($sp)
move $fp, $s0
jal DogDog
addu $t0, $fp, 4
lw $ra, 0($t0)
addu $sp, $fp, 12
addu $t0, $fp, 8
lw $fp, 0($t0)
subu $sp, $sp, 8 #VariableDeclarator tommy
lw $t0, -12($fp)
sw $t0, -20($fp)
subu $sp, $sp, 4 #Something
lw $t0, -20($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #CALL speak
subu $sp, $sp, 4
sw $fp, ($sp)
subu $sp, $sp, 4
sw $ra, ($sp)
subu $sp, $sp, 8
lw $t1, -20($fp)
sw $t1, ($sp)
addu $s0, $sp, 4
move $fp, $s0
jal Dogspeak
addu $t1, $fp, 12
sw $t0, ($t1)
addu $t0, $fp, 4
lw $ra, ($t0)
addu $t0, $fp, 12
move $sp, $t0
addu $t0, $fp, 8
lw $fp, ($t0)
	.data #STRINGLITERAL
LAB8:	.asciiz "tommy.age = "
	.text
subu $sp, $sp, 4
la $t0, LAB8
sw $t0, 0($sp)
lw $a0, -32($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #Something
lw $t0, -20($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
lw $t7, -36($fp) #fetchint0 start
lw $t0, 0($t7)
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB9:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB9
sw $t0, 0($sp)
lw $a0, -40($fp)
li $v0, 4
syscall
	.data #STRINGLITERAL
LAB10:	.asciiz "tommy.age changed to 23\n"
	.text
subu $sp, $sp, 4
la $t0, LAB10
sw $t0, 0($sp)
lw $a0, -44($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #Something
lw $t0, -20($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 23
sw $t0, 0($sp)
lw $s0, -48($fp) #Assignment
subu $s1, $fp, 52
lw $t0, 0($s1)
sw $t0, 0($s0)
	.data #STRINGLITERAL
LAB11:	.asciiz "tommy.age = "
	.text
subu $sp, $sp, 4
la $t0, LAB11
sw $t0, 0($sp)
lw $a0, -56($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #Something
lw $t0, -20($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
lw $t7, -60($fp) #fetchint0 start
lw $t0, 0($t7)
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB12:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB12
sw $t0, 0($sp)
lw $a0, -64($fp)
li $v0, 4
syscall
li $a0, 8
li $v0, 9
syscall
addu $v0, $v0, 8
subu $sp, $sp, 4 #NEW Cat
sw $v0, ($sp)
move $s0, $v0
subu $sp, $sp, 4
sw $fp, 0($sp)
subu $sp, $sp, 4
sw $ra, 0($sp)
subu $sp, $sp, 8
sw $s0, 0($sp)
addu $fp, $sp, 4
jal CatCat
addu $t0, $fp, 4
lw $ra, 0($t0)
addu $sp, $fp, 12
addu $t0, $fp, 8
lw $fp, 0($t0)
subu $sp, $sp, 8 #VariableDeclarator katie
lw $t0, -68($fp)
sw $t0, -76($fp)
	.data #STRINGLITERAL
LAB13:	.asciiz "katie.age = "
	.text
subu $sp, $sp, 4
la $t0, LAB13
sw $t0, 0($sp)
lw $a0, -80($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #Something
lw $t0, -76($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
lw $t7, -84($fp) #fetchint0 start
lw $t0, 0($t7)
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB14:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB14
sw $t0, 0($sp)
lw $a0, -88($fp)
li $v0, 4
syscall
	.data #STRINGLITERAL
LAB15:	.asciiz "katie.age changed to 45\n"
	.text
subu $sp, $sp, 4
la $t0, LAB15
sw $t0, 0($sp)
lw $a0, -92($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #Something
lw $t0, -76($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 45
sw $t0, 0($sp)
lw $s0, -96($fp) #Assignment
subu $s1, $fp, 100
lw $t0, 0($s1)
sw $t0, 0($s0)
	.data #STRINGLITERAL
LAB16:	.asciiz "katie.age = "
	.text
subu $sp, $sp, 4
la $t0, LAB16
sw $t0, 0($sp)
lw $a0, -104($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #Something
lw $t0, -76($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
lw $t7, -108($fp) #fetchint0 start
lw $t0, 0($t7)
move $a0, $t0
li $v0, 1
syscall
	.data #STRINGLITERAL
LAB17:	.asciiz "\n"
	.text
subu $sp, $sp, 4
la $t0, LAB17
sw $t0, 0($sp)
lw $a0, -112($fp)
li $v0, 4
syscall
subu $sp, $sp, 4 #Something
lw $t0, -76($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #CALL speak
subu $sp, $sp, 4
sw $fp, ($sp)
subu $sp, $sp, 4
sw $ra, ($sp)
subu $sp, $sp, 8
lw $t1, -76($fp)
sw $t1, ($sp)
addu $s0, $sp, 4
move $fp, $s0
jal Catspeak
addu $t1, $fp, 12
sw $t0, ($t1)
addu $t0, $fp, 4
lw $ra, ($t0)
addu $t0, $fp, 12
move $sp, $t0
addu $t0, $fp, 8
lw $fp, ($t0)
subu $sp, $sp, 4 #INTEGERLITERAL
li $t0, 23
sw $t0, 0($sp)
li $a0, 8
li $v0, 9
syscall
addu $v0, $v0, 8
subu $sp, $sp, 4 #NEW Pomerian
sw $v0, 0($sp)
move $s0, $v0
subu $sp, $sp, 4
sw $fp, 0($sp)
subu $sp, $sp, 4
sw $ra, 0($sp)
subu $sp, $sp, 8
sw $s0, 0($sp)
addu $s0, $sp, 4
subu $sp, $sp, 4
lw $t0, -124($fp) #fetchint0 start
sw $t0, 0($sp)
move $fp, $s0
jal PomerianPomerian
addu $t0, $fp, 4
lw $ra, 0($t0)
addu $sp, $fp, 12
addu $t0, $fp, 8
lw $fp, 0($t0)
subu $sp, $sp, 8 #VariableDeclarator bruno
lw $t0, -128($fp)
sw $t0, -136($fp)
subu $sp, $sp, 4 #Something
lw $t0, -136($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #CALL speak
subu $sp, $sp, 4
sw $fp, ($sp)
subu $sp, $sp, 4
sw $ra, ($sp)
subu $sp, $sp, 8
lw $t1, -136($fp)
sw $t1, ($sp)
addu $s0, $sp, 4
move $fp, $s0
jal Pomerianspeak
addu $t1, $fp, 12
sw $t0, ($t1)
addu $t0, $fp, 4
lw $ra, ($t0)
addu $t0, $fp, 12
move $sp, $t0
addu $t0, $fp, 8
lw $fp, ($t0)
li $a0, 8
li $v0, 9
syscall
addu $v0, $v0, 8
subu $sp, $sp, 4 #NEW Cow
sw $v0, ($sp)
move $s0, $v0
subu $sp, $sp, 4
sw $fp, 0($sp)
subu $sp, $sp, 4
sw $ra, 0($sp)
subu $sp, $sp, 8
sw $s0, 0($sp)
addu $fp, $sp, 4
jal CowCow
addu $t0, $fp, 4
lw $ra, 0($t0)
addu $sp, $fp, 12
addu $t0, $fp, 8
lw $fp, 0($t0)
subu $sp, $sp, 8 #VariableDeclarator nandini
lw $t0, -148($fp)
sw $t0, -156($fp)
subu $sp, $sp, 4 #Something
lw $t0, -156($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #CALL speak
subu $sp, $sp, 4
sw $fp, ($sp)
subu $sp, $sp, 4
sw $ra, ($sp)
subu $sp, $sp, 8
lw $t1, -156($fp)
sw $t1, ($sp)
addu $s0, $sp, 4
move $fp, $s0
jal Cowspeak
addu $t1, $fp, 12
sw $t0, ($t1)
addu $t0, $fp, 4
lw $ra, ($t0)
addu $t0, $fp, 12
move $sp, $t0
addu $t0, $fp, 8
lw $fp, ($t0)
subu $sp, $sp, 4 #VariableDeclarator alice
lw $t0, -156($fp)
sw $t0, -168($fp)
subu $sp, $sp, 4 #Something
lw $t0, -168($fp)
subu $t0, $t0, 8
sw $t0, ($sp)
subu $sp, $sp, 4 #CALL speak
subu $sp, $sp, 4
sw $fp, ($sp)
subu $sp, $sp, 4
sw $ra, ($sp)
subu $sp, $sp, 8
lw $t1, -168($fp)
sw $t1, ($sp)
addu $s0, $sp, 4
move $fp, $s0
jal Animalspeak
addu $t1, $fp, 12
sw $t0, ($t1)
addu $t0, $fp, 4
lw $ra, ($t0)
addu $t0, $fp, 12
move $sp, $t0
addu $t0, $fp, 8
lw $fp, ($t0)
jr $ra
