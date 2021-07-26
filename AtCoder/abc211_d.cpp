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
#define int lld








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
        vector<lld> adj[n];
        forn(i, m) {
            lld a, b; cin >> a >> b;
            adj[--a].push_back(--b);
            adj[b].push_back(a);
        }
        cout << findShortestPaths(adj, 0, n);
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
    void BFS(vector<int> adj[], int src, int dist[], int paths[], int n) {
        bool visited[n];
        for (int i = 0; i < n; i++)
            visited[i] = false;
        dist[src] = 0;
        paths[src] = 1;

        queue <int> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto x : adj[curr]) {
                if (visited[x] == false) {
                    q.push(x);
                    visited[x] = true;
                }
                if (dist[x] > dist[curr] + 1) {
                    dist[x] = dist[curr] + 1;
                    paths[x] = paths[curr];
                }

                else if (dist[x] == dist[curr] + 1)
                    (paths[x] += paths[curr]) %= mod;
            }
        }
    }

    int findShortestPaths(vector<int> adj[], int s, int n) {
        int dist[n], paths[n];
        for (int i = 0; i < n; i++)
            dist[i] = INT_MAX;
        for (int i = 0; i < n; i++)
            paths[i] = 0;
        BFS(adj, s, dist, paths, n);
        return paths[n-1];
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

