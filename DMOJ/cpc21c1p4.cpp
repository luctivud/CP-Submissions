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
        lld n, m; cin >> n >> m;
        vector<lld> adj[n+1];
        vector<lld> maxPossible(n+1, 0);
        vector<lld> indegree(n+1, 0ll);
        forn(i, m) {
            lld a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            indegree[b] += 1;
        }
        vector<bool> visited(n+1, false);
        forn1(i, n) {
            if (!visited[i] and indegree[i] == 0) {
                _____error_____(i);
                dfs(i, maxPossible, indegree, visited, adj);
            }
        }

        forn1(i, n) {
            if (!visited[i]) {
                dfs(i, maxPossible, indegree, visited, adj);
            }
        }
        _____error_____(visited);
        _____error_____(maxPossible);
        lld x = -1, y = -1;
        forn1(i, n) {
            if (i < maxPossible[i]) {
                if (i > x) {
                    x = i, y = maxPossible[i];
                } else if (i == x) {
                    y = maxPossible[i];
                }
            }
        }
        if (x == -1) {
            cout << x;
        } else {
            cout << x << " " << y;
        }
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    lld dfs(lld node, vector<lld> &maxPossible, vector<lld> &indegree, vector<bool> &visited, vector<lld> adj[]) {
        if (visited[node]) {
            return maxPossible[node] = max(maxPossible[node], node);
        }
        visited[node] = true;
        for (auto child : adj[node]) {
            maxPossible[node] = max({
                        child,
                        maxPossible[node], 
                        dfs(child, maxPossible, indegree, visited, adj)
                });
        }
        // _____error_____(node, maxPossible[node]);
        return maxPossible[node];
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

