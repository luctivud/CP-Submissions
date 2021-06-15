    #include <bits/stdc++.h>

    using namespace std;
    typedef long long int lld;

    lld sol(string &X, string &Y, int n, int m) {
        lld LCSuff[n+1][m+1];
        memset(LCSuff, 0, sizeof(LCSuff));
        lld result = 0ll;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 or j == 0) {
                    LCSuff[i][j] = 0;
                } else if (X[i-1] == Y[j-1]) {
                    LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                    result = max(result, LCSuff[i][j]);
                } else {
                    LCSuff[i][j] = 0;
                }
            }
        }
        return result;
    }

    signed main() {
        int t; cin >> t;
        while (t--) {
            int n; cin >> n;
            string x, y; cin >> x >> y;
            cout << sol(x, y, n, n);
        }
        return 0;
    }
