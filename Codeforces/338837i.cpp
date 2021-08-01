/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIVUD
#include <buggyBaby.hpp>
pretty:: PrettyPrinter NonIterable;
#define cerr cout
#else
#define _____error_____(...)
#endif
#pragma GCC optimize "trapv"


/*:::::::::::::::::::SNIPS::::::::::::::::::::::::::::*/

typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


/*::::::::::::::::::/SNIPS::::::::::::::::::::::::::::*/
/*:::::::::::::::::::UTILS::::::::::::::::::::::::::::*/


const long double EPS = 1e-6;
lld MOD = int(1e9) + 7;
lld &mod = MOD;






#define ll long long
const int N = 1'00'001;



/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
    const lld inf = 1e18;
public:
    Solution() {
        ll p = 1000000007;
        InverseofNumber(p);
        InverseofFactorial(p);
        factorial(p);
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ": ";
        vector<lld> cntLetter(26, 0ll);
        string s; cin >> s;
        lld n = s.size();
        forn(i, n) {
            cntLetter[s[i] - 'a'] += 1;
        }
        lld ans = 1ll, res = fact[n];
        forn(i, 26) {
            (res *= factorialNumInverse[cntLetter[i]]) %= mod;
        }
        _____error_____(res);
        forn(i, n) {
            forn(j, 26) {
                if (s[i] - 'a' == j) {
                    break;
                }

                if (cntLetter[j] <= 0) continue;
                (res *= fact[cntLetter[j]]) %= mod;
                (res *= factorialNumInverse[n]) %= mod;
                cntLetter[j] -= 1;
                (res *= fact[n - 1]) %= mod;
                (res *= factorialNumInverse[cntLetter[j]]) %= mod;

                // lld res = fact[(n-i-1)];
                // forn(k, 26) {
                //     (res *= factorialNumInverse[cntLetter[k]]) %= mod;
                // }
                (res *= factorialNumInverse[cntLetter[j]]) %= mod;
                (res *= fact[n]) %= mod;
                (ans += res) %= mod;
                cntLetter[j] += 1;
                (res *= factorialNumInverse[n - 1]) %= mod;
                (res *= fact[cntLetter[j]]) %= mod;
            }

        }

        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

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
};



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif


    int _T0T4 = 1;
    cin >> _T0T4;

    Solution Aurora;
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Aurora.SolveEachTest(_TestCase);
        Aurora.ResetTestCase();
    }


#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}

/*:::::::::::::::::::::/INVOC:::::::::::::::::::::::::*/
/*  ~~
Author   :  Udit "luctivud" Gupta
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/

