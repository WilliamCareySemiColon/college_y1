

	.text
# The following line marks the label "myasm" as public which
# means that an entry is made for it in the symbol table in
# the object file (produced by 'assembling' this file).
# The linker can then find this symbol and link it up with 
# a call statement from the supporting C code
	.global myasm
# This program demonstrates the behaviour of the arithmetic flags


myasm:	

# Perform the sum 1+1.  All flags should be zero after this
	mov	$0x1,%eax
# add the value (hex) 5678 to eax
	add	$0x1,%eax

# Perform the sum 1-1
	mov 	$0x1,%eax
	sub	$0x1,%eax

# Perform the sum 15+1
	mov	$0xf,%eax
	add	$0x1,%eax

# Perform the sum 1 - 2
	mov 	$0x1,%eax
	sub	$0x2,%eax

#Perform the sum 0xffffffff + 1
	mov 	$0xffffffff,%eax
	add	$0x1,%eax

#Perform the sum 0x7fffffff + 1
	mov	$0x7fffffff,%eax
	add	$1,%eax


# return to main
	ret
	.end
