//             Author: Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)                  //


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T> using FSET = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define             deb1(x)    cout << #x << "=" << (x) << "\n";
#define             deb2(x)    cout << #x << "=" << (x) << " ";



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}

void read() { return; }
void print() { return; }
void println() { return; }
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


const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool isvalid(lld i, lld n) {
	return i >= 0 and i < n;
}



lld solve(lld ind, lld currH, lld n, vector<lld> arr, vector<map<lld, lld>> &dp) {
	if (ind == n) return 0;
	// if (dp[ind][depInd] != -1) return dp[ind][depInd];

	// if (dp[ind] != -1) return dp[ind];
	if (dp[ind].find(currH) != dp[ind].end()) return dp[ind][currH];
	lld minH = INT_MIN;
	lld maxH = INT_MAX;
	if (isvalid(ind+1, n)) {
		maxH = arr[ind + 1]-1;
	}
	if (isvalid(ind-1, n)) {
		minH = currH + 1;
	}

	if (ind == 1) error(ind, currH);
	dp[ind][currH] = min({
		1+ solve(ind+1, minH, n, arr, dp), 
		1+ solve(ind+1, maxH, n, arr, dp), 
		((arr[ind] > currH) ? solve(ind+1, arr[ind], n, arr, dp) : INT_MAX)
	});

	return dp[ind][currH];
}



void solveEachTest(lld _TestCase = 1) {
    // cout << "Case#" << _TestCase << ": ";
    
	lld n; read(n);
	vector<lld> arr(n);
	read(arr);

	vector<map<lld, lld>> dp(n);
	// fill(all(dp[0]), 0);
	println(solve(0, -1, n, arr, dp));

    // cout << "\n"; 
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.precision(10);

    lld T3X0 = 0, T353 = 1;

    // TESTCASES() 
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought :  null  