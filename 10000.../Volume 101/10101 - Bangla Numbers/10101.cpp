//https://ithelp.ithome.com.tw/articles/10237596
#include<iostream>
#include<iomanip>
using namespace std;

void solve(long long n) {
    if (n >= 10000000) {
        solve(n / 10000000);
        cout << " kuti";
        n %= 10000000;
    }
    if (n >= 100000) {
        solve(n / 100000);
        cout << " lakh";
        n %= 100000;
    }
    if (n >= 1000) {
        solve(n / 1000);
        cout << " hajar";
        n %= 1000;
    }
    if (n >= 100) {
        solve(n / 100);
        cout << " shata";
        n %= 100;
    }
    if (n) {
        cout << " " << n;
    }
}

int main() {
    long long n;
    int cases = 1;
    while (cin >> n) {
        cout << setw(4) << cases++ << ".";
        if (n) solve(n);
        else cout << " 0";
        cout << endl;
    }
    return 0;
}
