# What ?
This repository holds the codebase of a custom interpreter written from scratch in C.

# Why ? 
This interpreter acts as a great educational tool for programming languages and runtime designers.
It can also act as a language that is fast to setup, great for testing your programming ideas quickly since it
has a neat and modern syntax. However it does have bugs and provides lesser features than modern production interpreters
that limit the ability of the user to ideate and work quickly. Iam actively working on solving bugs,expanding features
and to provide libraries.

# How ?
The project uses the classic interpreter architecture with a lexer and a recursive parser that produces an AST (abstract syntax tree).
The AST is then recursively evaluated (tree walker) and executed. Memory is handled by a Pool that holds all allocations from LexerNodes,
ASTnodes,String allocations,Variables,Functions etc. It automatically frees memory on program end ensuring no memory leak occurs. Variables and Functions
are stored in a Hashmap (chains on collisions) for faster lookups during the evaluation of the AST. It also supports Indentation for readability and 
uses a stack for tracking the indentation.

# Setup
-- Clone the Repo Using Git or Download Manually
-- The repo consists of a Makefile which can be run using the command
```
  make
```
-- An executable is now produced , which can be used to run ".app" files. Example - To run a file called "main.app" , run
```
  ./interpret "main.app"
```

# Documentation
This section provides the documentation for all the features supported by this interpreter version. It is advised to go through
the documentation before programming since it has similar syntax to other languages like python that can make it confusing.

## Comments
```python
# Comments Can be Made using a '#'
```

## IO statements
### print()
--- To print contents on the terminal , use the built-in print() function. The print() function takes any number of parameters and prints them 
in the same line with spaces in between with the newline escape sequence.

```python
print("Hello World") # Hello World
print(1 + 2) # 3
print("Pi is",3.1428) # Pi is 3.1428
```

### input()



