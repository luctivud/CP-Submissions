#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

const lld mXn = 1e18;

signed main() {

	ios_base::sync_with_stdio(false); cin.tie(0);

	lld n, m; cin >> n, m;

	vector<lld> adj[n + 1];

	vector<vector<lld>> graph(n + 1, vector<lld>(n + 1, -1));

	for (lld i = 0ll; i < m; i++) {
		lld a, b, weight; cin >> a >> b >> weight;
		graph[a][b] = weight;
		graph[b][a] = weight;
	}

	vector<lld> key(n + 1, mXn);
	key[1] = 0;

	vector<bool> visited(n + 1, false);
	vector<lld> parent(n + 1, -1);


	lld total_weight = 0ll;
	for (lld xx = 0; xx < n - 1; xx++) {
		lld chosenKey = mXn, chosenInd = 0;
		for (int i = 0; i < n; i++) {
			if (key[i] < chosenKey and !visited[i]) {
				chosenKey = key[i];
				chosenInd = i;
			}
		}

		visited[chosenInd] = true;

		for (int i = 0; i < n; i++) {
			if (graph[i][chosenInd] != -1 and (chosenKey + graph[chosenInd][i] < key[i])) {
				key[i] = chosenKey + graph[chosenInd][i];
				parent[i] = chosenInd;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		total_weight += graph[i][parent[i]];
	}
	cout << total_weight << "\n";

	return 0;
}
