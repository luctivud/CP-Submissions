#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

signed main() {

	ios_base::sync_with_stdio(false); cin.tie(0);
	cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
	freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
	freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif

	string a, b; cin >> a >> b;
	lld na = a.length(), nb = b.length();

	stack<pair<char, lld> >st;

	for (lld i =  0ll; i < na; i++) {
		if (!st.empty() and ((st.top()).second >= 0) and b[(st.top()).second + 1] == a[i]) {
			if (st.top().second + 1 == nb - 1) {
				lld todo = nb - 2;
				while (!st.empty() and todo >= 0 and st.top().second == todo) {
					// cout << st.top().first << " popped\n";
					st.pop();
					todo--;
				}
			} else {
				st.push({a[i], (st.top()).second + 1});
			}
		} else {
			if (a[i] == b[0]) {
				st.push({a[i], 0});
			} else {
				st.push({a[i], -1});
			}
		}
		// cout << (st.top().first) << " "  << st.top().second << " " << st.size() << " top\n";
	}

	lld ans = st.size();
	cout << ans << "\n";

	return 0;
}
