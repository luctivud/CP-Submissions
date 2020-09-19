// ************************* J A I  S H R E E  R A M  *************************


/* 
  
      :: All is One ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

      Author: Udit "luctivud" Gupta 
      linkedin : (https://www.linkedin.com/in/udit-gupta-1b7863135/)

      My original ids go by the username @luctivud 
      However, if summoned, my alts can surround your surroundings in a flash.

      Do you know Hairu Ihei ? 

      :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: One is All ::


*/


#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
#pragma GCC optimize ("Ofast")
// #pragma GCC target ("fpmath=sse,sse2")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")


using namespace std;



typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define         debhairu(x)    cout << #x << " = "; println(x);
#define         debspace(x)    cout << #x << " = "; print(x); cout << " ";
#define                  f1    first
#define                  s2    second



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); huehue(_it, args); cout << "\n";}

void huehue(istream_iterator<string> it) {}
template<typename T, typename... Args>
void huehue(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << ", ";
  huehue(++it, args...);
}


template <class T> T inf() {
  return numeric_limits<T>::max();
}


void read() { return; }
void print() { return; }
void println() { cout << "\n"; return; }
template<class T> T read(T& x)   { cin >> x; return x; }
template<class T> void print(T a)   { cout << a; }
template<class T> void println(T a) { cout << a << "\n"; }

template<class T> void read(vector<T> &arr)   { EACH(i, arr) cin >> (i); }
template<class T> void print(vector<T> arr)   { EACH(i, arr) {cout << i << " ";} }
template<class T> void println(vector<T> arr) { EACH(i, arr) {cout << i << " ";} cout << "\n"; }

template<class T> void read(vector<vector<T>> &arr)   { EACH(i, arr) read(i); }
template<class T> void print(vector<vector<T>> arr)   { EACH(i, arr) println(i); }
template<class T> void println(vector<vector<T>> arr) { EACH(i, arr) println(i); }

template<typename T, typename... Args> void read(vector<T> &arr, Args &... args)   { read(arr); read(args...);}
template<typename T, typename... Args> void read(vector<vector<T>> &arr, Args &... args)   { read(arr); read(args...);}
template<typename T, typename... Args> void read(T &a, Args &... args) { cin >> (a); read(args...); }
template<typename T, typename... Args> void print(vector<T> &arr, Args &... args)   { print(arr); print(args...);}
template<typename T, typename... Args> void print(T a, Args... args) { cout << a << " "; print(args...); };
template<typename T, typename... Args> void println(vector<T> &arr, Args &... args)   { print(arr); println(args...);}
template<typename T, typename... Args> void println(T a, Args... args) { cout << a << " "; println(args...); };


const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

const auto start_time = std::chrono::high_resolution_clock::now();
signed luctivud() {

    #ifdef LUCTIVUD
      auto end_time = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> diff = end_time-start_time;
        cerr<<"Finished in : "<<diff.count() <<"\n";
    #endif

    return 0;
}


const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;


const long double EPS = 1e-6;

const lld INFll = inf<lld>();
const int INFi = inf<int>();


void add_undirected_edge(lld a, lld b, vector<lld> adj[]) {
  adj[a].pb(b);
  adj[b].pb(a);
  return;
}



/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/


const lld MAXN = (lld)(2e5) + 5ll;
const lld level = 18ll;
vector<lld> values(MAXN);



void dfs(lld cur, lld prev, vector<lld> &depth, vector<lld> adj[], vector<vector<lld>> &parent, vector<lld> &children, vector<lld> &oddSum, vector<lld> &evenSum) {
	depth[cur] = depth[prev] + 1;
	oddSum[cur] = oddSum[prev];
	evenSum[cur] = evenSum[prev];
	if (values[cur] & 1) {
		oddSum[cur] += values[cur];
	}
	if (!(values[cur] & 1)) {
		evenSum[cur] += values[cur];
	}
	parent[cur][0] = prev;
	children[cur] = 1;
	EACH(i, adj[cur]) {
		if (i != prev) {
			dfs(i, cur, depth, adj, parent, children, oddSum, evenSum);
			children[cur] += children[i];
		}
	}
}


void precomputeSparseMatrix(lld n, vector<vector<lld>> &parent) {
	for (lld i = 1; i < level; i++) {
		for (lld node = 1; node <= n; node++) {
			if (parent[node][i - 1] != -1)
				parent[node][i] = parent[parent[node][i - 1]][i - 1];
		}
	}
}


lld lca(lld u, lld v, vector<lld> &depth, vector<vector<lld>> &parent) {
	if (depth[v] < depth[u])
		swap(u, v);

	lld diff = depth[v] - depth[u];

	for (lld i = 0; i < level; i++)
		if ((diff >> i) & 1)
			v = parent[v][i];

	if (u == v)
		return u;

	for (lld i = level - 1; i >= 0; i--)
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}

	return parent[u][0];
}







void solveEachTest(lld _TestCase) {
    // cout << "Case#" << _TestCase << ": ";
    lld n; read(n);
    forn1(i, n) {
    	read(values[i]);
    }
	vector<lld> adj[n + 1];

	vector<lld> depth(n + 1, 0ll);
	vector<vector<lld>> parent(n + 1, vector<lld>(level, 0)) ;
	// int parent[MAXN][level] = {0};

	forn(i, n - 1) {
		lld a, b; read(a, b);
		adj[a].pb(b);
		adj[b].pb(a);
	}



	// UDdfs(1, -1, depth, adj);

	vector<lld> oddSum(n+1, 0ll);
	vector<lld> evenSum(n+1, 0ll);


	vector<lld> children(n+1, 0ll);
	dfs(1ll, 0ll, depth, adj, parent, children, oddSum, evenSum);
	// debspace(depth);

	precomputeSparseMatrix(n, parent);

	// println(values);

	forn1(i, n) {
		newoddSum[i] += depth[i] * oddSum[parent[i][0]];
		newevenSum[i] += depth[i] * evenSum[parent[i][0]];
	}
	println(oddSum);
	println(evenSum);

	println(evenSum[6] + oddSum[7]-2 * evenSum[2]);


    // cout << "\n"; 
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout<<fixed;

    lld T3X0 = 0, T353 = 1;

    TESTCASES() 
        solveEachTest(T353 - T3X0);
        
    return luctivud();
}

// Random Thought :  null  
/*
        My lungs will fill and then deflate.
*/
