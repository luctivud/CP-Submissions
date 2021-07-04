#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

signed main() {

    // Input - Output and optimization

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif

    map<int, vector<pair<int, int>>> adj;
    map<int, int> ans;
    const int inf = 1e9;

    int n; cin >> n;
    vector<int> nodes(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
        ans[nodes[i]] = inf;
    }

    int m; cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    int source, dest; cin >> source >> dest;
    queue<pair<int, int>> q;
    q.push({source, 0});
    ans[source] = 0;

    while (q.size()) {
        auto [node, dep] = q.front();
        q.pop();
        for (auto [i, w] : adj[node]) {
            if (ans[i] > w + ans[node]) {
                ans[i] = w + ans[node];
                q.push({i, ans[i]});
            }
        }
    }

    cout << (ans[dest] != inf ? ans[dest] : -1) << "\n";

    return 0;
}
