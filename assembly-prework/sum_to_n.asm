section .text
global sum_to_n
sum_to_n:
	mov rax, rdi	; rax is used as the total (and will be returned from func)
	mov rdx, rax	; rdx is the next increment; set the next increment equal to the arg n
	jmp compare

compare:
	cmp rdx, 0	; compare the next increment to zero
	jnz sum_it_up	; if not zero, make money moves
	ret 	; otherwise return, we done

sum_it_up:
	sub rdx, 1	; subtract one from our increment to form next increment
	add rax, rdx	; increment total
	jmp compare	; iterate