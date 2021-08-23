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

    // ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/IO/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/IO/Zoutput.txt", "w", stdout);
#endif

    return;
}







/*          D S U         */

void makeSet(lld n, vector<lld> &par3t, vector<lld> &ran4k) {
    iota(all(par3t), 0ll);
}

lld find_repr(lld x, vector<lld> &par3t, vector<lld> &ran4k) {
    if (x != par3t[x])
        par3t[x] = find_repr(par3t[x], par3t, ran4k);
    return par3t[x];
}

void Union(lld x, lld y, vector<lld> &par3t, vector<lld> &ran4k) {
    // _____error_____(x, y);
    x = find_repr(x, par3t, ran4k);
    y = find_repr(y, par3t, ran4k);

    if (x == y) return;

    if (ran4k[x] < ran4k[y]) {
        par3t[x] = y;
    } else if (ran4k[x] > ran4k[y]) {
        par3t[y] = x;
    } else {
        par3t[y] = x;
        ran4k[x] = ran4k[x] + 1;
    }
    return;
}



// create par3t and ran4k at the place.







/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    cout << "Case #" << _TestCase << ": ";
    lld n, m; cin >> n >> m;
    vector<vector<char>> matr(n, vector<char> (m));
    forn(i, n) {
        forn(j, m) {
            cin >> matr[i][j];
        }
    }

    vector<lld> par3t(n * m, 0);
    vector<lld> ran4k(n * m, 0);
    makeSet(n * m, par3t, ran4k);

    forn(i, n) {
        lld lj = 0, rj = 0;
        while (rj < m) {
            lj = rj;
            while (lj < m and matr[i][lj] == '#') {
                lj++;
            }
            rj = lj;
            while (rj < m and matr[i][rj] != '#') {
                rj++;
            }
            rj--;
            // _____error_____(i, lj, rj);

            lld ljCopy = lj, rjCopy = rj;
            while (ljCopy < rjCopy) {
                lld pseudoNum1 = (i * m) + ljCopy;
                lld pseudoNum2 = (i * m) + rjCopy;
                Union(pseudoNum1, pseudoNum2, par3t, ran4k);
                ljCopy++, rjCopy--;
            }
            rj++;
        }
    }


    forn(i, m) {
        lld lj = 0, rj = 0;
        while (rj < n) {
            lj = rj;
            while (lj < n and matr[lj][i] == '#') {
                lj++;
            }
            rj = lj;
            while (rj < n and matr[rj][i] != '#') {
                rj++;
            }
            rj--;
            // _____error_____(i, lj, rj);

            lld ljCopy = lj, rjCopy = rj;
            while (ljCopy < rjCopy) {
                lld pseudoNum1 = (ljCopy * m) + i;
                lld pseudoNum2 = (rjCopy * m) + i;
                // _____error_____(pseudoNum1, pseudoNum2);
                Union(pseudoNum1, pseudoNum2, par3t, ran4k);
                ljCopy++, rjCopy--;
            }
            rj++;
        }
    }

    map<lld, vector<pair<lld, lld>>> cass;

    forn(i, n) {
        forn(j, m) {
            lld pseudoNum = (i * m) + j;
            lld parOfPseudo = find_repr(pseudoNum, par3t, ran4k);
            cass[parOfPseudo].push_back({i, j});
        }
    }

    // NonIterable.print(cass);

    lld ans = 0ll;

    for (auto [ke, va] : cass) {
        char yebeby = '$';
        for (auto [i, j] : va) {
            if (matr[i][j] != '#' and matr[i][j] != '.') {
                yebeby = matr[i][j];
                break;
            }
        }
        if (yebeby == '$') continue;
        for (auto [i, j] : va) {
            // _____error_____(i, j, yebeby);
            if (matr[i][j] == '.') ans++;
            matr[i][j] = yebeby;
        }
    }

    cout << ans << "\n";

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
    cin >> _T0T4;

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        // cout << "\n";
    }

    return pleaseAC();
}




/*  ~~
    I ponder of something great
    My lungs will fill and then deflate
    They fill with fire, exhale desire
    I know it's dire my time today

    I have these thoughts, so often I ought
    To replace that slot with what I once bought
    'Cause somebody stole my car radio
    And now I just sit in silence

    Sometimes quiet is violent
    I find it hard to hide it
    My pride is no longer inside
    It's on my sleeve
    My skin will scream reminding me of
    Who I killed inside my dream
    I hate this car that I'm driving
    There's no hiding for me
    I'm forced to deal with what I feel
    There is no distraction to mask what is real
    I could pull the steering wheel

*/
