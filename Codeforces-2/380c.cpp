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





// segment_tree snippet from Aeren's repo (orz).


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
struct segment_tree {
    int n, size, log;
    vector<T> data;
    F TT; // monoid operation (always adjacent)
    T T_id; // monoid identity
    // O(n)
    segment_tree(int m_n, F m_TT, T m_T_id): segment_tree(vector<T>(m_n, m_T_id), m_TT, m_T_id) {}
    // O(n)
    segment_tree(int m_n, T m_init, F m_TT, T m_T_id): segment_tree(vector<T>(m_n, m_init), m_TT, m_T_id) {}
    // O(n)
    segment_tree(const vector<T> &a, F m_TT, T m_T_id): n((int)a.size()), TT(m_TT), T_id(m_T_id) { // O(n)
        log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
        data = vector<T>(size << 1, T_id);
        copy(a.begin(), a.end(), data.begin() + size);
        for (auto i = size - 1; i >= 1; -- i) refresh(i);
    }
    // O(1)
    void refresh(int i) {
        data[i] = TT(data[i << 1], data[i << 1 | 1]);
    }
    // O(log n)
    void set(int p, T x) {
        assert(0 <= p && p < n);
        data[p += size] = x;
        for (auto i = 1; i <= log; ++ i) refresh(p >> i);
    }
    // O(1)
    T query(int p) const {
        assert(0 <= p && p < n);
        return data[p + size];
    }
    // O(log n)
    T query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        T res_left = T_id, res_right = T_id;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res_left = TT(res_left, data[l ++]);
            if (r & 1) res_right = TT(data[-- r], res_right);
        }
        return TT(res_left, res_right);
    }
    // O(1)
    T query_all() const {
        return data[1];
    }
    // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns min r with F (n + 1 if no such r)
    // O(log n)
    int max_pref(int l, auto f) const {
        assert(0 <= l && l <= n);
        if (!f(T_id)) return l;
        // if(l == n) return n + 1; // is this needed?
        l += size;
        T sm = T_id;
        do {
            while (~l & 1) l >>= 1;
            if (!f(TT(sm, data[l]))) {
                while (l < size) {
                    l = l << 1;
                    if (f(TT(sm, data[l]))) sm = TT(sm, data[l ++]);
                }
                return l - size + 1;
            }
            sm = TT(sm, data[l ++]);
        } while ((l & -l) != l);
        return n + 1;
    }
    // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns max l with F (-1 if no such l)
    // O(log n)
    int min_suff(int r, auto f) const {
        assert(0 <= r && r <= n);
        if (!f(T_id)) return r;
        // if(r == 0) return -1; // is this needed?
        r += size;
        T sm = T_id;
        do {
            -- r;
            while (r > 1 && r & 1) r >>= 1;
            if (!f(TT(data[r], sm))) {
                while (r < size) {
                    r = r << 1 | 1;
                    if (f(TT(data[r], sm))) sm = TT(data[r --], sm);
                }
                return r - size;
            }
            sm = TT(data[r], sm);
        } while ((r & -r) != r);
        return -1;
    }
};




class Node {
public:
    lld maxSz = 0;
    lld leftBrackets = 0ll, rightBrackets = 0ll;

    Node(lld m_maxSz = 0ll, lld m_leftBrackets = 0ll, lld m_rightBrackets = 0ll)
        : maxSz(m_maxSz),  leftBrackets(m_leftBrackets), rightBrackets(m_rightBrackets)
    { }
};


Node merge_func(Node l, Node r) {
    lld newSz = min(l.leftBrackets, r.rightBrackets);
    return Node(
               l.maxSz + r.maxSz + 2*newSz,
               l.leftBrackets + r.leftBrackets - newSz,
               r.rightBrackets + l.rightBrackets - newSz
           );
}



/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    string s; cin >> s;
    lld n = len(s);

    vector<Node> arr(n);
    forn(i, n) {
        if (s[i] == '(') {
            arr[i].leftBrackets = 1;
        } else {
            arr[i].rightBrackets = 1;
        }
    }

    segment_tree brcSeq(arr, merge_func, Node(0, 0, 0));

    lld q; cin >> q;
    forn(qq, q) {
        int l, r;
        cin >> l >> r;
        cout << brcSeq.query(l - 1, r).maxSz << "\n";
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
