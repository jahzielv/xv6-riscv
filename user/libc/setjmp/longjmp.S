.global longjmp
.type longjmp,@function
longjmp:
	mov  4(%esp),%edx
	mov  8(%esp),%eax
	test    %eax,%eax
	jnz setup_from_jmpbuf
	inc     %eax

setup_from_jmpbuf:
	mov   (%edx),%ebx
	mov  4(%edx),%esi
	mov  8(%edx),%edi
	mov 12(%edx),%ebp
	mov 16(%edx),%ecx
	mov     %ecx,%esp
	mov 20(%edx),%ecx
	jmp *%ecx

