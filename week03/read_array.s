N_SIZE = 10
READ_INT = 5

main:
	# Registers
	# $t0 - int i
	# $t1 - &numbers[i]
	# $t2 - temp

	li	$t0, 0

main__loop:
	bge	$t0, N_SIZE, main__epilogue


	# numbers[i] = numbers + i * sizeof(int)
	li	$v0, READ_INT
	syscall

	la	$t1, numbers	# $t1 = numbers
	mul	$t2, $t0, 4	# $t2 = i * 4
	add	$t1, $t1, $t2	# $t1 = numbers + i * 4
	sw	$v0, ($t1)	# scanf("%d", &numbers[i]);

	addi	$t0, 1

	b	main__loop

main__epilogue:
	li	$v0, 0
	jr	$ra


	.data
numbers:
	.word 	0:N_SIZE