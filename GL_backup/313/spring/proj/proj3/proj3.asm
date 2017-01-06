	;; File: proj3.asm
	;; Arrest Records stored in the c object file
	;;  nasm -f elf -g -F stabs proj3.asm
	;; ld -melf_32  -o proj3 proj3.o data.o

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT 1
%define SYSCALL_READ 3
%define SYSCALL_WRITE 4
%define BUFLEN 256
%define BUFLEN2 256
	;; Offsets for struct citizens 
%define OFFSET_LAST_NAME 0
%define OFFSET_FIRST_NAME 20
%define OFFSET_NUM_ARRESTS 40
%define OFFSET_ARRESTS_PTR 44
%define OFFSET_NEXT 48

	;; Offsets for struct arrests
%define OFFSET_ARREST_YEAR	0
%define OFFSET_ARREST_MONTH 8
%define OFFSET_ARREST_DAY	12
%define OFFSET_ARREST_DESCRIPTION 16
%define SIZEOF_STRUCT_ARRESTS 56
	

	SECTION .data		;intializing data

msg1:	 db "Enter citizens last name: " ;user prompt
len1:	 equ $-msg1			;length of msg1

msg2:	 db "Enter citizen's first name: "
len2:	 equ $-msg2

msg3:	db "Unknown last name: "
len3:	equ $-msg3

msg4:	db "Unknown name: "
len4:	equ $-msg4

msg5:	db "In the record"
len5:	equ $-msg5

msg6:	   db ", "
len6:	   equ $-msg6
	
extern citizens
	
	SECTION .bss 			;unintialized data

temp:	resb 8
buf:	resb BUFLEN 			;buffer for read
rlen:	resb 4
buf2:	resb BUFLEN2
rlen2:	resb 4
	
	SECTION .text			;code section	
	global _start

_start:	 nop
start:
	;; READING LAST NAME 
	;;  user prompt
	mov 	eax, SYSCALL_WRITE 		;write
	mov 	ebx, STDOUT 		;file descriptor
	mov 	ecx, msg1 			;addr message
	mov 	edx, len1 			;lenght of message
	int 	080h			;kernel call

	;; reading input
	mov 	eax, SYSCALL_READ		;read
	mov 	ebx, STDIN			;file descriptor
	mov 	ecx, buf			;address to buf
	mov 	edx, BUFLEN			;buf lenght
	int 	080h			;kernel call

	mov 	[rlen], eax

	;; READING FIRST NAME
	
;;;   user prompt
	mov     eax, 	SYSCALL_WRITE 	;write
	mov     ebx, 	STDOUT	   	;file descriptor
	mov     ecx, 	msg2	   	;addr message
	mov     edx, 	len2	   	;lenght of message
	int     080h		   	;kernel call

;;;  reading input
	mov     eax, 	SYSCALL_READ 	;read
	mov     ebx, 	STDIN	  	;file descriptor
	mov     ecx, 	buf2	  	;address to buf
	mov     edx, 	BUFLEN2	  	;buf lenght
	int     080h		  	;kernel call   

	mov 	[rlen2], eax
	mov 	esi,	 citizens
	mov 	eax, 	[esi]
	mov 	ebx,	 buf
	cmp 	eax, 	 buf
	je 	known
	jmp 	unknown
	
known:
;;;   user prompt
	mov     eax, SYSCALL_WRITE ;write
	mov     ebx, STDOUT	   ;file descriptor
	mov     ecx, msg5	   ;addr message
	mov     edx, len5	   ;lenght of message
	int     080h		   ;kernel call 
	jmp 	exit
	
unknown:	
;;;   user prompt
	mov     eax, SYSCALL_WRITE ;write
	mov     ebx, STDOUT	   ;file descriptor
	mov     ecx, msg4	   ;addr message
	mov     edx, len4	   ;lenght of message
	int     080h		   ;kernel call

	mov     eax,    SYSCALL_WRITE	;write
	mov     ebx,    STDOUT	;file descriptor
	mov     ecx,    buf	;addr message
	mov     edx,    BUFLEN	;lenght of message
	int     080h		;kernel call         

	mov     eax,    SYSCALL_WRITE	;write
	mov     ebx,    STDOUT	;file descriptor
	mov     ecx,    msg6	;addr message
	mov     edx,    len6	;lenght of message
	int     080h		;kernel call
	
	mov     eax,    SYSCALL_WRITE	;write
	mov     ebx,    STDOUT	;file descriptor
	mov     ecx,    buf2	;addr message
	mov     edx,    BUFLEN2	;lenght of message
	int     080h		;kernel call         
exit:
	mov eax, SYSCALL_EXIT		;exit function 
	mov ebx,0			;exti code, 0 = normal
	int 080h			;kernel call