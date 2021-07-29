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






class Point {
public:
    lld X, Y;
};


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
        vector<Point> arr(n);
        forn(i, n) {
            cin >> arr[i].X >> arr[i].Y;
        }
        // NonIterable.print(arr);

        // lld ans = (n * (n - 1)) / 2;
        // ans = (ans * (ans - 1)) / 2;

        lld ans = 0ll;
        map<array<long double, 3>, lld> lines;
        map<lld, lld> slopes;
        forn(i, n) {
            for (lld j = i+1; j < n; j++) {
                auto [m, c1, c2] = getSlopeIntersept(arr[i], arr[j]);
                lines[{m, c1, c2}] += 1;
                if (lines[{m, c1, c2}] == 1) {
                    slopes[m] += 1;
                }
            }
        }

        _____error_____(slopes);
        _____error_____(lines);

        ans = (lines.size() * ((lld)lines.size() - 1)) / 2;

        for (auto [ke, va] : slopes) {

            ans -= (va * (va - 1)) / 2;
        }

        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    lld intersect(Point a, Point b, Point c, Point d) {
        return (a.Y - b.Y) * (d.X - c.X) == (d.Y - c.Y) * (a.X - b.X);
    }

    lld isCollinear(Point a, Point b, Point c) {
        return (a.Y - b.Y) * (b.X - c.X) == (b.Y - c.Y) * (a.X - b.X);
    }

    array<long double, 3> getSlopeIntersept(Point a, Point b) {
        // eqn
        long double m = ((a.X - b.X != 0) ? (a.Y - b.Y) / (a.X - b.X) : inf);
        // y = mx+c , c = y-mx; 
        long double c1 = (m == inf ? inf : a.Y - m * a.X);
        long double c2 = (m == 0 ? inf : - (long double)c1 / m);
        array<long double, 3> res = {m, c1, c2};
        return res;
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

// for (lld i = 0; i< n; i++) {
//     for (lld j = i+1; j < n; j++) {
//         for (lld k = j+1; k < n; k++) {
//             for (lld l = k+1; l < n; l++) {
//                 if (!intersect(arr[i], arr[j], arr[k], arr[l])) {
//                     _____error_____(i, j, k, l);
//                     ans += 1;
//                 }
//             }
//         }
//     }
// }