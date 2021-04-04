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

    lld n; cin >> n;
    lld a, b; cin >> a >> b;
    vector<lld> adj[n+1];

    for (int i=0; i<n; i++) {
    	lld x, y; cin >> x >> y;
    	adj[y].push_back(x);
    }

    vector<lld> visited(n+1, 0);

    lld ans = -1;

    queue<lld> q;

    q.push(a);
    visited[a] = 1;

    while (!q.empty()) {
    	lld x = q.front();
    	q.pop();
    	for (auto i : adj[x]) {
    		if (!visited[i]) {
	    		q.push(i);
	    		visited[i] = 1;
    		}
    	}
    }

    q.push(b);
    if (visited[b]) {
    	ans = b;
    	q.pop();
    }

    while (!q.empty()) {
    	lld x = q.front();
    	q.pop();
    	for (auto i : adj[x]) {
    		if (!visited[i]) {
	    		q.push(i);
	    		visited[i] = 1;
    		} else {
    			if (ans == -1) {
    				ans = i;
    			}
    		}
    	}
    }


    // for (auto i : visited) {
    // 	cout << i << ":" ;
    // }

    cout << ans << "\n";		

    return 0;
}
