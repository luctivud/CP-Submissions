
#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

class Solution {
	static int dfs(int node, int par, int ch, vector<bool> &visited, vector<int> adj[]) {
		if (visited[node]) {
			return 0ll;
		}
		visited[node] = true;
		for (int neighbour : adj[node]) {
			if (neighbour != par) {

			}
		}
	}
  public:
  	int solve(int n, vector<vector<int>> edges, string s) {
  		vector<int> adj[n+1];
  		for (auto e : edges) {
  			adj[e[0]].push_back(e[1]);
  		}
  		s = '$' + s;
  		vector<bool> visited(n+1, false);
  		int ans = 0ll;
  		for (int ch = 0ll; ch < 26; ch++) {
  			fill(visited.begin(), visited.end(), false);
  			int res = 0ll;
  			for (int i = 1ll; i <= n; i++) {
  				if (!visited[i]) {
  					//dfs for max ans

  				}
  			}
  			ans = max(ans, res);
  		}

  		return ans;
  	}
  
};




void readNumber(lld &N) {
  cin >> N;
}

void readVector(vector<lld> arr) {
  for (auto &i : arr) {
    cin >> i;
  }
}



signed main() {
  // Solution obj;

  // lld N; vector<lld> arr(N);
  // readNumber(N); readVector(arr);


  return 0;
}
