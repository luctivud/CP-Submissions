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


// sparse_table snippet from Aeren's repo (orz).


/* As a BlackBox -

Eg:

    ---- ----

    const bitset<26> merge_func(bitset<26> a, bitset<26> b) {
        return (a | b);
    }
    segment_tree uniqSeg(arr, merge_func, bitset<26> {0});

    ---- ----

    arr - is the array for original seg tree nodes
    merge_func or class template F is function, can be passed as a lambda from ++2a


    0-based indexing

    pass for query [l, r)

    set position (pos, val)

    ---- ----

    F -> Function
    TT -> operation or real function
    T -> data type
    T_id -> default value for nodes in segment_tree

    ---- ----

*/



template<class T, class F>
struct sparse_table {
    int n;
    vector<vector<T>> data;
    F TT;
    T T_id;
    sparse_table() { }
    // O(n log n)
    sparse_table(const vector<T> &a, F m_TT, T m_T_id): n((int)a.size()), data({a}), TT(m_TT), T_id(m_T_id) {
        for (auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i) {
            data.emplace_back(n - (p << 1) + 1);
            for (auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = TT(data[i - 1][j], data[i - 1][j + p]);
        }
    }
    // O(1)
    T query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return T_id;
        int d = __lg(r - l);
        return TT(data[d][l], data[d][r - (1 << d)]);
    }
};



lld merge_func(lld l,  lld r) {
    return min(l, r);
}



/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, q; cin >> n >> q;

    vector<lld> arr(n);
    forn(i, n) {
        cin >> arr[i];
    }

    sparse_table sp(arr, merge_func, inf);

    forn(qq, q) {
        int l, r; cin >> l >> r;
        cout << sp.query(l - 1, r) << "\n";
    }

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