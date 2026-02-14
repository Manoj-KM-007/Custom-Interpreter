# Custom Interpreter V0.2.0
This Repo provides the code to implement an interpreter written from scratch in c. (No name yet).  
This version is the superset of v0.1.0 with better and more features.

# What's Already There ?
* Data Types (Number,String,Boolean,None)
* Arithmetic Operations (+,-,*,/,^,%)
* Boolean Operations (and,or,not)
* Variables and Constants  (using const)
* Comparators (==,!=,>,<,>=,<=)
* IO operations using input() , print()
* Type conversion using int()
* Conditional Statements (if/elif/else)
* While loops
* Comments with #
* Indentation-Based Syntax
* Basic Error Messages

# What's New ?
* Organised Project Structure (From single-c file in v0.1.0 to scripts,include,build and Makefile in v0.2.0)
* Functions (Supports Parameters and Return , no Recursion .. yet)
* Stronger Error Indication
* New Built-in Functions str() and bool() for type conversion

# Installation Guide
Download the files from the repo and use the Makefile to compile. After compilation , create a build folder with:
```
md build
```
Check if the exe file exists with:
```
./interpret --version
```
To interpret and run a file in current directory,  run:
```
./interpret "filename.app"
```
# Guide On New Features
* Function Declaration
  ```
  fn add(a,b):
    return a+b
  ```
  use the 'fn' keyword to create a function
* Function Call
  ```
  const ans = add(1,2) # use function name followed by arguments
  ``
* str() and bool() type conversion
  ```
  const a = str(0) # '0'
  const b = str(True) # 'True' 
  const c = bool(100) # True
  const d = bool(0) # False
  ```

# Future Plans
* Write Recursion Logic
* Provide Exception Handling
* Write an Import system
* Write a Standard Library
* Write a Garbage Collector

# Author
-- Manoj K M
-- Written With C and Curiosity

