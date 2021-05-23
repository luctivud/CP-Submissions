//  J A I  S H R E E  R A M  //

#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
// #pragma GCC optimize ("Ofast")
// // #pragma GCC target ("fpmath=sse,sse2")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("-ffloat-store")


using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cout << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << H << ", "; dbg_out(T...);}
#define _____error_____(...) cout << #__VA_ARGS__ << " : ", dbg_out(__VA_ARGS__)

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/

// Table for storing 2^ith parent
int **table;
  
// To store the height of the tree
int height;
  
// initializing the table and
// the height of the tree
void initialize(int n)
{
    height = (int)ceil(log2(n));
    table = new int *[n + 1];
}
  
// Filling with -1 as initial
void preprocessing(int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        table[i] = new int[height + 1];
        memset(table[i], -1, sizeof table[i]);
    }
}
  
// Calculating sparse table[][] dynamically
void calculateSparse(int u, int v)
{
    // Using the recurrence relation to
    // calculate the values of table[][]
    table[v][0] = u;
    for (int i = 1; i <= height; i++)
    {
        table[v][i] = table[table[v][i - 1]][i - 1];
  
        // If we go out of bounds of the tree
        if (table[v][i] == -1)
            break;
    }
}
  
// Function to return the Kth ancestor of V
int kthancestor(int V, int k)
{
    // Doing bitwise operation to
    // check the set bit
    for (int i = 0; i <= height; i++)
    {
        if (k & (1 << i))
        {
            V = table[V][i];
            if (V == -1)
                break;
        }
    }
    return V;
}
  




void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    vector<lld> adj[n+1];
    initialize(n);
    for (lld i = 2; i <= n; i++) {
    	cin >> TempVar;
    	calculateSparse(i, TempVar);
    	adj[TempVar].push_back(i);
    }

    vector<lld> depth(n+1, 0);

    dfs(1);

    lld Q; cin >> Q;

    forn(qq, Q) {
    	lld node, dep; cin >> node >> dep;
    	if (depth[node] > dep) {
    		cout << "0\n";
    		continue;
    	} else {
    		
    	}
    }


    // forn1(i, n) {
    // 	_____error_____(adj[i]);
    // }




    
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    MOD = mod = lld(1e9) + 7ll;
    lld _T0T4 = 1;
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


/*  ~~
Author   :  Udit "luctivud" Gupta 
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
