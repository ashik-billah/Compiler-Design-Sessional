
#include <bits/stdc++.h>
using namespace std;

struct Symbol {
    string name, idType, dataType, scope, value;
};

vector<Symbol> symbolTable;

void insert(string name, string idType, string dataType, string scope, string value) {
    Symbol sym = {name, idType, dataType, scope, value};
    symbolTable.push_back(sym);
}

void display() {
    cout << "Symbol Table:" << endl;
    cout << "Name\tType\tDataType\tScope\tValue" << endl;
    for (auto &sym : symbolTable) {
        cout << sym.name << "\t" << sym.idType << "\t" << sym.dataType
             << "\t\t" << sym.scope << "\t" << sym.value << endl;
    }
}

void parseCode(string code) {
    istringstream codeStream(code);
    string line;
    string scope = "global";
    regex identifierPattern("(int|float|double|char|void)\\s+([a-zA-Z_][a-zA-Z0-9_]*)");

    while (getline(codeStream, line)) {
        smatch match;

        if (regex_search(line, match, identifierPattern)) {
            string dataType = match[1];
            string name = match[2];

            if (line.find('(') != string::npos && line.find(')') != string::npos) {
                insert(name, "func", dataType, scope, "");
                scope = name;
            } else {
                insert(name, "var", dataType, scope, "");
            }
        }

        if (line.find('}') != string::npos) {
            scope = "global";
        }
    }
}

int main() {
    string code;

    cout << "Enter the code: \n";
    string line;

    while (getline(cin, line))
    {
        code += line + "\n";
    }
    parseCode(code);
    display();

    return 0;
}
