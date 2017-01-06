; File: proj1.asm 
; Using UPC code thing 
; Assemble using NASM:  nasm -f elf -g -F stabs proj1.asm
; Link with ld:  ld -o proj1 proj1.o -melf_i386
;

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_READ  3
%define SYSCALL_WRITE 4
%define BUFLEN 256


        SECTION .data                   ; initialized data section

msg1:   db "Enter 12-digit UPC: "             ; user prompt
len1:   equ $-msg1                            ; length of first message

msg2:   db "This is a valid UPC number "      ; original string label
len2:   equ $-msg2                            ; length of second message

msg3:   db "This is NOT a valid UPC number "  ; converted string label
len3:   equ $-msg3

msg4:	   db 10, "Read error", 10    ; error message
len4:	   equ $-msg4
	
array db 0, 3, 6, 9, 2, 5, 8, 1, 4, 7 ;the array of lookup 
check_Digit dw 0		      ;the checkdigit number 

        SECTION .bss                    ; uninitialized data section
buf:    resb BUFLEN                     ; buffer for read
newstr: resb BUFLEN                     ; converted string
rlen:   resb 4                          ; length


        SECTION .text                   ; Code section.
        global  _start                  ; let loader see entry point

_start: nop                             ; Entry point.
start:                                  ; address for gdb

        ; prompt user for input
        ;
        mov     eax, SYSCALL_WRITE      ; write function
        mov     ebx, STDOUT             ; Arg1: file descriptor
        mov     ecx, msg1               ; Arg2: addr of message
        mov     edx, len1               ; Arg3: length of message
        int     080h                    ; ask kernel to write

        ; read user input
        ;
        mov     eax, SYSCALL_READ       ; read function
        mov     ebx, STDIN              ; Arg 1: file descriptor
        mov     ecx, buf                ; Arg 2: address of buffer
        mov     edx, BUFLEN             ; Arg 3: buffer length
        int     080h
	;; --------------------------------------------------------
  
       

initial:	
        mov     ebx, 0                  ; initialize count (i)
        mov     esi, buf                ; point to start of buffer
        mov     al, 0                  	; eax is checkDigit
 

loop:
	cmp ebx, 11		; compare i with 11
	jge done_Loop		; jump to done loop if done 11 times
        mov ah, [esi]		; mov whatever esi is pointing to al
	sub ah, '0'		; change char to int
	test ebx,1		; check if odd or not 
	jnz Odd_Digit 		; jump to odd
	mov dl, [ebx*4+array]	; move current value to dl
	add dl, ah		; add dl and checkdigit
	mov al,dl		; move that value into al 
	jmp check_MoreThanEqual_Ten ; jump to dodge oddDigit

Odd_Digit:	
	add al, ah		; add on the value to check digit
	
check_MoreThanEqual_Ten:
	cmp al, 10		; compare check with 10
	jge sub_Ten		; jump if greater or equal
	jmp cont		; jump to cont if less then 10
 
sub_Ten:
	sub al, 10
cont:
        inc     ebx		; update char count
	jnz     loop		; loop to top if more chars 


done_Loop:
	
Check_MoreThan_Zero:	
	cmp al,0		;compare if check digit is 0
	jg subtract_check	;if greater than 0 jump sub
	jmp final

subtract_check:
	mov dl, 10		;save value 10 in dl
	sub dl, al		;subtract al from 10 and store in dl
	mov al, dl		;push the new value into al 

final:
	mov bl, [esi]		;move the value last value into bl
	sub bl, '0'		;convert bl into number
	cmp al,bl		;compare with check digit
	jne not_UPC		;jump if not equal
	
UPC:
	mov     eax, SYSCALL_WRITE ; write message
	mov     ebx, STDOUT
	mov     ecx, msg2
	mov     edx, len2
	int     080h
	jmp exit
	
not_UPC:
	mov     eax, SYSCALL_WRITE ; write message
	mov     ebx, STDOUT
	mov     ecx, msg3
	mov     edx, len3
	int     080h

	; final exit
        ;
exit:   mov     eax, SYSCALL_EXIT       ; exit function
        mov     ebx, 0                  ; exit code, 0=normal
        int     080h                    ; ask kernel to take over
