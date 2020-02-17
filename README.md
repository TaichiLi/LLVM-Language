# LLVM-Language

<figure class="third">

<a href="https://github.com/TaichiLi/LLVM-Language">
    <img src="https://img.shields.io/badge/Build-Passed-success.svg"/>
</a>

<a href="https://github.com/TaichiLi/LLVM-Language">
    <img src="https://img.shields.io/badge/LLVM-9.0.0-important.svg"/>
</a>

<a href="https://github.com/TaichiLi/LLVM-Language">
    <img src="https://img.shields.io/badge/Clang-9.0.0-critical.svg"/>
</a>

</figure>

## Introduction

A new language and a compiler with LLVM, follow the tutorial “My First Language Frontend with LLVM”.

## Environment

### LLVM

```
llvm version 9.0.0 (tags/RELEASE_900/final)
Target: x86_64-w64-windows-gnu
Thread model: posix
```

### Clang

```
clang version 9.0.0 (tags/RELEASE_900/final)
Target: x86_64-w64-windows-gnu
Thread model: posix
```

## Build

### v1.0

#### Windows(Powershell)

```
clang++ -g -O3 Lexer.cpp Parser.cpp Handler.cpp main.cpp $($(llvm-config --cxxflags).split()) -o toy.exe
```
#### Linux

```
clang++ -g -O3 Lexer.cpp Parser.cpp Handler.cpp main.cpp `llvm-config --cxxflags` -o toy.exe
```

### v2.0

#### Windows(Powershell)

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp main.cpp $($(llvm-config --cxxflags --ldflags --system-libs --libs core).split()) -lpthread -o toy.exe
```
#### Linux

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp main.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -lpthread -o toy.exe
```

### v3.0

