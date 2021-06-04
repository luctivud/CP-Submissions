/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#pragma GCC optimize("-O2")


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







// find totient Value complexity O(sqrt(N))
int getPhiVal(int n0n) {
    int result = n0n;
    for (int i = 2; i * i <= n0n; i++) {
        if (n0n % i == 0) {
            while (n0n % i == 0)
                n0n /= i;
            result -= result / i;
        }
    }
    if (n0n > 1)
        result -= result / n0n;
    return result;
}

// vector<lld> phiVal;
// // precompute_phiVal complexity O(N.log(log(N)))
// void precompute_phiVal(lld n0n) {
//     phiVal.resize(n0n+1);
//     phiVal[0] = 0;
//     phiVal[1] = 1;
//     for (lld i = 2; i <= n0n; i++)
//         phiVal[i] = i;

//     for (lld i = 2; i <= n0n; i++) {
//         if (phiVal[i] == i) {
//             for (lld j = i; j <= n0n; j += i)
//                 phiVal[j] -= phiVal[j] / i;
//         }
//     }
// }

// // precompute_phiVal(n);




int isPrime(int n0n) {
    _____error_____(n0n);
    if (n0n < 2) return 0;
    int ind = 2;
    while (ind * ind <= n0n) {
        if (n0n % ind == 0) {
            return 0;
        }
        ind++;
    }
    return 1;
}






/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        int N, Q; cin >> N >> Q;
        vector<int> arr(N);
        for (int i =0; i< N; i++) {
            cin >> arr[i];
            arr[i] = getPhiVal(arr[i]);
            _____error_____(arr[i]);
            arr[i] = int(isPrime(arr[i]));
            if (i > 0) {
                arr[i] += arr[i-1];
            }
        }
        _____error_____(arr);
        for (int i = 0; i < Q; i++) {
            int l, r; cin >> l >> r;
            --l, --r;
            int ans = arr[r];
            if (l > 0) {
                ans -= arr[l-1];
            }
            cout << ans << "\n";
        }
    }

public:
    void ResetTestCase() {
        // cout << "\n";
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

