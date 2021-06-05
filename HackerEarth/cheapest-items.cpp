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


const lld maxn = 1001;
pair<lld, lld> arr[maxn];
lld n;
const lld inf = lld(1e15);

/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

lld solve(lld ind, lld val, vector<vector<lld>> &dp) {
    if (val >= n) return 0ll;
    if (ind == n) return inf;
    // lld res = 0ll;
    lld &res = dp[ind][val];
    if (res != -1) return res;
    return res = min(arr[ind].s2 + solve(ind+1, val+arr[ind].f1, dp), 
        solve(ind+1, val, dp));
}




void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    cin >> n;

    forn(i, n) {
        cin >> arr[i].f1 >> arr[i].s2;
        arr[i].f1++;
        // ans += arr[i].s2;
        // sz += arr[i].f1;
    }

    // sort(arr, arr+n, [](auto &a, auto &b) {
    //     return a.s2 - a.f1 > b.s2 - b.f1;
    // });
    vector<vector<lld>> dp(n, vector<lld>(n+1, -1));

    cout << solve(0, 0, dp);
    
    

    return;
}



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
