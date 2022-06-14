/*          J  A  I   S  H  R  E  E   R  A  M          */
#ifdef LUCTIVUD
    #include <mydebug.h>
    pprint:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #include <bits/stdc++.h>
    using namespace std;
    #define _____error_____(...)
#endif


#pragma GCC optimize("O3,unroll-loops,trapv")
// #pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"



typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};





const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e10;





const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};




/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/

class Point {
public:
    lld x, y;
    Point(lld m_x, lld m_y) : x(m_x), y(m_y) {}
};



void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld k; cin >> k;

    lld n, m; cin >> n >> m;

    lld matr[n][m], dp[n][m];
    forn(i, n) {
        forn(j, m) {
            cin >> matr[i][j];
            dp[i][j] = inf;
        }
    }

    set<pair<lld, pair<lld, lld>>> q;
    q.insert({matr[0][0], {0ll, 0ll}});
    while (q.size()) {
        auto [dist, point] = *(q.begin());
        q.erase(q.begin());
        forn(xx, 4) {
            lld newI = point.f1 + d4i[xx];
            lld newJ = point.s2 + d4j[xx];
            if (newI >= 0 and newI < n and newJ >= 0 and newJ < m and dist + matr[newI][newJ] < dp[newI][newJ]) {
                dp[newI][newJ] = dist + matr[newI][newJ];
                q.insert({dp[newI][newJ], {newI, newJ}});
            }
        }
    }

    cout << max(-1ll, k - 10 * dp[n-1][m-1]);
    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/udit/CPPrc/zinput.txt", "r", stdin);
        freopen("/home/udit/CPPrc/zoutput.txt", "w", stdout);
    #endif


    int __NTestCases = 1;
    cin >> __NTestCases; 
    
    for (int _TestCase = 1; _TestCase <= __NTestCases; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }


    #ifdef LUCTIVUD
        // auto end_time = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<double> diff = end_time - start_time;
        // cerr << "Finished in : " << diff.count() << "\n";
    #endif


    return 0; 
}




/*  ~~
    .?.?.?.
*/
