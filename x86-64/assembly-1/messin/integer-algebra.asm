        global _main

        section .text
_main:   
        mov esi, 5
        mov edi, 6
        jmp add_bytes

add_bytes: 
        movz rax, di
        ret

