#include <iostream>
using namespace std;

int solve(int n) {
    int count = 1;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        count++;
    }
    return count;
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int ans = 0;
        if (i > j) swap(i, j);
        for (int k = i; k <= j; k++) {
            ans = max(ans, solve(k));
        }
        cout << i << " " << j << " " << ans << endl;
    }
    return 0;
}
