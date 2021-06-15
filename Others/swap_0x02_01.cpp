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
    
const int MAXAX = 1e5+2;
vector<int> indeg(MAXAX, 0), outdeg(MAXAX, 0);
int n;
list<int> *adj;
vector<pair<int, int>> bb;

void Euler(int u, bool visited[], int disc[], int low[], int parent[]) {
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;
        if (!visited[v]) {
            parent[v] = u;
            Euler(v, visited, disc, low, parent);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
            bb.push_back({u, v});
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}



void fillBridge() {
    bool *visited = new bool[n];
    int *disc = new int[n];
    int *low = new int[n];
    int *parent = new int[n];
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            Euler(i, visited, disc, low, parent);
        }
    }
}


void solveEachTest(int _TestCase) {
    cin >> n;
    adj = new list<int>[n];
    int m; cin >> m;

    forn(i, n) {
        // _____error_____(adj[i]);
    }

    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        indeg[b] += 1;
        outdeg[a] += 1;
    }

    fillBridge();

    _____error_____(bb);

    _____error_____(indeg);
    _____error_____(outdeg);

    for (auto[a, b] : bb) {
        indeg[b] -= 1;
        outdeg[a] -= 1;
    }
    _____error_____(indeg);
    _____error_____(outdeg);

    for (int i = 0; i < n; i++) {
        cout << ((indeg[i]+outdeg[i]) != 0) << " ";
    }
    return;
}



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


    MOD = mod = lld(1e9) + 7ll;
    int _T0T4 = 1;
    // cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n"; 
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
