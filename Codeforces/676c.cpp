//  J A I  S H R E E  R A M  //

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "trapv"



#ifdef LUCTIVUD
    #include <buggyBaby.hpp>
    pretty:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #define _____error_____(...)
#endif



typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second



const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/


class Solution {
	static const int maxN = int(1e5);

  public:
	Solution() {
		MOD = mod = lld(1e9) + 7ll;
	}


  public:
	void SolveEachTest(int _TestCase) {
	    // cout << "Case #" << _TestCase << ":";
	    int N, K; cin >>  N >> K;
	    string s; cin >> s;

	    int ans = 0;
	    for (char c = 'a'; c <= 'z'; c++) {
	    	int tempK = 0;
	    	int l = 0, r = 0;
	    	while (r < N) {
	    		while (r < N) {
	    			if (s[r] != c) {
	    				if (tempK + 1 > K) {
	    					break;
	    				}
	    				tempK += 1;
	    			}
    				r++;
	    		}
	    		ans = max(ans, r - l);
	    		// _____error_____(c, l, r, tempK);
	    		while (tempK >= K) {
	    			if (s[l] != c) {
	    				tempK -= 1;
	    			}
	    			l++;
	    		}
	    		// _____error_____(c, l, r, tempK);
	    	}
	    }
		
		// _____error_____(ans);
		// _____error_____(s);
		// NonIterable.print(s);

		cout << ans;

	    return;
	}


  public:
	void reset_test() {
		cout << "\n";
	}

};







signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    int _T0T4 = 1;
    // cin >> _T0T4; 
    
    Solution Wrath;
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Wrath.SolveEachTest(_TestCase);
        Wrath.reset_test();
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

