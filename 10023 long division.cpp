#include <bits/stdc++.h>
using namespace std;

void delete_zero(string& s) {
    while (s[0] == '0') {
        if (s.length() == 1) {
            return;
        }
        s.erase(s.begin());
    }
}

string string_mul(string s1, string s2) { // 0 <= s2 < 10
    int tmp, carry = 0, len = s1.length();
    reverse(s1.begin(), s1.end());
    for (int i = 0; i < len; i++) {
        tmp = s1[i] - '0';
        tmp *= (s2[0] - '0');
        tmp += carry;
        s1[i] = (char)tmp % 10 + 48;
        carry = tmp / 10;
    }
    if (carry) s1.push_back(carry + '0');
    reverse(s1.begin(), s1.end());
    delete_zero(s1);
    return s1;
}

string string_sub(string s1, string s2) { //s1 > s2
    int tmp, carry = 0, i;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (i = 0; i < s2.size(); i++) {
        if (carry) {
            tmp = s1[i] - '0';
            tmp--;
            s1[i] = (char)tmp + 48;
            carry = 0;
        }
        if (s1[i] - '0' < s2[i] - '0') {
            carry = 1;
            s1[i] = (char)(s1[i] - '0') - (s2[i] - '0') + 58;
        }
        else {
            s1[i] = (char)(s1[i] - '0') - (s2[i] - '0') + 48;
        }
    }
    if (carry) s1[i]--;
    reverse(s1.begin(), s1.end());
    delete_zero(s1);
    return s1;
}

string string_plus(string s) {
    reverse(s.begin(), s.end());
    int n = s[0] - '0', carry = 0, i = 1;
    n *= 2;
    n++;
    if (n > 9) {
        carry = 1;
    }
    while (carry) {
        if (i == s.length()) {
            s.append("1");
            break;
        }
        s[i] += 1;
        carry = 0;
        if (s[i] > '9') {
            s[i] = '0';
            carry = 1;
            i++;
        }
    }
    s[0] = n % 10 + '0';
    reverse(s.begin(), s.end());
    return s;
}

int string_cmp(string& s1, string& s2) { //s1 > s2
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
    vector<int> Ynum;
    cin >> t;
    while (t--) {
        string Y, ans = "", remainder = "", divisor = "", tmp, diff;
        cin >> Y;
        Ynum.clear();
        if (Y.length() % 2 == 0) {
            for (int i = 0; i < Y.length() / 2; i++) {
                Ynum.push_back((Y[2 * i] - '0') * 10 + (Y[2 * i + 1] - '0'));
            }
        }
        else {
            Ynum.push_back(Y[0] - '0');
            for (int i = 1; i < Y.length() / 2 + 1; i++) {
                Ynum.push_back((Y[2 * i - 1] - '0') * 10 + (Y[2 * i] - '0'));
            }
        }
        if (Ynum.size() < 2) {
            cout << sqrt(Ynum[0]) << endl;
            continue;
        }
        for (int i = 0; i < Ynum.size(); i++) {
            if (Ynum[i] < 10) remainder.append("0");
            remainder.append(to_string(Ynum[i]));
            delete_zero(remainder);
            divisor = string_mul(ans, "2");
            for (int num = 0; num < 10; num++) {
                divisor.append(to_string(num));
                tmp = string_mul(divisor, to_string(num));
                tmp = string_sub(remainder, tmp);
                diff = string_plus(divisor);
                if (string_cmp(tmp, diff) == 1 || string_cmp(tmp, diff) == 2) {
                    divisor.pop_back();
                }
                else {
                    ans.append(to_string(num));
                    divisor = string_mul(divisor, to_string(num));
                    break;
                }
            }
            remainder = string_sub(remainder, divisor);
        }
        cout << ans << endl;
        if (t)cout << endl;
    }
    return 0;
}
