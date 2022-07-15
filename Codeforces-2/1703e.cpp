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


bool isvalid(pair<lld, lld> &p, lld n) {
    return p.f1 >= 0 and p.f1 < n and p.s2 >= 0 and p.s2 < n;
}


void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    vector<string> arr(n);
    forn(i, n) {
        cin >> arr[i];
    }

    // NonIterable.print(arr);

    // forn(i, n) {
    //     forn(j, n) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    lld ans = 0ll;
    forn(i, n) {
        forn(j, n) {
            lld cnt0 = 0ll, cnt1 = 0ll;
            set<pair<lld, lld>> points;
            points.insert({i, j});
            points.insert({n - j - 1, i});
            points.insert({j, n - i - 1});
            points.insert({n - i - 1, n - j - 1});
            for(auto k : points) {
                if (isvalid(k, n)) {
                    ((arr[k.f1][k.s2] == '1') ? cnt1 : cnt0) += 1;
                }
            }
            // _____error_____(i, j, cnt0, cnt1);
            ans += min(cnt0, cnt1);
        }
    }
    _____error_____(ans);
    assert(ans % 4 == 0);
    ans /= 4;
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
