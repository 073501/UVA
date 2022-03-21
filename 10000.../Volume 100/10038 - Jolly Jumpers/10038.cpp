#include<iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int num[3005];
        bool arr[3005]{};
        bool jolly = 1;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        if (n == 1) {
            cout << "Jolly" << endl;
            continue;
        }
        for (int i = 1; i < n; i++) arr[abs(num[i] - num[i - 1])] = 1;
        for (int i = 1; i < n; i++) {
            if (!arr[i]) jolly = 0;
        }
        if (jolly)cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;
    }
    return 0;
}
