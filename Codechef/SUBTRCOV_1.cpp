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



const lld maxN = lld(1e5) + 2;
lld n, k; 
vector<lld> adj[maxN];
vector<lld> depth(maxN, 0ll);


void dfs(lld node, lld par) {
    depth[node] = depth[par] + 1;
    for (auto i : adj[node]) {
        if (i != par) {
            dfs(i, node);
        }
    }
}

bool markVisited(lld node, lld par, lld otherEnd) {
    if (node == otherEnd) {
        depth[node] = 0;
        k -= 1;
        return true;
    }

    bool seen = false;
    for (auto i : adj[node]) {
        if (i == par) continue;
        seen |= markVisited(i, node, otherEnd);
    }
    if (seen) {
        k -= 1;
        depth[node] = 0;
    }
    // depth[node] = depth[par] + 1;
    return seen;
}


void markAftermath(lld node, lld par) {
    if (depth[node] != 0) {
        depth[node] = depth[par] + 1;
    }
    for (auto i : adj[node]) {
        if (i != par) {
            markAftermath(i, node);
        }
    }
}


class LCA {
    vector<lld> height, euler, first, segtree;
    vector<bool> visited;
public:
    LCA(lld root = 0) {        
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(root);
        lld m = len(euler);
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(lld node, lld h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = len(euler);
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(lld node, lld b, lld e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            lld mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            lld l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    lld query(lld node, lld b, lld e, lld L, lld R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        lld mid = (b + e) >> 1;

        lld left = query(node << 1, b, mid, L, R);
        lld right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }
public:
    lld lca(lld u, lld v) {
        lld left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};




/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
public:
    Solution() {
        depth[0] = -1;
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        cin >> n >> k;

        if (k == 1) {
            cout << "1";
            return;
        }
        reset();

        forn(xx, n-1) {
            lld a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // _____error_____(n, k);

        dfs(1, 0);
        lld oneEnd = max_element(depth.begin()+1, depth.begin() + n+1) - depth.begin();
        dfs(oneEnd, 0);
        lld otherEnd = max_element(depth.begin()+1, depth.begin() + n+1) - depth.begin();
        // _____error_____(depth);
        // markVisited(oneEnd, 0, otherEnd);
        // markAftermath(1, 0);
        // _____error_____(oneEnd, otherEnd);
        // _____error_____(depth);
        k -= depth[otherEnd] + 1;

        priority_queue<lld> pQue;
        lld ans = 2;
        // _____error_____(k);
        LCA LLL(1);
        forn1(i, n) {
            if (len(adj[i]) == 1 and i != oneEnd and i != otherEnd) {
                // leaves.push_back(i);
                _____error_____(i, otherEnd, LLL.lca(i, otherEnd));
                pQue.push(depth[i] - depth[LLL.lca(i, otherEnd)]);
            }
        }

        while (k > 0) {
            lld tp = pQue.top();
            pQue.pop();
            k -= tp;
            ans++;
        }

        _____error_____(k);
        cout << ans;

    }

public:
    void ResetTestCase() {
        cout << "\n";
    }

    void reset() {
        forn1(i, n) {
            adj[i].clear();
            depth[i] = 0;
        }
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

// 1
// 7 7
// 1 2 
// 2 3
// 3 5
// 3 6
// 2 4
// 4 7
