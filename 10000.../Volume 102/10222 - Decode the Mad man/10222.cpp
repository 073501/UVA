#include<iostream>
#include<string>
using namespace std;

int main() {
    string s = "qwertyuiop[]asdfghjkl;'zxcvbnm,./", input;
    while (getline(cin, input)) {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == ' ')cout << ' ';
            else {
                for (int j = 0; j < s.length(); j++) {
                    if (input[i] == s[j] || input[i] + 32 == s[j])cout << s[j - 2];
                }
            }
        }
        cout << endl;
    }
    return 0;
}
