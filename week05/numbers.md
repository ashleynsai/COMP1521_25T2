# Binary, Octal, Decimal and Hexadecimal



## Binary

- base 2 (each digit can only be 0 or 1)
- `0b`  prefix
- e.g. `0b0011 1100`

## Octal

- Base 8 (each digit goes from 0-7)
- `0`  prefix (sometimes has `0o`  prefix)
- e.g. `0777` 

## Decimal

- base 10 (each digit can be from 0-9)
- e.g. `909`

## Hexadecimal

- base 16 (each digit goes from 0-9 then a-f)
- `0x`  prefix
- e.g. `0xABC8`



``` c
Convert 0b1111 0110 (246 in decimal) into octal and hexidecimal

246 = 0b11110110

To convert into octal, split the binary into groups of three, starting from the LSB
246 = 0b 011 110 110
246 = 0   3   6  6 = 0366

To convert into hexadecimal, split the binary into groups of four, starting from RHS
246 = 0b 1111 0110
246 = 0x  f    6 = 0xF6
 // hex goes 8 9 a b c d e f
246 = 
```



```shell
# Easy way to convert between bases in your terminal! (can be used in final exam)
$ python3
>>> bin(246)			# Convert decimal 29 into binary
'0b11101'
>>> oct(29)				# Convert into octal
'0o35'
>>> hex(29)				# Convert into hex
'0x1d'
>>> int(0x1d) 		# Convert back into decimal
29
>>> ctrl-D 				# to exit
```



# Bitwise Operations

### & and

Think of this as an **extracting** operation - whichever bits are set in the mask, is extracted out of the original value

```c
//   0b xxxx xxxx  -- original value
// & 0b 0011 1100  -- mask
// = 0b 00xx xx00  -- final result

//   0b 1110 0101  -- original value
// & 0b 0100 1001  -- mask
// = 0b 0100 0001  -- final result

int a = 20 & 5;
//   0b 0001 0100
// & 0b 0000 0101
// = 0b 0000 0100
```



### | or

Think of this as a **setting** operation - whichever bits are set in the mask, are set in the final value

```c
//   0b xxxx xxxx  -- original value
// | 0b 0110 0110  -- mask
// = 0b x11x x11x

//   0b 1000 0000  -- original value
// | 0b 0000 1111  -- mask
// = 0b 1000 1111
```



### ^ XOR

XOR means if **ONLY ONE OR THE OTHER** bit is set, the final result is set. Exclusive OR. Not both, not neither.

```c
//   0b 1010 0000  -- original value
// | 0b 0010 1111  -- mask
// = 0b 
```



### ~ not

Just flips every bit

```
  ~ 0b 1111 0000
  = 0b 
```



### << left shift

Shifts all the bits to the left

```c
uint8_t a = 0b 1000 1111 << 5 		// Shift 0b 1000 1111 to the left by 5
   //.         0001 1110
   //.         0011 1100
  
  //.          1110 0000
```



### >> right shift

Shifts all the bits to the right

```c
uint8_t b = 0b 0000 0111 >> 3			// Shift to the right by 3
  //.          0000 0000
```



Exercise time!

```c
uint8_t a = 0x55 // 0b 0101 0101
uint8_t b = 0xAA // 0b 1010 1010
  
// What is a & (b << 1)
// b << 1 = 0b 0101 0100
  
//   0b 0101 0101
//  &0b 0101 0100
  // 0b 0101 0100. EXTRACTION COMPLETE 
```





### BCD - binary coded decimals (will be in labs!)

BCD is where each byte (8 bits, or 2 hex digits) is interpreted as 1 digit in decimal.

Note - all BCD's must be between 0 and 9 inclusive as that is the limit of a decimal. 0x0A0F would not be a valid

```shell
$ ./bcd 0x0A    # !! Not a valid BCD as A cannot be represented as a decimal digit from 0-9
$ ./bcd 0x07    # equivalent to decimal
$ ./bcd 0x 01 02  # equivalent to decimal  2x16**0 + 1 x 16**2 - wrong, 
# split it up into groups of two hex digits
# 0x0102 = 12
$ ./bcd 0x 04 02  # equivalent to decimal
#.      42
0x08 09 02 03 04
89234
```



Packed BCD's are where the digits are packed closer together. So now each half byte (4 bits) is interpreted as 1 digit in decimal

```shell
$ ./packed_bcd 0x 1 7   # equivalent to decimal 17
$ ./packed_bcd 0x 4 1 0 2 # equivalent to decimal 4102
```

