//WA in uva, AC in zerojudge
#include<iostream>
#include<sstream>
#include<vector>
#include<math.h>
using namespace std;

int main() {
    int x;
    string s;
    while (cin >> x) {
        vector<long long> poly;
        long long ans = 0;
        getline(cin, s);
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s) {
            poly.push_back(stoll(s));
        }
        poly.pop_back();
        for (int i = 0; i < poly.size(); i++) {
            ans += poly[i] * ((long long)poly.size() - i) * pow(x, poly.size() - i - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
