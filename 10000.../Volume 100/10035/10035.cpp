#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (s1 == "0" && s2 == "0") break;
        int c_count = 0, carry = 0, maxlen = max(s1.length(), s2.length());
        while (s1.length() != s2.length()) {
            if (s1.length() < s2.length()) s1.insert(0, "0");
            else if (s1.length() > s2.length()) s2.insert(0, "0");
        }
        for (int i = maxlen - 1; i >= 0; i--) {
            int add_result = s1[i] - '0' + s2[i] - '0' + carry;
            if (add_result >= 10) c_count++, carry = 1;
            else carry = 0;
        }
        if (c_count > 0) cout << c_count;
        else cout << "No";
        cout << " carry operation";
        if (c_count > 1) cout << "s";
        cout << "." << endl;
    }
    return 0;
}
