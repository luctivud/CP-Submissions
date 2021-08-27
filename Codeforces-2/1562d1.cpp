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






/*  Snips   */


typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second



/*  Utils   */


const lld MOD = int(1e9) + 7;
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



signed pleaseAC(void) {

#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}


void IAmJustice(void) {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/IO/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/IO/Zoutput.txt", "w", stdout);
#endif

    return;
}














/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, q; cin >> n >> q;

    string s; cin >> s;

    vector<vector<lld>> dp(n, vector<lld> (4, 0));

    forn(i, n) {
        if (i > 0) {
            dp[i] = dp[i - 1];
        }
        if (!(i & 1)) {
            if (s[i] == '+') {
                dp[i][0] += 1;
            } else {
                dp[i][1] += 1;
            }
        } else {
            if (s[i] == '+') {
                dp[i][3] += 1;
            } else {
                dp[i][2] += 1;
            }
        }
    }

    forn(i, q) {
        lld l, r; cin >> l >> r;
        --l, --r;
        lld p1 = dp[r][0];
        lld n1 = dp[r][1];
        lld p2 = dp[r][2];
        lld n2 = dp[r][3];
        if (l > 0) {
            --l;
            p1 -= dp[l][0];
            n1 -= dp[l][1];
            p2 -= dp[l][2];
            n2 -= dp[l][3];
        }

        _____error_____(p1, n1, p2, n2);

        if (p1 + p2 == n1 + n2) {   
            cout << "0\n";
        } else if ((p1 + p2 + n1 + n2) & 1) {
            cout << "1\n";
            lld lo = l, hi = r, res = lo;
            while (lo <= hi) {
                lld mid = (lo + hi) / 2;
                lld p11 = 0ll, p22 = 0ll, n11 = 0ll, n22 = 0ll;
                
            }
        } else {
            cout << "2\n";
        }
    }

    // NonIterable.print(dp);

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    IAmJustice();

    int _T0T4 = 1;
    cin >> _T0T4;

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        // cout << "\n";
    }

    return pleaseAC();
}




/*  ~~
    .?.?.?.
*/
