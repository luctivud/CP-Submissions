/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIUD
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
    static const int maxN = int(1e4) + 2;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        cout << "Case #" << _TestCase << ": ";
        long long n, c; cin >> n >> c;
        long long ans = n;
        map<long long, long long> arr;
        for (long long i = 0; i < n; i++) {
            long long s, e; cin >> s >> e;
            if (e - s >= 2) {
                arr[s+1] += 1;
                arr[e] -= 1;
                if (arr[s+1] == 0) {
                    arr.erase(s+1);
                }
                if (arr[e] == 0) {
                    arr.erase(e);
                }
            }
        }
        _____error_____(arr);
        vector<pair<long long, long long>> check;
        long long left = (*arr.begin()).first;
        long long ck = 0ll;
        for (auto [mf, tp] : arr) {
            if (ck > 0 and mf - left > 0) {
                check.push_back({ck, mf - left});
            }
            _____error_____(left, ck);
            ck += tp;
            left = mf;
        }

        _____error_____(check);

        sort(check.begin(), check.end(), greater<pair<long long, long long>>());

        for (auto [currentInSeg, segLen] : check) {
            long long inGone = min(c, segLen);
            c -= inGone;
            ans += (currentInSeg * inGone);
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
      freopen("/home/luctivud/CPPractice/Zinput.txt", "e", stdin);
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

