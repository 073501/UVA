#include <bits/stdc++.h>
using namespace std;

vector<int> multiply(vector<int> v1, vector<int> v2) {
    int len1 = v1.size(), len2 = v2.size();
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0, i_n2 = 0;
    for (int i = 0; i < len1; i++) {
        int carry = 0;
        i_n2 = 0;
        for (int j = 0; j < len2; j++) {
            int sum = v1[i] * v2[j] + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0) { result[i_n1 + i_n2] += carry; }
        i_n1++;
    }
    while (result[result.size() - 1] == 0) result.pop_back();
    return result;
}

void sum(vector<int> &X, vector<int> v1, vector<int> v2) { // v2 > v1
    int carry = 0;
    for (int i = 0; i < v2.size(); i++) {
        if (i < v1.size()) {
            X.push_back((v1[i] + v2[i] + carry) % 10);
            carry = (v1[i] + v2[i] + carry) / 10;
        }
        else {
            X.push_back((v2[i] + carry) % 10);
            carry = (v2[i] + carry) / 10;
        }
    }
    if (carry)X.push_back(1);
}

void divide_by_two(vector<int> &v1) {
    v1[0] /= 2;
    for (int i = 1; i < v1.size(); i++) {
        if (v1[i] % 2 != 0) {
            v1[i - 1] += 5;
        }
        v1[i] /= 2;
    }
    while (v1[v1.size() - 1] == 0) v1.pop_back();
}

int cmp(vector<int>& v1, vector<int>& v2) {
    if (v1.size() > v2.size()) return 1;
    else if (v1.size() < v2.size()) return -1;
    else {
        for (int i = v1.size() - 1; i >= 0; i--) {
            if (v1[i] > v2[i]) return 1;
            else if (v1[i] < v2[i]) return -1;
            else if (v1[i] == v2[i]) continue;
        }
        return 0;
    }
}

int main() {
    int t;
    string s;
    vector<int> Y, bottom, up, X, sqX;
    cin >> t;
    while (t--) {
        Y.clear();
        bottom.clear();
        up.clear();
        cin >> s;
        int l = s.length();
        for (int i = l - 1; i >= 0; i--) {
            Y.push_back(s[i] - '0');
        }
        for (int i = 0; i < (l + 1) / 2 - 1; i++) {
            bottom.push_back(0);
            up.push_back(0);
        }
        bottom.push_back(1);
        up.push_back(0);
        up.push_back(1);
        while (true) {
            X.clear();
            sqX.clear();
            sum(X, bottom, up);
            divide_by_two(X);
            sqX = multiply(X, X);
            if (cmp(sqX, Y) == 0) {
                for (int i = X.size() - 1; i >= 0; i--) {
                    cout << X[i];
                }
                cout << endl;
                break;
            }
            else if (cmp(sqX, Y) == 1) {
                up.assign(X.begin(), X.end());
            }
            else {
                bottom.assign(X.begin(), X.end());
            }
        }
    }
    return 0;
}
