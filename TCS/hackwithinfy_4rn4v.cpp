#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

int minimumUnhappiness (vector<int> C) {
	int ans = 0;
	int N = (int) C.size();
	multiset<int> ml;
	for (int i = 0; i < N; i++) {
		ml.insert(C[i]);
	}
	for (int i = 1; i <= N; i++) {
		auto it = ml.upper_bound(i);
		auto it2 = it;
		if (it != ml.begin()) {
			it2--;
		}
		if (it == ml.end()) {
			it--;
		}
		// cout << i << " i " << *it << " it " << *it2 << "\n";
		if (abs(i - *it) < abs(i - *it2)) {
			// cout << "selected - " << *it << "\n";
			ans += abs(i - *it);
			ml.erase(it);
		} else {
			// cout << "selected - " << *it2 << "\n";
			ans += abs(i - *it2);
			ml.erase(it2);
		}
	}
	return ans;
}

signed main() {

	ios_base::sync_with_stdio(false); cin.tie(0);
	cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
	freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
	freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif

	int n; cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) cin >> A[i];

	cout <<  minimumUnhappiness(A) ;
	return 0;
}
