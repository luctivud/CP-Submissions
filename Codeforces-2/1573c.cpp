#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    int indegree[n+1] = {0};
    vector<int> adj[n+1];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int node;
            cin >> node;
            indegree[i] += 1;
            adj[node].push_back(i);
        }
    }

    set<int> q;
    int visited_nodes = 0, ans = 1, last_read = 0;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            visited_nodes += 1;
            q.insert(i);
        }
    }
    while (q.size()) {
        int node = *q.begin();
        cout << node << endl;
        q.erase(q.begin());
        for (int i : adj[node]) {
            indegree[i] -= 1;
            if (indegree[i] == 0) {
                q.insert(i);
                visited_nodes += 1;
            }
        }
        if (last_read > node) {
            ans += 1;
        }
        last_read = node;
    }
    if (visited_nodes == n) {
        cout << ans;
    } else {
        cout << "-1";
    }

}

int main(int argc, char const *argv[]) {
    int t; cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
}