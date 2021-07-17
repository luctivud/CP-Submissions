#include <bits/stdc++.h>

signed main() {
    long long n; cin >> n;
    long long arr[n];
    multiset<long long> se;
    long double maxVal = -1, sum = 0ll;
    vector<long long> ans;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        se.insert(arr[i]);
    }

    for (int i = 0; i < n-2; i++) {
        se.erase(se.find(arr[i]));
        sum -= arr[i];
        long double thisVal = (sum-*se.begin()) / ((long double)se.size() - 1);
        if (thisVal > maxVal) {
            maxVal = thisVal;
            ans.clear();
            ans.push_back(i+1);
        } else if (thisVal == maxVal) {
            ans.push_back(i+1);
        }
    }

    for (auto i : ans) {
        cout << i << " ";
    }
    
    return 0;
}
