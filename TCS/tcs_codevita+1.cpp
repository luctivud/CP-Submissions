//             Author: Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)                  //


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define         _input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define              all(x)    (x).begin(), (x).end()
#define              deb(x)    cout << #x << "=" << (x) << " ";



void solveEachTest(lld T35TC453N = 1) {
	lld n, w, d; cin >> n >> w >> d;
	vector<lld> prefix_sum = {0}, window1[w+1], window2[w+d+1];
	lld currsum = 0ll;
	for4 (i, 1, n+1, 1) {
		lld temp; cin >> temp;
		currsum += temp;
		prefix_sum.push_back(currsum);
		if ((lld)window1[i % (w+1)].size() == 0ll) {
			window1[i % (w+1)].push_back(0);
			if (i == w+1) {
				window1[i % (w+1)].push_back(temp);
			}
		} else {
			window1[i% (w+1)].push_back(temp + window1[i%(w+1)][(lld)window1[i % (w+1)].size()-1ll]);
		}
		if ((lld)window2[i % (w+d+1)].size() == 0ll) {
			window2[i % (w+d+1)].push_back(0);
			if (i == w+d+1) {
				window2[i % (w+d+1)].push_back(temp);
			}
		} else {
			window2[i% (w+d+1)].push_back(temp + window2[i%(w+d+1)][(lld)window2[i % (w+d+1)].size()-1ll]);
		}
	}

	for (auto i : prefix_sum) cout << i << " " ;
	cout << endl;
	for (auto i : window1) {for (auto j : i) cout << j << ", "; cout << "\n";}
	for (auto i : window2) {for (auto j : i) cout << j << ", "; cout << "\n";}

	lld ans1 = 0ll, ans2 = 0ll;
	for4(j, 1, w+1, 1) {
		for4 (i, 1, j+2, 1) {
			lld ind = (i-1) % (j+1);
			lld sz = lld(window1[ind].size());
			deb(i); deb(ind); deb(sz);
			cout << prefix_sum[n] - prefix_sum[i-1] - window1[ind][sz-1] << " ";
			if (i != w+1)
				ans1 = max(ans1, prefix_sum[n] - prefix_sum[i-1] - window1[ind][sz-1]);
			else
				ans1 = max(ans1, prefix_sum[n] - prefix_sum[i-1] - window1[ind][sz-1] + window1[ind][1]);
			cout << ans1 << "\n";
		}
	}

	for4 (i, 1, w+d+2, 1) {
		lld ind = (i-1) % (w+d+1);
		lld sz = lld(window1[ind].size());
		if (i != w+d+1)
			ans2 = max(ans2, prefix_sum[n] - prefix_sum[i-1] - window2[ind][sz-1]);
		else
			ans2 = max(ans2, prefix_sum[n] - prefix_sum[i-1] - window2[ind][sz-1] + window2[ind][1]);
	}

	cout << ans1 << " " << ans2;
    cout << "\n"; 

    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.precision(10);

    lld T3X0 = 0, T353 = 1;

    TESTCASES() 
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought :  null  