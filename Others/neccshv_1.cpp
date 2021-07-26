#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s; cin >> s;

    int a[] = {0, 0, 0};
    int ind = 0;
    for (auto i : s) {
        if (i == '-') {
            ++ind;
        } else {
            a[ind] = a[ind] * 10 + (i - '0');
        }
    }

    string ans[3];
    bool ok = true;

    for (int i = 0; i < 3; i++) {
        // cout << a[i] << " ";
        int n = a[i];
        if (n > 255) {
            ok = false;
            break;
        }
        string item = "ABCDEF";
        for (int j = 0; j < 2; j++) {
            int r = n % 16;
            n /= 16;
            if (r >= 10) {
                ans[i] += item[r - 10];
            } else {
                ans[i] += to_string(r);
            }
        }
        reverse(ans[i].begin(), ans[i].end());
    }


    if (ok) {
        cout << "#";
        for (int i = 0; i < 3; i++) {
            cout << ans[i];
        }
    } else {
        cout << "NA";
    }


    return 0;
}
