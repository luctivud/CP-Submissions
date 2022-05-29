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

const lld inf = 2e18;










/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/


bool canReach(int n, int m, vector<vector<int>> &grid, int destX, int destY){
    // Write your code here.
    vector<pair<int, int>> guards;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                guards.push_back({i, j});
            }
        }
    }
    for (pair<int, int> pos : guards) {
        int i = pos.first, j = pos.second;
        for (int x = i+1; x < n && (grid[x][j] == 0 or grid[x][j] == 3); x++) {
            grid[x][j] = 3;
        }
        for (int x = i-1; x >= 0 && (grid[x][j] == 0 or grid[x][j] == 3); x--) {
            grid[x][j] = 3;
        }
        for (int x = j+1; x < m && (grid[i][x] == 0 or grid[i][x] == 3); x++) {
            grid[i][x] = 3;
        }
        for (int x = j-1; x >= 0 && (grid[i][x] == 0 or grid[i][x] == 3); x--) {
            grid[i][x] = 3;
        }
    }
    


    queue<pair<int, int>> q;
    if (grid[destX][destY] == 0) {
        q.push({destX, destY});
        grid[destX][destY] = 4;
    }

    const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};

    while (q.size()) {
        pair<int, int> pos = q.front(); q.pop();
        int i = pos.first, j = pos.second;
        for (int x = 0; x < 4; x++) {
            int newI = i + d4i[x], newJ = j + d4j[x];
            if (newI >= 0 && newI < n and newJ >= 0 and newJ < m and (grid[newI][newJ] == 0)) {
                grid[newI][newJ] = 4;
                q.push({newI, newJ});
            }
        }
    }

    bool ok = false;
    vector<pair<int, int>> entries = {{0, 0}, {n-1, m-1}, {0, m-1}, {n-1, 0}};
    for (pair<int, int> entry : entries) {
        if (grid[entry.first][entry.second] == 4) {
            ok = true;
        }
    }

    return ok;
}



void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    int n, m; cin >> n >> m;

    vector<vector<int>> grid(n, vector<int> (m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int destX, destY; cin >> destX >> destY;


    if ((_TestCase == 609) or (_TestCase == 708)) {
        _____error_____(destX, destY);
        NonIterable.print(grid);
        bool ok = canReach(n, m, grid, destX, destY);
        NonIterable.print(grid);
        _____error_____(ok);
    }


    // _____error_____(ok);
    // cout << (ok ? "YES" : "NO");
    
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
        // cout << "\n";
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
