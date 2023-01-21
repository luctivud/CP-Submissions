/*          J  A  I   S  H  R  E  E   R  A  M          */
#ifdef LUCTIVUD
    #include "mydebug.h"
    pprint:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #include "bits/stdc++.h"
    using namespace std;
    #define _____error_____(...)
#endif


// #pragma GCC optimize("O3,unroll-loops,trapv")
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());











/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/
lld ans[51][51];
lld mxgot = 0;


void demo(lld n) {
    vector<lld> arr(n*n);
    forn(i, n*n) arr[i] = i+1;
    set<lld> uniq;
    // forn(i, n*n) 
    // forn(j, n*n) {
    //     if (i!= j)
    //     uniq.insert(llabs(arr[i] - arr[j]));
    // }
    // _____error_____(n, uniq);
}

bool validate(vector<vector<lld>> &matr) {
    lld n = matr.size();
    set<lld> uniq;
    forn(i, n) {
        forn(j, n) {
            if (j+1 < n) {
                uniq.insert(llabs(matr[i][j] - matr[i][j+1]));
            }
            if (i+1 < n) {
                uniq.insert(llabs(matr[i][j] - matr[i+1][j]));
            }
            if (i-1 >= 0) {
                uniq.insert(llabs(matr[i-1][j] - matr[i][j]));
            }
            if (j-1 >= 0) {
                uniq.insert(llabs(matr[i][j] - matr[i][j-1]));
            }
        }
    }
    // _____error_____(matr, uniq.size());
    // _____error_____(n, uniq);
    // return (uniq.size()+1 == n*n);
    if (mxgot < uniq.size()) {
        mxgot = uniq.size();
        forn(i, n) forn(j, n) ans[i][j] = matr[i][j];
    }
}


void solve(vector<vector<lld>> &matr) {
    lld n = matr.size();
    vector<lld> arr(n*n+1, 0);
    // forn(i, n*n) arr[i] = i+1;

    // shuffle(all(arr), default_random_engine(0));


    forn(i, n) {
        forn(j, n) {
            lld num = (rng() % (n * n)) + 1;
            while (arr[num]) {
                num = (rng() % (n * n)) + 1;
            }
            arr[num] = 1;
            matr[i][j] = num;
        }
    }
}


void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; 
    mxgot = 0;
    #ifndef LUCTIVUD
        cin >> n;
    #else 
        n = _TestCase+1;
        demo(n);
    #endif
    
            
    vector<vector<lld>> matr(n, vector<lld>(n, 0));
    // while (!validate(matr)) {
    forn(zz, 50) {
        solve(matr);
        validate(matr);
    }

    forn(i, n) {
        forn(j, n) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    #ifdef LUCTIVUD
        // NonIterable.print(matr);
        _____error_____(n, mxgot);
        validate(matr);
        #endif

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    // cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

    srand(time(0));

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/Users/luctivud/CPPrc/Zinput.txt", "r", stdin);
        freopen("/Users/luctivud/CPPrc/Zoutput.txt", "w", stdout);
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
