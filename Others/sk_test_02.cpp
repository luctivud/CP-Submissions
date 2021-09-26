#include<bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;

    int matr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matr[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int res = 0;
            if (matr[i][j] == 1) {
                continue;
            }
            if (i - 1 >= 0 and matr[i - 1][j] == 1) {
                res += 1;
            }
            if (i + 1 < n and matr[i + 1][j] == 1) {
                res += 1;
            }
            if (j - 1 >= 0 and matr[i][j - 1] == 1) {
                res += 1;
            }
            if (j + 1 < n and matr[i][j + 1] == 1) {
                res += 1;
            }
            ans += (res == 4);
        }
    }

    cout << ans;

    return 0;
}