#### Windows(Powershell)

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp main.cpp $($(llvm-config --cxxflags --ldflags --system-libs --libs core mcjit native orcjit).split()) -lpthread -o toy.exe
```
#### Linux

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp main.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core mcjit native orcjit` -std=c++14 -lpthread -o toy.exe
```

__Note:__ 

1.  If you get `error: 'make_unique' is not a member of 'std'`, you can add build option `-std=c++14`,  `-std=c++17` or `-std=c++2a`.
   
2.  If you get 
    ```
    D:/LLVM/lib/libLLVMOrcJIT.a(Core.cpp.obj): duplicate section `.rdata$_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag[_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag]' has different size
    D:/LLVM/lib/libLLVMOrcJIT.a(Legacy.cpp.obj): duplicate section `.rdata$_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag[_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag]' has different size
    D:/LLVM/lib/libLLVMDebugInfoDWARF.a(DWARFContext.cpp.obj): duplicate section `.rdata$_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag[_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag]' has different size
    D:/LLVM/lib/libLLVMRuntimeDyld.a(RuntimeDyld.cpp.obj): duplicate section `.rdata$_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag[_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag]' has different size
    D:/LLVM/lib/libLLVMBitstreamReader.a(BitstreamReader.cpp.obj): duplicate section `.rdata$_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag[_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag]' has different size
    D:/LLVM/lib/libLLVMCore.a(DiagnosticHandler.cpp.obj): duplicate section `.rdata$_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag[_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag]' has different size
    D:/LLVM/lib/libLLVMSupport.a(BinaryStreamRef.cpp.obj): duplicate section `.rdata$_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag [_ZZNSt19_Sp_make_shared_tag5_S_tiEvE5__tag]' has different size
    ```
    you can try to change `clang++` with `g++`. The error seems like ABI incompatibility according to this [link](https://groups.google.com/forum/#!topic/llvm-dev/8Tcz49kTNCw), And fixed in 2019-03-06 according to [link](https://bugs.llvm.org/show_bug.cgi?id=35978). In llvm 8.0, this bug has been fixed. Both `clang++` and `g++` work fine. But I still have this error in `LLVM-9.0.0`, so if you have the error too, try the method above.

3.  If you get
    ```
    C:\Users\admin\AppData\Local\Temp\ccPL4pEz.o:D:/LLVM/include/llvm/ExecutionEngine/Orc/IRCompileLayer.h:93: undefined reference to `llvm::orc::SimpleCompiler::operator()(llvm::Module&)'
    C:\Users\admin\AppData\Local\Temp\ccPL4pEz.o: In function `llvm::orc::LegacyRTDyldObjectLinkingLayer::ConcreteLinkedObject<std::shared_ptr<llvm::RuntimeDyld::MemoryManager> >::finalize()':
    D:/LLVM/include/llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h:235: undefined reference to `llvm::orc::JITSymbolResolverAdapter::JITSymbolResolverAdapter(llvm::orc::ExecutionSession&, llvm::orc::SymbolResolver&, llvm::orc::MaterializationResponsibility*)'
    C:\Users\admin\AppData\Local\Temp\ccPL4pEz.o:D:/LLVM/include/llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h:235: undefined reference to `llvm::orc::JITSymbolResolverAdapter::JITSymbolResolverAdapter(llvm::orc::ExecutionSession&, llvm::orc::SymbolResolver&, llvm::orc::MaterializationResponsibility*)'
    C:\Users\admin\AppData\Local\Temp\ccPL4pEz.o:Handler.cpp:(.rdata$.refptr._ZTVN4llvm3orc24JITSymbolResolverAdapterE[.refptr._ZTVN4llvm3orc24JITSymbolResolverAdapterE]+0x0): undefined reference to `vtable for llvm::orc::JITSymbolResolverAdapter'
    C:\Users\admin\AppData\Local\Temp\ccpm0DJF.o: In function `llvm::orc::KaleidoscopeJIT::KaleidoscopeJIT()':
    G:\C_C++\LLVMexamples\Kaleidoscope\toy2/KaleidoscopeJIT.h:57: undefined reference to `llvm::orc::ExecutionSession::ExecutionSession(std::shared_ptr<llvm::orc::SymbolStringPool>)'
    C:\Users\admin\AppData\Local\Temp\ccpm0DJF.o: In function `llvm::DenseSet<llvm::orc::SymbolStringPtr, llvm::DenseMapInfo<llvm::DenseSet> > llvm::orc::lookupWithLegacyFn<llvm::orc::KaleidoscopeJIT::KaleidoscopeJIT()::{lambda(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)#1}>(llvm::orc::ExecutionSession&, llvm::orc::AsynchronousSymbolQuery&, llvm::DenseMapInfo<llvm::DenseSet> const&, llvm::orc::KaleidoscopeJIT::KaleidoscopeJIT()::{lambda(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)#1})':
    D:/LLVM/include/llvm/ExecutionEngine/Orc/Legacy.h:151: undefined reference to `llvm::orc::AsynchronousSymbolQuery::notifySymbolMetRequiredState(llvm::orc::SymbolStringPtr const&, llvm::JITEvaluatedSymbol)'
    D:/LLVM/include/llvm/ExecutionEngine/Orc/Legacy.h:166: undefined reference to `llvm::orc::AsynchronousSymbolQuery::handleComplete()'
    D:/LLVM/include/llvm/ExecutionEngine/Orc/Legacy.h:159: undefined reference to `llvm::orc::ExecutionSession::legacyFailQuery(llvm::orc::AsynchronousSymbolQuery&, llvm::Error)'
    C:\Users\admin\AppData\Local\Temp\ccpm0DJF.o:main.cpp:(.rdata$_ZTVN4llvm3orc22LegacyLookupFnResolverIZNS0_15KaleidoscopeJITC4EvEUlRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE_EE[_ZTVN4llvm3orc22LegacyLookupFnResolverIZNS0_15KaleidoscopeJITC4EvEUlRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEE_EE]+0x30): undefined reference to `llvm::orc::SymbolResolver::anchor()'
    collect2.exe: error: ld returned 1 exit status
    ```
    you can see the [answer](https://stackoverflow.com/questions/59561710/llvm-kaleidoscope-tutorial-jit-compilation-problem) on stackoverflow, and add `llvm-config` option `orcjit`.

### v4.0

#### Windows(Powershell)

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp main.cpp $($(llvm-config --cxxflags --ldflags --system-libs --libs core mcjit native orcjit).split()) -lpthread -o toy.exe
```
#### Linux

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp main.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core mcjit native orcjit` -std=c++14 -lpthread -o toy.exe
```

### v5.0

#### Windows(Powershell)

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp AST.cpp main.cpp $($(llvm-config --cxxflags --ldflags --system-libs --libs core mcjit native orcjit).split()) -lpthread -o toy.exe
```
#### Linux

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp AST.cpp main.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core mcjit native orcjit` -std=c++14 -lpthread -o toy.exe
```

### v6.0

#### Windows(Powershell)

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp AST.cpp main.cpp $($(llvm-config --cxxflags --ldflags --system-libs --libs core mcjit native orcjit).split()) -lpthread -o toy.exe
```
#### Linux

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp AST.cpp main.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core mcjit native orcjit` -std=c++14 -lpthread -o toy.exe
```

## Change Log

### v1.0 (2020-02-15)

Support for recursive descent parsing and operator precedence parsing.

### v2.0 (2020-02-16)

Support for generating LLVM IR.

### v3.0 (2020-02-16)

Add JIT support.

### v4.0 (2020-02-16)

Add control flow operations (‘if’ statement and a ‘for’ loop) support.

### v5.0 (2020-02-17)

Support for users define arbitrary unary and binary operators.

Add `AST.cpp`, and adjust project file structure.

### v6.0 (2020-02-17)

Support for user-defined local variables.

## Contributors

- [My First Language Frontend with LLVM Tutorial](http://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html)
- [@Li Taiji](https://github.com/TaichiLi)