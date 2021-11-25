#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;

    set<int> distinctCities;
    vector<pair<int, int>> members(n);

    for (int i = 0; i < n; i++) {
        cin >> members[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> members[i].second;
        distinctCities.insert(members[i].second);
    }

    sort(members.begin(), members.end());

    int cntDistinctCities = (int) distinctCities.size();

    int ans = members[n - 1].first - members[0].first;
    int lo = 0, hi = ans;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        bool ok = false;
        map<int, int> count;
        int p1 = 0, p2 = 0;
        while (p2 < n) {
            while (p1 < n and (members[p2].first - members[p1].first) > mid) {
                count[members[p1].second]--;
                if (count[members[p1].second] == 0) {
                    count.erase(members[p1].second);
                }
                p1++;
            }
            while (p2 < n and (members[p2].first - members[p1].first) <= mid) {
                count[members[p2].second]++;
                p2++;
            }
            ok |= (cntDistinctCities == (int)count.size());
            count[members[p1].second]--;
            if (count[members[p1].second] == 0) {
                count.erase(members[p1].second);
            }
            p1++;
        }

        ok |= (cntDistinctCities == (int)count.size());
        if (ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
