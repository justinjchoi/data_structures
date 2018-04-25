	.text
	.intel_syntax noprefix
	.file	"Circle.cpp"
	.globl	_ZN6CircleC2Ev
	.align	16, 0x90
	.type	_ZN6CircleC2Ev,@function
_ZN6CircleC2Ev:                         # @_ZN6CircleC2Ev
	.cfi_startproc
# BB#0:
	mov	qword ptr [rsp - 8], rdi
	mov	rdi, qword ptr [rsp - 8]
	mov	dword ptr [rdi], 2
	ret
.Lfunc_end0:
	.size	_ZN6CircleC2Ev, .Lfunc_end0-_ZN6CircleC2Ev
	.cfi_endproc

	.globl	_ZN6Circle9getRadiusEv
	.align	16, 0x90
	.type	_ZN6Circle9getRadiusEv,@function
_ZN6Circle9getRadiusEv:                 # @_ZN6Circle9getRadiusEv
	.cfi_startproc
# BB#0:
	mov	qword ptr [rsp - 8], rdi
	mov	rdi, qword ptr [rsp - 8]
	mov	eax, dword ptr [rdi]
	ret
.Lfunc_end1:
	.size	_ZN6Circle9getRadiusEv, .Lfunc_end1-_ZN6Circle9getRadiusEv
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	sub	rsp, 24
.Ltmp0:
	.cfi_def_cfa_offset 32
	lea	rdi, [rsp + 16]
	call	_ZN6CircleC1Ev
	lea	rdi, [rsp + 16]
	call	_ZN6Circle9getRadiusEv
	xor	ecx, ecx
	mov	dword ptr [rsp + 12], eax
	mov	eax, ecx
	add	rsp, 24
	ret
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc


	.globl	_ZN6CircleC1Ev
	.type	_ZN6CircleC1Ev,@function
_ZN6CircleC1Ev = _ZN6CircleC2Ev
	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
