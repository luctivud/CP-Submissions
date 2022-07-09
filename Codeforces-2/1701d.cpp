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
    lld n; cin >> n;
    vector<array<lld, 4>> arr(n);
    vector<lld> ans(n, -1);
    set<lld> nums;
    forn(i, n) {
        cin >> arr[i][0];
        lld num = i + 1;
        nums.insert(i+1);
        arr[i][3] = i;
        if (arr[i][0] == 0) {
            arr[i][1] = num + 1;
            arr[i][2] = n;
            continue;
        }
        arr[i][1] = (num / (arr[i][0] + 1)) + 1;
        arr[i][2] = (num / arr[i][0]);
    }

    sort(all(arr), [](auto a, auto b){
        return a[2] < b[2]; 
    });

    // NonIterable.print(arr);

    forn(i, n) {
        lld l = arr[i][1], r = arr[i][2], res = -1ll;
        res = *((nums.lower_bound(l)));
        // while (l <= r) {
        //     lld mid = (l + r) / 2;
        //     if (nums.find(mid) != nums.end()) {
        //         res = mid;
        //         r = mid - 1;
        //     } else {
        //         l = mid + 1;
        //     }
        // }
        // _____error_____(nums, l, r);
        // _____error_____(res);
        assert(res >= l and res <= r);
        ans[arr[i][3]] = res;
        nums.erase(res);
    }

    forn(i, n) {
        // assert(lld((i+1) / ans[i]) == arr[i][0]);
        // _____error_____((i+1) / ans[i]);
        cout << ans[i] << " ";
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
