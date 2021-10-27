#include<bits/stdc++.h>
using namespace std;

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

void delete_zero(vector<int> &v) {
	while (v[v.size() - 1] == 0) {
		if (v.size() == 1) return;
		v.erase(v.end() - 1);
	}
}

void fun1(vector<int>& v1, vector<int>& v2) {
	vector<int> v3, v4;
	int c = 0, tmp;
	v3.push_back(0);
	for (int i = 0; i < v1.size(); i++) {
		v3.push_back((v1[i] * 2) % 10 + c);
		c = v1[i] * 2 / 10;
	}
	if (c)v3.push_back(c);
	if (cmp(v2, v3) == -1) {
		v1.insert(v1.begin(), 0);
		return;
	}
	else {
		for (int i = 1; i <= 10; i++) {
			v4.clear();
			v3[0] = i;
			c = 0;
			for (int j = 0; j < v3.size(); j++) {
				tmp = v3[j] * i + c;
				v4.push_back(tmp % 10);
				c = tmp / 10;
			}
			if (c) v4.push_back(c);
			if (cmp(v2, v4) == 1) {
				continue;
			}
			else if (cmp(v2, v4) == 0) {
				v2.clear();
				v1.insert(v1.begin(), i);
			}
			else {
				v3[0] = i - 1;
				v1.insert(v1.begin(), i - 1);
				c = 0;
				for (int j = 0; j < v3.size(); j++) {
					tmp = v3[j] * (i - 1) + c;
					v3[j] = tmp % 10;
					c = tmp / 10;
				}
				if (c) v3.push_back(c);
				c = 0;
				for (int j = 0; j < v3.size(); j++) {
					v2[j] += c;
					if (v2[j] < v3[j]) v2[j] = v2[j] + 10 - v3[j], c = -1;
					else v2[j] -= v3[j], c = 0;
				}
				if (c && v2.size() > v3.size()) v2[v2.size() - 1] += c;
			}
			break;
		}
	}
	return;
}

int main() {
	int t;
	vector<int> Y, ans, re, tmp;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		Y.clear();
		ans.clear();
		re.clear();
		tmp.clear();
		int l = s.length(), ansl, rel;
		for (int i = l-1; i >=0 ; i--) {
			Y.push_back(s[i] - '0');
		}
		int c, k, i;
		if (l % 2) k = Y[l - 1], c = 1;
		else k = Y[l - 1] * 10 + Y[l - 2], c = 2;
		for (i = 0; i * i <= k && i < 10; i++);
		ans.push_back(--i);
		ansl = 1;
		k = k - i * i;
		if (k < 10) { re.push_back(k); rel = 1; }
		else { re.push_back(k % 10); re.push_back(k / 10); rel = 2; }
		for (int i = (l - 1) / 2; i > 0; i--) {
			re.insert(re.begin(), Y[i * 2 - 1]);
			re.insert(re.begin(), Y[i * 2 - 2]);
			delete_zero(re);
			fun1(ans, re);
		}
		for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
		cout << endl;
	}
	return 0;
}
//test1=0.822s
//test2=0.811s
