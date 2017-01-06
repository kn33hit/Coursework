	;; gcc -fno-stack-protector -c -m32 -g sorter.c -o sorter.o
	;; nasm -f elf -g -F dwarf library.asm -o library.o 
	;; gcc -m32 -g -nostdlib -o sorter_nostdlib sorter.o library.o

	;; Neh Patel

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_READ  3
%define SYSCALL_WRITE 4
%define BUFLEN 256


	SECTION .data	; initialized data section	

	SECTION .bss
buf:	    resb BUFLEN
	
	SECTION .text		; Code section.
	extern main
	global  _start	; let loader see entry point
	global write
	global read
	global strcmp
	
_start:	 nop			; Entry point.
start:				; address for gdb
	call 	main
	;;  prompt user for input
	;;
	call 	exit
write:	
	push 	ebp
	mov 	ebp, esp
	push 	ebx
	push 	esi
	push 	edi
	
	mov     eax, SYSCALL_WRITE ; write function
	mov     ebx, [EBP+8]	   ; Arg1: file descriptor
	mov     ecx, [EBP+12]	   ; Arg2: addr of message
	mov     edx, [EBP+16]	   ; Arg3: length of message
	int     080h		   ; ask kernel to write

	pop 	edi
	pop 	esi
	pop 	ebx
	mov 	esp, ebp
	pop 	ebp
	ret


	;;  read user input
	;;
	
read:	
	push    ebp
	mov     ebp, esp
	push    ebx
	push    esi
	push    edi

	mov     eax, SYSCALL_READ ; read function
	mov     ebx, [EBP+8] 	; Arg 1: file descriptor
	mov     ecx, [EBP+12]	; Arg 2: address of buffer
	mov     edx, [EBP+16] 	; Arg 3: buffer length
	int     080h

	pop     edi
	pop     esi
	pop     ebx
	mov     esp, ebp
	pop     ebp
	ret
	

strcmp:
	push    ebp
	mov     ebp, esp
	push    ebx
	push    esi
	push    edi

	mov 	esi, [EBP+8] 	;esi is string 1
	mov 	edi,[ebp+12]	;edi is string 2
compare:
	mov 	al,[esi]
	mov 	bl,[edi]
	cmp 	al, bl 
	jne	swap
	inc 	esi
	inc 	edi
	jmp 	compare

swap:
	jg 	greater
	mov 	eax, -1
	jmp 	done
	
greater:
	mov 	eax, 1

done:	
	pop   	edi
	pop     esi
	pop     ebx
	mov     esp, ebp
	pop     ebp
	ret

exit:	mov 	ebx, eax
	mov     eax, SYSCALL_EXIT 	; exit function	     
	int     080h		     	; ask kernel to take over

	