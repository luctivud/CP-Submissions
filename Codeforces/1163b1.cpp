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
        lld ans = 0ll;
        map<lld, lld> cnt;
        lld SZ = 0ll;//, F1 = -1ll, F2 = -1ll, S1 = -1ll, S2 = -1ll;
        map<lld, lld> elemCnt;

        forn(i, n) {
            cin >> arr[i];
            cnt[arr[i]] += 1;
            _____error_____(cnt);
            if (cnt[arr[i]] == 1) {
                elemCnt[1] += 1;
            } else {
                elemCnt[cnt[arr[i]]] += 1;
                elemCnt[cnt[arr[i]] - 1] -= 1;
                if (elemCnt[cnt[arr[i]] - 1] == 0) {
                    lld temp = cnt[arr[i]] - 1;
                    // cout << temp << " hehe\n";
                    elemCnt.erase(temp);
                }
            }


            // if (cnt[arr[i]] == 1) {
            //     SZ += 1;
            //     if (cnt[arr[i]] <= F1) {
            //         if (cnt[arr[i]] == F1) {
            //             F2 += 1;
            //         } else {
            //             swap(F1, S1);
            //             swap(F2, S2);
            //         }
            //     } else if (cnt[arr[i]] <= S1) {

            //     }
            // } else {

            // }
            // map<lld,lld> elemCnt;
            // _____error_____(i, cnt);
            // for (auto [ke, va] : cnt) {
            //     elemCnt[va]+=1;
            // }
            _____error_____(elemCnt);
            SZ = len(elemCnt);
            if (SZ == 1) {
                auto [F1, F2] = *elemCnt.begin();
                auto [S1, S2] = *elemCnt.rbegin();
                if (F1 == 1 or F2 == 1) {
                    ans = i+1;
                }
                // ans = i+1;
            } else if (SZ == 2) {
                auto [F1, F2] = *elemCnt.begin();
                auto [S1, S2] = *elemCnt.rbegin();
                if (F1 + 1 == S1 and S2 == 1) {
                    ans = i+1;
                } else if (F1 == 1 and F2 == 1) {
                    ans = i+1;
                }
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

