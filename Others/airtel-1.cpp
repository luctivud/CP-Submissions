#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef unsigned long long int lld;
typedef pair<lld, lld> pi;

struct cmp1 {
 	constexpr bool operator()(pi const& a, pi const& b) const noexcept {
        return ((a.first - (a.first / 2)) * (a.second)) < ((b.first - (b.first / 2)) * b.second);
    }
};

struct cmp2 {
	constexpr bool operator()(pi const& a, pi const& b) const noexcept {
        return ((a.second - (a.second / 2)) * (a.first)) < ((b.second - (b.second / 2)) * b.first);
    }
};

signed main() {
	
	// Input - Output and optimization
	
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    lld test; cin >> test;
    while (test--) {
    	lld n; cin >> n;
    	lld a[n], b[n];
    	for (lld i=0; i < n; i++) {
    		cin >> a[i];
    	}
    	for (lld i=0; i < n; i++) {
    		cin >> b[i];
    	}
    	lld k; cin >> k;

    	lld originalSum = 0ll;
    	for (lld i=0; i<n; i++) {
    		originalSum += lld(a[i] * b[i]);
    	}

    	priority_queue<pi, vector<pi>, cmp1> pq1;
    	priority_queue<pi, vector<pi>, cmp2> pq2;

    	for (lld i=0; i < n; i++) {
    		pq1.push(make_pair(a[i], b[i]));
    		pq2.push(make_pair(a[i], b[i]));
    	}

    	// for (lld i=0; i < n; i++) {
    	// 	pi u = pq2.top();
    	// 	pq2.pop();
    	// 	cout << u.first << "," << u.second << "\n";
    	// }

    	// cout << originalSum;

    	lld alice = 0, bob = 0;
    	lld originalSumAlice = originalSum, 
    	originalSumBob = originalSum;

    	while (originalSumAlice > k) {
    		pi t = pq1.top();
    		lld t1 = t.first, t2 = t.second;
    		pq1.pop();
    		originalSumAlice = originalSumAlice - (t1 * t2) + ((t1/2) * t2);
    		pq1.push(make_pair(t1/2, t2));
    		alice++;
    		// cout << t1 <<" . " << t2 <<" . "<< originalSumAlice << "\n";
    	}

    	while (originalSumBob > k) {
    		pi t = pq2.top();
    		lld t1 = t.first, t2 = t.second;
    		pq2.pop();
    		originalSumBob = originalSumBob - (t1 * t2) + (t1 * (t2/2));
    		pq2.push(make_pair(t1, t2/2));
    		bob++;
    		// cout << t1 <<" . " << t2 <<" . "<< originalSumBob << "\n";
    	}

    	// cout << alice << " : " << bob << "\n";

    	if (alice == bob) {
    		cout << "Tie\n";
    	} else if (alice < bob) {
    		cout << "Alice\n";
    	} else {
    		cout << "Bob\n";
    	}

    }

    return 0;
}
