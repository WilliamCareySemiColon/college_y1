# First assembler example

	.text
# The following line marks the label "myasm" as public which
# means that an entry is made for it in the symbol table in
# the object file (produced by 'assembling' this file).
# The linker can then find this symbol and link it up with 
# a call statement from the supporting C code
	.global myasm
# This first function adds two numbers together in the eax
# register and returns to main.

myasm:	
# put the value (hex) 1234 ('immediate' addressing) into the eax register
	mov	$0x1234,%eax
# add the value (hex) 5678 to eax
	add	$0x5678,%eax

# return to main
	ret
	.end
