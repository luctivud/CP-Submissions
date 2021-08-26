// ------------------------------------------------------------------- //
/*

      Author :  Udit "luctivud" Gupta
    Linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
      Github :  https://github.com/luctivud

*/
// ------------------------------------------------------------------- //



/*          J  A  I   S  H  R  E  E   R  A  M          */



#include <bits/stdc++.h>
using namespace std;

#ifdef LUCTIVUD
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
    // cout << "Case #" << _TestCase << ": ";
    lld n, m, k; cin >> n >> m >> k;
    char matr[n][m];
    forn(i, n) {
        forn(j, m) {
            cin >> matr[i][j];
        }
    }

    dequeue<pair<lld, lld>> q;
    vector<vector<lld>> cntBlockedNeighbours(n, vector<lld>(m, 4));

    lld xdir[] = {1, 0, 0, -1};
    lld ydir[] = {0, 1, -1, 0};

    forn(i, n) {
        forn(j, m) {
            if (matr[i][j] == '#') {
                cntBlockedNeighbours[i][j] = 4;
                continue;
            }
            lld ni, nj;
            forn(z, 4) {
                ni = i + xdir[z];
                nj = j + ydir[z];
                if (ni >= 0 and ni < n and nj >= 0 and nj < m) {
                    cntBlockedNeighbours[i][j] -= (matr[ni][nj] == '.');
                }
            }
            if (cntBlockedNeighbours[i][j] == 3) {
                q.push({i, j});
            }
        }
    }


    while (k > 0) {
        auto [i, j] = q.front(); q.pop();
        // assert(matr[i][j] == '.');
        if (matr[i][j] != '.') continue;
        matr[i][j] = 'X';
        lld ni, nj;
        forn(z, 4) {
            ni = i + xdir[z];
            nj = j + ydir[z];
            if (ni >= 0 and ni < n and nj >= 0 and nj < m and matr[ni][nj] == '.') {
                cntBlockedNeighbours[ni][nj] += 1;
                if (cntBlockedNeighbours[ni][nj] == 3) {
                    q.push({ni, nj});
                }
            }
        }
        k--;
    }

    forn(i, n) {
        forn(j, m) {
            cout << matr[i][j];
        }
        cout << "\n";
    }


    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    IAmJustice();

    int _T0T4 = 1;
    // cin >> _T0T4;

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }

    return pleaseAC();
}




/*

    Speed Solving

*/
