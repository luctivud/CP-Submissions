#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T; cin >> T;
    for (int Test = 1; Test <= T; Test++) {
        cout << "Case #" << Test << ":\n";

        int n; cin >> n;

        char in[n];
        for (int i = 0; i < n; i++) cin >> in[i];

        char out[n];
        for (int i = 0; i < n; i++) cin >> out[i];

        char ans[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    ans[i][j] = 'Y';
                } else if (i < j) {
                    int pos = i; 
                    int end = j;
                    while (pos < end) {
                        if (out[pos] == 'Y' && in[pos+1] == 'Y') pos++;
                        else break;
                    }
                    if (pos == end) ans[i][j] = 'Y';
                    else ans[i][j] = 'N';
                } else {
                    int pos = i;
                    int end = j;
                    while (pos > end) {
                        if (out[pos] == 'Y' && in[pos-1] == 'Y') pos--;
                        else break;
                    }
                    if (pos == end) ans[i][j] = 'Y';
                    else ans[i][j] = 'N';
                }
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j];
            }
            cout << "\n";
        }

    }
}