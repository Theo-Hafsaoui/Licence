	.file	"testgcc.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$2, -16(%rbp)
	movl	$1, -8(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L2
.L3:
	addl	$1, -16(%rbp)
	addl	$1, -12(%rbp)
.L2:
	cmpl	$9, -12(%rbp)
	jle	.L3
	addl	$1, -16(%rbp)
	movl	-16(%rbp), %eax
	addl	%eax, -8(%rbp)
	movl	-16(%rbp), %edx
	movl	-8(%rbp), %eax
	leal	(%rdx,%rax), %ecx
	movl	-16(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	movl	%ecx, %edx
	imull	%eax, %edx
	movl	-16(%rbp), %eax
	subl	-8(%rbp), %eax
	movl	%eax, %ecx
	movl	-16(%rbp), %eax
	subl	-8(%rbp), %eax
	imull	%eax, %ecx
	movl	-16(%rbp), %eax
	subl	-8(%rbp), %eax
	imull	%ecx, %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
