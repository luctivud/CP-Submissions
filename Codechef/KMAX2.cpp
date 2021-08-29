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
#define int lld


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
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif

    return;
}





class Segtree {
public:

// A utility function to get the
// middle index of given range.
    int getMid(int s, int e)
    {
        return s + (e - s) / 2;
    }

    /* A recursive function to get the sum of
        values in given range of the array.
        The following are parameters for this
        function.

        st   -> Pointer to segment tree
        node     -> Index of current node in
                    the segment tree .
        ss & se -> Starting and ending indexes
                    of the segment represented
                    by current node, i.e., st[node]
        l & r -> Starting and ending indexes
                    of range query */
    int MaxUtil(int* st, int ss, int se, int l,
                int r, int node)
    {
        // If segment of this node is completely
        // part of given range, then return
        // the max of segment
        if (l <= ss && r >= se)
            return st[node];

        // If segment of this node does not
        // belong to given range
        if (se < l || ss > r)
            return -1;

        // If segment of this node is partially
        // the part of given range
        int mid = getMid(ss, se);

        return max(MaxUtil(st, ss, mid, l, r,
                           2 * node + 1),
                   MaxUtil(st, mid + 1, se, l,
                           r, 2 * node + 2));
    }

    int getMax(int* st, int n, int l, int r)
    {
        // Check for erroneous input values
        if (l < 0 || r > n - 1 || l > r)
        {
            return -1;
        }

        return MaxUtil(st, 0, n - 1, l, r, 0);
    }

// A recursive function that constructs Segment
// Tree for array[ss..se]. si is index of
// current node in segment tree st
    int constructSTUtil(int arr[], int ss, int se,
                        int* st, int si)
    {
        // If there is one element in array, store
        // it in current node of
        // segment tree and return
        if (ss == se)
        {
            st[si] = arr[ss];
            return arr[ss];
        }

        // If there are more than one elements, then
        // recur for left and right subtrees and
        // store the max of values in this node
        int mid = getMid(ss, se);

        st[si] = max(constructSTUtil(arr, ss, mid, st,
                                     si * 2 + 1),
                     constructSTUtil(arr, mid + 1, se,
                                     st, si * 2 + 2));

        return st[si];
    }

    /* Function to construct segment tree
    from given array.
    This function allocates memory for
    segment tree.*/
    int* constructST(int arr[], int n)
    {
        // Height of segment tree
        int x = (int)(ceil(log2(n)));

        // Maximum size of segment tree
        int max_size = 2 * (int)pow(2, x) - 1;

        // Allocate memory
        int* st = new int[max_size];

        // Fill the allocated memory st
        constructSTUtil(arr, 0, n - 1, st, 0);

        // Return the constructed segment tree
        return st;
    }

};








/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, k; cin >> n >> k;
    k -= 1;

    lld arr[n];
    forn(i, n) cin >> arr[i];

    lld ans = 0ll;
    lld mx = *max_element(arr, arr+n);
    vector<lld> posOfMax;
    forn(i, n) {
        if (arr[i] == mx) {
            posOfMax.push_back(i);
        }
    }

    for (auto i : posOfMax) {
        if (i >= k) {
            ans += (n - i);
        }
    }

    // Segtree sg;
    // int* st = sg.constructST(arr, n);

    // for (lld i = 0; i < n - k; i++) {
    //     lld lo = i, hi = n - 1;
    //     lld poswa = lo;
    //     while (lo <= hi) {
    //         lld mid = lo + (hi - lo) / 2;
    //         if (sg.getMax(st, n, i, mid) <= arr[i + k]) {
    //             lo = mid + 1;
    //             poswa = mid;
    //         } else {
    //             hi = mid - 1;
    //         }
    //     }
    //     ans += max(0ll, poswa - i - k);
    // }

    cout << ans;

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    IAmJustice();

    int _T0T4 = 1;
    cin >> _T0T4;

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }

    return pleaseAC();
}




/*  ~~
    .?.?.?.
*/
