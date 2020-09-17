/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:,'..'xXWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO. .:kOo.,kNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO. .lNWWo..lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MNOxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxMMMMWKxoloxKWNc  .:xxd;  ,dxxxkXMXkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxMM
MKc''''''''''''''''.  ..'''''.   .''''.  .''MMMWx..,:. .xXo''.  .''.  ..'';kMk;'''''.  .'.''.  .''''''.  ..''.   .''MM
MWNXNNNNNNNNNNNNNNNO' ;KNNNNNKo. cKNNNd. lXNMMMK; ,0Wx. :NWXXl .dNNO' ;KNNNWMWNNNNNXc .kNNNNx. cXNNNNNO' ;KNN0; 'ONNMM
MMMMMMMMMMMMMMMMMWM0' :NMMMMWMX: .OMWWx. oWMMMMWx. ';. .dNMWWo .xMM0' :NWWMMMMMMMMWWl .OMMMWk. lWWMMWM0' ;XMMX: ,KMMMM
MMMMMMWMWkccccccccc;. :NMWNNNKd. :XMMWx. oWMMMWKo. .',. .,ldx; .dMM0' :NMMMMMMMNNWMWl .OMMMWk. lWMMMMM0' ;XMMX: ,0MMMM
MMWXKNWMWxcc,. .;cc;. :XMk,''..'lKWMMWx. oWMNx:. .lONNKxl.     .xMM0' :NMMMMMM0:,oKO' ,KMMMMk. lWWNkoc,. .;::;. ,KMMMM
MMXc.lXMMWWWNd..xWM0' :NM0;  ;kXWMMMWNl  oWMK:.;xXWWMWXx:. ,c' .dMM0' :NMMMMMMKc. ...;kWMMMMk. lWWc .:;. .clc:. ,KMMMM
MWWx. lXMWMMMK, lWM0' :NMMNx'.,ldxxoc'   oWMWNKNWWWN0o' .:kNWo .dMM0' :NMMMMMMMNO;  ,OWWWMMMk. lWM' lXx. lNMMX: ,KMMMM
MMMWk'.,xKNX0c..kWM0' :NMMMMNkl;,'',:l:  oWMMMMMWMWO' 'l0WMWWo .xMM0' :NMMMMMMMMMNd. .oXWMMMk. lWMd.....;0WMMX: ,KMMMM
MMMMWKo'...'..:kWMM0' :NMMMMMMMWWNNWWWx. oWMMMMMMMMWOxXWMWMWWo .xMM0' :NMMMMMMMMMMMKl. ,kNMMk. lWMWKkxx0NMWMMX: ,KMMMM
MMMMMMMN0kxk0XNWMMWKl;xNMMMMMMMMMMMMWM0c;kWMMMMMMMMMMMWWMMMMWk;:OMMXl,dNMMMMMMMMMMMMWO; .dNM0c;kWWMMMMMMMMMMMNd,oXMMMM
MMMMMMMMWWMWMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMWWMMWMMMMMMMMMMMMMMNkxKWMMWWMMMMMMMMMMMMMMWMMWMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*/

//             Author: Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)                  //


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T> using FSET = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define         _input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((lld)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define             deb1(x)    cout << #x << "=" << (x) << "\n";
#define             deb2(x)    cout << #x << "=" << (x) << " ";



const int d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};


bool cmp(const pair<lld, lld> &i, const pair<lld, lld> j) {
	return i.second < j.second;
}
 

void dfs(lld parent, lld dep, vector<lld> &depths, vector<lld> adj[], vector<bool> &visited) {
	if (visited[parent]) {
		return;
	}

	visited[parent] = true;
	depths[parent] = dep;

	for (auto i : adj[parent]) {
		if (!visited[i]) {
			dfs(i, dep + 1, depths, adj, visited);
		}
	}
	return;
}



void solveEachTest(lld T35TC453N = 1) {
	lld n; cin >> n;
	vector<lld> adj[n];
	for4(i, 0, n - 1, 1) {
		lld a, b; cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	lld parent = -1;

	for4(i, 0, n, 1) {
		if (len(adj[i]) == 1ll) {
			parent = i;
			break;
		}
	}

	vector<lld> depths(n, 0);
	vector<bool> visited(n, false);
	dfs(parent, 0, depths, adj, visited);

	/////////////////////////////////////////////////////////////
	// deb1(parent);

	// for (auto i : depths) {
	// 	cout << i << " ";
	// }

	string s; cin >> s;

	string col1, col2;

	for (auto i : depths) {
		if (i & 1) {
			col1.pb('1');
			col2.pb('0');
		} else {
			col2.pb('1');
			col1.pb('0');
		}
	}

	// cout << col1 << "\n" << col2;

	bool ok = false;

	lld ans1 = INT_MAX;
	lld ans2 = INT_MAX;

	lld match = count(all(s), '0');
	if (count(all(col1), '0') == match) {
		ok = true;
		ans1 = 0ll;
		vector<pair<lld, lld>> mismatchZero;
		vector<pair<lld, lld>> mismatchOne;
		for4(i, 0, n, 1) {
			if (s[i] != col1[i]) {
				if (s[i] == '1') {
					mismatchOne.pb(make_pair(i, depths[i]));
				} else {
					mismatchZero.pb({i, depths[i]});
				}
			}
		}

		lld sz1 = len(mismatchZero);
		// lld sz2 = len(mismatchOne);

		sort(all(mismatchOne), cmp);
		sort(all(mismatchZero), cmp);

		for4(i, 0, sz1, 1) {
			ans1 += abs(mismatchZero[i].second - mismatchOne[i].second);
		}
	}



	if (count(all(col2), '0') == match) {
		ok = true;
		ans2 = 0ll;
		vector<pair<lld, lld>> mismatchZero;
		vector<pair<lld, lld>> mismatchOne;
		for4(i, 0, n, 1) {
			if (s[i] != col2[i]) {
				if (s[i] == '1') {
					mismatchOne.pb(make_pair(i, depths[i]));
				} else {
					mismatchZero.pb({i, depths[i]});
				}
			}
		}

		lld sz1 = len(mismatchZero);
		// lld sz2 = len(mismatchOne);

		sort(all(mismatchOne), cmp);
		sort(all(mismatchZero), cmp);

		for4(i, 0, sz1, 1) {
			ans2 += abs(mismatchZero[i].second - mismatchOne[i].second);
		}
	}


	cout << (ok ? min(ans1, ans2) : -1);

	cout << "\n";

	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10);

	lld T3X0 = 0, T353 = 1;

	TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}
// Random Thought :  null