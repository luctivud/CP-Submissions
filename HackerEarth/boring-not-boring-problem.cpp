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







lld power(lld x, lld y) {
    lld res = 1;

    x = x % MOD;

    if (x == 0) return 0;

    while (y > 0)  {
        if (y & 1)
            res = (res * x) % MOD;

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}






/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/


void perform(lld mask, vector<lld> &dp, lld &ans) {
    forn(i, 21) {
        if ((mask & 1 << i) == 0)
            continue;
        if (!dp[i]) {
            dp[i] = mask;
            ++ans;
            return;
        }
        mask ^= dp[i];
    }
}



lld maxSize(map<lld, lld> &avatars) {
    lld ans = 0ll;
    vector<lld> dp(20, 0ll);

    for (auto &[ke, va] : avatars) {
        forn(i, va) {
            perform(ke, dp, ans);
        }
    }

    return (power(2ll, ans) % mod);
}




void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    int n, m; cin >> n >> m;
    vector<pair<map<int, int>, map<int, int>>> arr(n + 1);

    forn(j, m) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        arr[l].f1[x] += 1;
        arr[r].s2[x] += 1;
    }

    _____error_____(arr);

    lld ans = 1ll;

    map<int, int> avatars;
    avatars[0] = 1;

    forn(i, n) {
        for (auto &[ke, va] : arr[i].f1) {
            avatars[ke] += va;
        }
        for (auto &[ke, va] : arr[i].s2) {
            avatars[ke] -= va;
            if (avatars[ke] == 0) {
                avatars.erase(ke);
            }
        }
        _____error_____(avatars);
        (ans *= avatars.size()) %= mod;
    }

    cout << ans;

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
    // cin >> __NTestCases;

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
