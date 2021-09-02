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
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};





const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;




int getMid(int s, int e) { return s + (e - s) / 2; }
 
int MaxUtil(int* st, int ss, int se, int l, int r, int node) {
    if (l <= ss && r >= se)
        return st[node];
    if (se < l || ss > r)
        return -1;
    int mid = getMid(ss, se);
    return max(MaxUtil(st, ss, mid, l, r, 2 * node + 1),
               MaxUtil(st, mid + 1, se, l, r, 2 * node + 2));
}


int getMax(int* st, int n, int l, int r) {
    if (l < 0 || r > n - 1 || l > r) {
        return -1;
    }
    return MaxUtil(st, 0, n - 1, l, r, 0);
}

 
int constructSTUtil(int arr[], int ss, int se, int* st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
     
    st[si] = max(constructSTUtil(arr, ss, mid, st,
                                 si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se,
                                 st, si * 2 + 2));
     
    return st[si];
}


int* constructST(int arr[], int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    int* st = new int[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}




int Solve(int n, vector<int> &arr, int q, vector<vector<int>> queries) {
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) {
            dp[i] = dp[i-1] + 1;
        } else {
            dp[i] = 1;
        }
    }

    int *st = constructST(dp, n);

    for (int i = 0; i < q; i++) {
        int l = queries[i][0] - 1;
        int r = queries[i][1] - 1;
        int mx = getMax(st, n, l, r);
        if (mx > r-l+1) {
            mx = mx - dp[l];
        }
        cout << mx << "\n";
    }

    return 0;
}




void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    int n; cin >> n;
    vector<int> arr(n);
    forn(i, n) {
        cin >> arr[i];
    }

    int q; cin >> q;
    vector<vector<int>> queries(q, vector<int> (2));

    forn(i, q) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solve(n, arr, q, queries);
    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
        freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    int _T0T4 = 1;
    // cin >> _T0T4;    
    
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
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
