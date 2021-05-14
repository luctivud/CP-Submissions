// ************************.- J A I  S H R E E  R A M -.*************************


/* 
      ::: ---------- ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

          Author   :  Udit "luctivud" Gupta 

          linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
          github   :  https://github.com/luctivud

      :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ---------- :::
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


#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); huehue(_it, args); cout << "\n";}

void huehue(istream_iterator<string> it) {}
template<typename T, typename... Args>
void huehue(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ", ";
    huehue(++it, args...);
}

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;

lld TempVar;

const long double EPS = 1e-6;

/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/


const lld MAXN = lld(2e5) + 1;

vector<lld> depth(MAXN, 0);
vector<lld> adj[MAXN];
vector<set<lld>> reachable(MAXN);


auto cmp = [](auto &a, auto &b) {
	return depth[a.f1] <= depth[b.f1];
};

set<pair<lld, lld>, decltype(cmp)> leaves(cmp);



void add_undirected_edge(lld a, lld b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
	return;
}

set<lld> dfs(lld node = 1, lld par = 0) {
	depth[node] = depth[par] + 1;
	for (auto i : adj[node]) {
		if (i != par) {
			set<lld> res = dfs(i, node);
			for (auto ii : res) {
				reachable[node].insert(ii);
			}
		}
	}

	if (len(adj[node]) == 1 and node != 1) {
		// error(node, len(adj[node]));
		leaves.insert({node, node});
		reachable[node].insert(node);
		
	}
	return reachable[node];
}





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    
	lld n; cin >> n;

	// reset
	forn1(i, n) adj[i].clear(), depth[i] = 0, reachable[i].clear();
	leaves.clear();

	// add edge
	forn(i, n - 1) {
		lld a, b; cin >> a >> b;
		add_undirected_edge(a, b);
	}

	depth[0] = -1;
	dfs(1, 0);

	// // confirm depth
	// forn1(i, n) cout << depth[i] <<  " ";
	// cout << "\n";

	// // confirm reachable
	// forn1(i, n) {
	// 	cout << i << ": ";
	// 	for (auto j : reachable[i]) {
	// 		cout << j << " ";
	// 	}
	// 	cout << "\n";
	// }

	// confirm set 
	for (auto [a, b] :  leaves) {
		cout << a << " "  << b << "\n";
	}

	lld time = 0ll;
	while (++time <= n) {
		
	}




    // cout << "\n"; 
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


    lld _T0T4 = 1;
    cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
    }


    #ifdef LUCTIVUD
      // auto end_time = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double> diff = end_time - start_time;
      // cerr << "Finished in : " << diff.count() << "\n";
    #endif

    return 0; 
}

/*        0.2s   Ryoki Tenkai:  
                                  Jihei Endonka     */
