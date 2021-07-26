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
        lld n, m, k; cin >> n >> m >> k;
        lld modiji = (n & 1) * (m >> 1);
        // _____error_____(modiji);
        bool ok = true;
        // ok &= (((k - modiji) & 1)); // ? "NO" : "YES");
        forn(i, n / 2) {
            if (modiji < k) {
                modiji += min(2 * ((k - modiji) / 2), 2 * (m / 2));
            }
        }
        // _____error_____(modiji);
        ok &= (modiji == k);
        cout << (ok ? "YES" : "NO");
        cout << "\n";
        if (ok) {
            vector<vector<char>> matr(n, vector<char> (m, '$'));
            vector<string> bebey = {
                "abcd",
                "abcd",
                "efgh",
                "efgh"
            };
            forn(i, n) {
                forn(j, m) {
                    matr[i][j] = bebey[i % 4][j % 4];
                }
            }
            if (n & 1) {
                forn(j, m) {
                    matr[n-1][j] = 'u';
                }
                k -= (m >> 1);
            }

            // NonIterable.print(matr);

            forn(i, n/2) {
                forn(j, m/2) {
                    if (k > 0) {
                        lld x = 2*i, y = 2*j;
                        if (x + 1 < n and y + 1 < m) {
                            k -= 2;
                            swap(matr[x+1][y], matr[x][y+1]);
                        }
                    }
                }
            }
            // _____error_____(k);
            assert(k == 0);
            forn(i, n) {
                forn(j, m) {
                    cout << matr[i][j];
                }
                cout << "\n";
            }
        }
    }

public:
    void ResetTestCase() {
        // cout << "\n";
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

