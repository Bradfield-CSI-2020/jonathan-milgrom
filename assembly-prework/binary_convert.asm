section .text
global binary_convert

; rdi points at the address of the first character of the string

binary_convert:
				xor rdx, rdx				; index = 0 (rdx)
				xor rax, rax				; sum = 0 (rax)
compare:	
				movzx rsi, byte [rdi + rdx]	; c = s[index] (rsi)
				mov r8, rsi 				; i = c; will be used to calculate integer value (r8)
				sub r8, 48 					; subtract ascii of 0 (48), in order to get integer value of c
				cmp rsi, 0					; NUL character is 0
				jnz convert
				ret
convert:
				imul rax, 2					; increase order of magnituted of sum
				add rax, r8					; add newest value to sum
				inc rdx						; index++
				jmp compare

