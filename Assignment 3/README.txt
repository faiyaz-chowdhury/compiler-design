# CSE 420 - Compiler Design Lab 3: Semantic Analysis
## Student IDs: 22101848_22101069

## Project Overview
This project implements semantic analysis for a C compiler, building upon the previously developed lexical analyzer and syntax analyzer. It performs type checking, type conversion, uniqueness checking, array index validation, and function parameter validation.

## Files Included
1. **22101848_22101069.l** - Lexical analyzer (Flex file)
2. **22101848_22101069.y** - Syntax analyzer with semantic analysis (Bison/Yacc file)
3. **symbol_info.h** - Symbol information class definition
4. **scope_table.h** - Scope table implementation for managing symbol scopes
5. **symbol_table.h** - Symbol table implementation for managing multiple scopes
6. **script.sh** - Bash script to compile and run the analyzer
7. **input.c** - Sample C input file for testing

## Prerequisites
Before running the project, ensure you have the following tools installed:
- **g++** (GNU C++ compiler)
- **flex** (Fast Lexical Analyzer Generator)
- **bison** or **yacc** (Parser generator)

### Installation on Ubuntu/Debian:
```bash
sudo apt-get update
sudo apt-get install -y bison flex g++
```

### Installation on macOS:
```bash
brew install bison flex gcc
```

### Installation on Windows (using WSL):
```bash
sudo apt-get update
sudo apt-get install -y bison flex g++
```

## Compilation and Execution

### Method 1: Using the provided script (Recommended)
```bash
# Make the script executable
chmod +x script.sh

# Run the script
./script.sh
```

### Method 2: Manual compilation
```bash
# Step 1: Generate parser files from yacc/bison file
yacc -d -y --debug --verbose 22101848_22101069.y

# Step 2: Compile the parser
g++ -w -c -o y.o y.tab.c

# Step 3: Generate scanner from flex file
flex 22101848_22101069.l

# Step 4: Compile the scanner
g++ -fpermissive -w -c -o l.o lex.yy.c

# Step 5: Link object files to create executable
g++ y.o l.o -o a.out

# Step 6: Run the analyzer on an input file
./a.out input.c
```

## Output Files
After execution, two output files will be generated:
1. **22101848_22101069_log.txt** - Contains:
   - Grammar rules matched
   - Corresponding source code segments
   - Symbol table contents
   - Total line count
   - Total error count

2. **22101848_22101069_error.txt** - Contains:
   - All error and warning messages
   - Total error count

## Semantic Analysis Features Implemented

### 1. Type Checking
- **Assignment Type Consistency**: Checks if operands of assignment operators are type-compatible
- **Array Index Type**: Validates that array indices are integers
- **Modulus Operator**: Ensures both operands of modulus (%) are integers
- **Division by Zero**: Detects division or modulus by zero
- **Function Call Validation**: 
  - Verifies correct number of arguments
  - Checks argument type consistency with function definition
- **Void Function Check**: Prevents void functions from being used in expressions

### 2. Type Conversion
- **Float to Int Assignment**: Generates warning when assigning float to int variable
- **Boolean Results**: RELOP and LOGICOP operations always return integer type

### 3. Uniqueness Checking
- **Undeclared Variables**: Reports when variables are used without declaration
- **Multiple Declarations**: Detects multiple declarations in the same scope
- **Function Redeclaration**: Prevents multiple function definitions

### 4. Array Handling
- **Array with Index**: Ensures arrays are used with indices
- **Non-array with Index**: Reports error when non-array variables are indexed
- **Index Type Validation**: Checks that array indices are integers

### 5. Function Parameter Validation
- **Parameter Count**: Verifies correct number of parameters in function calls
- **Parameter Type Matching**: Checks type consistency between arguments and parameters
- **Non-function Call**: Detects when non-function identifiers are called as functions

## Error Messages
The semantic analyzer detects and reports the following errors:

