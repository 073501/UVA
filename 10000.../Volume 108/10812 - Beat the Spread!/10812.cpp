#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long s, d;
        cin >> s >> d;
        long long a = (s + d) / 2;
        long long b = s - a;
        if (b < 0 || (s + d) % 2 != 0) {
            cout << "impossible" << endl;
            continue;
        }
        if (a > b) cout << a << " " << b << endl;
        else cout << b << " " << a << endl;
    }
    return 0;
}
