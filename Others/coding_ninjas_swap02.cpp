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

lld MOD = int(1e9) + 7;
lld &mod = MOD;






/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/
const long double EPS = 1e-6;

if (a < b) // iski jagah
if (abs(a-b) < EPS) // ye use kro



void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    int n, k; cin >> n >> k;
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<long long, int>> dp(n);
    long long currVal = 0ll;
    int currSize = 0;
    for (int i = 0; i < n; i++) {
        if (((long double)currVal / currSize) <= ((long double)(currVal + arr[i]) / (currSize + 1))) {
            currVal += arr[i];
            ++currSize;
        } else {
            currVal = arr[i];
            currSize = 1;
        }
        dp[i] = {currVal, currSize};
    }

    // NonIterable.print(dp);

    long double ans = 0.0;
    currVal = 0;
    for (int i = 0; i < k; i++) {
        currVal += arr[i];
    }

    ans = (long double)currVal / k;
    long double currAns = ans;

    for (int i = k; i < n; i++) {
        currAns += (long double)(arr[i] - arr[i-k]) / k;
        ans = max(ans, currAns);
        ans = max(ans, currAns + ((long double)dp[i-k].first / dp[i-k].second));
    }

    cout << currAns;
    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    MOD = mod = lld(1e9) + 7ll;
    int _T0T4 = 1;
    cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
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


/*:::::::::::::::::::::/INVOC:::::::::::::::::::::::::*/
/*  ~~
Author   :  Udit "luctivud" Gupta 
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
