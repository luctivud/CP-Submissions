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


bool isPalindrome(string s) {
    string sRev = s;
    reverse(all(sRev));
        // _____error_____(s);
    if (s == sRev) {
    }
    return s == sRev;
}


lld power(lld x, lld y) {
    lld res = 1;

    x = x % MOD;

    if (x == 0) return 0;

    while (y > 0)  {
        if (y & 1)
            res = (res * x) % MOD;

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}


lld p = 0ll, q = 0ll;
vector<lld> facto(402, 1);

void mulmod(lld &a, lld b) {
    (a *= b) %= mod;
}


void solve(string str) {
    int N = str.length();
 
    // create a 2D array to store the count of palindromic
    // subsequence
    int cps[N + 1][N + 1];
    memset(cps, 0, sizeof(cps));
 
    // palindromic subsequence of length 1
    for (int i = 0; i < N; i++)
        cps[i][i] = 2;
 
    // check subsequence of length L is palindrome or not
    for (int L = 2; L <= N; L++) {
        for (int i = 0; i <= N-L; i++) {
            int k = L + i - 1;
            if (str[i] == str[k])
                cps[i][k]
                    = (cps[i][k - 1] * facto[k-i]) + (cps[i + 1][k] * facto[k-i]) + facto[k-i+1];
            else
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k]
                            - cps[i + 1][k - 1];
        }
    }
 
    // return total palindromic subsequence
    p =  cps[0][N - 1];
    return;
}


void solveEachTest(int _TestCase) {
    cout << "Case #" << _TestCase << ": ";

    int n; cin >> n;
    string s; cin >> s;

    p = 0, q = facto[n];
    solve(s);

    cout << (p * power(q, mod - 2)) % mod;

    _____error_____(p, q);

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

    forn1(i, 401) {
        (facto[i] *= (facto[i-1] * i) % mod) %= mod;
    }

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
