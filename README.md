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

## Build

### v1.0

#### Windows(Powershell)

```
clang++ -g -O3 Lexer.cpp Parser.cpp Handler.cpp main.cpp $($(llvm-config --cxxflags).split()) -o toy.exe
```
#### Linux

```
clang++ -g -O3 Lexer.cpp Parser.cpp Handler.cpp main.cpp 'llvm-config --cxxflags' -o toy.exe
```

### v2.0


#### Windows(Powershell)

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp main.cpp $($(llvm-config --cxxflags --ldflags --system-libs --libs core).split()) -lpthread -o toy.exe
```
#### Linux

```
clang++ -g -O3 Lexer.cpp Parser.cpp Logger.cpp Handler.cpp main.cpp 'llvm-config --cxxflags --ldflags --system-libs --libs core' -lpthread -o toy.exe
```

## Change Log

### v1.0 (2020-02-15)

Support for recursive descent parsing and operator precedence parsing.

### v2.0 (2020-02-16)

Support for generating LLVM IR.

## Contributors

- [My First Language Frontend with LLVM Tutorial](http://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html)
- [@Li Taiji](https://github.com/TaichiLi)