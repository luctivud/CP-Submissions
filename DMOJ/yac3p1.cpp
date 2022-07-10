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





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, m, a, b; cin >> n >> m >> a >> b;

    vector<array<lld, 4>> arr(m);
    forn(i, m) {
        cin >> arr[i][0];
        arr[i][1] = -1;
        if (arr[i][0] != -1) {
            cin >> arr[i][1];
        }
    }

    lld currPos = a;
    forn(i, m) {
        // _____error_____(currPos, arr[i][0], arr[i][1]);
        if ((arr[i][0] == currPos) or (arr[i][1] == currPos)) {
            currPos = arr[i][0] + arr[i][1] - currPos;
        }
        arr[i][2] = currPos;
    }

    currPos = b;
    forn(j, m) {
        lld i = n-j-1;
        // _____error_____(currPos, arr[i][0], arr[i][1]);
        if ((arr[i][0] == currPos) or (arr[i][1] == currPos)) {
            currPos = arr[i][0] + arr[i][1] - currPos;
        }
        arr[i][3] = currPos;
    }

    forn(j, m) {
        lld i = n-j-1;
        if (arr[i][0] == -1 and arr[i][0] != arr[i][1]) {
            arr[i][0] = arr[i][2];
            arr[i][1] = arr[i][3];
            break;
        }
    }

    currPos = a;
    forn(i, n) {
        set<lld> se {1, 2, 3};
        if (arr[i][0] == -1) {
            if (se.find(currPos) != se.end()) {
                se.erase(currPos);
            }
            arr[i][0] = *(se.begin());
            arr[i][1] = *(se.rbegin());
        }
        if ((arr[i][0] == currPos) or (arr[i][1] == currPos)) {
            currPos = arr[i][0] + arr[i][1] - currPos;
        }
    }

    // NonIterable.print(arr);

    forn(i, n) {
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    }
    
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
    // cin >> __NTestCases; 
    
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