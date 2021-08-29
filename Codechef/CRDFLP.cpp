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
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif

    return;
}














/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;

    vector<lld> arr(n), brr(n);

    forn(i, n) {
        cin >> arr[i];
    }

    forn(i, n) {
        cin >> brr[i];
    }


    lld allset = (1ll << 32) - 1;
    lld myVal = allset;

    forn(i, n) {
        myVal &= (arr[i] | brr[i]);
    }

    vector<set<lld>> remainingChoices(n);
    forn(i, n) {
        remainingChoices[i].insert(0ll);
        remainingChoices[i].insert(1ll);
    }


    for (lld i = 31; i >= 0; i--) {
        if ((myVal >> i) & 1) {
            forn(j, n) {
                if (remainingChoices[j].find(0) != remainingChoices[j].end() and ((arr[j] >> i) & 1) == 0) {
                    remainingChoices[j].erase(0);
                }
                if (remainingChoices[j].find(1) != remainingChoices[j].end() and ((brr[j] >> i) & 1) == 0) {
                    remainingChoices[j].erase(1);
                }
            }
            myVal = allset;
            forn(j, n) {
                lld riza = 0ll;
                for (auto el : remainingChoices[j]) {
                    if (el == 0) {
                        riza |= arr[j];
                    } else {
                        riza |= brr[j];
                    }
                }
                myVal &= riza;
            }
        }
    }


    // NonIterable.print(remainingChoices);


    lld maxPossible = allset, minFlips = 0ll;
    forn(i, n) {
        if (remainingChoices[i].size() == 2) {
            maxPossible &= arr[i];
        } else {
            if (*remainingChoices[i].begin() == 0) {
                maxPossible &= arr[i];
            } else {
                minFlips += 1;
                maxPossible &= brr[i];
            }
        }
    }

    
    cout << maxPossible <<  " " << minFlips;

    // vector<vector<lld>> dp(n+1, vector<lld> (2, allset));

    // forn(i, n) {
    //     dp[i+1][0] = max(arr[i] & dp[i][0], arr[i] & dp[i][1]);
    //     dp[i+1][1] = max(brr[i] & dp[i][0], brr[i] & dp[i][1]);
    // }

    // NonIterable.print(dp);
    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

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
    .?.?.?.
*/
