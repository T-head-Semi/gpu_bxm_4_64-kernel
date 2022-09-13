; RUN: llc -mtriple=armv7-none-eabi -mattr=-neon,-vfp2d16sp %s -o - | FileCheck %s  -check-prefixes=COMMON,NOVFP
; RUN: llc -mtriple=armv7-none-eabi -mattr=+neon %s -float-abi=hard -o - | FileCheck %s -check-prefixes=COMMON,VFP

; The intent here is to test "X", which says that any operand whatsoever is allowed.
; Using this mechanism, we want to test toggling allocating GPR or SPR registers
; depending on whether the float registers are available. Thus, the mnemonic is
; totally irrelevant here, which is why we use FOO and also comment it out using "@"
; to avoid assembler errors.

; Note that this kind of IR can be generated by a function such as:
;  void f1(float f) {asm volatile ("@FOO $0, $0" : : "X" (f));}

define arm_aapcs_vfpcc void @func(float %f) {
; COMMON-LABEL: func
; NOVFP:        FOO r0, r0
; VFP:          FOO s0, s0
entry:
  call void asm sideeffect "@FOO $0, $0", "X" (float %f) nounwind
  ret void
}