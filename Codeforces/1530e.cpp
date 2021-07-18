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
        string s; cin >> s;
        map<char, lld> cnt;
        lld n = len(s);
        for (auto i : s) {
            cnt[i] += 1;
        }
        if (cnt.size() == 1) {
            cout << s;
            return;
        }
        char chu = '$';
        for (auto[ke, va] : cnt) {
            if (va == 1) {
                chu = ke;
                break;
            }
        }
        if (chu != '$') {
            sort(all(s));
            cout << chu;
            for (auto i : s) {
                if (i != chu) {
                    cout << i;
                }
            }
            return;
        }

        auto [smol, smolCnt] = *cnt.begin();
        cnt.erase(smol);
        // _____error_____(smol, smolCnt);
        // _____error_____(cnt);

        if (smolCnt - 2 <= n - smolCnt) {
            // interveave
            cout << smol << smol;
            smolCnt -= 2;
            for (auto [ke, va] : cnt) {
                forn(i, va) {
                    cout << ke;
                    if (smolCnt > 0) {
                        cout << smol;
                        smolCnt--;
                    }
                }
            }
        } else {
            if (cnt.size() == 1) {
                // b first
                cout << smol;
                forn(i, (*cnt.begin()).s2) {
                    cout << (*cnt.begin()).f1;
                }
                forn(i, smolCnt - 1) {
                    cout << smol;
                }
            } else {
                // sexy jugad
                auto[smol2, smol2Cnt] = *cnt.begin();
                cnt.erase(smol2);
                auto[smol3, smol3Cnt] = *cnt.begin();
                cnt.erase(smol3);
                cout << smol << smol2;
                smolCnt--, smol2Cnt--;
                forn(i, smolCnt) {
                    cout << smol;
                }
                cout << smol3;
                smol3Cnt--;
                forn(i, smol2Cnt) {
                    cout << smol2;
                }
                forn(i, smol3Cnt) {
                    cout << smol3;
                }
                for (auto [ke, va] : cnt) {
                    forn(i, va) {
                        cout << ke;
                    }
                }
            }
        }

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

