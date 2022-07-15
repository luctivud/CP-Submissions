/*          J  A  I   S  H  R  E  E   R  A  M          */
#ifdef LUCTIVUD
    #include <mydebug.h>
    pprint:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #include <bits/stdc++.h>
    using namespace std;
    #define _____error_____(...)
#endif


#pragma GCC optimize("O3,unroll-loops,trapv")
// #pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
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
lld n, k; 


lld solve(lld ind, lld op, vector<vector<lld>> &lalala, vector<vector<lld>> &dp) {
    if (ind == n) return 0ll;
    lld &x = dp[ind][op];
    if (x != -inf) return x;
    return x = max(
            -k + lalala[ind][op] + solve(ind+1, op, lalala, dp),
            lalala[ind][op+1] + solve(ind+1, min(op+1, 58ll), lalala, dp)
        );
}



void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    
    cin >> n >> k;

    vector<lld> arr(n);
    forn(i, n) {
        cin >> arr[i];
    }

    // vector<vector<lld>> pref_sums(n, vector<lld> (60, 0)), 
    vector<vector<lld>> lalala(n, vector<lld> (60, 0)), dp(n, vector<lld> (60, -inf));
    forn(i, n) {
        forn(j, 60) {
            // pref_sums[i][j] = (arr[i] >> j);
            lalala[i][j] = (arr[i] >> j);
        }
    }
        

    // for (lld i = n-2; i >= 0; i--) {
    //     forn(j, 60) {
    //         pref_sums[i][j] += pref_sums[i+1][j];
    //     }
    // }

    cout << solve(0, 0, lalala, dp);
    return;

    // /// no greedy stupid;

    // lld ans = 0ll, op = 0ll;
    // forn(i, n) {
    //     lld now = pref_sums[i][op];
    //     lld afop = pref_sums[i][op+1];
    //     if (now - afop < k) {
    //         op += 1;
    //         op = min(op, 58ll);
    //     } else {
    //         ans -= k;
    //     }
    //     // _____error_____(now, afop, op);
    //     ans += lalala[i][op];
    // }

    // // NonIterable.print(lalala);
    // // NonIterable.print(pref_sums);

    // cout << ans;

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/udit/CPPrc/zinput.txt", "r", stdin);
        freopen("/home/udit/CPPrc/zoutput.txt", "w", stdout);
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
