#include<iostream>
using namespace std;

int main() {
    long long s, d;
    while (cin >> s >> d) {
        long long sum = s;
        while (sum < d) {
            sum += s + 1;
            s++;
        }
        cout << s << endl;
    }
    return 0;
}
