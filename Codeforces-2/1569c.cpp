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
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
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





const lld MOD = 998244353;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;
const lld MAXN = lld(2e5)+1;


#define ll long long
const int N = MAXN;
using namespace std;
 
// array to store inverse of 1 to N
ll factorialNumInverse[N + 1];
 
// array to precompute inverse of 1! to N!
ll naturalNumInverse[N + 1];
 
// array to store factorial of first N numbers
ll fact[N + 1];
 
// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
 
    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
// Function to calculate factorial of 1 to N
void factorial(ll p)
{
    fact[0] = 1;
 
    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
 
// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    ll ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}






/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/



lld facto[MAXN + 2];




void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;

    vector<lld> arr(n);
    map<lld, lld> cnt;
    forn(i, n) cin >> arr[i], cnt[arr[i]] += 1;

    sort(rall(arr));

    if (arr[0] == arr[1]) {
        cout << facto[n];
    } else if (arr[0] > arr[1] + 1) {
        cout << "0";
    } else {
        lld others = n - 1 - cnt[arr[1]];
        lld ans = facto[n];
        // _____error_____(others);
        forn(i, n) {
            if (others < i) break;
            ans -= (((Binomial(others, i, mod) * facto[n-1-i]) % mod * facto[i])) % mod;
            (ans += mod) %= mod;
        }
        cout << ans;
    }

    
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


    facto[0] = 1;
    forn1(i, MAXN) {
        (facto[i] = facto[i-1] * (i)) %= mod;
    }

    ll p = mod;
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);

    
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
