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
// #pragma GCC optimize "trapv"


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









/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e4) + 2;
    lld facto[maxN];
public:
    Solution() {
        factoCompute();
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld n, x, pos; cin >> n >> x >> pos;
        vector<lld> arr(n, 0);
        BinarySearchTech(arr, x, pos);
        arr[pos] = mod;
        // _____error_____(arr);
        lld zless = 0ll, zmore = 0ll;
        forn(i, n) {
            if (arr[i] == -1) {
                zless += 1;
            } else if (arr[i] == 1) {
                zmore += 1;
            }
        }
        lld nMore = n - x, nLess = x - 1;
        lld ans = 1ll;
        ans = (ans * ((choose(nMore, zmore) * facto[zmore]) % mod)) % mod;
        ans = (ans * ((choose(nLess, zless) * facto[zless]) % mod)) % mod;
        // ans = (ans * (choose(nMore, zmore) * 1ll) % mod) % mod;
        // ans = (ans * (choose(nLess, zless) * 1ll) % mod) % mod;
        ans = (ans * facto[n - zless - zmore - 1]) % mod;
        // _____error_____(nMore, zmore, nLess, zless);
        // _____error_____(n - zless - zmore - 1);
        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    void BinarySearchTech(vector<lld> &arr, lld x, lld posDesired) {
        lld l = 0ll, r = arr.size();
        while (l < r) {
            lld mid = (l + r) >> 1;
            if (mid <= posDesired) {
                arr[mid] = -1;
                l = mid + 1;
            } else {
                arr[mid] = 1;
                r = mid;
            }
            // _____error_____(mid, arr[mid]);
        }
        assert(l > 0 and l - 1 == posDesired);
    }


    lld EE(lld a, lld b, lld *x, lld *y) {
        if (a == 0) {
            *x = 0, *y = 1;
            return b;
        }
    
        lld x1, y1;
        lld gcd = EE(b % a, a, &x1, &y1);
    
        *x = y1 - (b / a) * x1;
        *y = x1;
    
        return gcd;
    }
    
    
    lld inverse(lld a, lld m) {
        lld x, y;
        EE(a, m, &x, &y);
        if (x < 0) x += m;
        return x;
    }
    
    lld choose(lld n, lld k) {
        lld i;
    
        lld num = 1;
    
        // for (i = 2; i <= k; i++) {
        //     den *= i;
        //     den %= mod;
        // }
    
        // for (i = n - k + 1; i <= n; i++) {
        //     num *= i;
        //     num %= mod;
        // }

        num = facto[n];
        lld den1 = facto[k], den2 = facto[n-k];
    
        i = num * inverse(den1, mod);
        i %= mod;
        i = i * inverse(den2, mod);
        return i % mod;
    }

    void factoCompute() {
        facto[0] = 1;
        forn1(i, maxN-1) {
            facto[i] = (facto[i-1] * i) % mod;
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

