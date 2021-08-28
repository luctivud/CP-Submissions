/*          J  A  I   S  H  R  E  E   R  A  M          */



#include <bits/stdc++.h>
using namespace std;

#ifdef LUCTIVUD
#include <buggyBaby.hpp>
pretty:: PrettyPrinter NonIterable;
#define cerr cout
#else
#define _____error_____(...)
#endif

#pragma GCC optimize("O3,unroll-loops,trapv")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"






/*  Snips   */


typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second
#define sz 1001
#define int lld

/*  Utils   */


const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



signed pleaseAC(void) {

#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}


void IAmJustice(void) {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/IO/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/IO/Zoutput.txt", "w", stdout);
#endif

    return;
}




class Sparse {
public:
    vector < int > adj[sz]; // stores the tree
    vector < int > euler;    // tracks the eulerwalk
    vector < int > depthArr; // depth for each node corresponding
    // to eulerwalk

    int FAI[sz];     // stores first appearance index of every node
    int level[sz]; // stores depth for all nodes in the tree
    int ptr;         // pointer to euler walk
    int dp[sz][18]; // sparse table
    int logn[sz]; // stores log values
    int p2[20];  // stores power of 2

    void buildSparseTable(int n)
    {
        // initializing sparse table
        memset(dp, -1, sizeof(dp));

        // filling base case values
        for (int i = 1; i < n; i++)
            dp[i - 1][0] = (depthArr[i] > depthArr[i - 1]) ? i - 1 : i;

        // dp to fill sparse table
        for (int l = 1; l < 15; l++)
            for (int i = 0; i < n; i++)
                if (dp[i][l - 1] != -1 and dp[i + p2[l - 1]][l - 1] != -1)
                    dp[i][l] =
                        (depthArr[dp[i][l - 1]] > depthArr[dp[i + p2[l - 1]][l - 1]]) ?
                        dp[i + p2[l - 1]][l - 1] : dp[i][l - 1];
                else
                    break;
    }

    int query(int l, int r)
    {
        int d = r - l;
        int dx = logn[d];
        if (l == r) return l;
        if (depthArr[dp[l][dx]] > depthArr[dp[r - p2[dx]][dx]])
            return dp[r - p2[dx]][dx];
        else
            return dp[l][dx];
    }

    void preprocess()
    {
        // memorizing powers of 2
        p2[0] = 1;
        for (int i = 1; i < 18; i++)
            p2[i] = p2[i - 1] * 2;

        // memorizing all log(n) values
        int val = 1, ptr = 0;
        for (int i = 1; i < sz; i++)
        {
            logn[i] = ptr - 1;
            if (val == i)
            {
                val *= 2;
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
    void dfs(int cur, int prev, int dep)
    {
        // marking FAI for cur node
        if (FAI[cur] == -1)
            FAI[cur] = ptr;

        level[cur] = dep;

        // pushing root to euler walk
        euler.push_back(cur);

        // incrementing euler walk pointer
        ptr++;

        for (auto x : adj[cur])
        {
            if (x != prev)
            {
                dfs(x, cur, dep + 1);

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

    int LCA(int u, int v)
    {
        // trival case
        if (u == v)
            return u;

        if (FAI[u] > FAI[v])
            swap(u, v);

        // doing RMQ in the required range
        return euler[query(FAI[u], FAI[v])];
    }
};










/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    cout << "Case #" << _TestCase << ": ";

    Sparse sp;

    lld n; cin >> n;
    vector<lld> points(n + 1);
    forn1(i, n) {
        cin >> points[i];
    }


    vector<lld> adj[n + 1];

    forn(i, n - 1) {
        lld a, b; cin >> a >> b;
        sp.adj[a].push_back(b);
        sp.adj[b].push_back(a);
    }

    // _____error_____(n);
    // return;

    queue<array<lld, 3>> q;
    q.push({1, 0, points[1]});
    vector<lld> cumulative_points(n + 1, 0);

    // vector<lld> leaves;
    while (q.size()) {
        auto [u, v, w] = q.front();
        q.pop();
        cumulative_points[u] = w;
        // bool isLeaf = true;
        for (auto neigh : sp.adj[u]) {
            if (neigh != v) {
                // isLeaf = false;
                q.push({neigh, u, w + points[neigh]});
            }
        }
        // if (isLeaf and u != 1) {
        //     leaves.push_back(u);
        // }
    }
    lld ans = 0ll;

    sp.preprocess();

    // doing the Euler walk
    sp.ptr = 0;
    memset(sp.FAI, -1, sizeof(sp.FAI));
    sp.dfs(1, 0, 0);

    // creating depthArray corresponding to euler[]
    sp.makeArr();

    // building sparse table
    sp.buildSparseTable(sp.depthArr.size());

    // _____error_____(cumulative_points);
    // _____error_____(leaves);

    for (lld i = 1; i <= n; i++) {
        lld res = cumulative_points[i];
        ans = max(ans, res);
        for (lld j = i + 1; j <= n; j++) {
            lld lucaa = sp.LCA(i, j);
            if (lucaa != 1) continue;
            lld res2 = res - cumulative_points[lucaa] + cumulative_points[j];
            ans = max(ans, res2);
            // _____error_____(i, j, lucaa, res2);
        }
    }

    cout << ans;

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    IAmJustice();

    int _T0T4 = 1;
    cin >> _T0T4;

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }

    return pleaseAC();
}




/*  ~~
    .?.?.?.
*/

// sort(rall(leafSums));

// _____error_____(leafSums);

// lld ans = leafSums[0];
// if (leafSums.size() > 1) {
//     ans += (leafSums[1] - points[1]);
// }