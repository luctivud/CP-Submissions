#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;


long long int solve(int n, int m, vector<int>c, vector<int>w) {
	long long int ans = 0;
	map<int, vector<long long int> > elem;
	for (int i = 0; i<n; i++) {
		elem[w[i]].push_back(c[i]);
	}

	sort(elem[1].begin(), elem[1].end(), greater<long long int>());
	sort(elem[2].begin(), elem[2].end(), greater<long long int>());

	int sz1 = (int)elem[1].size(), sz2 = (int)elem[2].size();

	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j < (int)elem[i].size(); j++) {
			elem[i][j] += elem[i][j-1];
		}
	}

	elem[1].insert(elem[1].begin(), 0);
	elem[2].insert(elem[2].begin(), 0);


	for (int chosen1 = 0; chosen1 <= m; chosen1++) {
		if (chosen1 > sz1) {
			break;
		}
		int chosen2 = (m - chosen1) / 2;

		if (chosen2 > sz2) {
			chosen2 = sz2;
		}

		// cout << elem[1][chosen1] << "ch ";
		ans = max(ans, elem[1][chosen1] + elem[2][chosen2]);

	}

	return ans;

}

signed main() {
	
	// Input - Output and optimization
	
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) {
    	cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> c[i];
    }

    cout <<  solve(n, m, c, w);
    return 0;
}
