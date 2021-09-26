#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0ll;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > '0') {
            ans += 1 + (s[i] - '0');
        }
    }

    cout << ans + (s[n-1] - '0');
}

int main(int argc, char const *argv[]) {
    int t; cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
}