/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIVUD
#include <buggyBaby.hpp>
pretty:: PrettyPrinter NonIterable;
#define cerr cout
#else
#define _____error_____(...)
#endif
// #pragma GCC optimize "trapv"


/*:::::::::::::::::::SNIPS::::::::::::::::::::::::::::*/

typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


/*::::::::::::::::::/SNIPS::::::::::::::::::::::::::::*/
/*:::::::::::::::::::UTILS::::::::::::::::::::::::::::*/


const long double EPS = 1e-6;
lld MOD = int(1e9) + 7;
lld &mod = MOD;

const lld maxn = 5001;


// lld dp[maxn][maxn] = {{0}};//, dp[maxn][maxn] = {{0}};

lld **dp;



/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld n, a, b, k; cin >> n >> a >> b >> k;
        --a, --b;
        dp = new int[n][k+1];
        memset(dp, 0, sizeof(dp));
        // memset(dp, 0, sizeof(dp));
        // vector<vector<lld>> dp(n, vector<lld>(k + 1, 0)), dp(n, vector<lld>(k + 1, 0));
        dp[a][0] = 1;

        // function updateDP = [] (lld l, lld m, lld r, lld res, lld mv) {
        //     (dp[l][mv] += res) %= mod;
        //     (dp[m][mv] -= res) %= mod;
        //     if (m+1 < n) (dp[m+1][mv] += res) %= mod;
        //     if (r + 1 < n) (dp[r+1][mv] -= res) %= mod;
        // };

        forn(move, k) {
            forn(i, n) {
                if (i == b) continue;
                // dp[l..r][move+1] += dp[i][move] =>
                // dp[l][move+1] += dp[i][move], dp[r+1][move+1] -= dp[i][move]
                lld diff = abs(i - b) - 1;
                lld l = max(0ll, i - diff), r = min(i + diff, n - 1), m = i;
                // updateDP(l, i, r, dp[i][move], move+1);
                lld res = dp[i][move];
                (dp[l][move+1] += res) %= mod;
                (dp[m][move+1] -= res) %= mod;
                if (m + 1 < n) (dp[m + 1][move+1] += res) %= mod;
                if (r + 1 < n) (dp[r + 1][move+1] -= res) %= mod;
                // dp[i][move+1] -= 1;
                // if (i+1 < n) dp[i+1][move+1] += 1;
            }
            // NonIterable.print(dp);
            forn1(i, n - 1) {
                (dp[i][move + 1] += dp[i - 1][move + 1]) %= mod;
            }
            forn(i, n) {
                dp[i][move + 1] = dp[i][move + 1];
            }
        }


        // NonIterable.print(dp);

        lld ans = 0ll;
        forn(i, n) {
            if (i == b) continue;
            (ans += dp[i][k]) %= mod;
        }

        cout << (ans + mod) % mod;

    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
};



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
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

    Solution Aurora;
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Aurora.SolveEachTest(_TestCase);
        Aurora.ResetTestCase();
    }


#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}

/*:::::::::::::::::::::/INVOC:::::::::::::::::::::::::*/
/*  ~~
Author   :  Udit "luctivud" Gupta
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/

// dp[a][0] = 1;
// forn1(i, n - 1) {
//     dp[i][0] += dp[i][0] + dp[i - 1][0];
// }

// function findPrefSum = [&] (lld l, lld r, lld mv) {
//     return (dp[r][mv] - (l>0 ? dp[l-1][mv] : 0ll)) % mod;
// };



// forn1(move, k) {
//     forn(i, n) {
//         // dp[i][move] = dp[l][move-1] + .. + dp[r][move-1] - dp[i][move-1];
//         // if (i == b) continue;
//         lld diff = abs(i - b) - 1;
//         lld l = max(0ll, i-diff), r = max(i+diff, n-1);
//         (dp[i][move] = findPrefSum(l, r, move-1) - dp[i][move-1]) %= mod;
//         (dp[i][move] += dp[i][move] + (i-1>=0?dp[i-1][move]:0ll)) %= mod;
//     }
// }
