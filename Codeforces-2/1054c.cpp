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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using PBSET = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*  
    .insert(el) - set hai!
    .find_by_order(3) - returns an iterator to the k-th largest element (counting from zero)
    .order_of_key(6) - the number of items in a set that are strictly smaller than our item
*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    vector<lld> l(n), r(n), arr(n, -1ll);
    forn(i, n) cin >> l[i];
    forn(i, n) cin >> r[i];

    map<lld, lld> vals;
    lld k = 100000ll, fac = 1ll;
    bool ok = true;
    PBSET<lld> oset;
    forn(i, n) {
        if (vals[l[i] + r[i]] != 0) {
            arr[i] = vals[l[i] + r[i]];
        } else if (l[i] == 0) {
            arr[i] = (k * fac);
            fac += 1;
        } else {
            if (l[i] > (lld)oset.size()) {
                ok = false;
                break;
            } else if (l[i] == (lld)oset.size()) {
                arr[i] = *(oset.rbegin()) / 2;
            } else {
                lld a = *oset.find_by_order(l[i]);
                lld b = *oset.find_by_order(l[i] - 1);
                _____error_____(oset);
                _____error_____(i, a, b);
                arr[i] = (a + b) / 2;
            }
        }
        oset.insert(arr[i]);
        vals[l[i] + r[i]] = arr[i];
    }


    oset.clear();
    forn(j, n) {
        lld i = n-j-1;
        ok &= ((lld)oset.order_of_key(arr[i]) == r[i]);
        oset.insert(arr[i]);
    }
    _____error_____(arr, ok);

    if (!ok) {
        cout << "NO";
        return;
    }

    cout << "YES\n";

    forn(i, n) {
        cout << n - oset.order_of_key(arr[i]) << " ";
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
