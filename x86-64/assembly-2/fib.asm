section .text
global fib

; int fib(int n)
; n in rdi
fib:
    push rbx        ; save n
    mov rbx, rdi
    cmp rdi, 1
    jle .RET
    dec rdi
    call fib
    dec rdi
    call fib
    call 

.RET:
    pop rbx
    ret
