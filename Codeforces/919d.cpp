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
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        int n, m; cin >> n >> m;
        string s; cin >> s;
        s = '$' + s;
        vector<int> adj[n + 1];
        vector<int> indeg(n + 1, 0);
        forn(i, m) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            indeg[b] += 1;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        vector<vector<int>>dp(n + 1, vector<int> (26, 0));
        int ans = 0;
        int nodes = 0;
        while (!q.empty() and nodes <= n) {
            nodes += 1;
            int node = q.front();
            q.pop();
            dp[node][s[node] - 'a'] += 1;
            for (int i : adj[node]) {
                for (int j = 0; j < 26; j++) {
                    dp[i][j] = max(dp[i][j], dp[node][j]);
                }
                if (--indeg[i] == 0) {
                    q.push(i);
                }
            }
        }

        // NonIterable.print(dp);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                ans = max(ans , dp[i][j]);
            }
        }
        cout << (nodes == n ? ans : -1);
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
