global	_ft_strdup
extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy
extern	_ft_strcmp

_ft_strdup:
	call	_ft_strlen
	inc 	rax
	push	rdi
	mov		rdi, rax
	call	_malloc
	cmp		rax, 0
	je		exit
	pop		rsi
	mov		rdi, rax
	call	_ft_strcpy
	mov		r8, rax
	mov		rdi, rax
	call	_ft_strcmp
	cmp		rax, 0
	je		exit
	jmp		error

exit:
	mov 	rax, r8
	ret

error:
	mov		rax, -1
	ret