//https://ithelp.ithome.com.tw/articles/10237596
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    int n;
    string country;
    map<string, int> m;
    cin >> n;
    while (n--) {
        cin >> country;
        m[country]++;
        getline(cin, country);
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
