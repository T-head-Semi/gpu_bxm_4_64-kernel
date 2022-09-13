# NOTE: Assertions have been autogenerated by utils/update_mca_test_checks.py
# RUN: llvm-mca -mtriple=x86_64-unknown-unknown -mcpu=bdver2 -iterations=100 -timeline -timeline-max-iterations=1 -noalias=false < %s | FileCheck %s

vmovaps (%rsi), %xmm0
vmovaps %xmm0, (%rdi)
vmovaps 16(%rsi), %xmm0
vmovaps %xmm0, 16(%rdi)
vmovaps 32(%rsi), %xmm0
vmovaps %xmm0, 32(%rdi)
vmovaps 48(%rsi), %xmm0
vmovaps %xmm0, 48(%rdi)

# CHECK:      Iterations:        100
# CHECK-NEXT: Instructions:      800
# CHECK-NEXT: Total Cycles:      2403
# CHECK-NEXT: Total uOps:        800

# CHECK:      Dispatch Width:    4
# CHECK-NEXT: uOps Per Cycle:    0.33
# CHECK-NEXT: IPC:               0.33
# CHECK-NEXT: Block RThroughput: 8.0

# CHECK:      Instruction Info:
# CHECK-NEXT: [1]: #uOps
# CHECK-NEXT: [2]: Latency
# CHECK-NEXT: [3]: RThroughput
# CHECK-NEXT: [4]: MayLoad
# CHECK-NEXT: [5]: MayStore
# CHECK-NEXT: [6]: HasSideEffects (U)

# CHECK:      [1]    [2]    [3]    [4]    [5]    [6]    Instructions:
# CHECK-NEXT:  1      5     1.50    *                   vmovaps	(%rsi), %xmm0
# CHECK-NEXT:  1      1     1.50           *            vmovaps	%xmm0, (%rdi)
# CHECK-NEXT:  1      5     1.50    *                   vmovaps	16(%rsi), %xmm0
# CHECK-NEXT:  1      1     1.50           *            vmovaps	%xmm0, 16(%rdi)
# CHECK-NEXT:  1      5     1.50    *                   vmovaps	32(%rsi), %xmm0
# CHECK-NEXT:  1      1     1.50           *            vmovaps	%xmm0, 32(%rdi)
# CHECK-NEXT:  1      5     1.50    *                   vmovaps	48(%rsi), %xmm0
# CHECK-NEXT:  1      1     1.50           *            vmovaps	%xmm0, 48(%rdi)

# CHECK:      Resources:
# CHECK-NEXT: [0.0] - PdAGLU01
# CHECK-NEXT: [0.1] - PdAGLU01
# CHECK-NEXT: [1]   - PdBranch
# CHECK-NEXT: [2]   - PdCount
# CHECK-NEXT: [3]   - PdDiv
# CHECK-NEXT: [4]   - PdEX0
# CHECK-NEXT: [5]   - PdEX1
# CHECK-NEXT: [6]   - PdFPCVT
# CHECK-NEXT: [7.0] - PdFPFMA
# CHECK-NEXT: [7.1] - PdFPFMA
# CHECK-NEXT: [8.0] - PdFPMAL
# CHECK-NEXT: [8.1] - PdFPMAL
# CHECK-NEXT: [9]   - PdFPMMA
# CHECK-NEXT: [10]  - PdFPSTO
# CHECK-NEXT: [11]  - PdFPU0
# CHECK-NEXT: [12]  - PdFPU1
# CHECK-NEXT: [13]  - PdFPU2
# CHECK-NEXT: [14]  - PdFPU3
# CHECK-NEXT: [15]  - PdFPXBR
# CHECK-NEXT: [16.0] - PdLoad
# CHECK-NEXT: [16.1] - PdLoad
# CHECK-NEXT: [17]  - PdMul
# CHECK-NEXT: [18]  - PdStore

# CHECK:      Resource pressure per iteration:
# CHECK-NEXT: [0.0]  [0.1]  [1]    [2]    [3]    [4]    [5]    [6]    [7.0]  [7.1]  [8.0]  [8.1]  [9]    [10]   [11]   [12]   [13]   [14]   [15]   [16.0] [16.1] [17]   [18]
# CHECK-NEXT: 4.00   12.00   -      -      -      -      -      -     6.00   6.00    -      -      -     4.00   2.00   2.00   6.00   6.00    -     6.00   6.00    -     4.00

