	.file	"test1.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$420, %esp
	leal	-404(%ebp), %edx
	movl	$-4, %eax
	leal	(%edx,%eax), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	scanf
	movl	-408(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	$0, %eax
	addl	$420, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.comm	b,400,32
	.ident	"GCC: (GNU) 4.1.2 20070626 (Red Hat 4.1.2-14)"
	.section	.note.GNU-stack,"",@progbits
