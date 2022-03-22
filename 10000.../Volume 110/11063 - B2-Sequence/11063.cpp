#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, count = 1;
    while (cin >> n) {
        int arr[101]{};
        vector<int> v;
        bool ans = 1;
        if (n < 2) ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] < 1) ans = 0;
            if (i)if (arr[i] <= arr[i - 1])ans = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (find(v.begin(), v.end(), arr[i] + arr[j]) != v.end()) {
                    ans = 0;
                    break;
                }
                v.push_back(arr[i] + arr[j]);
            }
        }
        cout << "Case #" << count++ << ": It is";
        if (ans) cout << " a B2-Sequence." << endl << endl;
        else cout << " not a B2-Sequence." << endl << endl;
    }
    return 0;
}
