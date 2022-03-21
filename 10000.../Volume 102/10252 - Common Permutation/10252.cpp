#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1, s2;
    while (getline(cin, s1)) {
        getline(cin, s2);
        int arr1[26]{}, arr2[26]{};
        for (int i = 0; i < s1.length(); i++) arr1[s1[i] - 'a']++;
        for (int i = 0; i < s2.length(); i++) arr2[s2[i] - 'a']++;
        for (int i = 0; i < 26; i++)if (arr1[i] && arr2[i])for (int j = 0; j < min(arr1[i], arr2[i]); j++)cout << (char)('a' + i);
        cout << endl;
    }
    return 0;
}
