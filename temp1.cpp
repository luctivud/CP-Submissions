#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    lld t; cin >> t;
    while (t--) {
    	string s, p; cin >> s >> p;
    	string ans;
    	vector<lld> count(26, 0ll);
    	for (auto i : s) count[i-'a']++;
		for (auto i : p) count[i-'a']--;
		for(int i=0; i<26; i++) {
			for (lld j =0ll; j<count[i]; j++) {
				ans.push_back(char(i+'a'));
			}
			if(i==(p[0]-'a')) {
				for (auto j : p) {
					ans.push_back(j);
				}
			}
		}
		cout << ans;
		// if (ans.compare(s) != 0) {
		// 	cout << ans;
		// } else {
			
		// }

		
		cout << "\n";
    }
    return 0;
}
