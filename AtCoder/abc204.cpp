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






/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/


void solve(lld node, lld par, lld timmy, vector<array<lld, 3>> adj[], vector<lld> &ans) {
    // _____error_____(node, par, timmy);
    if (timmy > ans[node]) return;
    ans[node] = timmy;
    for (auto &[i, c, d] : adj[node]) {
        if (i != par) {
            lld timmy2 = max(timmy, (lld)sqrt(d));
            // _____error_____(timmy2);
            timmy2 += c + (d / (timmy2+1));
            // _____error_____(i, node, timmy2);
            solve(i, node, timmy2, adj, ans);
        }
    }
}

bool aura (array<lld, 3> &a, array<lld, 3> &b) {
    return a[1] + a[2] > b[1] + b[2];
};


void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, m; cin >> n >> m;

    vector<array<lld, 3>> adj[n+1];
    forn(i, m) {
        lld a, b, c, d; cin >> a >> b >> c >> d;
        adj[a].push_back({b, c, d});
        adj[b].push_back({a, c, d});
    }

    const lld inf = 1e15;
    
    priority_queue<array<lld, 3>, vector<array<lld, 3>>, decltype(aura)> pQue(aura);

    vector<lld> ans(n+1, inf);
    solve(1, 0, 0, adj, ans);
    // _____error_____(ans);

    // NonIterable.print(adj);

    if (ans[n] == inf) ans[n] = -1;
    cout << ans[n];
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
    // cin >> _T0T4; 

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
