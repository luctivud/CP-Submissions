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

#define  forn(I7, E4) for(lld I7=0; I7 < E4; (I7)+=1)
#define forn1(I7, E4) for(lld I7=1; I7 < E4+1; (I7)+=1)
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


class BinaryLift {
    int height;
    vector<vector<int>> table;

public:
    void initit(int n) {
        height = (int) ceil(log2(n));
        table.resize(n+1, vector<int> (height+1));
        forn(i, n+1) {
            forn(j, height+1) {
                table[i][j] = -1;
            }
        }
    }
public:
    void calculateSparse(int u, int v) {
        table[v][0] = u;
        for (int i = 1; i <= height; i++) {
            table[v][i] = table[table[v][i - 1]][i - 1];
            if (table[v][i] == -1)
                break;
        }
    }

public:
    int kthAncestor(int V, int k) {
        for (int i = 0; i <= height; i++) {
            if (k & (1ll << i)) {
                V = table[V][i];
                if (V == -1)
                    break;
            }
        }
        return V;
    }

};






/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        int n, k; cin >> n >> k;
        if (n >= 1000) {
            SolveEachTest_Good(n, k);
        } else {
            SolveEachTest_Brute(n, k);
        }

    }

    void SolveEachTest_Brute(int n, int k) {
        // cout << "Case #" << _TestCase << ":";
        // if (k == 1) {
        //     cout << "1";
        //     return;
        // }

        vector<int> adj[n+1];
        BinaryLift binod;
        binod.initit(n);
        forn(xx, n-1) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            // binod.calculateSparse(a, b);
        }

        vector<int> depth(n+1, 0), parent(n+1, 0);
        dfs(1, 0, adj, depth, parent, false, binod);
        int oneEnd = int(max_element(depth.begin()+1, depth.begin() + n+1) - depth.begin());
        dfs(oneEnd, 0, adj, depth, parent, true, binod);
        // _____error_____(oneEnd, depth);
        // int otherEnd = max_element(depth.begin()+1, depth.begin() + n+1) - depth.begin();
        set<int> leaves;
        for (int i = 1; i <= n; i++) {
            if (len(adj[i]) == 1 and i != oneEnd) {
                leaves.insert(i);
            }
        }

        // function decrDepthFromMark = [&](int &a, int & b) {
        //     return depth[a] < depth[b];
        // };

        int ans = 1ll;
        k -= 1;
        depth[oneEnd] = 0ll;

        while (k > 0 and len(leaves)) {
            // sort(all(leaves), decrDepthFromMark);
            set<int> leavesCopy = leaves;
            int otherEnd = *leaves.begin();
            // choose otherEnd by lifting + bs.
            int chosenDepth = 1ll;
            int lo = 0ll, hi = k;
            // bs;
            while (lo <= hi) {
                set<int> newLeaves;
                int mid = (lo + hi) >> 1;
                bool found = false;
                for (auto leaf : leaves) {
                    int kthBaap = binod.kthAncestor(leaf, mid);
                    // _____error_____(leaf, mid, kthBaap);
                    if (kthBaap == -1) continue;
                    // _____error_____(kthBaap, depth[kthBaap]);
                    if (depth[kthBaap] != 0) {
                        found = true;
                        otherEnd = leaf;
                        newLeaves.insert(leaf);
                    }
                }
                if (found) {
                    chosenDepth = mid + 1;
                    lo = mid + 1;
                    leaves = newLeaves;
                } else {
                    hi = mid - 1;
                }
            }
            // _____error_____("=>");
            // _____error_____(chosenDepth, otherEnd);
            
            k -= chosenDepth;
            // markChosen();
            markChosen(otherEnd, depth, parent);
            leaves = leavesCopy;
            leaves.erase(otherEnd);
            ans++;
        }

        // _____error_____(k);

        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    void dfs(int node, int par, vector<int> adj[], vector<int> &depth, vector<int> &parent, bool sparseBoy, BinaryLift &binod) {
        depth[node] = depth[par] + 1;
        parent[node] = par;
        for (auto i : adj[node]) {
            if (i != par) {
                if (sparseBoy) {
                    binod.calculateSparse(node, i);
                }
                dfs(i, node, adj, depth, parent, sparseBoy, binod);
            }
        }
    }

    void markChosen(int node, vector<int> &depth, vector<int> &parent) {
        if (depth[node] == 0) {
            return;
        }
        depth[node] = 0;
        markChosen(parent[node], depth, parent);
    }
    
    void recalcDepth(vector<int> &leaves, vector<int> &depth, vector<int> &parent) {
        for (auto leaf : leaves) {
            depth[leaf] = getVal(leaf, depth, parent);
        }
    }

    int getVal(int node, vector<int> &depth, vector<int> &parent) {
        if (depth[node] == 0) {
            return 0ll;
        }
        return depth[node] = getVal(parent[node], depth, parent) + 1;
    }

    void SolveEachTest_Good(int n, int k) {
        // cout << "Case #" << _TestCase << ":";
        if (k <= 1) {
            cout << k;
            return;
        }
        vector<int> adj[n+1];
        forn(xx, n-1) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> depth(n+1, 0);
        dfs1(1, 0, depth, adj);
        int oneEnd = int(max_element(depth.begin()+1, depth.begin() + n+1) - depth.begin());
        vector<pair<int, int>> leaves;
        leaves.push_back(dfs2(oneEnd, 0, adj, leaves));
        // _____error_____(leaves);
        // NonIterable.print(leaves);

        sort(all(leaves), compareBySecond);
        int ans = 1;
        for (int i = 0; i < len(leaves); i++) {
            if (k <= 0) break;
            k -= leaves[i].s2;
            ans++;
        }
        cout << ans;
    }


    void dfs1(int node, int par, vector<int>&depth, vector<int> adj[]) {
        depth[node] = depth[par] + 1;
        for (auto i : adj[node]) {
            if (i != par) {
                dfs1(i, node, depth, adj);
            }
        }
    }

    static bool compareBySecond(pair<int, int> &a, pair<int, int> &b) {
        return a.s2 > b.s2;
    }

    pair<int, int> dfs2(int node, int par, vector<int> adj[], vector<pair<int, int>> &leaves) {
        vector<pair<int, int>> res;
        // _____error_____(node, par);
        for (auto i : adj[node]) {
            if (i != par) {
                res.push_back(dfs2(i, node, adj, leaves));
            }
        }
        if (len(res) == 0) {
            return {node, 1};
        }
        sort(all(res), compareBySecond);
        for (int i = 1; i < len(res); ++i) {
            leaves.push_back(res[i]);
        }
        
        // _____error_____(node, res);
        return {res[0].f1, res[0].s2+1};
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
    cin >> _T0T4; 
    
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

