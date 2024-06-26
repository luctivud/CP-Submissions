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

    map<int, vector<int>> adj;

    int n; cin >> n;
    vector<int> nodes(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    int m; cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    int source, dest; cin >> source >> dest;
    queue<int> q;
    vector<bool> visited(n+1, false);
    q.push(source);
    visited[source] = true;

    while (q.size()) {
        int node = q.front();
        q.pop();
        for (int i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                if (i == dest) {
                    break;
                }
            }
        }
    }

    cout << (visited[dest] ? 1 : 0) << "\n";

    return 0;
}
