#include<iostream>
#include<string>
using namespace std;

void fun(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    if (sum >= 10) {
        fun(sum);
    }
    else {
        cout << sum << endl;
        return;
    }
}

int main() {
    int n;
    while (cin >> n && n) {
        fun(n);
    }
    return 0;
}
