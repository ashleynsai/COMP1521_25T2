main:
	# Local vars
	# $t0 - int i
	# $t1 - int j

outer_init:
	li	$t0, 1			# i = 1;

outer_cond:
	bgt	$t0, 10, outer_end	# if (i > 10) goto outer_end;

outer_body:
inner_init:
	li	$t1, 0			# j = 0

inner_cond:
	bge	$t1, $t0, inner_end 	# if (j >= i) goto inner_end;

inner_body:
	li	$v0, 11
	la	$a0, '*'
	syscall				# printf("*");

# Tutorial ended here ... continued by Ashley
inner_incr:
	addi	$t1, 1			# j++;
	b	inner_cond		# goto inner_cond;

inner_end:
	li	$v0, 11			
	li	$a0, '\n'
	syscall				# printf("\n");

outer_incr:
	addi	$t0, 1			# i++;
	b	outer_cond		# goto outer_cond;

outer_end:
	li	$v0, 0
	jr	$ra			# return 0