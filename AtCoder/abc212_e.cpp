// ------------------------------------------------------------------- //
/*

      Author :  Udit "luctivud" Gupta 
    Linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
      Github :  https://github.com/luctivud

*/
// ------------------------------------------------------------------- //



/*          J  A  I   S  H  R  E  E   R  A  M          */



#include <bits/stdc++.h>
using namespace std;

#ifdef LUCTIVUD
    #include <buggyBaby.hpp>
    pretty:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #define _____error_____(...)
#endif
#pragma GCC optimize "trapv"



/*
    Snips
            */



typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


/*
    Utils
            */


const lld MOD = 998244353;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void IAmJustice(void) {
   
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    return;
}



signed pleaseAC(void) {

    #ifdef LUCTIVUD
      // auto end_time = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double> diff = end_time - start_time;
      // cerr << "Finished in : " << diff.count() << "\n";
    #endif
    
    return 0;
}









/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/



class Solution {
    static const int maxN = int(1e5) + 2;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ": ";
        lld n, m, k; cin >> n >> m >> k;
        // vector<vector<lld>> edges(n, vector<lld> (n, 1));
        vector<lld> adj[n];
        // forn(i, n) {
        //     edges[i][i] = 0;
        // }
        forn(i, m) {
            lld u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            // edges[u][v] = edges[v][u] = 0;
        }
        vector<vector<lld>> dp(k+1, vector<lld> (n, 0));
        // vector<lld> inkatar(n, 0);
        // inkatar[0] = 1;
        dp[0][0] = 1;

        lld riza = 1ll;
        forn1(i, k) {
            lld temp = 0ll;
            forn(j, n) {
                dp[i][j] = (riza - dp[i-1][j] + mod) % mod;
                forn(zz, len(adj[j])) {
                    ((dp[i][j] -= dp[i-1][adj[j][zz]]) += mod) %= mod;
                }
                (temp += dp[i][j]) %= mod;
            }
            riza = temp;
        }

        // forn1(i, k) {
        //     forn(j, n) {
        //         forn(l, n) {
        //             (dp[i][j] += (edges[l][j] ? dp[i-1][l] : 0ll)) %= mod;
        //         }
        //         // dp[i][j] += dp[i-1][j];
        //     }
        //     // _____error_____(dp[i]);
        // }
        // NonIterable.print(edges);
        // NonIterable.print(dp);
        cout << dp[k][0];
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
};



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/



signed main() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    IAmJustice();

    int _T0T4 = 1;
    // cin >> _T0T4; 
    
    Solution Aurora;
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Aurora.SolveEachTest(_TestCase);
        Aurora.ResetTestCase();
    }

    return pleaseAC(); 
}



/*  ~~

    I ponder of something great
    My lungs will fill and then deflate
    They fill with fire, exhale desire
    I know it's dire my time today

    I have these thoughts, so often I ought
    To replace that slot with what I once bought
    'Cause somebody stole my car radio
    And now I just sit in silence

    Sometimes quiet is violent
    I find it hard to hide it
    My pride is no longer inside
    It's on my sleeve
    My skin will scream reminding me of
    Who I killed inside my dream
    I hate this car that I'm driving
    There's no hiding for me
    I'm forced to deal with what I feel
    There is no distraction to mask what is real
    I could pull the steering wheel

*/

