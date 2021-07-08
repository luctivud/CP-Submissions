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
        lld n; cin >> n;
        lld arr[n];
        forn(i, n) {
            cin >> arr[i];
        }

        // create par3t and ran4k at the place.
        vector<lld> par3t(n, 0);
        vector<lld> ran4k(n, 0);
        makeSet(n, par3t, ran4k);
        vector<bool> visited(n, false);
        forn(j, n) {
            if (visited[j]) continue;
            lld i = j;
            while (!visited[i]) {
                visited[i] = true;
                Union(i, j, par3t, ran4k);
                i = arr[i];
            }
        }
        vector<lld> cnt(n, 0);
        forn(i, n) {
            cnt[find_repr(i, par3t, ran4k)] += 1;
        }
        cout << *max_element(all(cnt));
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
    /*          D S U         */

    void makeSet(lld n, vector<lld> &par3t, vector<lld> &ran4k) {
        iota(all(par3t), 0ll);
    }

    lld find_repr(lld x, vector<lld> &par3t, vector<lld> &ran4k) {
        if (x != par3t[x])
            par3t[x] = find_repr(par3t[x], par3t, ran4k);
        return par3t[x];
    }

    void Union(lld x, lld y, vector<lld> &par3t, vector<lld> &ran4k) {
        x = find_repr(x, par3t, ran4k);
        y = find_repr(y, par3t, ran4k);

        if (x == y) return;

        if (ran4k[x] < ran4k[y]) {
            par3t[x] = y;
        } else if (ran4k[x] > ran4k[y]) {
            par3t[y] = x;
        } else {
            par3t[y] = x;
            ran4k[x] = ran4k[x] + 1;
        }
        return;
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