1. `Undeclared variable <name>`
2. `Variable already declared: <name>`
3. `Multiple declaration of function <name>`
4. `Variable declared with void type`
5. `Array used without index: <name>`
6. `Non-array variable used with index: <name>`
7. `Array index must be integer type`
8. `Type mismatch in assignment`
9. `Warning: Assigning float to int may lose precision`
10. `Void function used in expression`
11. `Modulus operator requires integer operands`
12. `Division or modulus by zero`
13. `Undeclared function <name>`
14. `<name> is not a function`
15. `Incorrect number of arguments for function <name>`
16. `Type mismatch for argument <n> of function <name>`
17. `Multiple declaration of parameter <name> in a parameter of <function>`

## Sample Input File (input.c)
```c
int func() {
    int a;
    if (a>1){
        float a;
        if (a>1) {
            int a;
             if (a>1) {
                float a;
                if (a>1) {
                    int a;
                    if (a>1) {
                        float a;
                    }
                }
             }
        }
    }
}
```

## Testing Your Own Code
To test with your own C source file:
```bash
./a.out your_input_file.c
```

The analyzer will generate:
- `22101848_22101069_log.txt` with complete analysis
- `22101848_22101069_error.txt` with error summary

## Cleaning Up
To remove all generated files:
```bash
rm -f y.tab.c y.tab.h y.output lex.yy.c y.o l.o a.out 22101848_22101069_log.txt 22101848_22101069_error.txt
```

## Symbol Table Structure
The symbol table uses a hierarchical scope management system:
- **Global Scope**: Outermost scope (ID: 1)
- **Function Scopes**: New scope for each function definition
- **Block Scopes**: New scope for each compound statement (code block)

### Hash Table Configuration
- Default bucket count: 10
- Hash function: Prime number (31) based polynomial rolling hash
- Collision resolution: Separate chaining using linked lists

## Project Structure
```
22101848_22101069/
├── 22101848_22101069.l          # Lexical analyzer
├── 22101848_22101069.y          # Syntax & semantic analyzer
├── symbol_info.h                # Symbol information class
├── scope_table.h                # Scope table class
├── symbol_table.h               # Symbol table class
├── script.sh                    # Compilation script
├── input.c                      # Sample input file
└── README.txt                   # This file
```

## Implementation Details

### Symbol Information
Each symbol stores:
- Name and type
- Data type (int, float, void)
- Array information (size if array)
- Function information (return type, parameters)
- Operational flags

### Scope Management
- New scope created on entering compound statements
- Function parameters inserted into function scope
- Scopes properly nested and destroyed

### Error Recovery
The analyzer:
- Continues parsing after errors
- Reports all errors found
- Maintains error count
- Does not halt on first error

## Common Issues and Solutions

### Issue 1: "yacc: command not found"
**Solution**: Install bison
```bash
sudo apt-get install bison
```

### Issue 2: "flex: command not found"
**Solution**: Install flex
```bash
sudo apt-get install flex
```

### Issue 3: "g++: command not found"
**Solution**: Install g++
```bash
sudo apt-get install g++
```

### Issue 4: Permission denied when running script
**Solution**: Make script executable
```bash
chmod +x script.sh
```

### Issue 5: Cannot find header files
**Solution**: Ensure all .h files are in the same directory as .l and .y files

## Notes
- The analyzer performs comprehensive error checking but does not generate intermediate code
- All semantic errors are logged in both log and error files
- Line numbers are tracked and reported for all errors
- The symbol table is printed at the end of parsing
- Memory is properly managed with destructors for all dynamic allocations

## Author Information
- Student IDs: 22101848, 22101069
- Course: CSE 420 - Compiler Design
- Semester: Spring 2024
- Institution: BRAC University

## Submission Checklist
✓ Lexical analyzer file (22101848_22101069.l)
✓ Syntax analyzer file (22101848_22101069.y)
✓ Symbol information header (symbol_info.h)
✓ Scope table header (scope_table.h)
✓ Symbol table header (symbol_table.h)
✓ Compilation script (script.sh)
✓ Sample input file (input.c)
✓ README file with instructions

## Important Reminders
1. DO NOT include generated files (.tab.c, .tab.h, .yy.c, .o, executables) in submission
2. DO NOT include output files (log.txt, error.txt) in submission
3. Ensure all files follow the naming convention: 22101848_22101069.*
4. Test thoroughly with various input files before submission
5. Compress folder as .zip file named 22101848_22101069.zip

---
End of README
