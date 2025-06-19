N_SIZE = 10
SIZEOF_INT = 4

main:
	# Registers 
	# $t0 - int i
	# $t1 - &numbers[i]
	# $t2 - temp
	# $t3 - numbers[i]

	li	$t0, 0 		# i = 0;

main__loop:
	bge	$t0, N_SIZE, main__epilogue

	# &numbers[i] = numbers + i * sizeof(int)
	mul	$t2, $t0, SIZEOF_INT
	lw	$t3, numbers($t2)
	bge	$t3, 0, main__increment	# if (numbers[i] >= 0) goto increment;

	addi	$t3, 42
	sw	$t3, numbers($t2)	# numbers[i] += 42;

main__increment:
	addi	$t0, 1			# i++
	b	main__loop		# goto main__loop;

main__epilogue:
	li	$v0, 0
	jr	$ra			# return 0;

	.data
numbers:
	.word  0, 1, 2, -3, 4, -5, 6, -7, 8, 9