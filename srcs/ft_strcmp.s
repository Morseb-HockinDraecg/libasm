global _ft_strcmp

_ft_strcmp:
        mov     rax,0
        jmp     loop_compar

loop_compar:
        mov     cl, BYTE[rdi + rax]
        cmp     BYTE[rsi + rax], cl
        je      equal_comp
        jmp     diff_comp

equal_comp:
        cmp     BYTE[rsi + rax], 0
        je      exit
        inc     rax
        jmp     loop_compar

diff_comp:
        sub		cl, BYTE[rsi + rax] 
        movsx	rax, cl
        ret

exit:
        mov		rax, 0
        ret