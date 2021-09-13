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
};









/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/



struct Node {
    int leftBrackets = 0, rightBrackets = 0, correctSequence = 0;
    Node (int m_leftBrackets, int m_rightBrackets, int m_correctSequence)
        : leftBrackets(m_leftBrackets), rightBrackets(m_rightBrackets), correctSequence(m_correctSequence) { }
};

Node merge_func(Node a, Node b) {
    int gotIt = min(a.leftBrackets, b.rightBrackets);
    return Node(a.leftBrackets + b.leftBrackets - gotIt,
                a.rightBrackets + b.rightBrackets - gotIt,
                a.correctSequence + b.correctSequence + 2 * gotIt);
}


Node makeNode(char c) {
    if (c == '(') {
        return Node(1, 0, 0);
    } else {
        return Node(0, 1, 0);
    }
}


void solveEachTest(int _TestCase) {
    cout << "Test " << _TestCase << ":\n";
    int n; cin >> n;
    string s; cin >> s;
    vector<Node> arr(n, Node(0, 0, 0));
    forn(i, n) {
        arr[i] = makeNode(s[i]);
    }
    segment_tree<Node, Node(*)(Node, Node)> segg(arr, merge_func, Node(0, 0, 0));
    int q; cin >> q;
    forn(i, q) {
        int pos; cin >> pos;
        if (pos == 0) {
            lld sz = segg.query_all().correctSequence;
            if (sz == n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            pos--;
            s[pos] = (s[pos] == '(' ? ')' : '(');
            segg.set(pos, makeNode(s[pos]));
        }
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


    int __NTestCases = 10;
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
