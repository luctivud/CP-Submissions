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
        int n; cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        constructSegmentTree(arr, n);
        int l = 0, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = l + ((r - l) / 2);
            set<long long> elems;
            for (int i = 0; i < n; i++) {
                int l1, r1, l2, r2;
                l1 = i, r1 = min(i + mid, n - 1);
                l2 = 0, r2 = (i + mid) % n;
                long long elem = findRangeGcd(l1, r1, arr, n);
                if (i + mid >= n) {
                    elem = __gcd(elem, findRangeGcd(l2, r2, arr, n));
                }
                elems.insert(elem);
            }
            // _____error_____(mid, elems);
            if (elems.size() == 1) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
    int *st;
    int findGcd(int ss, int se, int qs, int qe, int si)
    {
        if (ss > qe || se < qs)
            return 0;
        if (qs <= ss && qe >= se)
            return st[si];
        int mid = ss + (se - ss) / 2;
        return __gcd(findGcd(ss, mid, qs, qe, si * 2 + 1),
                     findGcd(mid + 1, se, qs, qe, si * 2 + 2));
    }
    int findRangeGcd(int ss, int se, int arr[], int n)
    {
        if (ss < 0 || se > n - 1 || ss > se)
        {
            cout << "Invalid Arguments" << "\n";
            return -1;
        }
        return findGcd(0, n - 1, ss, se, 0);
    }

    int constructST(int arr[], int ss, int se, int si)
    {
        if (ss == se)
        {
            st[si] = arr[ss];
            return st[si];
        }
        int mid = ss + (se - ss) / 2;
        st[si] = __gcd(constructST(arr, ss, mid, si * 2 + 1),
                       constructST(arr, mid + 1, se, si * 2 + 2));
        return st[si];
    }
    int *constructSegmentTree(int arr[], int n)
    {
        int height = (int)(ceil(log2(n)));
        int size = 2 * (int)pow(2, height) - 1;
        st = new int[size];
        constructST(arr, 0, n - 1, 0);
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

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Solution Aurora;
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

