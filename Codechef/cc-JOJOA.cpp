

#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;



typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define         debspace(x)    cout << #x << " = "; println(x);
#define          debline(x)    cout << #x << " = "; print(x); cout << " ";
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


const lld d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const lld d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




const int MAX_CHARS = 256;

// Function to find smallest window containing
// all distinct characters
string findSubString(string str)
{
	int n = int(str.length());

	// Count all distinct characters.
	int dist_count = 0;
	bool visited[MAX_CHARS] = { false };
	for (int i = 0; i < n; i++) {
		if (visited[str[i]] == false) {
			visited[str[i]] = true;
			dist_count++;
		}
	}

	// Now follow the algorithm discussed in below
	// post. We basically maintain a window of characters
	// that contains all characters of given string.
	int start = 0, start_index = -1, min_len = INT_MAX;

	int count = 0;
	int curr_count[MAX_CHARS] = { 0 };
	for (int j = 0; j < n; j++) {
		// Count occurrence of characters of string
		curr_count[str[j]]++;

		// If any distinct character matched,
		// then increment count
		if (curr_count[str[j]] == 1)
			count++;

		// if all the characters are matched
		if (count == dist_count) {
			// Try to minimize the window i.e., check if
			// any character is occurring more no. of times
			// than its occurrence in pattern, if yes
			// then remove it from starting and also remove
			// the useless characters.
			while (curr_count[str[start]] > 1) {
				if (curr_count[str[start]] > 1)
					curr_count[str[start]]--;
				start++;
			}

			// Update window size
			int len_window = j - start + 1;
			if (min_len > len_window) {
				min_len = len_window;
				start_index = start;
			}
		}
	}

	// Return substring starting from start_index
	// and length min_len
	return str.substr(start_index, min_len);
}




void solveEachTest(lld _TestCase) {
	// cout << "Case#" << _TestCase << ": ";
	string s; cin >> s;
	string ans = (findSubString(s));

	for (auto i : ans) {
		print(i - 'a' + 1);
	}



	cout << "\n";
	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed;

	lld T3X0 = 0, T353 = 1;

	TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}