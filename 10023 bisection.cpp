#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0){
        return "0"; 
    }
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;      
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0) { result[i_n1 + i_n2] += carry; }
        i_n1++;
    }
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0) { i--; }
    if (i == -1) { return "0"; }
    string s = "";
    while (i >= 0)
        s += to_string(result[i--]);
    return s;
}

string sum(string str1, string str2) { // s2 > s1
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i = 0; i < n1; i++) {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n1; i < n2; i++) {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry) { str.push_back(carry + '0'); }
    reverse(str.begin(), str.end());
    return str;
}

string divide_by_two(string s1) {
    int carry = 0, tmp;
    for (int i = 0; i < s1.length(); i++) {
        tmp = s1[i] - '0';
        if (carry == 1) {
            tmp += 10;
            carry = 0;
        }
        if (tmp % 2 != 0) {
            carry = 1;
        }
        tmp /= 2;
        s1[i] = (char)tmp + '0';
    }
    if (s1[0] == '0') {
        s1.erase(s1.begin());
    }
    return s1;
}

int cmp(string s1, string s2) { //s1 > s2
    if (s1.length() > s2.length()) {
        return 1;
    }
    else if (s1.length() < s2.length()) {
        return 0;
    }
    else if (s1 == s2) {
        return 2;
    }
    else if (s1 > s2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
	int t;
    string Y, X;
	cin >> t;
	while (t--) {
        cin >> Y; 
        string bottom = "1", up = Y;
        while (true) {
            X = divide_by_two(sum(bottom, up));
            while (X.length() > Y.length() / 2 + 1) {
                X = divide_by_two(X);
            }
            if (cmp(multiply(X, X), Y) == 2) {
                cout << X;
                if (t > 0) {
                    cout << endl;
                }
                cout << endl;
                break;
            }
            else if (cmp(multiply(X, X), Y) == 1) {
                up = X;
            }
            else {
                bottom = X;
            }
        }
	}
	return 0;
}
