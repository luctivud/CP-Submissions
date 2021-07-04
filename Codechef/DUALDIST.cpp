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
// #pragma GCC optimize "trapv"


/*:::::::::::::::::::SNIPS::::::::::::::::::::::::::::*/

typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0; I7 < E4; (I7)+=1)
#define forn1(I7, E4) for(lld I7=1; I7 < E4+1; (I7)+=1)
#define        len(v) ((lld)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


/*::::::::::::::::::/SNIPS::::::::::::::::::::::::::::*/
/*:::::::::::::::::::UTILS::::::::::::::::::::::::::::*/


const long double EPS = 1e-6;
lld MOD = lld(1e9) + 7;
lld &mod = MOD;
#define sz 1009




/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const lld maxN = lld(1e5) + 2;
public:
    Solution() {
    }
public:
    void SolveEachTest(lld _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        // memset(parent,-1,sizeof(parent));
        lld n, q; cin >> n >> q;
        // vector<lld> adj[n+1];
        // vector<lld> depth(n+1, 0);
        // vector<vector<lld>> parent(n+1, vector<lld>(level+1, -1));

        // _____error_____(n, q);

        forn(xx, n-1) {
            lld a, b; cin >> a >> b;
            // _____error_____(a, b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // dfs(1, 0);
        // precomputeSparseMatrix(n, parent);
        // precomputeSparseMatrix(n);

        // performing required precalculations
        preprocess();

        // doing the Euler walk
        ptr = 0;
        memset(FAI,-1,sizeof(FAI));
        dfs(1,0,0);

        // creating depthArray corresponding to euler[]
        makeArr();

        // building sparse table
        buildSparseTable((lld)depthArr.size());

        vector<vector<lld>> lca_of_ij(n+1, vector<lld> (n+1, 0));
        // _____error_____(depth);
        for (lld i = 1; i <= n; i++) {
            for (lld j = 1; j <= n; j++) {
                lca_of_ij[i][j] = LCA(i, j);
                assert(lca_of_ij[i][j] > 0);
                // cout << i << " " << j << " " << lca(i, j) << "\n";
                // lca(i, j);
            }
        }

        // NonIterable.print(lca_of_ij);



        forn(qq, q) {
            lld a, b; cin >> a >> b;
            lld ans = 0ll;
            for (lld i = 1; i <= n; i++) {
                lld laa, lbb;
                laa = depth[i] + depth[a] - 2* depth[lca_of_ij[i][a]];
                lbb = depth[i] + depth[b] - 2* depth[lca_of_ij[i][b]];
                ans += min(laa, lbb);
                // _____error_____(i, a, i, b);
                _____error_____(laa, lbb);
                // _____error_____(lca_of_ij[i][a], lca_of_ij[i][b]);
                // _____error_____(depth[lca_of_ij[i][a]], depth[lca_of_ij[i][b]]);
            }

            cout << ans << "\n";
        }

        forn1(i, n) {
            adj[i].clear();
        }
    }

public:
    void ResetTestCase() {
        // cout << "\n";
    }

    lld depth[sz];
    vector < lld > adj[sz]; // stores the tree
    vector < lld > euler;    // tracks the eulerwalk
    vector < lld > depthArr; // depth for each node corresponding
                            // to eulerwalk

    lld FAI[sz];     // stores first appearence index of every node
    lld level[sz]; // stores depth for all nodes in the tree
    lld ptr;         // pointer to euler walk
    lld dp[sz][18]; // sparse table
    lld logn[sz]; // stores log values
    lld p2[20];  // stores power of 2

    void buildSparseTable(lld n)
    {
        // initializing sparse table
        memset(dp,-1,sizeof(dp));

        // filling base case values
        for (lld i=1; i<n; i++)
            dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i;

        // dp to fill sparse table
        for (lld l=1; l<15; l++)
        for (lld i=0; i<n; i++)
            if (dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1)
            dp[i][l] =
                (depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])?
                dp[i+p2[l-1]][l-1] : dp[i][l-1];
            else
                break;
    }

    lld query(lld l,lld r)
    {
        lld d = r-l;
        lld dx = logn[d];
        if (l==r) return l;
        if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]])
            return dp[r-p2[dx]][dx];
        else
            return dp[l][dx];
    }

    void preprocess()
    {
        // memorizing powers of 2
        p2[0] = 1;
        for (lld i=1; i<18; i++)
            p2[i] = p2[i-1]*2;

        // memorizing all log(n) values
        lld val = 1;
        ptr=0;
        for (lld i=1; i<sz; i++)
        {
            logn[i] = ptr-1;
            if (val==i)
            {
                val*=2;
                logn[i] = ptr;
                ptr++;
            }
        }
    }

    /**
    * Euler Walk ( preorder traversal)
    * converting tree to linear depthArray
    * Time Complexity : O(n)
    * */
    void dfs(lld cur,lld prev,lld dep)
    {
        // marking FAI for cur node
        depth[cur] = depth[prev] + 1;
        if (FAI[cur]==-1)
            FAI[cur] = ptr;

        level[cur] = dep;

        // pushing root to euler walk
        euler.push_back(cur);

        // incrementing euler walk pointer
        ptr++;

        for (auto x:adj[cur])
        {
            if (x != prev)
            {
                dfs(x,cur,dep+1);

                // pushing cur again in backtrack
                // of euler walk
                euler.push_back(cur);

                // increment euler walk pointer
                ptr++;
            }
        }
    }

    // Create Level depthArray corresponding
    // to the Euler walk Array
    void makeArr()
    {
        for (auto x : euler)
            depthArr.push_back(level[x]);
    }

    lld LCA(lld u,lld v)
    {
        // trival case
        if (u==v)
        return u;

        if (FAI[u] > FAI[v])
        swap(u,v);

        // doing RMQ in the required range
        return euler[query(FAI[u], FAI[v])];
    }

    
};



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    lld _T0T4 = 1;
    cin >> _T0T4; 
    
    for (lld _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Solution Aurora;
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
