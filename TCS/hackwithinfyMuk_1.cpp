#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

lld cups(lld n, lld L, lld arr[]) {
	lld lo = 0ll, hi = lld(1e9);
   	lld ans = -1, min_wastage = lld(1e16);

   	while (lo <= hi) {
   		lld mid = (lo + hi) / 2;
   		lld total = 0ll, wasted = 0ll;
   		for (lld i = 0ll; i < n; i++) {
   			lld thisFill = min(arr[i], mid);
   			wasted += mid - thisFill;
   			total += thisFill;
   		}

   		if (total >= L) {
   			if (wasted <= min_wastage) {
   				hi = mid - 1;
   				min_wastage = wasted;
   				ans = (mid);
   			} else {
   				hi = mid - 1;
   			}
   		} else {
   			lo = mid + 1;
   		}
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

    lld n, L; cin >> n >> L;

    lld arr[n]; 
    for (lld i = 0; i < n; i++) cin >> arr[i];

	cout << cups(n, L, arr);
   	

    return 0;
}
