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

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

/*          D S U         */

void makeSet(lld n, vector<lld> &par3t, vector<lld> &ran4k) {
    iota(all(par3t), 0ll);
}

lld find_repr(lld x, vector<lld> &par3t, vector<lld> &ran4k) {
    if (x != par3t[x])
        par3t[x] = find_repr(par3t[x], par3t, ran4k);
    return par3t[x];
}

void Union(lld x, lld y, vector<lld> &par3t, vector<lld> &ran4k) {
    x = find_repr(x, par3t, ran4k);
    y = find_repr(y, par3t, ran4k);

    if (x == y) return;

    if (ran4k[x] < ran4k[y]) { 
        par3t[x] = y; 
    } else if (ran4k[x] > ran4k[y]) { 
        par3t[y] = x; 
    } else { 
        par3t[y] = x; 
        ran4k[x] = ran4k[x] + 1; 
    } 
    return;
}



    // create par3t and ran4k at the place.





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;

    // string res = "";
    // forn(i, n) {
    // 	cin >> TempVar;
    // 	char TempVarC = char(TempVar + '0');
    // 	while (len(res) and TempVarC > res.back()) {
    // 		res.pop_back();
    // 	}
    // 	// res.push_back(TempVarC);
    // 	for (auto it : res) {
    // 		cout << it << ".";
    // 	}
    // 	cout << TempVarC << "\n";
    // 	res.push_back(TempVarC);
    // }

    vector<lld> par3t(n+1, 0);
    vector<lld> ran4k(n+1, 0);
    makeSet(n+1, par3t, ran4k);

    lld arr[n+1]; 
    arr[0] = 0;
    forn1(i, n) {
    	cin >> arr[i];
    }

    stack<pair<lld,lld>> st;
    vector<lld> pariii(n+1, 0);
    // st.push({-1, 0});

    for (lld ind = n; ind > 0; ind--) {
    	st.push({arr[ind], ind});
    	if (st.top().f1 == 1) {
    		auto [el, elPos] = st.top();
    		st.pop();
    		while (st.size() and st.top().f1 == el + 1) {
    			Union(elPos, st.top().s2, par3t, ran4k);
    			el = st.top().f1;
    			elPos = st.top().s2;
    			st.pop();
    		}
    		lld RRR = find_repr(elPos, par3t, ran4k);
    		// _____error_____(RRR);
    		pariii[RRR] = ind-1;
    	}
    }

    forn1(i, n) {
    	pariii[i] = pariii[find_repr(i, par3t, ran4k)];
    }
    // _____error_____(pariii);

    vector<string> ans(n+1, "");
    forn1(i, n) {
    	if (pariii[i] == 0) {
    		ans[i] += to_string(arr[i]);
    	} else {
    		ans[i] = ans[pariii[i]];
    		ans[i] += '.';
    		ans[i] += to_string(arr[i]);
    	}
    }
    
    // cout << n << "\n";
    forn1(i, n) {
    	cout << ans[i] << "\n";
    }

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
    cin >> _T0T4; 


    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        // cout << "\n"; 
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
