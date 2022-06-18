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

bool allOk(lld a, lld b, lld c, lld d, lld e) {
    return (a >= 1) && (b >= 1) && (c >= 1) && (d >= 1) and (e >= 1);
}



void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    vector<lld> r(3), c(3);
    forn(i, 3) {
        cin >> r[i];
    }
    forn(i, 3) {
        cin >> c[i];
    }

    vector<vector<lld>> maxTrix(3, vector<lld> (3, mod));
    forn(i, 3) {
        forn(j, 3) {
            maxTrix[i][j] = min({maxTrix[i][j], r[i], c[j]});
        }
    }

    // NonIterable.print(maxTrix);
    lld ans = 0ll;

    forn1(a00, 30) {
        forn1(a01, 30) {
            forn1(a10, 30) {
                forn1(a11, 30) {
                    lld a02 = r[0] - a00 - a01;
                    lld a12 = r[1] - a10 - a11;
                    lld a20 = c[0] - a00 - a10;
                    lld a21 = c[1] - a01 - a11;
                    lld a22_r = r[2] - a20 - a21;
                    lld a22_c = c[2] - a02 - a12;
                    if ((a22_c == a22_r) && allOk(a02, a12, a20, a21, a22_r)) {
                        ans += 1;
                    }
                }
            }
        }
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
    freopen("/home/udit/CPPrc/zinput.txt", "r", stdin);
    freopen("/home/udit/CPPrc/zoutput.txt", "w", stdout);
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
