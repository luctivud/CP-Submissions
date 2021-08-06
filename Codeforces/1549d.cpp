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
// #pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,bmi,bmi2,lzcnt")
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
    lld n; cin >> n;
    lld arr[n], diff[n-1];
    forn(i, n) {
        cin >> arr[i];
        if (i) diff[i-1] = llabs(arr[i] - arr[i-1]);
    }

    if (n == 1) {
        cout << 1;
        return;
    }

    n -= 1;

    lld table[n][26];
    for (int i = 0; i < n; i++) {
        table[i][0] = diff[i];
    }
    
    for (int j = 1; j < 26; j++) {
        for (int i = 0; i <= (n - (1ll << j)); i++) {
            table[i][j] = __gcd(table[i][j-1], table[i + (1ll << (j - 1))][j - 1]);
        }
    }

    lld l = 1, r = n, ans = 1;
    while (l <= r) {
        lld mid = l + (r - l) / 2;
        lld sz = (lld)log2(mid);
        bool ok = false;
        for (int i = 0; i+mid <= n; i++) {
            if (__gcd(table[i][sz], table[i+mid-(1ll << sz)][sz]) != 1) {
                ok = true;
                break;
            }
        }
        if (ok) {
            l = mid + 1;
            ans = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    IAmJustice();

    int _T0T4 = 1;
    cin >> _T0T4; 
    
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
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









// #include <bits/stdc++.h>
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// // using namespace __gnu_pbds;
 
// // Pragmas
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
 
// // Aliases
// using ll = long long;
// using ull = unsigned long long;
// using ld = long double;
// // template<typename T>
// // using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// // Constants
// constexpr ll INF = 2e18;
// constexpr ld EPS = 1e-9;
// constexpr ll MOD = 1000000007;
 
// // Macros
// #define F first
// #define S second
// #define all(x) begin(x), end(x)
// #define allr(x) rbegin(x), rend(x)
// #define int long long
 
// // Custom hash map
// struct custom_hash
// {
//     static uint64_t splitmix64(uint64_t x)
//     {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
 
//     size_t operator()(uint64_t x) const
//     {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
// template <typename T1, typename T2> // Key should be integer type
// using safe_map = unordered_map<T1, T2, custom_hash>;
 
// // Operator overloads
// template<typename T1, typename T2> // cin >> pair<T1, T2>
// istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
// template<typename T> // cin >> vector<T>
// istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
// template<typename T1, typename T2> // cout << pair<T1, T2>
// ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
// template<typename T> // cout << vector<T>
// ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
// // Utility functions
// template <typename T>
// void print(T &&t)  { cout << t << "\n"; }
// template <typename T, typename... Args>
// void print(T &&t, Args &&... args)
// {
//     cout << t << " ";
//     print(forward<Args>(args)...);
// }
 
// template <typename T>
// int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }
 
// // Mathematical functions
// int GCD(int a, int b) {
//     while (b)
//     {
//         a %= b;
//         swap(a, b);
//     }
//     return a;
// }
// int GCD_extended(int a, int b, int &x, int &y) {
//     x = 1, y = 0;
//     int x1 = 0, y1 = 1, a1 = a, b1 = b;
//     while (b1)
//     {
//         int q = a1 / b1;
//         tie(x, x1) = make_tuple(x1, x - q * x1);
//         tie(y, y1) = make_tuple(y1, y - q * y1);
//         tie(a1, b1) = make_tuple(b1, a1 - q * b1);
//     }
//     return a1;
// }
// int LCM(int a, int b)
// {
//     return (a * b) / GCD(a, b);
// }
 
// int modpow(ll x, int n, int m = MOD)
// {
//     ll res = 1;
//     while (n > 0) 
//     {
//         if (n & 1)
//             res = (res * x) % m;
//         x = (x * x) % m;
//         n >>= 1;
//     }
//     return res;
// }
// int modinv(int x, int m = MOD)
// {   
//     return modpow(x, m - 2, m);
// }
 
// mt19937 rng;
// int getRandomNumber(int l, int r)
// {
//     uniform_int_distribution<int> dist(l, r);
//     return dist(rng);
// }
 
// // Flags to use: -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
// ///////////////////////////////////////////////////////////// START CODE HERE /////////////////////////////////////////////////////////////
 
// void preSolve()
// { 
//     rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
// }
 
// constexpr int MAX_SIZE = 2e5 + 5;
 
// int st[4 * MAX_SIZE];
 
// int combine(int x, int y)
// {
//     return GCD(x, y); // sum for sum queries
// }
 
// void buildST(vector<int> &a, int v, int l, int r)
// {
//     if (l == r)
//         st[v] = a[l];
//     else
//     {
//         int mid = (l + r) / 2;
//         buildST(a, 2 * v, l, mid);
//         buildST(a, 2 * v + 1, mid + 1, r);
//         st[v] = combine(st[v * 2], st[v * 2 + 1]);
//     } 
// }
 
// int sumQuery(int v, int nL, int nR, int l, int r)
// {
//     if (l > r)
//         return 0;
//     if (nL == l && nR == r)
//         return st[v];
//     int mid = (nL + nR) / 2;
//     return combine(
//         sumQuery(v * 2, nL, mid, l, min(r, mid)),
//         sumQuery(v * 2 + 1, mid + 1, nR, max(l, mid + 1), r)
//     );          
// }
 
// void updateST(int v, int nL, int nR, int pos, int newVal)
// {
//     if (nL == nR)
//     {
//         st[v] = newVal;
//         return;
//     }
//     int mid = (nL + nR) / 2;
//     if (pos <= mid)
//         updateST(2 * v, nL, mid, pos, newVal);
//     else
//         updateST(2 * v + 1, mid + 1, nR, pos, newVal);
//     st[v] = combine(st[2 * v], st[2 * v + 1]);
// }
 
 
// void solve(int tc)
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     cin >> a;
//     if (n == 1)
//     {
//         return void(print(1));
//     }
//     vector<int> d;
//     for (int i = 1; i < n; i++)
//         d.push_back(abs(a[i] - a[i - 1]));
//     n--;
 
//     int ans = 1;
//     int lo = 1, hi = n;
//     buildST(d, 1, 0, n - 1);
//     while (lo <= hi)
//     {
//         int sz = (lo + hi) / 2;
//         bool can = false;
//         for (int i = 0; i + sz - 1 < n; i++)
//         {
//             if (sumQuery(1, 0, n - 1, i, i + sz - 1) != 1)
//             {
//                 can = true;
//                 break;
//             }
//         }
//         if (can)
//         {
//             ans = sz + 1;
//             lo = sz + 1;
//         } else 
//         {
//             hi = sz - 1;
//         }
//     }
//     print(ans);
// }
 
// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout << setprecision(12) << fixed;
 
//     preSolve();
//     int tests = 1;
//     cin >> tests;
//     for (int t = 1; t <= tests; t++)
//         solve(t);
//     return 0;
// }


// // // // ------------------------------------------------------------------- //
// // // /*

// // //       Author :  Udit "luctivud" Gupta
// // //     Linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
// // //       Github :  https://github.com/luctivud

// // // */
// // // // ------------------------------------------------------------------- //



// // // /*          J  A  I   S  H  R  E  E   R  A  M          */



// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // #ifdef LUCTIVUD
// // // #include <buggyBaby.hpp>
// // // pretty:: PrettyPrinter NonIterable;
// // // #define cerr cout
// // // #else
// // // #define _____error_____(...)
// // // #endif
// // // #pragma GCC optimize "trapv"



// // // /*
// // //     Snips
// // //             */



// // // typedef long long lld; typedef unsigned long long llu;

// // // #define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
// // // #define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
// // // #define        len(v) ((int)((v).size()))
// // // #define        all(x) (x).begin(), (x).end()
// // // #define       rall(x) (x).rbegin(), (x).rend()
// // // #define            f1 first
// // // #define            s2 second


// // // /*
// // //     Utils
// // //             */


// // // const lld MOD = int(1e9) + 7;
// // // const lld &mod = MOD;

// // // const long double EPS = 1e-6;

// // // const lld inf = 2e18;


// // // struct custom_hash {
// // //     static uint64_t splitmix64(uint64_t x) {
// // //         // http://xorshift.di.unimi.it/splitmix64.c
// // //         x += 0x9e3779b97f4a7c15;
// // //         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// // //         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// // //         return x ^ (x >> 31);
// // //     }

// // //     size_t operator()(uint64_t x) const {
// // //         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// // //         return splitmix64(x + FIXED_RANDOM);
// // //     }
// // // };


// // // void IAmJustice(void) {

// // // #ifdef LUCTIVUD
// // //     // const auto start_time = std::chrono::high_resolution_clock::now();
// // //     freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
// // //     freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
// // // #endif

// // //     return;
// // // }



// // // signed pleaseAC(void) {

// // // // #ifdef LUCTIVUD
// // // //     // auto end_time = std::chrono::high_resolution_clock::now();
// // // //     // std::chrono::duration<double> diff = end_time - start_time;
// // // //     // cerr << "Finished in : " << diff.count() << "\n";
// // // // #endif

// // //     return 0;
// // // }



// // // #define int lld

// // // // int getMid(int s, int e) {
// // // //     return (s + (e - s) / 2);
// // // // }
// // // // int getGcdUtil(int* st, int ss, int se, int qs, int qe, int si) {
// // // //     if (qs <= ss && qe >= se)
// // // //         return st[si];

// // // //     if (se < qs || ss > qe)
// // // //         return 0;

// // // //     int mid = getMid(ss, se);
// // // //     return __gcd(getGcdUtil(st, ss, mid, qs, qe, 2 * si + 1),
// // // //                  getGcdUtil(st, mid + 1, se, qs, qe, 2 * si + 2));
// // // // }
// // // // int getGcd(int* st, int n, int qs, int qe) {

// // // //     if (qs < 0 || qe > n - 1 || qs > qe) {
// // // //         return -1;
// // // //     }

// // // //     return getGcdUtil(st, 0, n - 1, qs, qe, 0);
// // // // }
// // // // int constructGcdUtil(int arr[], int ss, int se, int* st, int si) {
// // // //     if (ss == se) {
// // // //         st[si] = arr[ss];
// // // //         return arr[ss];
// // // //     }

// // // //     int mid = getMid(ss, se);
// // // //     st[si] = __gcd(constructGcdUtil(arr, ss, mid, st, si * 2 + 1),
// // // //                    constructGcdUtil(arr, mid + 1, se, st, si * 2 + 2));
// // // //     return st[si];
// // // // }

// // // // int* constructGcd(int arr[], int n) {
// // // //     int x = (int)(ceil(log2(n)));
// // // //     int max_size = 2 * (int)pow(2, x) - 1;
// // // //     int* st = new int[max_size];
// // // //     constructGcdUtil(arr, 0, n - 1, st, 0);
// // // //     return st;
// // // // }

// // // int GCD(int a, int b) {
// // //     while (b)
// // //     {
// // //         a %= b;
// // //         swap(a, b);
// // //     }
// // //     return a;
// // // }


// // // constexpr int MAX_SIZE = 2e5 + 5;

// // // int st[4 * MAX_SIZE];

// // // int combine(int x, int y)
// // // {
// // //     return GCD(x, y); // sum for sum queries
// // // }

// // // void buildST(vector<int> &a, int v, int l, int r)
// // // {
// // //     if (l == r)
// // //         st[v] = a[l];
// // //     else
// // //     {
// // //         int mid = (l + r) / 2;
// // //         buildST(a, 2 * v, l, mid);
// // //         buildST(a, 2 * v + 1, mid + 1, r);
// // //         st[v] = combine(st[v * 2], st[v * 2 + 1]);
// // //     }
// // // }

// // // int sumQuery(int v, int nL, int nR, int l, int r)
// // // {
// // //     if (l > r)
// // //         return 0;
// // //     if (nL == l && nR == r)
// // //         return st[v];
// // //     int mid = (nL + nR) / 2;
// // //     return combine(
// // //                sumQuery(v * 2, nL, mid, l, min(r, mid)),
// // //                sumQuery(v * 2 + 1, mid + 1, nR, max(l, mid + 1), r)
// // //            );
// // // }

// // // void updateST(int v, int nL, int nR, int pos, int newVal)
// // // {
// // //     if (nL == nR)
// // //     {
// // //         st[v] = newVal;
// // //         return;
// // //     }
// // //     int mid = (nL + nR) / 2;
// // //     if (pos <= mid)
// // //         updateST(2 * v, nL, mid, pos, newVal);
// // //     else
// // //         updateST(2 * v + 1, mid + 1, nR, pos, newVal);
// // //     st[v] = combine(st[2 * v], st[2 * v + 1]);
// // // }



// // // void SolveEachTest(int _TestCase) {
// // //     // cout << "Case #" << _TestCase << ": ";
// // //     lld n; cin >> n;
// // //     lld a[n];
// // //     forn(i, n) cin >> a[i];

// // //     if (n == 1) {
// // //         cout << 1;
// // //         return;
// // //     }

// // //     vector<int> d;
// // //     for (int i = 1; i < n; i++)
// // //         d.push_back(abs(a[i] - a[i - 1]));
// // //     n--;

// // //     int ans = 1;
// // //     int lo = 1, hi = n;
// // //     buildST(d, 1, 0, n - 1);
// // //     while (lo <= hi)
// // //     {
// // //         int sz = (lo + hi) / 2;
// // //         bool can = false;
// // //         for (int i = 0; i + sz - 1 < n; i++)
// // //         {
// // //             if (sumQuery(1, 0, n - 1, i, i + sz - 1) != 1)
// // //             {
// // //                 can = true;
// // //                 break;
// // //             }
// // //         }
// // //         if (can)
// // //         {
// // //             ans = sz + 1;
// // //             lo = sz + 1;
// // //         } else
// // //         {
// // //             hi = sz - 1;
// // //         }
// // //     }
// // //     // vector<lld> gc(n - 1, 1);
// // //     // forn(i, n - 1) {
// // //     //     gc[i] = llabs(a[i + 1] - a[i]);
// // //     //     // cout << gc[i] << " ";
// // //     // }


// // //     // n--;
// // //     // // // int* st = constructGcd(gc, n - 1);

// // //     // lld l = 1ll, r = n, ans = 1;
// // //     // buildST(gc, 1, 0, n - 1);

// // //     // while (l <= r) {
// // //     //     int sz = (l + r) / 2;
// // //     //     bool can = false;
// // //     //     for (int i = 0; i + sz - 1 < n; i++)
// // //     //     {
// // //     //         if (sumQuery(1, 0, n - 1, i, i + sz - 1) != 1)
// // //     //         {
// // //     //             can = true;
// // //     //             break;
// // //     //         }
// // //     //     }
// // //     //     if (can)
// // //     //     {
// // //     //         ans = sz + 1;
// // //     //         l = sz + 1;
// // //     //     } else
// // //     //     {
// // //     //         r = sz - 1;
// // //     //     }
// // //     // }

// // // // vector<int> d;
// // // // for (int i = 1; i < n; i++)
// // // //     d.push_back(abs(a[i] - a[i - 1]));
// // // // n--;

// // // // int ans = 1;
// // // //     int lo = 1, hi = n;
// // // // // buildST(d, 1, 0, n - 1);
// // // //     while (lo <= hi)
// // // //     {
// // // //         int sz = (lo + hi) / 2;
// // // //         bool can = false;
// // // //         for (int i = 0; i + sz - 1 < n; i++)
// // // //         {
// // // //             if (sumQuery(1, 0, n - 1, i, i + sz - 1) != 1)
// // // //             {
// // // //                 can = true;
// // // //                 break;
// // // //             }
// // // //         }
// // // //         if (can)
// // // //         {
// // // //             ans = sz + 1;
// // // //             lo = sz + 1;
// // // //         } else
// // // //         {
// // // //             hi = sz - 1;
// // // //         }
// // // //     }

// // //     cout << ans << "\n";

// // // }

// // // /*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





// // // /*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/



// // // // signed main() {

// // // //     ios_base::sync_with_stdio(false); cin.tie(0);
// // // //     // cout.precision(10); cout << fixed;

// // // //     // IAmJustice();

// // // //     int _T0T4 = 1;
// // // //     cin >> _T0T4;

// // // //     for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
// // // //         // Aurora.SolveEachTest(_TestCase);
// // // //         // Aurora.ResetTestCase();
// // // //         SolveEachTest(_TestCase);
// // // //         cout << "\n";
// // // //     }

// // // //     return pleaseAC();
// // // // }

// // // int32_t main()
// // // {
// // //     ios_base::sync_with_stdio(false);
// // //     cin.tie(0);
// // //     cout << setprecision(12) << fixed;
 
// // //     // preSolve();
// // //     int tests = 1;
// // //     cin >> tests;
// // //     for (int t = 1; t <= tests; t++)
// // //         SolveEachTest(t);
// // //     return 0;
// // // }



// // // /*  ~~

// // //     I ponder of something great
// // //     My lungs will fill and then deflate
// // //     They fill with fire, exhale desire
// // //     I know it's dire my time today

// // //     I have these thoughts, so often I ought
// // //     To replace that slot with what I once bought
// // //     'Cause somebody stole my car radio
// // //     And now I just sit in silence

// // //     Sometimes quiet is violent
// // //     I find it hard to hide it
// // //     My pride is no longer inside
// // //     It's on my sleeve
// // //     My skin will scream reminding me of
// // //     Who I killed inside my dream
// // //     I hate this car that I'm driving
// // //     There's no hiding for me
// // //     I'm forced to deal with what I feel
// // //     There is no distraction to mask what is real
// // //     I could pull the steering wheel

// // // */

// // #include <bits/stdc++.h>
// // // #include <ext/pb_ds/assoc_container.hpp>
// // // #include <ext/pb_ds/tree_policy.hpp>
// // using namespace std;
// // // using namespace __gnu_pbds;

// // // Pragmas
// // #pragma GCC optimize("Ofast")
// // #pragma GCC target("avx,avx2,fma")

// // // Aliases
// // using ll = long long;
// // using ull = unsigned long long;
// // using ld = long double;
// // // template<typename T>
// // // using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// // // Constants
// // constexpr ll INF = 2e18;
// // constexpr ld EPS = 1e-9;
// // constexpr ll MOD = 1000000007;

// // // Macros
// // #define F first
// // #define S second
// // #define all(x) begin(x), end(x)
// // #define allr(x) rbegin(x), rend(x)
// // #define int long long

// // // Custom hash map
// // struct custom_hash
// // {
// //     static uint64_t splitmix64(uint64_t x)
// //     {
// //         x += 0x9e3779b97f4a7c15;
// //         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// //         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// //         return x ^ (x >> 31);
// //     }

// //     size_t operator()(uint64_t x) const
// //     {
// //         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// //         return splitmix64(x + FIXED_RANDOM);
// //     }
// // };
// // template <typename T1, typename T2> // Key should be integer type
// // using safe_map = unordered_map<T1, T2, custom_hash>;

// // // Operator overloads
// // template<typename T1, typename T2> // cin >> pair<T1, T2>
// // istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
// // template<typename T> // cin >> vector<T>
// // istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
// // template<typename T1, typename T2> // cout << pair<T1, T2>
// // ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
// // template<typename T> // cout << vector<T>
// // ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// // // Utility functions
// // template <typename T>
// // void print(T &&t)  { cout << t << "\n"; }
// // template <typename T, typename... Args>
// // void print(T &&t, Args &&... args)
// // {
// //     cout << t << " ";
// //     print(forward<Args>(args)...);
// // }

// // template <typename T>
// // int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }

// // // Mathematical functions
// // int GCD(int a, int b) {
// //     while (b)
// //     {
// //         a %= b;
// //         swap(a, b);
// //     }
// //     return a;
// // }
// // int GCD_extended(int a, int b, int &x, int &y) {
// //     x = 1, y = 0;
// //     int x1 = 0, y1 = 1, a1 = a, b1 = b;
// //     while (b1)
// //     {
// //         int q = a1 / b1;
// //         tie(x, x1) = make_tuple(x1, x - q * x1);
// //         tie(y, y1) = make_tuple(y1, y - q * y1);
// //         tie(a1, b1) = make_tuple(b1, a1 - q * b1);
// //     }
// //     return a1;
// // }
// // int LCM(int a, int b)
// // {
// //     return (a * b) / GCD(a, b);
// // }

// // int modpow(ll x, int n, int m = MOD)
// // {
// //     ll res = 1;
// //     while (n > 0) 
// //     {
// //         if (n & 1)
// //             res = (res * x) % m;
// //         x = (x * x) % m;
// //         n >>= 1;
// //     }
// //     return res;
// // }
// // int modinv(int x, int m = MOD)
// // {   
// //     return modpow(x, m - 2, m);
// // }

// // mt19937 rng;
// // int getRandomNumber(int l, int r)
// // {
// //     uniform_int_distribution<int> dist(l, r);
// //     return dist(rng);
// // }

// // // Flags to use: -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
// // ///////////////////////////////////////////////////////////// START CODE HERE /////////////////////////////////////////////////////////////

// // void preSolve()
// // { 
// //     rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
// // }

// // constexpr int MAX_SIZE = 2e5 + 5;

// // int st[4 * MAX_SIZE];

// // int combine(int x, int y)
// // {
// //     return GCD(x, y); // sum for sum queries
// // }

// // void buildST(vector<int> &a, int v, int l, int r)
// // {
// //     if (l == r)
// //         st[v] = a[l];
// //     else
// //     {
// //         int mid = (l + r) / 2;
// //         buildST(a, 2 * v, l, mid);
// //         buildST(a, 2 * v + 1, mid + 1, r);
// //         st[v] = combine(st[v * 2], st[v * 2 + 1]);
// //     } 
// // }

// // int sumQuery(int v, int nL, int nR, int l, int r)
// // {
// //     if (l > r)
// //         return 0;
// //     if (nL == l && nR == r)
// //         return st[v];
// //     int mid = (nL + nR) / 2;
// //     return combine(
// //         sumQuery(v * 2, nL, mid, l, min(r, mid)),
// //         sumQuery(v * 2 + 1, mid + 1, nR, max(l, mid + 1), r)
// //     );          
// // }

// // void updateST(int v, int nL, int nR, int pos, int newVal)
// // {
// //     if (nL == nR)
// //     {
// //         st[v] = newVal;
// //         return;
// //     }
// //     int mid = (nL + nR) / 2;
// //     if (pos <= mid)
// //         updateST(2 * v, nL, mid, pos, newVal);
// //     else
// //         updateST(2 * v + 1, mid + 1, nR, pos, newVal);
// //     st[v] = combine(st[2 * v], st[2 * v + 1]);
// // }


// // void solve(int tc)
// // {
// //     int n;
// //     cin >> n;
// //     vector<int> a(n);
// //     cin >> a;
// //     if (n == 1)
// //     {
// //         return void(print(1));
// //     }
// //     vector<int> d;
// //     for (int i = 1; i < n; i++)
// //         d.push_back(abs(a[i] - a[i - 1]));
// //     n--;

// //     int ans = 1;
// //     int lo = 1, hi = n;
// //     buildST(d, 1, 0, n - 1);
// //     while (lo <= hi)
// //     {
// //         int sz = (lo + hi) / 2;
// //         bool can = false;
// //         for (int i = 0; i + sz - 1 < n; i++)
// //         {
// //             if (sumQuery(1, 0, n - 1, i, i + sz - 1) != 1)
// //             {
// //                 can = true;
// //                 break;
// //             }
// //         }
// //         if (can)
// //         {
// //             ans = sz + 1;
// //             lo = sz + 1;
// //         } else 
// //         {
// //             hi = sz - 1;
// //         }
// //     }
// //     print(ans);
// // }

// // int32_t main()
// // {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(0);
// //     cout << setprecision(12) << fixed;

// //     preSolve();
// //     int tests = 1;
// //     cin >> tests;
// //     for (int t = 1; t <= tests; t++)
// //         solve(t);
// //     return 0;
// // }