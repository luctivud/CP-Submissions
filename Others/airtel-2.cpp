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

    lld n, q; cin >> n >> q;
    lld a[n], b[n];

    for (lld i=0; i<n; i++) {
    	cin >> a[i];
    }
    for (lld i=0; i<n; i++) {
    	cin >> b[i];
    }

    multiset <lld> ml1, ml2;
    for (lld i=0; i<n; i++) {
    	ml1.insert(a[i] + b[i]);
    	ml2.insert(a[i] - b[i]);
    }

    for (lld i=0; i < q; i++) {
    	char qq; cin >> qq;
    	if (qq == '?') {
    		lld mx1 = *ml1.begin() - *ml1.rbegin();
    		lld mx2 = *ml2.begin() - *ml2.rbegin();
    		cout << max(llabs(mx1), llabs(mx2)) << "\n"; 
    	} else if (qq == 'a') {
    		lld ind, val; cin >> ind >> val;
    		ind--;
    		lld val1 = a[ind] + b[ind];
    		lld val2 = a[ind] - b[ind];
    		auto it1 = ml1.find(val1);
    		ml1.erase(it1);
    		auto it2 = ml2.find(val2);
    		ml2.erase(it2);
    		a[ind] = val;
    		ml1.insert(a[ind] + b[ind]);
    		ml2.insert(a[ind] - b[ind]);
    	} else {
    		lld ind, val; cin >> ind >> val;
    		ind--;
    		lld val1 = a[ind] + b[ind];
    		lld val2 = a[ind] - b[ind];
    		auto it1 = ml1.find(val1);
    		ml1.erase(it1);
    		auto it2 = ml2.find(val2);
    		ml2.erase(it2);
    		b[ind] = val;
    		ml1.insert(a[ind] + b[ind]);
    		ml2.insert(a[ind] - b[ind]);
    	}
    }

    return 0;
}
