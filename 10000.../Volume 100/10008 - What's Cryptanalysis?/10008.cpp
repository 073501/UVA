#include<iostream>
#include<string>
using namespace std;

int main() {
    int n, max_num = 0, alpha[26]{};
    string s;
    cin >> n;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')alpha[s[i] - 'a']++;
            else if (s[i] >= 'A' && s[i] <= 'Z')alpha[s[i] - 'A']++;
        }
    }
    for (int i = 0; i < sizeof(alpha) / sizeof(alpha[0]); i++) {
        max_num = max(max_num, alpha[i]);
    }
    for (int i = max_num; i >= 1; i--) {
        for (int j = 0; j < 26; j++) {
            if (alpha[j] == i)cout << (char)('A' + j) << " " << alpha[j] << endl;
        }
    }
    return 0;
}
