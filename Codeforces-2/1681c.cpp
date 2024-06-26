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





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    vector<pair<lld, lld>> ans;
    lld n; cin >> n;

    vector<lld> arr(n), brr(n);

    forn(i, n) cin >> arr[i];
    forn(i, n) cin >> brr[i];

    forn(i, n) {
        for (lld j = i+1; j < n; j++) {
            if (arr[i] >= arr[j] and brr[i] >= brr[j]) {
                swap(arr[i], arr[j]);
                swap(brr[i], brr[j]);
                ans.push_back({i+1, j+1});
            }
        }
    }

    // vector<pair<lld, lld>> arr(n), brr(n), crr(n);
    // forn(i, n) {
    //     cin >> arr[i].f1;
    //     arr[i].s2 = i;
    //     crr[i].f1 = arr[i].f1;
    //     crr[i].s2 = arr[i].s2;
    // }

    // map<lld, lld> posIn2nd;

    // forn(i, n) {
    //     cin >> brr[i].f1;
    //     brr[i].s2 = i;
    //     posIn2nd[i] = brr[i].f1;
    // }

    // sort(all(arr), [](pair<lld, lld> &a, pair<lld, lld> &b) {
    //     return (a.f1 == b.f1) ? a.s2 < b.s2 : a.f1 < b.f1;
    // });

    // sort(all(brr), [](pair<lld, lld> &a, pair<lld, lld> &b) {
    //     return (a.f1 == b.f1) ? a.s2 < b.s2 : a.f1 < b.f1;
    // });

    _____error_____(arr);
    _____error_____(brr);

    // bool ok = true;
    // forn(i, n) {
    //     ok &= (posIn2nd[arr[i].s2] == brr[i].f1);
    // }

    // _____error_____(ok);

    if (!is_sorted(all(arr)) or !is_sorted(all(brr))) {
        cout << "-1\n";
        return;
    }


    // forn(i, n) {
    //     lld j = i + 1;
    //     for (; j < n; j++) {
    //         if ((arr[i].f1 == crr[j].f1) && (arr[i].s2 == crr[j].s2)) {
    //             break;
    //         }
    //     }
    //     if (j < n) {
    //         ans.push_back({i+1, j+1});
    //         swap(crr[i], crr[j]);
    //     }
    // }

    cout << ans.size() << "\n";

    for (auto [a, b] : ans) {
        cout << a << " " << b << "\n";
    }

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
        // cout << "\n";
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
