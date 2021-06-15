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

const lld inf = (lld)1e16;







/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
    lld n; 
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        cin >> n;
        vector<lld> arr(n);
        lld ans = 0ll;
        map<lld, lld, greater<lld>()> cnt;
        forn(i, n) {
            cin >> arr[i];
            cnt[arr[i]] += 1;
            if (i > 0)
                ans += llabs(arr[i] - arr[i-1]);
        }

        



        // lld ans = binaryBitch(0ll, mod, arr);

        // cout << ans;

        // set<pair<lld, lld>> shy_away;
        // forn1(i, n) {
        //     cin >> arr[i];
        //     shy_away.insert({arr[i], i, 1});
        // }
        // arr.push_back(0);
        // lld ans = 0ll;
        // forn1(i, n-1) {
        //     ans += llabs(arr[i] - arr[i-1]);
        // }
        // shy_away.insert(0);
        // lld res = ans;
        // while (len(shy_away) > 1) {
        //     auto it = prev(shy_away.end());

        //     ans = min(ans, res);
        // }

        // cout << ans;

    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    // lld binaryBitch(lld lo, lld hi, vector<lld> &arr) {
    //     if (lo > hi) {
    //         return inf;
    //     }
    //     lld m = (lo + hi) >> 1;
    //     lld prv1 = 0ll, prv2 = 0ll, prv3 = 0ll;
    //     forn(i, n) {
    //         prv1 = min(arr[i], lo);
    //         prv2 = min(arr[i], )
    //     }
    // }
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

