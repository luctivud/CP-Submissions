/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/


/* Points not to forget when this thing is left in peace for some days :

    1. The first optimal set of nodes to include is diameter.
    2. Run markNodeEmpty from the selected node till the parent which is already empty.
    3. To select a node use lifting, check with a brute force if this will work.
        Lets do binary search on depth with lifting.
        O 2.n(picking diameter) + (n.log(n).log(n))(choosing node) + O(n ~ log(n))(markNodeEmpty)

    4. Where to keep node in? pQue, set, or vector..? 
    5. Choose vector in brute force cuz depth will be changing in each pass. pop is O1.
        !important sort by increasing.
    6. Work around with pQue then, but I dont think it should work.
    7. If not lifting then, ??
    8. Check bf first, parent -> parent thing.

*/


#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIVU
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
    lld n, k; 
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        cin >> n >> k;
        if (k == 1) {
            cout << "1";
            return;
        }

        vector<lld> adj[n+1];
        forn(xx, n-1) {
            lld a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<lld> depth(n+1, 0), parent(n+1, 0);
        dfs(1, 0, adj, depth, parent);
        lld oneEnd = max_element(depth.begin()+1, depth.begin() + n+1) - depth.begin();
        dfs(oneEnd, 0, adj, depth, parent);
        _____error_____(oneEnd, depth);
        // lld otherEnd = max_element(depth.begin()+1, depth.begin() + n+1) - depth.begin();
        vector<lld> leaves;
        forn1(i, n) {
            if (len(adj[i]) == 1 and i != oneEnd) {
                leaves.push_back(i);
            }
        }

        function decrDepthFromMark = [&](lld &a, lld & b) {
            return depth[a] < depth[b];
        };

        lld ans = 1ll;

        while (k > 0 and len(leaves)) {
            sort(all(leaves), decrDepthFromMark);
            lld otherEnd = leaves.back();
            leaves.pop_back();
            k -= depth[otherEnd];
            ans++;
            _____error_____(otherEnd, depth[otherEnd]);
            // markChosen();
            markChosen(otherEnd, depth, parent);
            // recalcDepth();
            recalcDepth(leaves, depth, parent);
            _____error_____(depth);
        }

        _____error_____(k);

        cout << ans;
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    void dfs(lld node, lld par, vector<lld> adj[], vector<lld> &depth, vector<lld> &parent) {
        depth[node] = depth[par] + 1;
        parent[node] = par;
        for (auto i : adj[node]) {
            if (i != par) {
                dfs(i, node, adj, depth, parent);
            }
        }
    }

    void markChosen(lld node, vector<lld> &depth, vector<lld> &parent) {
        if (depth[node] == 0) {
            return;
        }
        depth[node] = 0;
        markChosen(parent[node], depth, parent);
    }

    void recalcDepth(vector<lld> &leaves, vector<lld> &depth, vector<lld> &parent) {
        for (auto leaf : leaves) {
            depth[leaf] = getVal(leaf, depth, parent);
        }
    }

    lld getVal(lld node, vector<lld> &depth, vector<lld> &parent) {
        if (depth[node] == 0) {
            return 0ll;
        }
        return depth[node] = getVal(parent[node], depth, parent) + 1;
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

