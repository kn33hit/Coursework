; File: proj1.asm 
; Using UPC code thing 
; Assemble using NASM:  nasm -f elf -g -F stabs proj.asm
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
        
        ; error check
        ;
        mov     ebx,0			; save length of string read

	cmp     eax, 0                  ; check if any chars read
        jg      Even_digit   		; >0 chars read = OK

	mov     eax, SYSCALL_WRITE      ; ow print error mesg
        mov     ebx, STDOUT
        mov     ecx, msg4
        mov     edx, len4
        int     080h
        jmp     exit                    ; skip over rest



        ; Loop for upper case conversion
        ; assuming rlen > 0
        ;
odd_Digit:	
        mov     ecx, [rlen]             ; initialize count
        mov     esi, buf                ; point to start of buffer
        mov     edi, newstr             ; point to start of new string

Even_digit:
        mov     al, [esi]               ; get a character
        inc     esi                     ; update source pointer
        cmp     al, 'a'                 ; less than 'a'?
        jb      L1_cont
        cmp     al, 'z'                 ; more than 'z'?
        ja      L1_cont
        and     al, 11011111b           ; convert to uppercase


check_MoreThanEqual_Ten:	 
      
Check_MoreThan_Zero:	

        ; final exit
        ;
exit:   mov     eax, SYSCALL_EXIT       ; exit function
        mov     ebx, 0                  ; exit code, 0=normal
        int     080h                    ; ask kernel to take over
