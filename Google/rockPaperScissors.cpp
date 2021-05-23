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
map<char, lld> indexOf {{'R', 0}, {'P', 1}, {'S', 2}};



char getChosen(long double probR, long double probP, long double probS) {
	long double maxProb = max({probR, probP, probS});
	lld maxCases = 0ll;
	set<char> se;
	if (abs(maxProb - probR) < EPS) {
		maxCases++;
	}
	if (abs(maxProb - probP) < EPS) {
		maxCases++;
	}
	if (abs(maxProb - probS) < EPS) {
		maxCases++;
	}

	if (maxCases == 1) {
		if (abs(maxProb - probR) < EPS) {
			se.insert('P');
		}
		if (abs(maxProb - probP) < EPS) {
			se.insert('S');
		}
		if (abs(maxProb - probS) < EPS) {
			se.insert('R');
		}
	} else if (maxCases == 2) {
		se.insert('R');
		se.insert('P');
		se.insert('S');
		if (abs(maxProb - probR) < EPS) {
			se.erase('R');
		}
		if (abs(maxProb - probP) < EPS) {
			se.erase('P');
		}
		if (abs(maxProb - probS) < EPS) {
			se.erase('S');
		}
	} else {
		se.insert('R');
		se.insert('P');
		se.insert('S');
	}

	lld zeta = rand() % len(se);

	auto it = se.begin();

	while (zeta --> 0) {
		it++;
	}

	// _____error_____(se);

	char chosenChar = *it;
	return chosenChar;
}




void solveEachTest(int _TestCase, lld exp) {
    cout << "Case #" << _TestCase << ": ";

    lld E, W; cin >> E >> W;

    // array<lld, 3> RPS{1, 0, 1};

    cout << "R";

    for (lld round = 2ll; round <= 57ll; round++) {
    	// long double probR = 0.0, probP = 0.0, probS = 0.0;
    	// if (round > 1) {
	    // 	probR = (long double)RPS[2] / (round - 1);
	    // 	probP = (long double)RPS[0] / (round - 1);
	    // 	probS = (long double)RPS[1] / (round - 1);
    	// }

    	// // _____error_____(probR, probP, probS);

    	// char chosenChar = getChosen(probP, probR, probS);



    	// cout << chosenChar;

    	// RPS[indexOf[chosenChar]] += 1;
    	cout << "S";
    }
    cout << "PPP";
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
    lld _T0T4 = 1, exp;
    cin >> _T0T4 >> exp; 

    srand(unsigned(time(NULL)));

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase, exp);
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
