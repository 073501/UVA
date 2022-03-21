#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        double p;
        cin >> n >> p >> i;
        if (p == 0.0) cout << "0.0000" << endl;
        else cout << fixed << setprecision(4) << pow((1 - p), i - 1) * p / (1 - pow(1 - p, n)) << endl;
    }
    return 0;
}
