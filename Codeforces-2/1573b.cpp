#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = n;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[0] or b[i] > a[0]) {
            ans = min(ans, i);
        }
    }
    cout << ans;

}

int main(int argc, char const *argv[]) {
    int t; cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
}