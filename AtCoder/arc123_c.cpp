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
    const lld inf = 1e18;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld n; cin >> n;
        lld ans = 0ll;
        // while (n > 0) {
        // lld l = 0, r = 1e4, chotu = -1;
        // while (l <= r) {
        //     lld mid = l + (r - l) / 2;
        //     lld num = toBalancedBase3(mid);
        //     if (n == num) {
        //         chotu = num;
        //         break;
        //     } else if (num > n) {
        //         r = mid - 1;
        //     } else {
        //         chotu = num;
        //         l = mid + 1;
        //     }
        //     _____error_____(mid, num, chotu);
        // }
        // _____error_____(chotu);
        // assert(chotu != -1);
        // n -= chotu;
        // ++ans;
        // }
        _____error_____(toBalancedBase3(4));

        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
    lld toBalancedBase3(lld n) {
        _____error_____(n);
        lld res = 0;
        lld size = 0;
        while ((lld)pow(3, size) <= n) {
            size++;
        }
        size--;
        n -= (lld)pow(3, size);
        size++;
        _____error_____("left",n);
        if (size > 18) {
            return inf;
        }
        string resStr = "";
        forn(i, size) {
            lld fac = n / (lld)(pow(3, (size-i-1)));
            _____error_____(fac);
            resStr += ('1' + fac);
            n -= fac * (lld)(pow(3, size-i-1));
        }

        _____error_____(resStr);

        _____error_____(n, size);
        return 0;
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
