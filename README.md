# COMPILER-DESIGN
This project explains the implementation of a simple compiler-like program in C++ that can parse and evaluate basic arithmetic expressions. It supports addition (+), subtraction (-), multiplication (*), division (/), and parentheses.
Program Features:
--------------------
- Parses and evaluates arithmetic expressions.
- Supports operator precedence.
- Handles nested parentheses.
- Manages whitespace and errors like division by zero or invalid
syntax.
------------------------
Code Explanation:
------------------------
1. **Headers Used:**
 - iostream: For input/output operations.
 - string: To handle string expressions.
 - cctype: For character checks like isdigit, isspace.
 - stdexcept: For throwing runtime errors.
2. **Functions:**
 - skipSpaces: Skips any whitespace in the expression.
 - factor: Parses numbers and parentheses. Supports floating point
numbers.
 - term: Handles '*' and '/' operations. Calls factor.
 - expression: Handles '+' and '-' operations. Calls term.
 - evaluate: Entry point to start evaluating from position 0 and
checks for leftover characters.
 - main: Accepts user input and evaluates it using the above logic.
-----------------------------
Operator Precedence:
-----------------------------
1. Parentheses '()' - Highest
2. Multiplication '*' and Division '/' - Medium
3. Addition '+' and Subtraction '-' - Lowest
---------------------------
Error Handling:
---------------------------
- Missing parentheses
- Invalid characters
- Division by zero
- Extra characters after valid expression
---------------------
Example Input/Output:
Input: 3 + 4 * (2 - 1)
Output: Result: 7
-------------------
Compilation & Run:
-------------------
Save the code in a file called simple_compiler.cpp and compile using:
 g++ -o simple_compiler simple_compiler.cpp
 ./simple_compiler
You can now enter arithmetic expressions, and the program will
output the result.
------------------------
Extensions Possible:
------------------------
- Add support for variables and assignments.
- Add power operator '^'.
- Support more complex expressions or functions like sin(), cos(), etc.
<img width="1920" height="1020" alt="Image" src="https://github.com/user-attachments/assets/f57b1f73-adeb-4038-8c0d-daa92c042636" />
