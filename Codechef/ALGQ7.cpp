/*------------------------- ---------------------------         
		--- --- --- ---   JAI SHREE RAM   --- --- --- ---          
--------------------------- ---------------------------*/
#ifdef LUCTIVUD
//#undef LUCTIVUD
#endif

#ifdef ONLINE_JUDGE
		#pragma GCC optimize("O3,unroll-loops")
		#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#endif

#ifdef LUCTIVUD
		// #pragma GCC optimize("O3,unroll-loops,trapv")
		// #pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
		// #pragma GCC optimize "trapv"
		#include "mydebug.h"
		pprint:: PrettyPrinter ppo;
		#define cerr cout
#else
		#include <bits/stdc++.h>
		using namespace std;
		#define debugluc(...)
#endif


//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T> using PBSET = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*  
		.insert(el) - set hai!
		.find_by_order(3) - returns an iterator to the k-th largest element (counting from zero)
		.order_of_key(6) - the number of items in a set that are strictly smaller than our item
*/

using lld       = long long;
using llu       = unsigned long long;
using ldo       = long double;

using vlld      = vector<lld>;
using plld      = pair<lld, lld>;
using vvlld     = vector<vlld>;
using vplld     = vector<plld>;


#define forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4)   for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define EACH(I7, AR7)   for(auto &I7 : AR7)
#define len(AR7)        ((lld)((AR7).size()))
#define all(AR7)        (AR7).begin(), (AR7).end()
#define rall(AR7)       (AR7).rbegin(), (AR7).rend()
#define f1              first
#define s2              second
#define pb              push_back


constexpr lld MOD = int(1e9) + 7;
//const lld &mod = MOD; //uhh, mod CAPITALISM

constexpr ldo EPS = 1e-6;
constexpr lld INF = 2e18;


const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


struct custom_hash {
		static uint64_t splitmix64(uint64_t x) {
				// http://xorshift.di.unimi.it/splitmix64.c
				x += 0x9e3779b97f4a7c15;
				x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
				x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
				return x ^ (x >> 31);
		}

		size_t operator()(uint64_t x) const {
				static const uint64_t FIXED_RANDOM = 
						chrono::steady_clock::now().time_since_epoch().count();
				return splitmix64(x + FIXED_RANDOM);
		}
};


void Read() { return; }
void Print() { return; }
void Println() { cout << "\n"; return; }
template<class T> T Read(T& x)   { cin >> x; return x; }
template<class T> void Print(T a)   { cout << a; }
template<class T> void Println(T a) { cout << a << "\n"; }
template<class T> void Read(vector<T> &arr)   { EACH(i, arr) cin >> (i); }
template<class T> void Print(vector<T> arr)   { EACH(i, arr) {cout << i << " ";} }
template<class T> void Println(vector<T> arr) { EACH(i, arr) {cout << i << " ";} cout << "\n"; }
template<class T> void Read(vector<vector<T>> &arr)   { EACH(i, arr) Read(i); }
template<class T> void Print(vector<vector<T>> arr)   { EACH(i, arr) Println(i); }
template<class T> void Println(vector<vector<T>> arr) { EACH(i, arr) Println(i); }
template<typename T, typename... Args> void Read(vector<T> &arr, Args &... args)   { Read(arr); Read(args...);}
template<typename T, typename... Args> void Read(vector<vector<T>> &arr, Args &... args)   { Read(arr); Read(args...);}
template<typename T, typename... Args> void Read(T &a, Args &... args) { cin >> (a); Read(args...); }
template<typename T, typename... Args> void Print(vector<T> &arr, Args &... args)   { Print(arr); Print(args...);}
template<typename T, typename... Args> void Print(T a, Args... args) { cout << a << " "; Print(args...); };
template<typename T, typename... Args> void Println(vector<T> &arr, Args &... args)   { Print(arr); Println(args...);}
template<typename T, typename... Args> void Println(T a, Args... args) { cout << a << " "; Println(args...); };

inline void add_undirected_edge(lld a, lld b, vector<lld> adj[]) {
		adj[a].push_back(b);
		adj[b].push_back(a);
		return;
}

inline bool isValidDimension(lld i, lld n) {
		return (i >= 0) and (i < n);
}

namespace modop {
		lld madd(lld a, lld b) {
				return (a + b) % MOD;
		}
		lld msub(lld a, lld b) {
				return (((a - b) % MOD) + MOD) % MOD;
		}
		lld mmul(lld a, lld b) {
				return ((a % MOD) * (b % MOD)) % MOD;
		}
		lld mpow(lld base, lld exp) {
				lld res = 1;
				while (exp) {
						if (exp % 2 == 1) {
								res = (res * base) % MOD;
						}
						exp >>= 1;
						base = (base * base) % MOD;
				}
				return res;
		}
		lld minv(lld base) {
				return mpow(base, MOD - 2);
		}
		lld mdiv(lld a, lld b) {
				return mmul(a, minv(b));
		}
}









/*:::::::::::::::::::::: ::::: :::::::::::::::::::::::::*/
/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/
/*:::::::::::::::::::::: ::::: :::::::::::::::::::::::::*/




void solveEachTest(int _TestCase) {

		// cout << "Case #" << _TestCase << ": ";
		string s; cin >> s;
		string t = "easy";
		vlld cnt(26, 0);
		EACH(i, s) cnt[i-'a'] += 1;
		EACH(i, t) cnt[i-'a'] -= 1;
		forn(i, 26) if (cnt[i] < 0) {Print("NO"); return;}
		Print("YES");
		return;
}


#ifdef LUCTIVUD
		const static auto start_time = std::chrono::high_resolution_clock::now();
#endif

inline void doPreWork() {

		cin.tie(0)->sync_with_stdio(0);
		cout.precision(10); cout << fixed;

		#ifdef LUCTIVUD
				freopen("/Users/luctivud/CPPrc/Zinput.txt", "r", stdin);
				freopen("/Users/luctivud/CPPrc/Zoutput.txt", "w", stdout);
		#endif
}


inline void doWork() {

		int __NTestCases = 1;
		cin >> __NTestCases; 
		
		for (int _TestCase = 1; _TestCase <= __NTestCases; _TestCase++) {
				solveEachTest(_TestCase);
				cout << "\n";
		}
}


inline void doPostWork() {

		#ifdef LUCTIVUD
				auto end_time = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> diff = end_time - start_time;
				cerr << "\n\nTime Taken : " << diff.count() << "\n" 
				<< "SHIT = " << /*DON'T WARN ME, DUH*/EPS + (INF - MOD) << "\n";
		#endif  
}



signed main() {

		doPreWork();
		doWork();
		doPostWork();

		return 0; 
}




/*  
		177 N3V4R F0RG3T U301
		??? 2023..............................???
		??? poem...... rain/pain/vain/gain ...???
		??? author.... luctivud ..............???
		??? RE................................~lx
*/
