	.data
prompt:
	.asciiz "Enter a number: "
sb:
	.asciiz "small/big\n"
m:
	.asciiz "medium\n"

	# Constants 
READ_INT = 5
PRINT_STRING = 4

	.text
main:
	# Local variables
	# $t0 - int x

	li	$v0, PRINT_STRING
	la	$a0, prompt
	syscall				# printf("Enter a number: ");

	li	$v0, READ_INT
	syscall				# scanf("%d", &x);
	move	$t0, $v0		# t0 = v0

	li	$v0, PRINT_STRING

	ble	$t0, 100, print_sb	# if (x <= 100) goto print_sb;
	bge	$t0, 1000, print_sb	# if (x >= 1000) goto print_sb;

print_m:
	la	$a0, m
	syscall

	b	end

print_sb:
	la	$a0, sb
	syscall

end:
	li	$v0, 0
	jr	$ra



