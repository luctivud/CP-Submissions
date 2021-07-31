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
        lld n, m, q; cin >> n >> m >> q;
        pair<lld, lld> arrSexy[m];
        forn(i, m) {
            cin >> arrSexy[i].f1 >> arrSexy[i].s2;
        }
        sort(arrSexy, arrSexy+m);
        lld arr[m];
        forn(i, m) {
            arr[i] = arrSexy[i].s2;
            // _____error_____(i, arr[i]);
        }

        // int* st = constructST(arr, m);

        forn1(i, m-1) {
            arr[i] = max(arr[i], arr[i-1]);
        }

        forn(qq, q) {
            lld l, r; cin >> l >> r;
            if (r < l) swap(l, r);
            if (l == r) {
                cout << "0\n";
                continue;
            }

            lld ans = 0ll, oldPos = -1;
            while (l < r) {
                // lld lo = 0, hi = m - 1, pos = m;
                // while (lo <= hi) {
                //     lld mid = lo + (hi - lo) / 2;
                //     if (arrSexy[mid].f1 > l) {
                //         pos = mid;
                //         hi = mid - 1;
                //     } else {
                //         lo = mid + 1;
                //     }
                // }
                // lld pos = poswa[l];
                pos -= 1;
                if (pos == oldPos) {
                    break;
                }
                // l = getMax(st, m, 0, pos);
                // _____error_____(oldPos, pos);
                l = arr[pos];
                ans++;
                oldPos = pos;
            }
            cout << (l >= r ? ans : -1) << "\n";
        }

    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
    int getMid(int s, int e)
    {
        return s + (e - s) / 2;
    }
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



// Return max of elements in range from
// index l (query start) to r (query end).
    int getMax(int* st, int n, int l, int r)
    {
        // Check for erroneous input values
        if (l < 0 || r > n - 1 || l > r)
        {
            // printf("Invalid Input");
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
    // cin >> _T0T4;

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

