//  J A I  S H R E E  R A M  //

#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
// #pragma GCC optimize ("Ofast")
// // #pragma GCC target ("fpmath=sse,sse2")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("-ffloat-store")

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using PBSET = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*  
    .insert(el) - set hai!
    .find_by_order(3) - returns an iterator to the k-th largest element (counting from zero)
    .order_of_key(6) - the number of items in a set that are strictly smaller than our item
*/




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






void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, k; cin >> n >> k;

    lld arr[n][n];
    forn(i, n) {
    	forn(j, n) {
    		cin >> arr[i][j];
    	}
    }

    lld posn = ((k*k)/2);

    // _____error_____(posn);


    lld ans = lld(1e18);

    // forn(i, n) {
    // 	if (i + k > n) break;
    // 	forn(j, n) {
    // 		PBSET<lld> ordered_ml;
    // 		if (j + k > n) break;
    // 		forn(xi, k) {
    // 			forn(xj, k) {
    // 				ordered_ml.insert(arr[i+xi][j+xj]);
    // 			}
    // 		}
    // 		// _____error_____(ordered_ml);
    // 		ans = min(ans, *ordered_ml.find_by_order(posn));
    // 	}
    // }

    bool rev = false;

    lld Horz = 0ll, Vert = k;
    PBSET<lld> ordered_ml;

    forn(i, k) {
    	forn (j, k) {
    		ordered_ml.insert(arr[i][j]);
    	}
    }

    ans = min(ans, *ordered_ml.find_by_order(posn));

    while (Horz < n) {
    	if (!rev) {
    		if (Vert == n) {
    			rev ^= 1;
    			for (lld xx = Vert-k; xx < Vert; xx++) {
    				ordered_ml.erase(ordered_ml.find(arr[Horz][xx]));
    				ordered_ml.insert(arr[Horz+k][xx]);
    			}
    			Vert--;
    		} else {
    			for (lld xx = Horz; xx < Horz+k; xx++) {
    				ordered_ml.erase(ordered_ml.find(arr[xx][Vert]));
    				ordered_ml.insert(arr[Horz+k][xx]);
    			}
    		}
    	} else {
    		if (Vert == 0) {
    			rev ^= 1;
    		} else {

    		}
    	}
    }
    	

	////
    cout << ans;
	_____error_____(ans);

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
