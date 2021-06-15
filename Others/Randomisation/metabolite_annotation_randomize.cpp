/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIV
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
    srand(unsigned(time(0)));
    // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    lld m, k, n; cin >> m >> k >> n;
    vector<pair<long double, lld>> M;
    long double TEMPP;
    set<long double> vis;
    forn(i, m) {
        cin >> TEMPP;
        if (vis.find(TEMPP) == vis.end()) {
            vis.insert(TEMPP);
            M.push_back({TEMPP, i+1});
        }
    }
    m = len(M);
    sort(all(M));

    vis.clear();
    vector<pair<long double, lld>> K;
    forn(i, k) {
        cin >> TEMPP;
        if (vis.find(TEMPP) == vis.end()) {
            vis.insert(TEMPP);
            K.push_back({TEMPP, i+1});
        }
    }
    k = len(K);

    // NonIterable.print(M);
    // _____error_____(K);

    auto binaryBitch = [&](long double s) {
        lld lo = 0ll, hi = m-1;
        long double huehue = mod;
        lld res = 0ll;
        while (lo <= hi) {
            lld mid = (lo + hi) >> 1;
            if (M[mid].first > s) {
                hi = mid - 1;
            } else if (M[mid].first < s) {
                lo = mid + 1;
            } else {
                return mid;
            }
            if (abs(M[mid].first - s) < huehue) {
                huehue = abs(M[mid].first - s);
                res = mid;
            }
        }
        return res;
    };

    forn(i, n) {
        cin >> TEMPP;
        lld p1 = -1, p2 = -1;
        long double rss = mod;
        if (i >= 8000 and i <= 10000) {
            forn(chosenKind, k) {
                // lld chosenKind = rand() % k;
                long double newSi = TEMPP - K[chosenKind].first;
                lld pos = binaryBitch(newSi);
                if (rss > abs(newSi - M[pos].f1)) {
                    rss = abs(newSi - M[pos].f1);
                    p1 = M[pos].s2;
                    p2 = K[chosenKind].s2;
                }
                // _____error_____(newSi, M[pos].first, rss);
            }
        } else {
            forn(zz, 20) {
            // forn(chosenKind, k) {
                // lld chosenKind = rng() % k;
                lld chosenKind = rand() % k;
                long double newSi = TEMPP - K[chosenKind].first;
                lld pos = binaryBitch(newSi);
                if (rss > abs(newSi - M[pos].f1)) {
                    rss = abs(newSi - M[pos].f1);
                    p1 = M[pos].s2;
                    p2 = K[chosenKind].s2;
                }
                // _____error_____(newSi, M[pos].first, rss);
            }
        }
        
        // if (i == 4319)
        cout << p1 << " " << p2 << " " << rss << "\n";
        // _____error_____(rss);

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
      // freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/5.txt", "r", stdin);
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
