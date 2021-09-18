#include<bits/stdc++.h>
using namespace std;

signed main() {
    string a, b; 
    cin >> a >> b;

    // cout << a << endl;
    // cout << b << endl;

    map<int, int> cntA, cntB;

    for (char i : a) {
        cntA[i] += 1;
    }

    for (char i : b) {
        cntB[i] += 1;
    }

    vector<int> valuesA, valuesB;

    for (auto &[key, val] : cntA) {
        valuesA.push_back(val);
    }

    for (auto &[key, val] : cntB) {
        valuesB.push_back(val);   
    }

    sort(valuesA.begin(), valuesA.end());
    sort(valuesB.begin(), valuesB.end());

    int n = (int) valuesA.size();
    int m = (int) valuesB.size();

    bool ok = (n == m);


    for (int i = 0;  i < min(n, m); i++) {
        // cout << valuesA[i] << " " << valuesB[i] << endl;
        ok &= (valuesA[i] == valuesB[i]);
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}


