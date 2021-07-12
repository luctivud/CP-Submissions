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
        cout << "Case #" << _TestCase << ": ";
        long long arr[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 and j == 1) {
                    continue;
                }
                cin >> arr[i][j];
            }
        }
        map<long long, long long> mp;
        if (!((arr[1][2] - arr[1][0]) & 1)) {
            mp[arr[1][0] + (arr[1][2] - arr[1][0]) / 2] += 1;
        }
        if (!((arr[2][1] - arr[0][1]) & 1)) {
            mp[arr[0][1] + (arr[2][1] - arr[0][1]) / 2] += 1;
        }
        if (!((arr[2][2] - arr[0][0]) & 1)) {
            mp[arr[0][0] + (arr[2][2] - arr[0][0]) / 2] += 1;
        }
        if (!((arr[2][0] - arr[0][2]) & 1)) {
            mp[arr[0][2] + (arr[2][0] - arr[0][2]) / 2] += 1;
        }
        long long res = 0;
        for (auto [key, value] : mp) {
            if (value > res) {
                res = value;
                arr[1][1] = key;
            }
        }

        long long ans = 0ll;
        for (int i = 0; i < 3; i++) {
            long long diff = (arr[i][2] - arr[i][0]);
            if (!(diff & 1) and (arr[i][1] == arr[i][0] + (diff / 2))) {
                ans += 1;
            }
        }
        for (int j = 0; j < 3; j++) {
            long long diff = (arr[2][j] - arr[0][j]);
            if (!(diff & 1) and (arr[1][j] == arr[0][j] + (diff / 2))) {
                ans += 1;
            }
        }

        long long diff = (arr[2][2] - arr[0][0]);
        if (!(diff & 1) and (arr[1][1] == arr[0][0] + (diff / 2))) {
            ans += 1;
        }

        diff = (arr[0][2] - arr[2][0]);
        if (!(diff & 1) and (arr[1][1] == arr[2][0] + (diff / 2))) {
            ans += 1;
        }
        cout << ans << "\n";
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

