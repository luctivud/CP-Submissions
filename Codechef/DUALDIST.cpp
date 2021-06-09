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

// #define int lld
const long double EPS = 1e-6;
lld MOD = int(1e9) + 7;
lld &mod = MOD;
const lld MAXN = 1e5+2;
#define sz 101
// vector<lld> adj[MAXN];




/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        int n, q;
        cin >> n >> q;
        forn(i, n-1) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            // _____error_____(a, b);
        }
        
        // performing required precalculations
        preprocess();
     
        // doing the Euler walk
        ptr = 0;
        memset(FAI,-1,sizeof(FAI));
        dfs(1,0,0);
     
        // creating depthArray corresponding to euler[]
        makeArr();
     
        // building sparse table
        buildSparseTable((int)depthArr.size());
        _____error_____(depthArr.size());



        forn(qq, q) {
            int a, b; cin >> a >> b;
            int res = 0ll;
            // _____error_____(a, b);
            int lucy = LCA(a, b);
            _____error_____(a, b, lucy);
            forn1(i, n) {
                int dista = 0ll, distb = 0ll;
                int lucya = LCA(i, a);
                int lucyb = LCA(i, b);
                dista = depthArr[i] + depthArr[a] - 2*depthArr[lucya];
                distb = depthArr[i] + depthArr[b] - 2*depthArr[lucyb];
                res += min(distb, dista);
                _____error_____(i, a, lucya);
                _____error_____(i, b, lucyb);
                _____error_____(depthArr[i], depthArr[a], depthArr[b]);
                _____error_____(dista, distb);
            }
            cout << res << "\n";
        }
    }

public:
    void ResetTestCase() {
        // cout << "\n";
        
    }

    
 
    vector < int > adj[sz];    // stores the tree
    vector < int > euler;      // tracks the eulerwalk
    vector < int > depthArr;   // depth for each node corresponding
                               // to eulerwalk
     
    int FAI[sz];     // stores first appearence index of every node
    int level[sz];   // stores depth for all nodes in the tree
    int ptr;         // pointer to euler walk
    int dp[sz][18];  // sparse table
    int logn[sz];    // stores log values
    int p2[20];      // stores power of 2
     
    void buildSparseTable(int n)
    {
        // initializing sparse table
        memset(dp,-1,sizeof(dp));
     
        // filling base case values
        for (int i=1; i<n; i++)
            dp[i-1][0] = (depthArr[i]>depthArr[i-1])?i-1:i;
     
        // dp to fill sparse table
        for (int l=1; l<15; l++)
          for (int i=0; i<n; i++)
            if (dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1)
              dp[i][l] =
                (depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])?
                 dp[i+p2[l-1]][l-1] : dp[i][l-1];
            else
                 break;
    }
     
    int query(int l,int r)
    {
        int d = r-l;
        int dx = logn[d];
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
        for (int i=1; i<18; i++)
            p2[i] = p2[i-1]*2;
     
        // memorizing all log(n) values
        int val = 1,ptr=0;
        for (int i=1; i<sz; i++)
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
    void dfs(int cur,int prev,int dep)
    {
        // marking FAI for cur node
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
     
    int LCA(int u,int v)
    {
        // trival case
        if (u==v)
           return u;
     
        if (FAI[u] > FAI[v])
           swap(u,v);
     
        // doing RMQ in the required range
        return euler[query(FAI[u], FAI[v])];
    }
     
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
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


    int _T0T4 = 1;
    cin >> _T0T4; 
    
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Solution Aurora;
        Aurora.SolveEachTest(_TestCase);
        // Aurora.ResetTestCase();
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

