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
const lld d3i[3] = {1, 1, 1};
const lld d3j[3] = {-1, 0, 1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/



lld n;
const lld MAXN = 33;
char matr[MAXN][MAXN];


bool isvalid(lld i, lld j) {
	return i >= 0 and i < n and j >=0 and j < n and matr[i][j] == '1';
}



void snakeIt(lld i, lld j, lld ok) {

	// _____error_____(i, j, ok);

	if (ok) {
		matr[i][j] = '$';
	}

	forn(xx, 3) {
		if (isvalid(i + d3i[xx], j + d3j[xx])) {
			snakeIt(i + d3i[xx], j + d3j[xx], 1);
			// _____error_____(i, j);
			break;
		}
	}
}


bool move(lld i, lld j, lld lives, lld direcn) {
	// if (matr[i][j] == '1') --lives;
	if (lives == 0) {
		return false;
	}

	if (i == 0 and j == 0) {
		return true;
	}

	if (matr[i][j] == '0') lives = 2;

	if (direcn == 1) {
		if (j-1 >= 0) {
			return move(i, j-1, lives-(matr[i][j-1] == '1'), 1);
		} else {
			return move(i-1, j, lives-(matr[i-1][j] == '1'), 0);
		}
	} else {
		if (j+1 < n) {
			return move(i, j+1, lives-(matr[i][j+1] == '1'), 0);
		} else {
			return move(i-1, j, lives-(matr[i-1][j] == '1'), 1);
		}
	}

}


void displayMatr() {
	forn(i, n) {
    	forn(j, n) {
    		cout <<  matr[i][j] << " ";
    	} cout << "\n";
    }
}


void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    cin >> n;
    forn(i, n) {
    	forn(j, n) {
    		cin >> matr[i][j];
    	}
    }

    forn(i, n) {
    	forn(j, n) {
    		if (matr[i][j] == '1') {
    			snakeIt(i, j, 0);
    		}
    	}
    }

    // displayMatr();

    bool ok = matr[n-1][0] != '1' and matr[0][0] != '1';
    ok &= move(n-1, 0, 2, 0);

    cout << ("No\0Yes" + 3*(ok));
    
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
