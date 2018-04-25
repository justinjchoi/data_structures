	.text
	.intel_syntax noprefix
	.file	"obj.cpp"
	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI0_0:
	.quad	4615063718147915776     # double 3.5
	.section	.rodata.cst4,"aM",@progbits,4
	.align	4
.LCPI0_1:
	.long	1073741824              # float 2
	.text
	.globl	_ZN3objC2Ev
	.align	16, 0x90
	.type	_ZN3objC2Ev,@function
_ZN3objC2Ev:                            # @_ZN3objC2Ev
	.cfi_startproc
# BB#0:
	movsd	xmm0, qword ptr [.LCPI0_0] # xmm0 = mem[0],zero
	movss	xmm1, dword ptr [.LCPI0_1] # xmm1 = mem[0],zero,zero,zero
	mov	qword ptr [rsp - 8], rdi
	mov	rdi, qword ptr [rsp - 8]
	mov	dword ptr [rdi], 1
	mov	byte ptr [rdi + 4], 120
	movss	dword ptr [rdi + 8], xmm1
	movsd	qword ptr [rdi + 16], xmm0
	mov	rdi, qword ptr [rdi + 24]
	mov	byte ptr [rdi], 112
	ret
.Lfunc_end0:
	.size	_ZN3objC2Ev, .Lfunc_end0-_ZN3objC2Ev
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	sub	rsp, 40
.Ltmp0:
	.cfi_def_cfa_offset 48
	lea	rdi, [rsp]
	mov	dword ptr [rsp + 36], 0
	call	_ZN3objC1Ev
	xor	eax, eax
	add	rsp, 40
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc


	.globl	_ZN3objC1Ev
	.type	_ZN3objC1Ev,@function
_ZN3objC1Ev = _ZN3objC2Ev
	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
