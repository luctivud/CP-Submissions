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
    map<int, vector<int>> reva;

    int n; cin >> n;
    vector<int> nodes(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    int m; cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        reva[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    int source, dest; cin >> source >> dest;
    vector<int> folo{reva[dest]};

    queue<int> q;
    q.push(source);
    visited[source] = true;

    set<int> ans;

    while (q.size()) {
        int node = q.front();
        q.pop();
        for (int i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    for (int node: folo) {
        if (visited[node]) {
            ans.insert(node);
        }
    }

    if (ans.size()) {
        for (int i : ans) {
            cout << i << " ";
        }
    } else {
        cout << "-1";
    }

    cout << "\n";

    return 0;
}
