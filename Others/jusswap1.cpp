#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
lld n;


pair<vector<vector<lld>>, vector<lld>> dfs(vector<lld> adj[], vector<bool>&visited, lld curr, vector<vector<lld>> &path, vector<lld> &st) {
    if (curr == n - 1) {
        path.push_back(st);
        st.pop_back();
        return make_pair(path, st);
    } else {
        visited[curr] = true;
        for (auto &i : adj[curr]) {
            if (!visited[i]) {
                st.push_back(i);
                auto [path2, st2] = dfs(adj, visited, i, path, st);
                path = path2;
                st = st2;
            }
        }
        st.pop_back();
        return make_pair(path, st);
    }
}


signed main() {
    
    // Input - Output and optimization
    
    // ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    lld m, t, c; cin >> n >> m >> t >> c;

    vector<lld> adj[n];
    vector<bool> visited(n, false);

    for (lld i = 0; i < m; i++) {
        lld a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<lld> st1;
    vector<vector<lld>> p1;
    auto [pt, st] = dfs(adj, visited, 0, p1, st1);

    sort(pt.begin(), pt.end(), [] (auto &a, auto &b) {
        return a.size() < b.size();
    });

    lld ans = 0ll;

    lld sz = (pt.size() >= 1 ? pt[0].size() : 0);

    for (lld i = 1; i < sz - 1; i++) {
        ans += c;
        lld temp = ans / t;
        if (temp & 1) {
            ans += (temp + 1) * t;
        }
    }

    cout << ans << "\n";

    return 0;
}
