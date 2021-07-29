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
        lld Globalxx = 1ll;
        string s; cin >> s;
        lld n; cin >> n;
        vector<set<lld>> visited(len(s));
        forn1(xx, n) {
            string t; cin >> t;
            forn(i, len(s)) {
                lld j = 0ll;
                for (j = 0; j < len(t); j++) {
                    if (i+j >= len(s) or s[i+j] != t[j]) {
                        break;
                    }
                }
                if (j == len(t)) {
                    visited[i].insert(Globalxx);
                    visited[i+len(t)-1].insert(-Globalxx);
                    Globalxx++;
                }
            }
        }

        n = len(s);
        lld i = 0ll, j = 0ll;
        while (j < n) {

        }


        // _____error_____(len(s));

        // NonIterable.print(visited);

        // lld lo = 1ll, hi = len(s), ans = 0ll, ratata = 0ll;

        // while (lo <= hi) {
        //     lld mid = lo + (hi - lo) / 2;
        //     multiset<lld> elemInd;
        //     bool ok = false, foundRep = false;
        //     lld thisStart = -1;
        //     lld netCunt = 0ll;
        //     forn(i, mid) {
        //         if (visited[i].size()) {
        //             for (auto xx : visited[i]) {
        //                 elemInd.insert(xx);
        //             }
        //         }
        //     }
        //     // for (auto xx : elemInd) {
        //     //     if (elemInd.find(-xx) != elemInd.end()) {
        //     //         foundRep = true;
        //     //     }
        //     // }

        //     if (!foundRep) {
        //         ok = true;
        //         thisStart = 0;
        //     }
        //     _____error_____(elemInd);

        //     for (lld i = mid; i < len(s); i++) {
        //         foundRep = false;
        //         if (visited[i].size()) {
        //             for (auto xx : visited[i]) {
        //                 elemInd.insert(xx);
        //             }
        //         }
        //         if (visited[i - mid].size()) {
        //             for (auto xx : visited[i - mid]) {
        //                 elemInd.erase(elemInd.find(xx));
        //             }
        //         }
        //         for (auto xx : elemInd) {
        //             if (elemInd.find(-xx) != elemInd.end()) {
        //                 foundRep = true;
        //             }
        //         }
        //         if (!foundRep) {
        //             ok = true;
        //             thisStart = i - mid + 1;
        //         }
        //         _____error_____(elemInd);
        //         // if (ok) break;
        //     }
        //     _____error_____(mid, ok);
        //     if (ok) {
        //         lo = mid + 1;
        //         ans = mid;
        //         ratata = thisStart;
        //     } else {
        //         hi = mid - 1;
        //     }
        // }

        // cout << ans << " " << ratata;

        // _____error_____(visited);
        // forn(i, len(s)) {
        //     // cout << s[i] << " " << visited[i] <<  "\n";
        //     _____error_____(s[i], visited[i]);
        // }
        // lld mxSize = 0ll, endPos = 0ll, thisSize = 0ll;
        // forn(i, len(s)) {
        //     if (visited[i] != 10) {
        //         thisSize += 1;
        //     } else {
        //         thisSize = 0ll;
        //     }
        //     if (thisSize > mxSize) {
        //         endPos = i;
        //         mxSize = thisSize;
        //     }
        //     cout << s[i] << " " << visited[i] << " " << thisSize << "\n";
        // }

        // cout << endPos << " " << mxSize;

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

// bool ok = false;
// lld thisStart = -1;
// forn(i, n) {
//     bool thisok = true;
//     set<lld> thisSet;
//     if (i + mid >= len(s)) break;
//     for (lld j = i; j < mid; j++) {
//         if (visited[j].size()) {
//             for (auto xx : visited[j]) {
//                 thisSet.insert(xx);
//             }
//         }
//     }
//     _____error_____(i, mid, thisSet);
//     for (auto xx : thisSet) {
//         if (thisSet.find(-xx) != thisSet.end()) {
//             thisok = false;
//             break;
//         }
//     }
//     if (thisok) {
//         ok = true;
//         thisStart = i;
//         break;
//     }
// }
// if (ok) {
//     ans = mid;
//     ratata = thisStart;
//     lo = mid + 1;
// } else {
//     hi = mid - 1;
// }