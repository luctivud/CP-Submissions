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
lld MOD = 1000000007; //int(1e9) + 7;
lld &mod = MOD;





/* This part should be outside the main in global paradigm. */

const long long MAXN = (lld)(1e6) + 1ll; // MAXN Size

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
        lld l, r, s;
        cin >> l >> r >> s;
        vector<lld> arr(r-l+1, 0ll);
        forn(i, len(prime_numbers)) {
            if (prime_numbers[i] > r) break;
            lld nunu = prime_numbers[i];
            lld newL = ((l + nunu - 1) / nunu) * nunu;
            lld newR = (r / nunu) * nunu;
            // _____error_____(newL, newR, nunu);
            for (lld j = newL; j <= newR; j += nunu) {
                arr[j-l] += 1ll;
            }
        }

        // for (lld i = l; i <= r; i++) {
        //     lld lilB = i;
        //     while (lilB > 1ll) {
        //         lld ssp = smallest_prime_factor[lilB];
        //         while (lilB % ssp == 0) {
        //             lilB /= ssp;
        //         }
        //         arr[i-l]++;
        //     }
        // }

        _____error_____(arr);
        lld n = arr.size();
        vector<vector<lld>> dp(n+1, vector<lld>(s+1, 0ll));

        dp[0][0] = 1ll;
        forn1(i, n) {
            dp[i][0] = 1ll;
        }

        forn1(i, n) {
            forn(j, s+1) {
                dp[i][j] = dp[i-1][j];
                dp[i][j] %= mod;
                if (j >= arr[i-1]) {
                    dp[i][j] += dp[i-1][j-arr[i-1]];
                }
                dp[i][j] %= mod;
                // dp[i][j] = (dp[i-1][j] + (arr[i-1] <= j ? 0ll : dp[i-1][j-arr[i-1]])) % mod;
            }
        }
        NonIterable.print(dp);
        cout << dp[n][s] % mod;   
    }

public:
    void ResetTestCase() {
        cout << "\n";
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
    // cin >> _T0T4; 
    
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

