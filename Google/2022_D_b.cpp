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
    cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    vector<lld> arr(n);
    forn(i, n) {
        cin >> arr[i];
    }

    lld m; cin >> m;
    vector<lld> brr(m);
    forn(i, m) {
        cin >> brr[i];
    }

    lld k; cin >> k;

    vector<lld> prefA(n), suffA(n), prefB(m), suffB(m);
    forn(i, n) {
        lld j = n-i-1;
        prefA[i] = arr[i];
        suffA[i] = arr[j];
        if (i) prefA[i] += prefA[i-1];
        if (i) suffA[i] += suffA[i-1];
    }

    forn(i, m) {
        lld j = m-i-1;
        prefB[i] = brr[i];
        suffB[i] = brr[j];
        if (i) prefB[i] += prefB[i-1];
        if (i) suffB[i] += suffB[i-1];
    }

    // _____error_____(prefA);
    // _____error_____(suffA);
    // _____error_____(prefB);
    // _____error_____(suffB);

    lld ans = 0ll;

    for (lld a = 0; a <= n; a++) {
        for (lld b = 0; b <= min(k-a, n-a); b++) {
            for (lld c = 0; c <= min(m, k-(a+b)); c++) {
                lld d = min({m, m-c, k-(a+b+c)});
                lld res = 0ll;
                if (a>0) res += prefA[a-1];
                if (b>0) res += suffA[b-1];
                if (c>0) res += prefB[c-1];
                if (d>0) res += suffB[d-1];
                // _____error_____(a, b, c, d, res);
                ans = max(ans, res);
            }
        }
    }

    cout << ans;

    // vector<array<lld, 2>> preSuf(k+1);

    // for (lld xx = 0; xx <= k; xx++) {
    //     lld pre = xx;
    //     lld suf = k-xx;
    //     lld mx = 0ll;
    //     for (lld i = 0; i <= pre; i++) {
    //         lld res = 0ll;
    //         if (i and i <= n) res += prefA[i-1];
    //         if (pre > i and pre - i <= m) res += prefB[pre - i - 1];
    //         mx = max(mx, res);
    //     }
    //     preSuf[xx][0] = mx;
    //     mx = 0ll;
    //     for (lld i = 0; i <= suf; i++) {
    //         lld res = 0ll;
    //         if (i and i <= n) res += suffA[i-1];
    //         if (suf > i and suf - i <= m) res += suffB[suf - i - 1];
    //         mx = max(mx, res);
    //     }
    //     preSuf[xx][1] = mx;
    // }

    // NonIterable.print(preSuf);

    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    // cin.tie(0)->sync_with_stdio(0);
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
