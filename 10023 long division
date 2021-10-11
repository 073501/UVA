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
	int tmp, carry_in = 0, carry_out = 0, len = s1.length();
	reverse(s1.begin(), s1.end());
	for (int i = 0; i < len; i++) {
		carry_in = carry_out;
		tmp = s1[i] - '0';
		tmp *= (s2[0] - '0');
		if (carry_in > 0) {
			tmp += carry_in;
		}
		if (tmp >= 10) {
			carry_out = tmp / 10;
			if (i == s1.size() - 1) {
				s1.push_back((char)carry_out + 48);
			}
		}
		else {
			carry_out = 0;
		}
		s1[i] = (char)tmp % 10 + 48;
	}
	reverse(s1.begin(), s1.end());
	delete_zero(s1);
	return s1;
}

void string_sub(string& s1, string& s2) { //s1 > s2
	int tmp, carry = 0;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	for (int i = 0; i < s2.size(); i++) {
		if (carry != 0) {
			tmp = s1[i] - '0';
			tmp--;
			s1[i] = (char)tmp + 48;
			carry = 0;
		}
		if (s1[i] - '0' < s2[i] - '0') {
			carry = -1;
			s1[i] = (char)(s1[i] - '0') - (s2[i] - '0') + 58;
		}
		else {
			s1[i] = (char)(s1[i] - '0') - (s2[i] - '0') + 48;
		}
		if (i == s2.size() - 1 && s1.length() > s2.length()) {
			tmp = s1[i + 1] - '0';
			tmp += carry;
			s1[i + 1] = (char)(tmp + 48);
		}
	}
	reverse(s1.begin(), s1.end());
	delete_zero(s1);
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
	string Y, ans = "", minus = "", factor = "", tmp;
	vector<int> Ynum;
	cin >> t;
	cout << endl;
	while (t--) {
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
		for (int num = 0; num < 10; num++) {
			if (Ynum[0] < num * num) {
				ans.push_back((char)(num - 1 + 48));
				tmp = to_string(Ynum[0] - (num - 1) * (num - 1));
				minus.append(tmp);
				break;
			}
			else if (num == 9) {
				ans.push_back((char)num + 48);
				tmp = to_string(Ynum[0] - num * num);
				minus.append(tmp);
			}
		}
		for (int i = 1; i < Ynum.size(); i++) {
			tmp = to_string(Ynum[i]);
			if (tmp.length() == 1) {
				minus.append("0");
			}
			minus.append(tmp);
			delete_zero(minus);
			factor = string_mul(ans, "2");
			for (int num = 0; num < 10; num++) {
				factor.push_back((char)num + 48);
				tmp = string_mul(factor, to_string(num));
				if (string_cmp(tmp, minus) == 1) {
					factor[factor.length() - 1] = (char)num + 47;
					factor = string_mul(factor, to_string(num - 1));
					ans.push_back((char)num + 47);
					break;
				}
				else if (string_cmp(tmp, minus) == 2) {
					factor = string_mul(factor, to_string(num));
					ans.push_back((char)num + 48);
					break;
				}
				else {
					if (num == 9) {
						factor = string_mul(factor, to_string(num));
						ans.push_back((char)num + 48);
						break;
					}
					factor.pop_back();
				}
			}
			string_sub(minus, factor);
		}
		cout << ans << endl;
	}
	return 0;
}
