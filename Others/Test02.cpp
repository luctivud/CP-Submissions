#include <bits/stdc++.h>

using namespace std;


typedef long long int lld;
typedef long double ldo;


ldo Euclid(ldo x1, ldo x2, ldo y1, ldo y2) {
	ldo ans = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
	return sqrt(ans);
}

lld n;

ldo minKey(ldo key[], bool mstSet[])  
{  
    // Initialize min value  
    ldo min = INT_MAX, min_index;  
  
    for (int v = 0; v < n; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  


void solve() {
	cin >> n;
	ldo x[n], y[n];
	for (int i = 0; i < n; i++) {
		ldo xi, yi;
		cin >> xi >> yi;
		x[i] = xi, y[i] = yi;
	}

	ldo graph[n][n] = {0};

	for (int i = 0; i < n; i++) 
{		for (int j = 0; j< n; j++) {
			if ((abs(x[i] - x[j]) + abs(y[i] - y[j])) == 1.0) {
				graph[i][j] = 0.0;
			} else {
				graph[i][j] = Euclid(x[i], x[j], y[i], y[j]);
			}
		}
	}

    int parent[n];  
    ldo key[n];  
    bool mstSet[n];  
    for (int i = 0; i < n; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    key[0] = 0;  
    parent[0] = -1;
  
    for (int count = 0; count < n - 1; count++) {  
        int u = minKey(key, mstSet);  
        mstSet[u] = true;  
        for (int v = 0; v < n; v++)  
            if (mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }

    ldo ans = 0.0;
    for (int i = 1; i < n; i++)  
        ans += graph[i][parent[i]];

    cout << ans << "\n";

}

signed main() {

	// light();
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(6); cout << fixed;

    lld T; cin >> T;

    while (T--) {
    	solve();
    }
    return 0;
}
