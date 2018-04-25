	.text
	.intel_syntax noprefix
	.file	"param.cpp"
	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp0:
	.cfi_def_cfa_offset 16
	movabs	rdi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, _ZNSt8ios_base4InitD1Ev
	movabs	rsi, _ZStL8__ioinit
	movabs	rdx, __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rsp + 4], eax # 4-byte Spill
	pop	rax
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc

	.text
	.globl	_Z7swapValPiS_
	.align	16, 0x90
	.type	_Z7swapValPiS_,@function
_Z7swapValPiS_:                         # @_Z7swapValPiS_
	.cfi_startproc
# BB#0:
	mov	qword ptr [rsp - 8], rdi
	mov	qword ptr [rsp - 16], rsi
	mov	rsi, qword ptr [rsp - 8]
	mov	eax, dword ptr [rsi]
	mov	dword ptr [rsp - 20], eax
	mov	rsi, qword ptr [rsp - 16]
	mov	eax, dword ptr [rsi]
	mov	rsi, qword ptr [rsp - 8]
	mov	dword ptr [rsi], eax
	mov	eax, dword ptr [rsp - 20]
	mov	rsi, qword ptr [rsp - 16]
	mov	dword ptr [rsi], eax
	ret
.Lfunc_end1:
	.size	_Z7swapValPiS_, .Lfunc_end1-_Z7swapValPiS_
	.cfi_endproc

	.globl	_Z7swapRefRiS_
	.align	16, 0x90
	.type	_Z7swapRefRiS_,@function
_Z7swapRefRiS_:                         # @_Z7swapRefRiS_
	.cfi_startproc
# BB#0:
	mov	qword ptr [rsp - 8], rdi
	mov	qword ptr [rsp - 16], rsi
	mov	rsi, qword ptr [rsp - 8]
	mov	eax, dword ptr [rsi]
	mov	dword ptr [rsp - 20], eax
	mov	rsi, qword ptr [rsp - 16]
	mov	eax, dword ptr [rsi]
	mov	rsi, qword ptr [rsp - 8]
	mov	dword ptr [rsi], eax
	mov	eax, dword ptr [rsp - 20]
	mov	rsi, qword ptr [rsp - 16]
	mov	dword ptr [rsi], eax
	ret
.Lfunc_end2:
	.size	_Z7swapRefRiS_, .Lfunc_end2-_Z7swapRefRiS_
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	sub	rsp, 40
.Ltmp1:
	.cfi_def_cfa_offset 48
	lea	rdi, [rsp + 28]
	lea	rsi, [rsp + 32]
	mov	dword ptr [rsp + 36], 0
	mov	dword ptr [rsp + 32], 6
	mov	dword ptr [rsp + 28], 7
	call	_Z7swapValPiS_
	movabs	rdi, _ZSt4cout
	mov	esi, dword ptr [rsp + 32]
	call	_ZNSolsEi
	movabs	rsi, .L.str
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	esi, dword ptr [rsp + 28]
	mov	rdi, rax
	call	_ZNSolsEi
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	lea	rdi, [rsp + 32]
	lea	rsi, [rsp + 28]
	mov	qword ptr [rsp + 16], rax # 8-byte Spill
	call	_Z7swapRefRiS_
	movabs	rdi, _ZSt4cout
	mov	esi, dword ptr [rsp + 32]
	call	_ZNSolsEi
	movabs	rsi, .L.str
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mov	esi, dword ptr [rsp + 28]
	mov	rdi, rax
	call	_ZNSolsEi
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	xor	ecx, ecx
	mov	qword ptr [rsp + 8], rax # 8-byte Spill
	mov	eax, ecx
	add	rsp, 40
	ret
.Lfunc_end3:
	.size	main, .Lfunc_end3-main
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.align	16, 0x90
	.type	_GLOBAL__sub_I_param.cpp,@function
_GLOBAL__sub_I_param.cpp:               # @_GLOBAL__sub_I_param.cpp
	.cfi_startproc
# BB#0:
	push	rax
.Ltmp2:
	.cfi_def_cfa_offset 16
	call	__cxx_global_var_init
	pop	rax
	ret
.Lfunc_end4:
	.size	_GLOBAL__sub_I_param.cpp, .Lfunc_end4-_GLOBAL__sub_I_param.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	" "
	.size	.L.str, 2

	.section	.init_array,"aw",@init_array
	.align	8
	.quad	_GLOBAL__sub_I_param.cpp

	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
