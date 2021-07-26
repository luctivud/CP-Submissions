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
        lld n, m; cin >> n >> m;
        vector<lld> arr(n);
        forn(i, n) {
            cin >> arr[i];
            --arr[i];
        }
        lld ansLpos = n, ansRpos = -1;
        lld l = 0, r = n-1;
        // while (l <= r) {
        //     lld milf = l + (r - l) / 2;
        for (lld milf = 0; milf < n-1; milf++) {
            map<lld, lld> poswa, revpos;
            lld remainLife = m;
            // shift by mid;
            forn(i, n) {
                poswa[i] = (i + milf) % n;
                revpos[(i + milf) % n] = i;
            }
            // _____error_____(milf);
            // _____error_____(poswa);
            // _____error_____(revpos);
            forn(i, n) {
                lld want = arr[i];
                lld got = revpos[i];
                if (want == got) {
                    continue;
                } else {
                    --remainLife;
                    lld temp;
                    // i = 2, want = 0, got = 3
                    // swap(poswa[want], poswa[got]);
                    // _____error_____(want, got);

                    revpos[i] = want;
                    temp = revpos[poswa[want]];
                    revpos[poswa[want]] = got;

                    poswa[got] = temp;
                    poswa[want] = i;

                    // revpos[i] = want;
                    // revpos[temp] = got;
                    // temp = poswa[want];
                    // poswa[want] = poswa[got];
                    // poswa[got] = temp;
                    // // swap(revpos[want], revpos[got]);
                    // temp = revpos[want];
                    // revpos[want] = revpos[got];
                    // revpos[got] = temp;
                }
            }
            // _____error_____(poswa, revpos, remainLife);
            // _____error_____(poswa);
            // _____error_____(revpos);
            _____error_____(remainLife);

            if (remainLife >= 0) {
                ansLpos = milf;
                r = milf - 1;
            } else {
                l = milf + 1;
            }
        }

        // l = 0, r = n-1;
        // while (l <= r) {

        // }
        _____error_____(ansLpos, ansRpos);
        cout << max(0ll, ansRpos - ansLpos+1) << " ";
        for (lld i = ansLpos; i <= ansRpos; i++) {
            cout << i << " ";
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

