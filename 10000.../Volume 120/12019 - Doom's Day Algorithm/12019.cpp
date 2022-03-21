#include<iostream>
using namespace std;

int main() {
    int t, m, d, date[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    string days[7] = { "Friday","Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday" }; // 1/1 is Saturday. -> 1/0 is Friday.
    cin >> t;
    while (t--) {
        cin >> m >> d;
        int sum = d;
        for (int i = 0; i < m - 1; i++) {
            sum += date[i];
        }
        cout << days[sum % 7] << endl;
    }
    return 0;
}
