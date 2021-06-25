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

const long long MAXN = (lld)(1e4) + 1ll; // MAXN Size

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
    static const int maxN = (lld)(31623) + 1ll;
public:
    Solution() {
        manipulated_seive();
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld n; cin >> n;
        vector<lld> arr(n);
        map<lld, lld> cnt;
        forn(i, n) {
            cin >> arr[i];
        }
        // cout << sqrt(1e9);
        // _____error_____(len(prime_numbers));
        vector<lld> brr(n, 1);
        for (auto num : prime_numbers) {
            if (num > maxN) {
                break;
            }
            forn(i, n) {
                if (arr[i] % num == 0) {
                    brr[i] *= num;
                    while (arr[i] % num == 0) {
                        arr[i] /= num;
                    }
                }
            }
        }

        forn(i, n) {
            if (arr[i] > 1) {
                cnt[arr[i]] += 1;
            }
        }

        forn(i, n) {
            for (lld j = 1; j * j <= brr[i]; j += 1) {
                if (brr[i] % j == 0) {
                    cnt[j] += 1;
                    if (brr[i] / j != j) {
                        cnt[brr[i]/j] += 1;
                    }
                }
                // if (j > 2) j++;
            }
        }
        _____error_____(arr);
        _____error_____(brr);
        _____error_____(cnt);

        lld mxNum = 0ll, mxNumCnt = 0ll;
        for (auto [ke, va] : cnt) {
            if (ke == 1) continue;
            if (va > mxNum) {
                mxNum = va;
                mxNumCnt = 1;
            } else if (va == mxNum) {
                mxNumCnt += 1;
            }
        }
        cout << mxNum << " " << mxNumCnt;
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

