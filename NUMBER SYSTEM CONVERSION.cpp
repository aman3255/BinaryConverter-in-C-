#include <iostream>
#include <vector>

using namespace std;

vector<int> decimalToBinary(int decimal) {
    vector<int> binary;
    
    if (decimal == 0) {
        binary.push_back(0);
    } else {
        while (decimal > 0) {
            int bit = decimal % 2;
            binary.push_back(bit);
            decimal /= 2;
        }
    }
    
    // Reverse the binary vector
    // reverse(binary.begin(), binary.end());
    
    return binary;
}

vector<int> hexadecimalToBinary(string hexadecimal) {
    vector<int> binary;
    
    for (char c : hexadecimal) {
        int value;
        if (isdigit(c)) {
            value = c - '0';
        } else {
            value = toupper(c) - 'A' + 10;
        }
        
        for (int i = 3; i >= 0; i--) {
            int bit = (value >> i) & 1;
            binary.push_back(bit);
        }
    }
    
    return binary;
}

vector<int> octalToBinary(int octal) {
    vector<int> binary;
    
    while (octal > 0) {
        int digit = octal % 10;
        for (int i = 2; i >= 0; i--) {
            int bit = (digit >> i) & 1;
            binary.push_back(bit);
        }
        octal /= 10;
    }
    
    // Reverse the binary vector
    // reverse(binary.begin(), binary.end());
    
    return binary;
}

int main() {
    int decimal;
    string hexadecimal;
    int octal;
    int option;
    
    cout << "Conversion Options:" << endl;
    cout << "1. Decimal to Binary" << endl;
    cout << "2. Hexadecimal to Binary" << endl;
    cout << "3. Octal to Binary" << endl;
    cout << "Enter your choice: ";
    cin >> option;
    
    switch (option) {
        case 1:
            cout << "Enter a decimal number: ";
            cin >> decimal;
            {
                vector<int> binary = decimalToBinary(decimal);
                cout << "Binary representation: ";
                for (int bit : binary) {
                    cout << bit;
                }
                cout << endl;
            }
            break;
        case 2:
            cout << "Enter a hexadecimal number: ";
            cin >> hexadecimal;
            {
                vector<int> binary = hexadecimalToBinary(hexadecimal);
                cout << "Binary representation: ";
                for (int bit : binary) {
                    cout << bit;
                }
                cout << endl;
            }
            break;
        case 3:
            cout << "Enter an octal number: ";
            cin >> octal;
            {
                vector<int> binary = octalToBinary(octal);
                cout << "Binary representation: ";
                for (int bit : binary) {
                    cout << bit;
                }
                cout << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}
