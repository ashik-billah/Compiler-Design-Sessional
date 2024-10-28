#include <bits/stdc++.h>
using namespace std;

bool isIdentifier(string word) {
    return (word[0] >= 'A' && word[0] <= 'Z') || (word[0] >= 'a' && word[0] <= 'z') || word[0] == '_';
}

bool isSymbol(string word) {
    return word.size() == 1 && (word[0] == '{' || word[0] == '}' || word[0] == '(' ||
                                word[0] == ')' || word[0] == '[' || word[0] == ']' ||
                                word[0] == ';' || word[0] == ',' || word[0] == '.' ||
                                word[0] == ':' || word[0] == '"' || word[0] == '\'');
}

bool isOperator(string word) {
    return word == "=" || word == "+" || word == "-" || word == "*" || word == "/" ||
           word == "%" || word == "<" || word == ">" || word == "!" || word == "&" ||
           word == "|" || word == "^" || word == "~" || word == "?" || word == ":" ||
           word == "<<";
}

bool isKeyword(string word) {
    return word == "break" || word == "char" || word == "continue" || word == "do" ||
           word == "double" || word == "else" || word == "float" || word == "for" ||
           word == "if" || word == "int" || word == "long" || word == "return" ||
           word == "while" || word == "cout" || word == "cin" || word == "endl"|| word=="main";
}

bool isConstant(const string& word) {
    return !word.empty() && all_of(word.begin(), word.end(), ::isdigit);
}


int Tokenizer(const string &code, vector<string> &keywords,
              vector<string> &constants,
              vector<string> &operators,
              vector<string> &symbols,
              vector<string> &identifiers) {
    int tokenCount = 0;
    stringstream ss(code);
    string word;
    set<string> matching;
    while (ss >> word) {
        if (matching.insert(word).second) {
            if (isKeyword(word)) {
                keywords.push_back(word);
            } else if (isOperator(word)) {
                operators.push_back(word);
            } else if (isSymbol(word)) {
                symbols.push_back(word);
            } else if (isIdentifier(word)) {
                identifiers.push_back(word);
            } else if (isConstant(word)) {
                constants.push_back(word);
            }
            tokenCount++;
        }
    }

    return tokenCount;
}

int main() {
    string code;
    cout<<"Enter C++ code (type 'ctrl+Z' to finish):";
    getline(cin, code, '\0');
    vector<string> keywords, constants, operators, symbols, identifiers;
    int tokenCount = Tokenizer(code, keywords, constants, operators, symbols, identifiers);

    cout << "Keywords: ";
    for (const string &word : keywords) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Identifiers: ";
    for (const string &word : identifiers) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Constants: ";
    for (const string &word : constants) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Symbols: ";
    for (const string &word : symbols) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Operators: ";
    for (const string &word : operators) {
        cout << word << " ";
    }
    cout << endl;

    cout << "TokenCount: " << tokenCount << endl;

    return 0;
}
