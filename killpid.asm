global _start
section .text
_start:
	xor eax, eax
	mov al, 0x25
	mov ebx, eax
	mov ecx, eax	
	mov bx, 2128
	mov cl, 9
	int 0x80
	
	mov al, 1
	int 0x80
