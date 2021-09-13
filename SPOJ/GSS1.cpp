/*          J  A  I   S  H  R  E  E   R  A  M          */
#include <bits/stdc++.h>
using namespace std;

#ifdef LUCTIVUD
#include <debug_error.hpp>
pprint:: PrettyPrinter NonIterable;
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



const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;


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


class Node {
public:
    int leftMax, rightMax, sumOfSegment;
    bool isConnected;

    Node() : Node(0, 0, 0, true) { }

    Node(int m_leftMax, int m_rightMax, int m_sumOfSegment, bool m_isConnected)
        :   leftMax(m_leftMax),
            rightMax(m_rightMax),
            sumOfSegment(m_sumOfSegment),
            isConnected(m_isConnected)
    { }
};


Node merge_func (Node a, Node b) {
    int netSum = a.sumOfSegment + b.sumOfSegment;
    if (a.sumOfSegment >= 0 and b.sumOfSegment >= 0) {
        return Node(netSum, netSum, netSum, true);
    } else if (a.sumOfSegment >= 0) {
        if (b.leftMax >= 0) {
            return Node(a.sumOfSegment + b.leftMax, b.rightMax, netSum, false);
        } else {
            return Node(a.leftMax, b.rightMax, netSum, false);
        }
    } else if (b.sumOfSegment >= 0) {
        if (a.rightMax >= 0) {
            return Node(a.leftMax, a.rightMax + b.sumOfSegment, netSum, false);
        } else {
            return Node(a.leftMax, b.rightMax, netSum, false);
        }
    } else {
        
    }
    return Node();
}


void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    int n;
    cin >> n;

    vector<int> arr(n);
    forn(i, n) cin >> arr[i];

    segment_tree<int, int (*) (int, int)> segg(arr, [](int a, int b) { return max(a, b);}, 0);

    int q;
    cin >> q;

    forn(qq, q) {
        int l, r;
        cin >> l >> r;
        cout << segg.query(l - 1, r) << "\n";
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
