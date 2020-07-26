#include <bits/stdc++.h>
using namespace std;
int main() {
    long int t; cin >> t;
    while (t--) {
        long int n;
        long long int ans = 1LL  << n;
        for (long int i = 1; i < n; i++) {
            ans -=  1LL << i;
        }
        cout << ans << "\n";

    }
    return 0;
}