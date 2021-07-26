#include <bits/stdc++.h>
using namespace std;

signed main() {
    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    vector<int> b = {0};

    string s1, s2;
    cin >> s1 >> s2;

    int ind1 = 0, ind2 = 0;

    vector<int> arr = {0};
    for(int i = 0; i < s1.length(); i++) {
        if (s1[i] == ',') {
            arr.push_back(0);
            continue;
        }
        arr.back() = (arr.back() * 10) + (i-'0');
    }

    for(auto i : s2) {
        if (i == ',') {
            b.push_back(0);
            ind2++;
            continue;
        }
        b[ind2] = (b[ind2] * 10) + (i-'0');
    }

    int n = max(a.size(), b.size());
    for (int i = 0; i < n; i++) {
        cout << (i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0);
        if (i < n-1) {
            cout << ",";
        }
    }
    
    return 0;
}
