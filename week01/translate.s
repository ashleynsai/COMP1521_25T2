	.text
main:
	li	$v0, 4  		# li = 4
	la	$a0, enter_string
	syscall				# printf("Enter a number: ");

	li	$v0, 5
	syscall
	move	$t0, $v0		# $t0 = x

	# $t1 = y
	mul	$t1, $t0, $t0		# y = x * x

	li	$v0, 1
	move	$a0, $t1
	syscall				# printf("%d", y);

	li	$v0, 11
	li	$a0, '\n'
	syscall				# printf("\n");

	li	$v0, 0
	jr	$ra			# return 0;
	.data
enter_string:
	.asciiz "Enter a number: \n"