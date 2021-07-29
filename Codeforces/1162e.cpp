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
    lld n; 
    lld netSum = 0ll;
    lld dp[51][251][20];
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        cin >> n;
        lld arr[n];
        forn(i, n) {
            cin >> arr[i];
            netSum += arr[i];
        }

        // vector<vector<vector<lld>>> dp(n, vector<vector<lld>> (netSum+1, vector<lld> (n+1, -1)));
        forn(i, n) forn(j, netSum+1) forn(k, n+1) dp[i][j][k] = -1;
        cout << (solve(0, arr, 0, 0) ? "Alice" : "Bob");

        // vector<lld> perm(n, 1);
        // forn(i, n/2) {
        //     perm[i] = 0;
        // }
        // do {

        // } while ()
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    bool solve(lld ind, lld arr[], lld currSum, lld currCount) {
        // _____error_____(ind, currCount, currSum, n);
        if (ind == n or currCount > n/2) {
            return 0;
        }
        // lld res = -1;
        lld &res = dp[ind][currSum ^ (netSum - currSum)][currCount];
        if (res != -1) {
            return res;
        }
        return (res = ((currCount == n/2 and (currSum ^ (netSum - currSum))) || 
                    solve(ind+1, arr, currSum, currCount) || 
                    solve(ind+1, arr, currSum + arr[ind], currCount + 1)
                    ));
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

