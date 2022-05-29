#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "12242";
    string b = "1313";

    int n = a.size();
    int m = b.size();

    vector<string> intermediate(n);

    for (int i = 0; i < n; i++) {
        int carry = 0;
        int num1 = a[n-i-1] - '0';
        for (int j = 0; j < m; j++) {
            int num2 = b[m-j-1] - '0';
            int res = num1 * num2 + carry;
            char c = char((res % 10) + '0');
            carry = res / 10;
            intermediate[i] += c;
        }
    }

    for (string s : intermediate) {
        reverse(s.begin(), s.end());
    }


    for (int i = 0; i < (int)intermediate.size(); i++) {
        for (int j = 0; j < i; j++) {
            intermediate[i] += '0';
        }
    }

    for (string s : intermediate) {
        cout << s << " \n";
    }

    string ans;

    for (int i = 0; i < n; i++) {

    }

    return 0;



/*

s

*/