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


// const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/


class Solution {
    static int solve(int ind, double timmy, int skipped, vector<int> dist, int speed, int hh, vector<map<double, int>> &dp) {
        double EPS = 1e-8;
        // _____error_____(ind, timmy, skipped);
        if (ind == (int)dist.size()) {
            if (timmy > hh) return int(1e6);
            return skipped;
        }
        if (timmy > hh) {
        	return int(1e6);
        }
        if (dp[ind].count(timmy) > 0) {
            return dp[ind][timmy];
        }
        int &res = dp[ind][timmy];
        timmy += ((double)dist[ind] / speed);
        double timmy2 = ceil(timmy - EPS);
        ++ind;
        if (abs(timmy - timmy2) < EPS) {
        	return res = solve(ind, timmy2, skipped, dist, speed, hh, dp);
        }
        return res = min(solve(ind, timmy2, skipped, dist, speed, hh, dp), 
                         solve(ind, timmy, skipped+1, dist, speed, hh, dp)
                        );
    }
    
public:
    int minSkips(vector<int>& dist, int speed, int hh) {
        int n = (int)dist.size();
        vector<map<double, int>> dp(n);
        int ans = solve(0, 0.0, 0, dist, speed, hh, dp);
        if (ans < int(1e6)) {
            return ans;
        }
        return -1;
    }
};





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    
	Solution sol;
	vector<int> dist = {40,31,8,31,73,11,11,94,63,9,98,69,99,17,17,85,61,71,22,34,68,78,55,28,70,97,94,89,26,92,40,52,86,84,48,57,67,58,16,32,29,9,44,3,76,71,30,76,29,1,10,91,81,8,30,9,5,43,10,66,31,36,86,63,28,70,17,93,74,74,61,32,61};
	int speed = 55, hh = 96;

	cout << (sol.minSkips(dist, speed, hh));
    
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
