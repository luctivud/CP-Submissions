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
        lld n; vector<lld> arr(4, 0);
        cin >> n;
        forn(i, 4) cin >> arr[i];

        forn(i, 4) {
            if (arr[i] > n) {
                cout << "NO";
                return;
            }
        }

        _____error_____(arr);

        lld fourBitSet = (1ll << 4);
        // _____error_____(fourBitSet);
        forn(mask, fourBitSet) {
            bitset<4> corners{(llu)mask};
            vector<lld> brr{arr};
            forn(i, 4) {
                if (corners[i]) {
                    brr[i] -= 1;
                    brr[(i+1) % 4] -= 1;
                }
            }
            _____error_____(corners);
            _____error_____(brr);
            bool ok = true;
            forn(i, 4) {
                ok &= (brr[i] >= 0 and brr[i] <= (n-2));
            }
            if (ok) {
                cout << "YES";
                return;
            }
        }   


        // forn(i, 4) {
        //     if (arr[i] > (n - 2)) {
        //         if (arr[(i+1) % 4] > 0) {
        //             --arr[i];
        //             --arr[(i+1) % 4];
        //         }
        //     }
        //     if (arr[i] > (n - 2)) {
        //         if (arr[(i+3) % 4] > 0) {
        //             --arr[i];
        //             --arr[(i+3) % 4];
        //         }
        //     }
        // }
        // _____error_____(arr);

        // forn(i, 4) {
        //     if (arr[i] > (n - 2)) {
        //         cout << "NO";
        //         return;
        //     }
        // }


        cout << "NO";
    }

public:
    void ResetTestCase() {
        cout << "\n";
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

