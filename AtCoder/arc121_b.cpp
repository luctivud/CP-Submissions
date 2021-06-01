//  J A I  S H R E E  R A M  //

#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
// #pragma GCC optimize ("Ofast")
// // #pragma GCC target ("fpmath=sse,sse2")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("-ffloat-store")


using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cout << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << H << ", "; dbg_out(T...);}
#define _____error_____(...) cout << #__VA_ARGS__ << " : ", dbg_out(__VA_ARGS__)

const lld d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const lld d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;

char TempVarChar;

/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/






void solveEachTest(int _TestCase) {
	// cout << "Case #" << _TestCase << ": ";
	lld n; cin >> n;

	map<char, vector<lld>> pos;

	forn(i, (2*n)) {
		cin >> TempVar >> TempVarChar;
		pos[TempVarChar].push_back(TempVar);
	}

	lld cntOdd = 0ll;

	string oddChar, evenChar;


	for (auto &[ke, va] : pos) {
		sort(all(va));
		if (len(va) & 1) {
			oddChar += ke;
			cntOdd++;
		} else {
			evenChar += ke;
		}
		// _____error_____(ke, va);
	}


	if (cntOdd == 0) {
		cout << "0";
		return;
	}

	// _____error_____(oddChar);

	lld ans = lld(1e18);

	// odd & odd

	for (auto &poso1 : pos[oddChar[0]]) {
		lld res = lld(1e18);
		auto it = upper_bound(all(pos[oddChar[1]]), poso1);
		if (it != pos[oddChar[1]].end()) {
			res = min(res, llabs(poso1 - *it));
		}
		if (it != pos[oddChar[1]].begin()) {
			it--;
			res = min(res, llabs(poso1 - *it));	
		}
		ans = min(ans, res);
	}

	// even - odd x 2

	if (len(evenChar) == 0) {
		cout << ans;
		return;
	}

	// _____error_____(ans);

	vector<pair<lld,lld>> o1e, o2e;

	forn(i, len(pos[evenChar[0]])) {
		lld pose = pos[evenChar[0]][i];
		auto it1 = upper_bound(all(pos[oddChar[0]]), pose);
		auto it2 = upper_bound(all(pos[oddChar[1]]), pose);

		lld res1 = lld(1e18), res2 = lld(1e18);

		if(it1 != pos[oddChar[0]].end()) {
			res1 = min(res1, llabs(pose - *it1));
		}
		if (it1 != pos[oddChar[0]].begin()) {
			it1--;
			res1 = min(res1, llabs(pose - *it1));
		}

		if(it2 != pos[oddChar[1]].end()) {
			res2 = min(res2, llabs(pose - *it2));
		}
		if (it2 != pos[oddChar[1]].begin()) {
			it2--;
			res2 = min(res2, llabs(pose - *it2));
		}
		o1e.push_back({res1, i});
		o2e.push_back({res2, i});
	}

	sort(all(o1e));
	sort(all(o2e));

	if (o1e[0].s2 == o2e[0].s2) {
		lld res = lld(1e18);
		res = min(res, o1e[0].f1 + o2e[1].f1);
		res = min(res, o1e[1].f1 + o2e[0].f1);
		ans = min(ans, res);
	} else {
		ans = min(ans, o1e[0].f1 + o2e[0].f1);
	}

	// _____error_____(pos);


	cout << ans;

	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// cout.precision(10); cout << fixed;
#ifdef LUCTIVUD
	// const auto start_time = std::chrono::high_resolution_clock::now();
	freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
	freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif


	MOD = mod = lld(1e9) + 7ll;
	lld _T0T4 = 1;
	// cin >> _T0T4;

	for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
		solveEachTest(_TestCase);
		cout << "\n";
	}


#ifdef LUCTIVUD
	// auto end_time = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double> diff = end_time - start_time;
	// cerr << "Finished in : " << diff.count() << "\n";
#endif

	return 0;
}


/*  ~~
Author   :  Udit "luctivud" Gupta
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
