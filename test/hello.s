
section .text
  global _my_strlen

_my_strlen :
	mov rax, 0
	jmp loop_c

loop_c :
	cmp BYTE[rdi + rax], 0
	je exit
	inc rax
	jmp loop_c

exit :
	ret