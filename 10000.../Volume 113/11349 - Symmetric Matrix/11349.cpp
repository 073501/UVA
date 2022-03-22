#include<iostream>
using namespace std;

int main() {
    int t, count = 1;
    string temp;
    cin >> t;
    while (t--) {
        int dim;
        long long m[101][101]{};
        bool sym = 1;
        cin >> temp >> temp >> dim;
        for (int i = 1; i <= dim; i++) {
            for (int j = 1; j <= dim; j++) {
                cin >> m[i][j];
            }
        }
        for (int i = 1; i <= dim; i++) {
            for (int j = 1; j <= dim; j++) {
                if (m[i][j] < 0 || m[i][j] != m[dim + 1 - i][dim + 1 - j]) {
                    sym = 0;
                    break;
                }
            }
        }
        cout << "Test #" << count++ << ": ";
        if (sym)cout << "Symmetric." << endl;
        else cout << "Non-symmetric." << endl;
    }
    return 0;
}
