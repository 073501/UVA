#include <iostream>
using namespace std;

int main() {
    string input;
    while (cin >> input) {
        int odd = 0, even = 0;
        if (input == "0") break;
        for (int i = 0; i < input.length(); i++) {
            if (i % 2 == 0) odd += input[i] - '0';
            else even += input[i] - '0';
        }
        cout << input << " is";
        if (abs(odd - even) % 11 != 0) cout << " not";
        cout << " a multiple of 11." << endl;
    }
    return 0;
}
