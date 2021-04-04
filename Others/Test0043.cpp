#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;



// remove from here
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
#define           PLEASE_AC    return



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

// remove till here


lld ans = 0, n;
lld dp[n][n][n][];

lld solve(lld i, lld s1, lld s2, lld mx, lld sum, vector<lld> arr) {
	// println(i, s1, s2, mx, sum);
	if (i == n) {
		if (s1 + s2 < mx) {
			return 0;
		}
		return sum;
	}

	// if (dp[i] != -1) return dp[i];

	lld t1 = solve(i+1, s1, s2, mx, sum, arr, dp);
	if (arr[i] > mx) mx = arr[i];
	if (arr[i] < s1) {
		s2 = s1;
		s1 = arr[i];
	} else if (s1 == arr[i]) {
		s2 = s1;
	} else if (s2 > arr[i]) {
		s2 = arr[i];
	}
	lld t2 = solve(i+1, s1, s2, max(mx, arr[i]),sum+arr[i], arr, dp);
	return dp[i] = max(t1, t2);
}

signed main() {
	
	// Input - Output and optimization
	
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    cin >> n;
    vector<lld> arr(n,0);
    for (lld i=0; i<n; i++)	{
    	cin >> arr[i];
    }
    // vector<lld> dp(n, -1);

    lld dp[n][n][n][n];

    for (lld i = 0; i < n; i++) 
    	for (lld j = 0; j < n; j++)
    		for (lld k = 0; k < n; k++)
    			for (lld l = 0; l < n; l++)
    				dp[i][j][k][l] = -1;
   

    ans = solve(0, 99999, 99999, 0, 0, arr, dp);

    cout << ans << "\n";

    return 0;
}
