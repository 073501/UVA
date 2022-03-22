#include<iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b && (a + b)) {
        int ans = 0;
        for (int i = 1; i < 317; i++) {
            if (i * i > b) break;
            if (i * i >= a && i * i <= b) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
