//===- llvm-build generated file --------------------------------*- C++ -*-===//
//
// Component Library Dependency Table
//
// Automatically generated file, do not edit!
//
//===----------------------------------------------------------------------===//

struct AvailableComponent {
  /// The name of the component.
  const char *Name;

  /// The name of the library for this component (or NULL).
  const char *Library;

  /// Whether the component is installed.
  bool IsInstalled;

  /// The list of libraries required when linking this component.
  const char *RequiredLibraries[28];
} AvailableComponents[66] = {
  { "aggressiveinstcombine", "LLVMAggressiveInstCombine", true, { "analysis", "core", "support", "transformutils" } },
  { "all", nullptr, true, { "all-targets", "asmprinter", "coroutines", "coverage", "debuginfogsym", "dlltooldriver", "engine", "fuzzmutate", "globalisel", "gtest_main", "libdriver", "lineeditor", "lto", "mca", "mcdisassembler", "mcjit", "mirparser", "native", "nativecodegen", "objectyaml", "orcjit", "symbolize", "tablegen", "testingsupport", "textapi", "windowsmanifest", "xray" } },
  { "all-targets", nullptr, true, {  } },
  { "analysis", "LLVMAnalysis", true, { "binaryformat", "core", "object", "profiledata", "support" } },
  { "asmparser", "LLVMAsmParser", true, { "binaryformat", "core", "support" } },
  { "asmprinter", "LLVMAsmPrinter", true, { "analysis", "binaryformat", "codegen", "core", "debuginfocodeview", "debuginfodwarf", "debuginfomsf", "mc", "mcparser", "remarks", "support", "target" } },
  { "binaryformat", "LLVMBinaryFormat", true, { "support" } },
  { "bitreader", "LLVMBitReader", true, { "bitstreamreader", "core", "support" } },
  { "bitstreamreader", "LLVMBitstreamReader", true, { "support" } },
  { "bitwriter", "LLVMBitWriter", true, { "analysis", "core", "mc", "object", "support" } },
  { "codegen", "LLVMCodeGen", true, { "analysis", "bitreader", "bitwriter", "core", "mc", "profiledata", "scalaropts", "support", "target", "transformutils" } },
  { "core", "LLVMCore", true, { "binaryformat", "remarks", "support" } },
  { "coroutines", "LLVMCoroutines", true, { "analysis", "core", "ipo", "scalaropts", "support", "transformutils" } },
  { "coverage", "LLVMCoverage", true, { "core", "object", "profiledata", "support" } },
  { "debuginfocodeview", "LLVMDebugInfoCodeView", true, { "support", "debuginfomsf" } },
  { "debuginfodwarf", "LLVMDebugInfoDWARF", true, { "binaryformat", "object", "mc", "support" } },
  { "debuginfogsym", "LLVMDebugInfoGSYM", true, { "support" } },
  { "debuginfomsf", "LLVMDebugInfoMSF", true, { "support" } },
  { "debuginfopdb", "LLVMDebugInfoPDB", true, { "object", "support", "debuginfocodeview", "debuginfomsf" } },
  { "demangle", "LLVMDemangle", true, {  } },
  { "dlltooldriver", "LLVMDlltoolDriver", true, { "object", "option", "support" } },
  { "engine", nullptr, true, { "interpreter" } },
  { "executionengine", "LLVMExecutionEngine", true, { "core", "mc", "object", "runtimedyld", "support", "target" } },
  { "fuzzmutate", "LLVMFuzzMutate", true, { "analysis", "bitreader", "bitwriter", "core", "scalaropts", "support", "target" } },
  { "globalisel", "LLVMGlobalISel", true, { "analysis", "codegen", "core", "mc", "selectiondag", "support", "target", "transformutils" } },
  { "gtest", "gtest", false, { "support" } },
  { "gtest_main", "gtest_main", false, { "gtest" } },
  { "instcombine", "LLVMInstCombine", true, { "analysis", "core", "support", "transformutils" } },
  { "instrumentation", "LLVMInstrumentation", true, { "analysis", "core", "mc", "support", "transformutils", "profiledata" } },
  { "interpreter", "LLVMInterpreter", true, { "codegen", "core", "executionengine", "support" } },
  { "ipo", "LLVMipo", true, { "aggressiveinstcombine", "analysis", "bitreader", "bitwriter", "core", "instcombine", "irreader", "linker", "object", "profiledata", "scalaropts", "support", "transformutils", "vectorize", "instrumentation" } },
  { "irreader", "LLVMIRReader", true, { "asmparser", "bitreader", "core", "support" } },
  { "jitlink", "LLVMJITLink", true, { "binaryformat", "object", "support" } },
  { "libdriver", "LLVMLibDriver", true, { "binaryformat", "bitreader", "object", "option", "support" } },
  { "lineeditor", "LLVMLineEditor", true, { "support" } },
  { "linker", "LLVMLinker", true, { "core", "support", "transformutils" } },
  { "lto", "LLVMLTO", true, { "aggressiveinstcombine", "analysis", "bitreader", "bitwriter", "codegen", "core", "ipo", "instcombine", "linker", "mc", "objcarcopts", "object", "passes", "remarks", "scalaropts", "support", "target", "transformutils" } },
  { "mc", "LLVMMC", true, { "support", "binaryformat", "debuginfocodeview" } },
  { "mca", "LLVMMCA", true, { "mc", "support" } },
  { "mcdisassembler", "LLVMMCDisassembler", true, { "mc", "support" } },
  { "mcjit", "LLVMMCJIT", true, { "core", "executionengine", "object", "runtimedyld", "support", "target" } },
  { "mcparser", "LLVMMCParser", true, { "mc", "support" } },
  { "mirparser", "LLVMMIRParser", true, { "asmparser", "binaryformat", "codegen", "core", "mc", "support", "target" } },
  { "native", nullptr, true, {  } },
  { "nativecodegen", nullptr, true, {  } },
  { "objcarcopts", "LLVMObjCARCOpts", true, { "analysis", "core", "support", "transformutils" } },
  { "object", "LLVMObject", true, { "bitreader", "core", "mc", "binaryformat", "mcparser", "support" } },
  { "objectyaml", "LLVMObjectYAML", true, { "object", "support", "debuginfocodeview" } },
  { "option", "LLVMOption", true, { "support" } },
  { "orcjit", "LLVMOrcJIT", true, { "core", "executionengine", "jitlink", "object", "mc", "runtimedyld", "support", "target", "transformutils" } },
  { "passes", "LLVMPasses", true, { "aggressiveinstcombine", "analysis", "codegen", "core", "ipo", "instcombine", "scalaropts", "support", "target", "transformutils", "vectorize", "instrumentation" } },
  { "profiledata", "LLVMProfileData", true, { "core", "support" } },
  { "remarks", "LLVMRemarks", true, { "support" } },
  { "runtimedyld", "LLVMRuntimeDyld", true, { "mc", "object", "support" } },
  { "scalaropts", "LLVMScalarOpts", true, { "aggressiveinstcombine", "analysis", "core", "instcombine", "support", "transformutils" } },
  { "selectiondag", "LLVMSelectionDAG", true, { "analysis", "codegen", "core", "mc", "support", "target", "transformutils" } },
  { "support", "LLVMSupport", true, { "demangle" } },
  { "symbolize", "LLVMSymbolize", true, { "debuginfodwarf", "debuginfopdb", "object", "support", "demangle" } },
  { "tablegen", "LLVMTableGen", true, { "support" } },
  { "target", "LLVMTarget", true, { "analysis", "core", "mc", "support" } },
  { "testingsupport", "LLVMTestingSupport", false, { "support" } },
  { "textapi", "LLVMTextAPI", true, { "support", "binaryformat" } },
  { "transformutils", "LLVMTransformUtils", true, { "analysis", "core", "support" } },
  { "vectorize", "LLVMVectorize", true, { "analysis", "core", "support", "transformutils" } },
  { "windowsmanifest", "LLVMWindowsManifest", true, { "support" } },
  { "xray", "LLVMXRay", true, { "support", "object" } },
};
