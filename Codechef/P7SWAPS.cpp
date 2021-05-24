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



/*          D S U         */

void makeSet(lld n, vector<lld> &parent, vector<lld> &rank) {
    iota(all(parent), 0ll);
}

lld find_repr(lld x, vector<lld> &parent, vector<lld> &rank) {
    if (x != parent[x])
        parent[x] = find_repr(parent[x], parent, rank);
    return parent[x];
}

void Union(lld x, lld y, vector<lld> &parent, vector<lld> &rank) {
    x = find_repr(x, parent, rank);
    y = find_repr(y, parent, rank);

    if (x == y) return;

    if (rank[x] < rank[y]) { 
        parent[x] = y; 
    } else if (rank[x] > rank[y]) { 
        parent[y] = x; 
    } else { 
        parent[y] = x; 
        rank[x] = rank[x] + 1; 
    } 
    return;
}



    // create parent and rank at the place.
    


void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    lld arr[n+1];
    forn1(i, n) {
    	cin >> arr[i];
    }

    lld brr[n+1];
    forn1(i, n) {
    	cin >> brr[i];
    }

    vector<lld> parent(n+1, 0);
    vector<lld> rank(n+1, 0);
    makeSet(n+1, parent, rank);

    map<lld, vector<lld>> cycleRepr;
    map<lld, lld> pos_of_num_in_cycle;

    vector<bool> visited(n+1, false);

    forn1(i, n) {
    	if (visited[i]) {
    		continue;
    	}
    	vector<lld> tempArr{i};
    	visited[i] = true;
    	pos_of_num_in_cycle[i] = 0;
    	lld pos = 0ll;
    	lld j = brr[i];
    	while (!visited[j]) {
    		visited[j] = true;
    		tempArr.push_back(j);
    		Union(i, j, parent, rank);
    		pos_of_num_in_cycle[j] = ++pos;
    		j = brr[j];
    	}
    	cycleRepr[find_repr(i, parent, rank)] = tempArr;
    }

    // _____error_____(cycleRepr);
    // _____error_____(pos_of_num_in_cycle);


    lld QueryCnt; cin >> QueryCnt;

    lld cntOfOp1 = 0ll;

    forn(qq, QueryCnt) {
    	lld Qtype; cin >> Qtype;
    	if (Qtype == 1) {
    		cntOfOp1 += 1ll;
    	} else if (Qtype == 2) {
    		lld l, r; cin >> l >> r;
    		lld reprL = find_repr(l, parent, rank), lenL = len(cycleRepr[reprL]),
    			reprR = find_repr(r, parent, rank), lenR = len(cycleRepr[reprR]);
    		lld posL = cycleRepr[reprL][(pos_of_num_in_cycle[l] - (cntOfOp1 % lenL) + lenL) % lenL], 
    			posR = cycleRepr[reprR][(pos_of_num_in_cycle[r] - (cntOfOp1 % lenR) + lenR) % lenR];
			swap(arr[posL], arr[posR]);
    	} else {
    		lld x; cin >> x;
    		lld reprX = find_repr(x, parent, rank), lenX = len(cycleRepr[reprX]);
    		lld posX = cycleRepr[reprX][(pos_of_num_in_cycle[x] - (cntOfOp1 % lenX) + lenX) % lenX];
    		cout << arr[posX] << "\n";
    	}
    }

    
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
    cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        // cout << "\n"; 
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
