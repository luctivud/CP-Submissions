#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int t; cin >> t;
    while (t--) {
        long long int n, k;
        cin >> n >> k;
        for (long long int i = 0; i < n; i++) {
            long long int d; cin >> d;
            if (d % k == 0) {
                cout << "1";
            } else {
                cout << "0";
            }
        }

        cout << "\n";
    }
    return 0;
}