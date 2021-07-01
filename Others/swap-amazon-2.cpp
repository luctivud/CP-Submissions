#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIVUD
    #include <buggyBaby.hpp>
    pretty:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #define _____error_____(...)
#endif
#pragma GCC optimize "trapv"

typedef long long int lld;

int myupperBound(vector<vector<int>> arr, int val) {
    int N = (int)arr.size();
    int l = 0, r = N;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (val >= arr[mid][1]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (l < N && arr[l][1] <= val) {
        l++;
    }

    return l;
}

vector<vector<int>> applicationPairs(int k, vector<vector<int>>fg, vector<vector<int>> bg) {
    vector<vector<int>> ans;

    sort(bg.begin(), bg.end(), [] (vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });

    // _____error_____(bg);

    int currentUsedMemory = 0;
    int n = (int)fg.size();
    for (int i = 0; i < n; i++) {
        int toSearch = k - fg[i][1];
        int pos = myupperBound(bg, toSearch) - 1;
        if (pos < 0) continue;
        int thisUsedMemory = fg[i][1] + bg[pos][1];
        if (thisUsedMemory > currentUsedMemory) {
            ans.clear();
            currentUsedMemory = thisUsedMemory;
            ans.push_back({fg[i][0], bg[pos][0]});
        } else if (thisUsedMemory == currentUsedMemory) {
            ans.push_back({fg[i][0], bg[pos][0]});
        }
    }
    if (ans.size() == 0) {
        vector<int> el;
        ans.push_back(el);
    }
    // cout << currentUsedMemory << "\n";
    return ans;
}

signed main() {

    // Input - Output and optimization

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif

    vector<vector<int>> fg{{2, 7}, {3, 14}};
    vector<vector<int>> bg{{2, 10}, {3, 14}};

    vector<vector<int>> ans = applicationPairs(16, fg, bg);

    for (auto &a : ans) {
        cout << a[0] << " " << a[1] << "\n";
    }

    return 0;
}
