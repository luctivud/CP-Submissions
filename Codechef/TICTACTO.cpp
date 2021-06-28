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
        brute();
        
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    void checkWhoWon(lld n, lld m, lld K, char &winnerChar, vector<vector<char>> &matr) {
        if (winnerChar != '$') return;
        forn(i, n) {
            forn(j, m) {
                lld al = 0ll, bo = 0ll;
                forn(kx, K) {
                    forn(ky, K) {
                        if (i+kx < n and j+ky < m) {
                            if (matr[i+kx][j+ky] == '.') continue;
                            (matr[i+kx][j+ky] == 'A' ? al : bo) += 1;
                        }
                    }
                }
                if (winnerChar == '$') {
                    if (al == K * K) {
                        winnerChar = 'A';
                    } else if (bo == K * K) {
                        winnerChar = 'B';
                    }
                } else {
                    return;
                }
            }
        }
    }

    void brute() {
        lld n, m, k; cin >> n >> m >> k;
        vector<vector<char>> matr(n, vector<char>(m, '.'));
        lld turn = 0ll;
        char winnerChar = '$';
        forn(xx, n) {
            forn(yy, m) {
                lld i, j; cin >> i >> j;
                --i, --j;
                matr[i][j] = ((++turn & 1) ? 'A': 'B');
                _____error_____(turn);
                NonIterable.print(matr);
                checkWhoWon(n, m, k, winnerChar, matr);
                _____error_____(winnerChar);
            }
        }
        if (winnerChar == '$') {
            cout << "Draw";
        } else {
            cout << (winnerChar == 'A' ? "Alice" : "Bob");
        }
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

