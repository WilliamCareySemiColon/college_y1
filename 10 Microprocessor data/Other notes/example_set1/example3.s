	.data
x:	.long	0x1234
y:	.long	0x5678
z:	.long	0

	.text

	.global myasm
# This program demonstrates the use of variables


myasm:	

	mov	x,%eax
	add	y,%eax
	mov	%eax,z

# return to main
	ret
	.end
