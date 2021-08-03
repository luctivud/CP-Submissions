#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << "\n";
    string ans(n, 'E');
    bool buy = false;
    for (int i = 0; i < n; i++) {
        if (buy and i > 0 and arr[i] > arr[i-1]) {
            ans[i] = 'S';
            buy = false;
        } else if (!buy) {
            buy = true;
            ans[i] = 'B';
        }
    }

    if (ans[n-1] != 'S') {
        for (int i = n-1; i >= 0; i--) {
            if (ans[i] == 'S') {
                ans[i] = 'E';
            }
        }
        ans[n-1] = 'S';
    }
    
    cout << ans << "\n";
    return 0;
}