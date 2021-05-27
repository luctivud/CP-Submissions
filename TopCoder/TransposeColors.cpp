
#include <bits/stdc++.h>
using namespace std;


typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(int I7=0; I7 < E4; (I7)+=1)
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


class TransposeColors {
    public:
    vector <int> move(int n) {
    	vector<int> ans;
    	if (n == 1) {
    		return ans;
    	}
    	map<int, set<int>> pos;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			if (i != j) {
    				pos[i].insert((int)j);
    			}
    		}
    	}

    	pos[n-1].erase(0);

		// _____error_____(pos);

    	int currX = 0, currY = 0;
    	for (int xx = 0; xx < (n*n)-n-1; xx++) {
    		currX = currY;
    		currY = *pos[currX].begin();
    		ans.push_back(currX * n + currY);
    		pos[currX].erase(pos[currX].begin());
    		// _____error_____(currX, currY, currX * n + currY);
    		// _____error_____(pos);
    	}

    	if (n != 1) {
    		ans.push_back(n * (n-1));
    		ans.push_back(n * n);
    	}
    	return ans;

    }
};




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




signed main() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      // freopen("/home/luctivud/CPPractice/Zinp.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zinput.txt", "w", stdout);
    #endif

    TransposeColors obj;
    vector<int> ans = obj.move(42);
    // cout << ans;

    for (auto i : ans) {
    	cout << i << " ";
    }
    


  return 0;
}
