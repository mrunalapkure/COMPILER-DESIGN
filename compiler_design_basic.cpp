#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

// Function declarations
double expression(const string& expr, size_t& pos);
double term(const string& expr, size_t& pos);
double factor(const string& expr, size_t& pos);

// Skip whitespace
void skipSpaces(const string& expr, size_t& pos) {
    while (pos < expr.size() && isspace(expr[pos])) {
        pos++;
    }
}

// Parse numbers and parentheses
double factor(const string& expr, size_t& pos) {
    skipSpaces(expr, pos);

    if (expr[pos] == '(') {
        pos++; // skip '('
        double result = expression(expr, pos);
        skipSpaces(expr, pos);
        if (expr[pos] != ')') {
            throw runtime_error("Missing closing parenthesis");
        }
        pos++; // skip ')'
        return result;
    }

    // Parse number
    double num = 0;
    bool hasDecimal = false;
    double decimalFactor = 0.1;

    if (!isdigit(expr[pos]) && expr[pos] != '.') {
        throw runtime_error("Expected number or '('");
    }

    while (pos < expr.size() && (isdigit(expr[pos]) || expr[pos] == '.')) {
        if (expr[pos] == '.') {
            hasDecimal = true;
        } else if (!hasDecimal) {
            num = num * 10 + (expr[pos] - '0');
        } else {
            num += (expr[pos] - '0') * decimalFactor;
            decimalFactor *= 0.1;
        }
        pos++;
    }

    return num;
}

// Handle * and /
double term(const string& expr, size_t& pos) {
    double result = factor(expr, pos);
    while (true) {
        skipSpaces(expr, pos);
        if (pos >= expr.size()) break;

        char op = expr[pos];
        if (op != '*' && op != '/') break;

        pos++;
        double next = factor(expr, pos);
        if (op == '*') result *= next;
        else if (op == '/') {
            if (next == 0) throw runtime_error("Division by zero");
            result /= next;
        }
    }
    return result;
}

// Handle + and -
double expression(const string& expr, size_t& pos) {
    double result = term(expr, pos);
    while (true) {
        skipSpaces(expr, pos);
        if (pos >= expr.size()) break;

        char op = expr[pos];
        if (op != '+' && op != '-') break;

        pos++;
        double next = term(expr, pos);
        if (op == '+') result += next;
        else if (op == '-') result -= next;
    }
    return result;
}

// Evaluate input string
double evaluate(const string& expr) {
    size_t pos = 0;
    double result = expression(expr, pos);
    skipSpaces(expr, pos);
    if (pos != expr.size()) throw runtime_error("Unexpected character at end");
    return result;
}

// Main function
int main() {
    string input;
    cout << "Enter arithmetic expression (e.g. 3 + 4 * (2 - 1)):" << endl;
    while (getline(cin, input)) {
        try {
            double result = evaluate(input);
            cout << "Result: " << result << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
        cout << "\nEnter another expression or press Ctrl+C to exit:\n";
    }
    return 0;
}