# CHECK:      Resource pressure by instruction:
# CHECK-NEXT: [0.0]  [0.1]  [1]    [2]    [3]    [4]    [5]    [6]    [7.0]  [7.1]  [8.0]  [8.1]  [9]    [10]   [11]   [12]   [13]   [14]   [15]   [16.0] [16.1] [17]   [18]   Instructions:
# CHECK-NEXT:  -     3.00    -      -      -      -      -      -      -     3.00    -      -      -      -      -     1.00    -      -      -      -     3.00    -      -     vmovaps	(%rsi), %xmm0
# CHECK-NEXT: 1.00    -      -      -      -      -      -      -      -      -      -      -      -     1.00    -      -      -     3.00    -      -      -      -     1.00   vmovaps	%xmm0, (%rdi)
# CHECK-NEXT:  -     3.00    -      -      -      -      -      -     3.00    -      -      -      -      -     1.00    -      -      -      -     3.00    -      -      -     vmovaps	16(%rsi), %xmm0
# CHECK-NEXT: 1.00    -      -      -      -      -      -      -      -      -      -      -      -     1.00    -      -     3.00    -      -      -      -      -     1.00   vmovaps	%xmm0, 16(%rdi)
# CHECK-NEXT:  -     3.00    -      -      -      -      -      -      -     3.00    -      -      -      -      -     1.00    -      -      -      -     3.00    -      -     vmovaps	32(%rsi), %xmm0
# CHECK-NEXT: 1.00    -      -      -      -      -      -      -      -      -      -      -      -     1.00    -      -      -     3.00    -      -      -      -     1.00   vmovaps	%xmm0, 32(%rdi)
# CHECK-NEXT:  -     3.00    -      -      -      -      -      -     3.00    -      -      -      -      -     1.00    -      -      -      -     3.00    -      -      -     vmovaps	48(%rsi), %xmm0
# CHECK-NEXT: 1.00    -      -      -      -      -      -      -      -      -      -      -      -     1.00    -      -     3.00    -      -      -      -      -     1.00   vmovaps	%xmm0, 48(%rdi)

# CHECK:      Timeline view:
# CHECK-NEXT:                     0123456789
# CHECK-NEXT: Index     0123456789          0123456

# CHECK:      [0,0]     DeeeeeER  .    .    .    ..   vmovaps	(%rsi), %xmm0
# CHECK-NEXT: [0,1]     D=====eER .    .    .    ..   vmovaps	%xmm0, (%rdi)
# CHECK-NEXT: [0,2]     D======eeeeeER .    .    ..   vmovaps	16(%rsi), %xmm0
# CHECK-NEXT: [0,3]     D===========eER.    .    ..   vmovaps	%xmm0, 16(%rdi)
# CHECK-NEXT: [0,4]     .D===========eeeeeER.    ..   vmovaps	32(%rsi), %xmm0
# CHECK-NEXT: [0,5]     .D================eER    ..   vmovaps	%xmm0, 32(%rdi)
# CHECK-NEXT: [0,6]     .D=================eeeeeER.   vmovaps	48(%rsi), %xmm0
# CHECK-NEXT: [0,7]     .D======================eER   vmovaps	%xmm0, 48(%rdi)

# CHECK:      Average Wait times (based on the timeline view):
# CHECK-NEXT: [0]: Executions
# CHECK-NEXT: [1]: Average time spent waiting in a scheduler's queue
# CHECK-NEXT: [2]: Average time spent waiting in a scheduler's queue while ready
# CHECK-NEXT: [3]: Average time elapsed from WB until retire stage

# CHECK:            [0]    [1]    [2]    [3]
# CHECK-NEXT: 0.     1     1.0    1.0    0.0       vmovaps	(%rsi), %xmm0
# CHECK-NEXT: 1.     1     6.0    0.0    0.0       vmovaps	%xmm0, (%rdi)
# CHECK-NEXT: 2.     1     7.0    0.0    0.0       vmovaps	16(%rsi), %xmm0
# CHECK-NEXT: 3.     1     12.0   0.0    0.0       vmovaps	%xmm0, 16(%rdi)
# CHECK-NEXT: 4.     1     12.0   0.0    0.0       vmovaps	32(%rsi), %xmm0
# CHECK-NEXT: 5.     1     17.0   0.0    0.0       vmovaps	%xmm0, 32(%rdi)
# CHECK-NEXT: 6.     1     18.0   0.0    0.0       vmovaps	48(%rsi), %xmm0
# CHECK-NEXT: 7.     1     23.0   0.0    0.0       vmovaps	%xmm0, 48(%rdi)
