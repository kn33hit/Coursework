;;;  File : a.asm
;;;   Neh Patel
;;;  project 2(313)
;;;   Hamming code format

	        SECTION .data
msg1	   dw 123		;string (not needed right noe)

	SECTION .bss
	
var3 resb 3
var2 resb 1
var1 resb 1
final resb 4
	        SECTION .text
	        global _start
start:	   nop
	;; for now lets say we read the file and have it stored in the
	;;  eax register
	mov eax, msg1		;0321
	ror ax, 8		;3012
	ror eax, 16		;2130
	ror ax, 8		;1230
	mov bx,ax		;copy first 16 bits
	
	and bl, F0h		;half way done
	shr ebx, 16		; store firt half in the same register
	
	

;;;  exit code
	        mov ebx, 0
	        mov eax, 0
	        int 080H
	