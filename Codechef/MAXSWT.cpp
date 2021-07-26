/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIVUD
#include <buggyBaby.hpp>
pretty:: PrettyPrinter NonIterable;
#define cerr cout
#else
#define _____error_____(...)
#endif
#pragma GCC optimize "trapv"


/*:::::::::::::::::::SNIPS::::::::::::::::::::::::::::*/

typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


/*::::::::::::::::::/SNIPS::::::::::::::::::::::::::::*/
/*:::::::::::::::::::UTILS::::::::::::::::::::::::::::*/


const long double EPS = 1e-6;
lld MOD = int(1e9) + 7;
lld &mod = MOD;


#define int lld






/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld n, d; cin >> n >> d;
        vector<pair<lld, lld>> arr(n);
        forn(i, n) {
            cin >> arr[i].f1;
        }
        forn(i, n) {
            cin >> arr[i].s2;
        }
        sort(all(arr));

        lld praiz[n];
        lld casto[n];
        forn(i, n) {
            casto[i] = arr[i].f1;
            praiz[i] = arr[i].s2;
        }

        lld ans = 0ll;
        int* st = constructST(praiz, n);

        forn(i, n) {
            lld pos = upper_bound(casto, casto+n, d - casto[i]) - casto - 1;
            // _____error_____(pos, d - casto[i]);
            if (d-casto[i] < 0) continue;
            lld mx = ((pos >= 0 and pos < n) ? getMax(st, n, i+1, pos) : 0);
            // _____error_____(mx);
            if (mx != -1) {
                ans = max(ans, praiz[i] + mx);
            }
        }

        forn(i, n) {
            if (casto[i] <= d) {
                ans = max(ans, praiz[i]);
            }
        }

        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
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
            return 0;

        // If segment of this node is partially
        // the part of given range
        int mid = getMid(ss, se);

        return max(MaxUtil(st, ss, mid, l, r,
                           2 * node + 1),
                   MaxUtil(st, mid + 1, se, l,
                           r, 2 * node + 2));
    }

    /* A recursive function to update the nodes
    which have the given index in their range.
    The following are parameters st, ss and
    se are same as defined
    above index -> index of the element
    to be updated.*/
    

// Return max of elements in range from
// index l (query start) to r (query end).
    int getMax(int* st, int n, int l, int r)
    {
        // Check for erroneous input values
        if (l < 0 || r > n - 1 || l > r)
        {
            return 0;
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



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif


    int _T0T4 = 1;
    cin >> _T0T4;

    Solution Aurora;
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Aurora.SolveEachTest(_TestCase);
        Aurora.ResetTestCase();
    }


#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}

/*:::::::::::::::::::::/INVOC:::::::::::::::::::::::::*/
/*  ~~
Author   :  Udit "luctivud" Gupta
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/

