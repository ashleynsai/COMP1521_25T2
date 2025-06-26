main:
main__epilogue:
	push	$ra
main__body:

	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal	sum4
	move	$a0, $v0		# int result = sum4(11, 13, 17, 19);

	li	$v0, 1
	syscall				# print result


main__prologue:
	pop	$ra
	li	$v0, 0
	jr	$ra

# sum4 is a non-leaf function
# Must push and pop $ra at the minimum
# As well as any $s registers we overwrite
sum4:
sum4__prologue:
	push	$ra
	push	$s0
	push	$s1
	push	$s2

	move	$s0, $a2
	move	$s1, $a3
sum4__body:

	jal	sum2
	move	$s2, $v0	# int res1 = sum2(a, b);

	move	$a0, $s0
	move	$a1, $s1
	jal	sum2
	move	$t2, $v0	# int res2 = sum2(c, d);

	move	$a0, $s2
	move	$a1, $t2
	jal	sum2

sum4__epilogue:
	pop	$s2
	pop	$s1
	pop	$s0
	pop	$ra

	jr	$ra

# In leaf functions, nothing needs to be push/popped
# sum2 is a leaf function as it doesn't jal to any other function!
sum2:
sum2__epilogue:
sum2__body:
	add	$v0, $a0, $a1

sum2__prologue:
	jr	$ra			# return x + y;