#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

signed main() {
	
	// Input - Output and optimization
	
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    lld t; cin >> t;

    while (t--) {
    	lld a, b; 
    	cin >> a >> b;
    	set<lld> se;
    	while (a > 0) {
    		if (se.find(a) == se.end()) {
    			se.insert(a);
    		} else {
    			se.erase(a);
    		}
    		a /= 2;
    	}
    	a = b;
    	while (a > 0) {
    		if (se.find(a) == se.end()) {
    			se.insert(a);
    		} else {
    			se.erase(a);
    		}
    		a /= 2;
    	}

    	cout << se.size() << "\n";
    }

    return 0;
}
