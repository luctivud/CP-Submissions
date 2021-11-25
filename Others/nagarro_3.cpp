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
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"



typedef long long int; typedef unsigned long long llu;

#define  forn(I7, E4) for(int I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(int I7=1ll; I7 < E4+1; (I7)+=1ll)
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





const int MOD = int(1e9) + 7;
const int &mod = MOD;

const long double EPS = 1e-6;

const int inf = 2e18;










/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/



/*          D S U         */

void makeSet(int n, vector<int> &par3t, vector<int> &ran4k) {
    iota(all(par3t), 0ll);
}

int find_repr(int x, vector<int> &par3t, vector<int> &ran4k) {
    if (x != par3t[x])
        par3t[x] = find_repr(par3t[x], par3t, ran4k);
    return par3t[x];
}

void Union(int x, int y, vector<int> &par3t, vector<int> &ran4k) {
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



int cheat(int n, int ** edges, int m, int firstBenchers[]) {
    vector<int> par3t(n+1, 0);
    vector<int> ran4k(n+1, 0);
    makeSet(n+1, par3t, ran4k);
    set<int> firstBenchersSet;
    for (int i = 0; i < m; i++) {
        firstBenchersSet.insert(firstBenchers[i]);
    }
    for (int i = 0; i < n-1; i++) {
        if (firstBenchersSet.find(edges[i][0]) != firstBenchersSet.end() and 
            firstBenchersSet.find(edges[i][1]) != firstBenchersSet.end()) {
            Union(edges[i][0], edges[i][1], par3t, ran4k);
        }
    }

    int sizeOfComponent[n] = {0};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int repr = find_repr(i, par3t, ran4k);
        sizeOfComponent[repr] += 1;
        ans = max(ans, sizeOfComponent[repr]);
    }
    return ans;

}



void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    


    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
        freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
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
