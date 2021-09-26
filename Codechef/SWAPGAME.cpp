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


// #pragma GCC optimize("O3,unroll-loops,trapv")
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

// #define int lld

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



lld merge_func(lld a, lld b) {
    return (a + b);
}



#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using PBSET = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*  
    .insert(el) - set hai!
    .find_by_order(3) - returns an iterator to the k-th largest element (counting from zero)
    .order_of_key(6) - the number of items in a set that are strictly smaller than our item
*/



/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/



const lld maxn = 1e5 + 2;
queue<lld> pos[maxn];

void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;

    vector<lld> arr(n), brr(n);
    // vector<queue<lld>> pos(maxn);
    forn(i, n) cin >> arr[i], pos[arr[i]].push(i);
    forn(i, n) cin >> brr[i];

    // _____error_____(pos);

    segment_tree segg(arr, merge_func, 0ll);

    PBSET<lld> removedIndices;


    lld ans = 0ll;
    for (lld i = n-1; i >= 0; i--) {
        lld ind = pos[brr[i]].front();
        lld indToRemove = ind;
        lld profit = segg.query((int)ind, (int)n);
        lld indxRemovedAfter = removedIndices.size() - removedIndices.order_of_key(ind);
        profit = ((n-ind - indxRemovedAfter) * brr[i]) - profit;

        // for (auto ind : pos[brr[i]]) {
        //     lld thisProfit = segg.query((int)ind, (int)n);
        //     lld indxRemovedAfter = removedIndices.size() - removedIndices.order_of_key(ind);
        //     _____error_____(ind, indxRemovedAfter, thisProfit, brr[i]);
        //     thisProfit = ((n-ind - indxRemovedAfter) * brr[i]) - thisProfit;
        //     _____error_____(thisProfit);
        //     if (thisProfit > profit) {
        //         profit = thisProfit;
        //         indToRemove = ind;
        //     }
        //     break;
        // }

        ans += profit;
        // pos[brr[i]].erase(indToRemove);
        pos[brr[i]].pop();
        segg.set((int)indToRemove, 0ll);
        removedIndices.insert(indToRemove);
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
