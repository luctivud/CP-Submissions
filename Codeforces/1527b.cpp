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



void solvePalindrome(string s, lld n, lld &alice, lld &bob, lld &flag) {
	if (n & 1) {
    	if (s[n/2] == '0') {
    		s[n/2] = '1';
    		flag = true;
    		alice++;
    	}
    }

    lld cnt = 0ll;
    forn(i, n) {
    	cnt += s[i] == '0';
    }

    lld zeta = (cnt >> 1) - 1;

    if (cnt != 0) {
	    if (flag) {
	    	bob += zeta + 2;
	    	alice += zeta;
	    } else {
	    	alice += zeta + 2;
	    	bob += zeta;
	    }
    }
    return;
}



void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    string s; cin >> s;

    lld alice = 0ll, bob = 0ll, flag = 0ll;

    lld mismatch = 0ll;
    forn(i, n/2) {
    	mismatch += (s[i] != s[n-i-1]);
    	if (s[i] != s[n-i-1]) {
	    	if (s[i] == '0') s[i] = '1';
	    	else s[n-i-1] = '1';
    	}
    }
    
    bob += mismatch;

    // if (n & 1 and s[n/2] == '0') {
    // 	bob += 1;
    // 	s[n/2] = '1';
    // }

    // _____error_____(alice, bob, mismatch, s);
    solvePalindrome(s, n, alice, bob, flag);

    if (alice == bob) {
    	cout << "DRAW";
    } else {
    	cout << (alice < bob ? "ALICE" : "BOB");
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
