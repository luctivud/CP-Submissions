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




/* This part should be outside the main in global paradigm. */

const long long MAXN = (lld)(1e5) + 1ll; // MAXN Size

vector<long long >isPrime(MAXN , true); // checkIfPrime
vector<long long >prime_numbers; // List of prime numbers
vector<long long >smallest_prime_factor(MAXN); // smallest_prime_factor of a number


void manipulated_seive() {
    isPrime[0] = isPrime[1] = false ;
    
    prime_numbers.push_back(2);
    smallest_prime_factor[2] = 2ll;

    for (long long int i=4; i < MAXN ; i+=2) {
        isPrime[i] = false;
        smallest_prime_factor[i] = 2ll;
    }

    for (long long int i = 3; i < MAXN ; i+=2) {
        if (isPrime[i]) {
            prime_numbers.push_back(i);
            smallest_prime_factor[i] = i;
        }

        for (long long int j = 0; j < (int)prime_numbers.size() && i * prime_numbers[j] < MAXN && prime_numbers[j] <= smallest_prime_factor[i]; j++) {
            isPrime[i * prime_numbers[j]] = false;
            smallest_prime_factor[i * prime_numbers[j]] = prime_numbers[j] ;
        }
    }
}


/* This should be called inside main. */
    










/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
public:
    Solution() {
        manipulated_seive();
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld n; cin >> n;
        string s; cin >> s;
        lld cnt1 = 0ll;
        forn(i, n) {
            cnt1 += s[i] == '1';
        }
        // vector<lld> cntF;
        // while (n > 1) {
        //     lld res = 0ll;
        //     lld ps = smallest_prime_factor[n];
        //     while (smallest_prime_factor[n] == ps) {
        //         n /= ps;
        //         res++;
        //     }
        //     cntF.push_back(res);
        // }

        vector<lld> factors;
        for (lld i = 1ll; (i * i) <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (n / i != i) {
                    factors.push_back(n / i);
                }
            }
        }
        sort(all(factors));
        _____error_____(factors);
        lld ans = n;
        for (lld fac: factors) { // 70
            vector<lld> cntChange(fac, 0ll);
            // n 1e5
            for (lld i = 0ll; i < fac; i++) { 
                for (lld j = i; j < n; j += fac) {
                    cntChange[i] += (s[j] != '1');
                }
                lld onesPresent = n / fac - cntChange[i];
                lld remainOne = cnt1 - onesPresent;
                _____error_____(onesPresent, remainOne);
                ans = min(ans, cntChange[i] + remainOne);

            }
            _____error_____(cntChange);
        }
        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
};



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
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

