global _ft_strcpy

_ft_strcpy:
        mov     rax, 0
        jmp     loop_copy

loop_copy:
        mov     cl, BYTE[rsi + rax]
        mov     BYTE[rdi + rax], cl
        cmp     BYTE[rsi + rax], 0
        je      exit
        inc     rax
        jmp     loop_copy

exit:
        mov     rax, rdi
        ret