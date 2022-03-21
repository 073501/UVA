#include<iostream>
#include<string>
using namespace std;

int main() {
    string str[105];
    int strlen = 0, n = 0;
    while (getline(cin, str[n])) {
        strlen = max(strlen, (int)str[n].length());
        n++;
    }
    for (int i = 0; i < strlen; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (str[j].length() <= i)cout << " ";
            else cout << str[j][i];
        }
        cout << endl;
    }
    return 0;
}
