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

class Solution {
    static const int maxN = int(1e5) + 2;
    lld ans = 0ll;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld n; cin >> n;
        vector<lld> adj[n+1];
        forn(i, n-1) {
            lld tv; cin >> tv;
            adj[tv].push_back(i+2);
        }
        // NonIterable.print(adj);
        // forn1(i, n) {
        //     NonIterable.print(adj[i]);
        // }
        vector<lld> vals(n+1, 0);
        forn1(i, n) {
            cin >> vals[i];
        }
        // NonIterable.print(vals);
        // auto [ans, dispo] = dfs(1, 0, vals, adj);

        dfs(1, 0, 0);

        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    pair<lld, lld> dfs(lld node, lld res, lld leaf) {
        for (auto i : adj[node]) {

        }
    }

    pair<lld, lld> dfs(lld node, lld par, vector<lld> &vals, vector<lld> adj[]) {
        lld cnt = 0ll, disposable = 0ll;
        vector<lld> resArr;
        for (auto i : adj[node]) {
            if (i != par) {
                cnt += 1;
                auto [res, dispo] = dfs(i, node, vals, adj);
                resArr.push_back(res);
                disposable += dispo;
            }
        }
        // _____error_____(node, vals[node], cnt);
        _____error_____(node, resArr, vals[node], disposable);
        if (cnt == 0) {
            return {vals[node], 0};
        }

        // return (vals[node] + cnt - 1) / cnt;
        sort(all(resArr));
        lld mendes = min(vals[node], disposable);
        vals[node] -= mendes;
        disposable -= mendes;
        forn(i, cnt) {
            lld zeta = min(vals[node], resArr[cnt-1] - resArr[i]);
            resArr[i] += zeta;
            vals[node] -= zeta;
        }
        resArr[cnt-1] += (vals[node] + cnt-1) / cnt;
        sort(all(resArr));
        forn(i, cnt) {
            disposable += resArr[cnt-1] - resArr[i];
        }
        return {resArr[cnt-1], disposable};
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

// 5
// 1 1 2 2
// 18 2 5 3 19