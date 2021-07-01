#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;


vector<int> findSongs(int rideTime, vector<int> songs) {
    vector<int> ans(2, -1);
    rideTime -= 30;
    
    map<int, vector<int>> songsMap;
    int n = (int) songs.size();
    for (int i = 0; i < n; i++) {
        songsMap[songs[i]].push_back(i);
    }

    for (int i = n-1; i >= 0; i--) {
        if (rideTime - songs[i] <= 0 or songs[i]*2 == rideTime) continue;
        if (songsMap.find(rideTime - songs[i]) != songsMap.end()) {
            int mx = max(songs[i], rideTime-songs[i]);
            int mn = min(songs[i], rideTime-songs[i]);
            if (ans[1] == -1 or mx > songs[ans[1]]) {
                ans[0] = songsMap[mn][0];
                ans[1] = songsMap[mx][0];
            }
        }
    }

    if ((songsMap[rideTime/2]).size() >= 2 and rideTime % 2 == 0) {
        if (ans[1] == -1 or songs[ans[1]] < rideTime/2) {
            ans[1] = songsMap[rideTime/2][0];
            ans[0] = songsMap[rideTime/2][1];
        }
    }
    sort(ans.begin(), ans.end());
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

    vector<int> songs {1, 85, 60, 35, 10};

    vector<int> ans = findSongs(125, songs);

    for (auto a : ans) {
        cout << a << " ";
    }
    
    return 0;
}
