#include <iostream>
#include <string>
using namespace std;

bool isNumericConstant(string s) {
    if (s.empty()) return false;

    for (int i = 0; i < s.length(); i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            return false;
        }
    }
    return true;
}

void findOperators(string s) {
    int count = 1;
    bool found = false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' ||
            s[i] == '/' || s[i] == '%' || s[i] == '=') {
            cout << "Operator" << count << ": " << s[i] << endl;
            count++;
            found = true;
        }
    }

    if (!found) {
        cout << "No operator found" << endl;
    }
}

bool isComment(string s) {
    if (s.length() >= 2) {
        if (s[0] == '/' && s[1] == '/') {
            return true;
        }
        if (s[0] == '/' && s[1] == '*') {
            if (s.length() >= 4 && s[s.length() - 2] == '*' && s[s.length() - 1] == '/') {
                return true;
            }
        }
    }
    return false;
}

bool isIdentifier(string s) {
    if (s.empty()) return false;

    if (!((s[0] >= 'A' && s[0] <= 'Z') ||
          (s[0] >= 'a' && s[0] <= 'z') ||
          s[0] == '_')) {
        return false;
    }

    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= '0' && s[i] <= '9') ||
              s[i] == '_')) {
            return false;
        }
    }

    return true;
}

int main() {
    string input;

    cout << "Enter input: ";
    getline(cin, input);

    if (isNumericConstant(input))
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric" << endl;

    findOperators(input);

    if (isComment(input))
        cout << "Comment line" << endl;
    else
        cout << "Not a comment" << endl;

    if (isIdentifier(input))
        cout << "Valid Identifier" << endl;
    else
        cout << "Not an Identifier" << endl;

    return 0;
}
