#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

void bfs(lld n, vector<lld> adj[], vector<bool> &visited, lld v = 0) {
	queue<lld> q;
	q.push(v);
	visited[v] = true;
	while (q.size()) {
		v = q.front();
		q.pop();
		for (auto i : adj[v]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

signed main() {

	ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif
	
	lld n, m; 
	cin >> n >> m;
	vector<lld> adj[n];

	for (lld i =0; i<m; i++) {
		lld a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<bool> visited(n, false);

	bfs(n, adj, visited);
    
    return 0;
}
