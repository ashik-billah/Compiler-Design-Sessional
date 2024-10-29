#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    return (op == '+' || op == '-') ? 1 : 2;
}

void generateTAC(const string &expr) {
    stack<string> operands;
    stack<char> operators;
    vector<string> tac;
    istringstream iss(expr);
    string token;

    while (iss >> token) {
        if (isOperator(token[0])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token[0])) {
                string op2 = operands.top(); operands.pop();
                string op1 = operands.top(); operands.pop();
                string tempVar = "t" + to_string(tac.size());
                tac.push_back(tempVar + " = " + op1 + " " + operators.top() + " " + op2);
                operands.push(tempVar);
                operators.pop();
            }
            operators.push(token[0]);
        } else {
            operands.push(token);
        }
    }

    while (!operators.empty()) {
        string op2 = operands.top(); operands.pop();
        string op1 = operands.top(); operands.pop();
        string tempVar = "t" + to_string(tac.size());
        tac.push_back(tempVar + " = " + op1 + " " + operators.top() + " " + op2);
        operands.push(tempVar);
        operators.pop();
    }

    for (const auto &line : tac) cout << line << endl;
}

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);
    generateTAC(expression);
    return 0;
}
