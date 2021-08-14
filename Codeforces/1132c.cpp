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
        lld n, q; cin >> n >> q;
        vector<pair<lld, lld>> arr(q);
        vector<lld> paintedFence(n+2, 0ll);
        forn(i, q) {
            cin >> arr[i].f1 >> arr[i].s2;
            paintedFence[arr[i].f1] += 1;
            paintedFence[arr[i].s2 + 1] -= 1;
        }

        forn1(i, n+1) {
            paintedFence[i] += paintedFence[i-1];
        }
        lld ans = 0ll;
        forn(i, q) {
            vector<lld> removedBebFence{paintedFence};
            lld res = 0ll;
            for (lld xx = arr[i].f1; xx <= arr[i].s2; xx++) {
                removedBebFence[xx] -= 1;
            }
            forn1(xx, n+1) {
                res += removedBebFence[xx] >= 1;
                removedBebFence[xx] = (removedBebFence[xx] == 1);
            }
            _____error_____(res);
            _____error_____(removedBebFence);
            forn1(xx, n+1) {
                (removedBebFence[xx] += removedBebFence[xx-1]);
            }
            _____error_____(removedBebFence);
            forn(j, q) {
                if (i == j) continue;
                _____error_____(j, removedBebFence[arr[j].s2], removedBebFence[arr[j].f1 - 1]);
                ans = max(ans, res - removedBebFence[arr[j].s2] + removedBebFence[arr[j].f1 - 1]);
            }
        }   

        cout << ans;

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

// sort(all(arr), [](auto &a, auto &b) {
//     return a.f1 < b.f1;
// });

// forn1(i, q - 1) {
//     arr[i].f1 = max(arr[i - 1].s2 + 1, arr[i].f1);
// }
// // _____error_____(arr);
// // NonIterable.print(arr);
// sort(all(arr), [](auto &a, auto &b) {
//     return a.s2 - a.f1 > b.s2 - b.f1;
// });

// NonIterable.print(arr);

// vector<lld> sectionsPainted(n + 2, 0);
// forn(i, q - 2) {
//     sectionsPainted[arr[i].f1] += 1;
//     sectionsPainted[arr[i].s2 + 1] -= 1;
// }

// forn1(i, n) {
//     sectionsPainted[i] += sectionsPainted[i - 1];
// }

// _____error_____(sectionsPainted);

// lld ans = 0ll;
// forn1(i, n) {
//     ans += (sectionsPainted[i] >= 1);
// }
// cout << ans;
