/*          J  A  I   S  H  R  E  E   R  A  M          */



#include <bits/stdc++.h>
using namespace std;

#ifdef LUCTIVU
    #include <buggyBaby.hpp>
    pretty:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #define _____error_____(...)
#endif

#pragma GCC optimize("O3,unroll-loops,trapv")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"






/*  Snips   */


typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second



/*  Utils   */


const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



signed pleaseAC(void) {

#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}


void IAmJustice(void) {
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/IO/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/IO/Zoutput.txt", "w", stdout);
#endif

    return;
}














/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    map<lld, lld> cntRows, cntCols;

    set<lld> availRows, availCols;

    forn(i, n) {
        availCols.insert(i);
        availRows.insert(i);
    }

    char matr[n][n];

    forn(i, n) {
        forn(j, n) {
            char c; cin >> c;
            matr[i][j] = c;
            if (c == 'X') {
                cntRows[i] += 1;
                cntCols[j] += 1;
            } else if (c == 'O') {
                if (availRows.find(i) != availRows.end()) {
                    availRows.erase(i);
                }
                if (availCols.find(j) != availCols.end()) {
                    availCols.erase(j);
                }
            }
        }
    }

    _____error_____(availRows);
    _____error_____(availCols);

    lld minRepl = inf;
    vector<lld> rowsAns, colsAns;

    for (auto ke : availRows) {
        lld va = cntRows[ke];
        if (n-va < minRepl) {
            minRepl = n-va;
            colsAns.clear();
            rowsAns.clear();
            rowsAns.push_back(ke);
        } else if (n-va == minRepl) {
            rowsAns.push_back(ke);
        }
    }

    for (auto ke : availCols) {
        lld va = cntCols[ke];
        if (n-va < minRepl) {
            minRepl = n-va;
            rowsAns.clear();
            colsAns.clear();
            colsAns.push_back(ke);
        } else if (n-va == minRepl) {
            colsAns.push_back(ke);
        }
    }

    _____error_____(rowsAns);
    _____error_____(colsAns);

    lld possets = (lld) rowsAns.size() + (lld) colsAns.size();

    if (minRepl == inf) {
        cout << "Impossible";
        return;
    }

    if (minRepl == 1) {
        set<pair<lld, lld>> bebyPos;
        for (auto i : rowsAns) {
            forn(j, n) {
                if (matr[i][j] == '.') {
                    bebyPos.insert({i, j});
                }
            }
        }
        for (auto i : colsAns) {
            forn(j, n) {
                if (matr[j][i] == '.') {
                    bebyPos.insert({j, i});
                }
            }
        }
        _____error_____(bebyPos);
        possets = (lld)bebyPos.size();
    }


    cout << minRepl << " " << possets;


    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    IAmJustice();

    int _T0T4 = 1;
    cin >> _T0T4; 
    
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }

    return pleaseAC(); 
}




/*  ~~
    .?.?.?.
*/
