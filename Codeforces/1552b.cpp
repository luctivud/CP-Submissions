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
        // vector<vector<pair<lld, lld>>> arr(5, vector<pair<lld, lld>>(n));
        lld arr[n][5];
        forn(i, n) {
            forn(j, 5) {
                // cin >> arr[j][i].f1;
                // arr[j][i].s2 = i;
                cin >> arr[i][j];
            }
        }

        // NonIterable.print(arr);

        // vector<lld> beby {0, 0, 1, 1, 1};

        // forn(i, 5) {
        //     sort(all(arr[i]));
        // }

        // vector<vector<lld>> pos(n, vector<lld> (5, 0));
        // vector<pair<lld, lld>> cumrank(n);
        // forn(i, n) {
        //     forn(j, 5) {
        //         pos[arr[j][i].s2][j] = i;
        //         cumrank[arr[j][i].s2].f1 += i;
        //         cumrank[arr[j][i].s2].s2 = arr[j][i].s2;
        //     }
        // }

        // sort(all(cumrank));

        // _____error_____(pos);
        lld ans = -2;

        set<lld> validCandidates;
        forn(i, n) {
            validCandidates.insert(i);
        }


        while (validCandidates.size() > 1) {
            auto it = validCandidates.begin();
            auto it2 = validCandidates.rbegin();
            lld cnt = 0ll;
            forn(i, 5) {
                cnt += (arr[*it][i] < arr[*it2][i]);
            }
            if (cnt >= 3) {
                validCandidates.erase(validCandidates.find(*it2));
            } else {
                validCandidates.erase(it);
            }
        }

        // NonIterable.print(validCandidates);
        auto it = validCandidates.begin();
        ans = *it;
        for (int i = 0; i < n; i++) {
            if (i != *it) {
                lld cnt = 0ll;
                forn(j, 5) {
                    cnt += (arr[*it][j] < arr[i][j]);
                }
                if (cnt < 3) {
                    ans = -2;
                }
            }
        }


        // lld szm = sqrt(n) * sqrt(sqrt(sqrt(n)));

        // forn(xx, szm) {
        //     lld i = cumrank[xx].s2;
        //     if (cumrank[xx].f1 > 3*n) break;
        //     map<lld, lld> defCount;
        //     bool ok = true;
        //     forn(match, 5) {
        //         forn(zz, pos[i][match]) {
        //             defCount[arr[match][zz].s2] += 1;
        //             if (defCount[arr[match][zz].s2] >= 3) {
        //                 ok = false;
        //                 break;
        //             }
        //         }
        //         if (!ok) break;
        //     }
        //     if (ok) {
        //         ans = i;
        //         break;
        //     }
        // }

        cout << ans + 1;
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

// do {
//     _____error_____(beby);
//     forn(i, n) {
//         bool okdone = false;
//         set<lld> defeats;
//         forn(match, 5) {
//             if (!beby[match]) continue;
//             if (!okdone) {
//                 okdone = true;
//                 for (lld jjj = 0; jjj < pos[i][match]; jjj++) {
//                     defeats.insert(arr[match][i].s2);
//                 }
//             } else {
//                 set<lld> newDef;
//                 for(lld jjj = 0; jjj < pos[i][match]; jjj++) {
//                     if (defeats.find(arr[match][i].s2) != defeats.end()) {
//                         newDef.insert(arr[match][i].s2);
//                     }
//                 }
//                 swap(newDef, defeats);
//             }
//         }
//         _____error_____(defeats);
//         _____error_____(i);
//         if (defeats.size() == 0) {
//             ans = i;
//         }
//     }
// } while (next_permutation(all(beby)));