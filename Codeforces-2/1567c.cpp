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


#pragma GCC optimize("O3,unroll-loops,trapv")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"



typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};





const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;










/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    string s; cin >> s;
    // reverse(all(s));

    lld n = len(s);

    string a1 = "0", a2 = "0";

    forn(i, n) {
        if (i & 1) {
            a1 += s[i];
        } else {
            a2 += s[i];
        }
    }


    lld ans = (stoi(a1) + 1) * (stoi(a2) + 1);

    cout << ans - 2;

    // vector<vector<lld>> dp(n + 1, vector<lld> (2, 0));

    // dp[0][0] = 1;
    // // dp[0][1] = 1;


    // vector<pair<lld, lld>> cnt(10);

    // forn(i, 10) {
    //     forn(j, 10) {
    //         lld num = i+j;
    //         if ((num) < 10) {
    //             cnt[num].f1 += 1;
    //         } else {
    //             cnt[num % 10].s2 += 1;
    //         }
    //     }
    // }

    // dp[0][0] = 1;

    // for (int i = 0; i < n; i++) {
    //     dp[i+1][0] = cnt[s[i] - '0'].f1 * ((i-1>=0?dp[i-1][0]:1ll)) + 
    //         ((i-1>=0?dp[i-1][1]:0ll) * cnt[(s[i] - '0' + 9) % 10].f1);
    //     dp[i+1][1] = cnt[s[i] - '0'].s2 * (dp[i][0]);
    // }


    // NonIterable.print(dp);

    // cout << dp[n][0] - 2;

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif


    int __NTestCases = 1;
    cin >> __NTestCases;

    for (int _TestCase = 1; _TestCase <= __NTestCases; _TestCase++) {
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
    .?.?.?.
*/

// for (int i = 0; i < n; i++) {
//     dp[i + 1][0] = dp[i + 1][1] = dp[i][0];
//     for (lld x = 0; x <= 9; x++) {
//         for (lld y = 0; y <= 9; y++) {
//             lld reswa = x + y;
//             // if (i == n and (x == 0 or y == 0)) continue;
//             if ((reswa % 10) == (s[i] - '0')) {
//                 // _____error_____(i, x, y);
//                 if (reswa >= 10) {
//                     dp[i + 1][1] += 1;
//                 } else {
//                     dp[i + 1][0] += 1;
//                 }
//             } else if (((1 + reswa) % 10) == (s[i] - '0')) {
//                 // _____error_____(i, x, y);
//                 if (reswa >= 10) {
//                     dp[i + 1][1] += (i - 1 >= 0 ? 1ll : 0ll);
//                 } else {
//                     dp[i + 1][0] += (i - 1 >= 0 ? 1ll : 0ll);
//                 }
//             }
//         }
//     }
// }