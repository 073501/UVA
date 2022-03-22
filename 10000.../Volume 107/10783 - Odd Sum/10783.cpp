#include<iostream>
using namespace std;

int main() {
    int t, count = 1;
    cin >> t;
    while (t--) {
        int num1, num2, sum = 0;
        cin >> num1 >> num2;
        if (num1 > num2) swap(num1, num2);
        for (int i = num1; i <= num2; i++) {
            if (i % 2 == 1) sum += i;
        }
        cout << "Case " << count++ << ": " << sum << endl;
    }
    return 0;
}
