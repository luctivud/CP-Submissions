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

	lld t; cin >> t;

	while (t--) {
		lld n; cin >> n;
		lld mx = 0ll;
		lld arr[n];
		for (int i = 0; i < n; i++) {
			lld x; cin >> x;
			while (x % 2 == 0) {
				x /= 2;
			}
			arr[i] = x;
			mx = max(mx, x);
		}

		for (lld i = 0ll; i < n; i++) {
			while ((llabs(arr[i] - mx) > llabs((arr[i] * 2) - mx)) and (arr[i] & 1)) {
				arr[i] *= 2;
			}
			cout << arr[i] << " ";
		}

		sort(arr, arr + n);

		cout << arr[n - 1] - arr[0] << "\n";
	}

	return 0;
}
