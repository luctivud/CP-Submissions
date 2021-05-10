#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

signed main() {
	
	// Input - Output and optimization
	

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    int n; cin >> n;
    string s; cin >> s;
    lld firstChar = n+1, lastChar = -1;
    for (int i =0; i<n-1; i++) {
    	if (s[i] == s[i+1]) {
    		firstChar = i+1;
    		break;
    	}
    }

    for (int i = n-1; i>0; i--) {
    	if (s[i] == s[i-1]) {
    		lastChar = i;
    		break;
    	}
    }

    lld removed = max(0ll, lastChar - firstChar + 1);
    // error("luct", removed, firstChar, lastChar);
    cout << n - removed << "\n";
    
    return 0;
}
