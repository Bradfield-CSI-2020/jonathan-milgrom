section .data
    msg db      "hello, world!", 10

section .text
    global _main
_main:
    mov     rax, 0x02000004
    mov     rdi, 1
    mov     rsi, msg
    mov     rdx, 14
    syscall
    mov    rax, 0x02000001
    mov    rdi, 0
    syscall