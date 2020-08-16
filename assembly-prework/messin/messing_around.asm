global _main
_main:
    mov rax, 1  ; set 1 corresponds to a system exit call
    mov rbx, 42 ; the status code of an exit
    int 0x80    ; 0x80 indicates a system call, which is handled by rax
