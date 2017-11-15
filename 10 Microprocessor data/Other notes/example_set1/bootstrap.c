// This is a simple C-program the sole purpose of 
// which is to call an assembler function
// Doing things this way helps make the examples
// work in Linux AND Windows as there is no direct
// interaction between the assembler and the OS

void myasm(void) asm("myasm");
int main(int argc, char *argv[])
{
	myasm();
}
