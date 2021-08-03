#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, d;
    cin >> k >> d;
    int minimalValue = 10;
    bool zeroPresent = false;
    for (int i = 0; i < d; i++) {
        int temp; cin >> temp;
        if (temp == 0) {
            zeroPresent = true;
        } else {
            minimalValue = min(minimalValue, temp);
        }
    }

    if (zeroPresent and minimalValue != 10) {
        for (int i = 0; i < k; i++) {
            if (i == 0 or i == k-1) {
                cout << minimalValue;
            } else {
                cout << "0";
            }
        }
    } else if (minimalValue != 10) {
        for (int i = 0; i < k; i++) {
            cout << minimalValue;
        }
    } else {
        cout << "-1";
    }
    cout << "\n";
    return 0;
}