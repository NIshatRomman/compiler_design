#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    bool isNumeric = true;

    for (int i = 0; i < input.length(); i++) {
        if (!(input[i] >= '0' && input[i] <= '9')) {
            isNumeric = false;
            break;
        }
    }

    if (isNumeric)
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric" << endl;

    return 0;
}



#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter expression: ";
    cin >> input;

    int count = 1;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
            input[i] == '/' || input[i] == '%' || input[i] == '=') {
            cout << "Operator" << count << ": " << input[i] << endl;
            count++;
        }
    }

    if (count == 1) {
        cout << "No operator found" << endl;
    }

    return 0;
}




#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter comment line: ";
    getline(cin, input);

    if (input[0] == '/' && input[1] == '/') {
        cout << "Single line comment" << endl;
    }
    else if (input[0] == '/' && input[1] == '*') {
        if (input[input.length() - 2] == '*' && input[input.length() - 1] == '/') {
            cout << "Multi line comment" << endl;
        } else {
            cout << "Not a proper comment" << endl;
        }
    }
    else {
        cout << "Not a comment" << endl;
    }

    return 0;
}




#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter identifier: ";
    cin >> input;

    bool valid = true;

    // First character check
    if (!((input[0] >= 'A' && input[0] <= 'Z') ||
          (input[0] >= 'a' && input[0] <= 'z') ||
          input[0] == '_')) {
        valid = false;
    }

    // Remaining character check
    for (int i = 1; i < input.length(); i++) {
        if (!((input[i] >= 'A' && input[i] <= 'Z') ||
              (input[i] >= 'a' && input[i] <= 'z') ||
              (input[i] >= '0' && input[i] <= '9') ||
              input[i] == '_')) {
            valid = false;
            break;
        }
    }

    if (valid)
        cout << "Valid Identifier" << endl;
    else
        cout << "Not an Identifier" << endl;

    return 0;
}