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






void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n1, n2, n3; cin >> n1 >> n2 >> n3;
    long double arr0x1[n1], arr0x2[n2];
    forn(i, n1) {
        cin >> arr0x1[i];
    }

    forn(i, n2) {
        cin >> arr0x2[i];
    }

    vector<tuple<long double, lld, lld>> arr;
    set<long double> vis;
    for (lld i = 0; i < n1; i += 1) {
        for (lld j = 0; j < n2; j += 1) {
            long double eeree = arr0x1[i] + arr0x2[j];
            if (eeree > 0 and vis.find(eeree) == vis.end()) {
                vis.insert(eeree);
                arr.push_back({eeree, i+1, j+1});
            }
        }
    }

    // _____error_____(arr);

    sort(all(arr), [](tuple<long double, lld, lld> &a, tuple<long double, lld, lld> &b) {
        return get<0>(a) < get<0>(b);
    });

    // NonIterable.print(arr);

    auto BoundUP = [&](long double si) {
        lld lo = 0ll, hi = len(arr)-1;
        auto res = arr.end();
        while (lo <= hi) {
            lld m = (lo + hi) >> 1;
            if (get<0>(arr[m]) >= si) {
                res = arr.begin() + m;
                hi = m - 1;
            } else {
                lo = m + 1;
            }
        }
        return res;
    };

    forn(i, n3) {
        long double si;
        cin >> si;
        auto it = BoundUP(si);
        lld p1 = -1, p2 = -1;
        long double rss = mod;
        if (it != arr.end()) {
            if (abs(si - get<0>(*it)) < rss) {
                rss = abs(si - get<0>(*it));
                p1 = get<1>(*it);
                p2 = get<2>(*it);
                // _____error_____(*it);

            }
        }
        if (it != arr.begin()) {
            it--;
            // _____error_____(*it);
            if (abs(si - get<0>(*it)) < rss) {
                rss = abs(si - get<0>(*it));
                p1 = get<1>(*it);
                p2 = get<2>(*it);
            }
        }

        cout << p1 << " " << p2 << "\n";
        _____error_____(rss);
    }


    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    MOD = mod = lld(1e9) + 7ll;
    int _T0T4 = 1;
    cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        // cout << "\n"; 
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
