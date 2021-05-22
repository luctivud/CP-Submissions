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

const lld d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const lld d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};


const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;

lld TempVar;

const long double EPS = 1e-6;

/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/






void solveEachTest(int _TestCase) {
	// cout << "Case #" << _TestCase << ": ";
	string s; cin >> s;
	lld n = len(s);
	set<pair<lld, lld>> captured_castle;

	map<lld, vector<lld>> pos_of_letters;

	lld mxCnt = 0;
	char mxCntLetter = 'a';
	forn(i, n) {
		pos_of_letters[s[i]].push_back(i);
		if (len(pos_of_letters[s[i]]) > mxCnt) {
			mxCnt = len(pos_of_letters[s[i]]);
			mxCntLetter = s[i];
		}
	}

	map<char, pair<lld, lld>> coordinate_of_letter;
	coordinate_of_letter[mxCntLetter] = {0, 0};
	captured_castle.insert({0, 0});

	// error(mxCntLetter);
	
	queue<pair<char, char>> tobe;
	for (auto i : pos_of_letters[mxCntLetter]) {
		if (i > 0 and coordinate_of_letter.find(s[i-1]) == coordinate_of_letter.end()) {
			tobe.push({s[i-1], mxCntLetter});	
		}
		if (i + 1 < n and coordinate_of_letter.find(s[i+1]) == coordinate_of_letter.end()) {
			tobe.push({s[i+1], mxCntLetter});	
		}
	}

	while (captured_castle.size() < pos_of_letters.size()) {
		auto [Letter, parentLetter] = tobe.front();
		tobe.pop();
		if (coordinate_of_letter.find(Letter) != coordinate_of_letter.end()) {
			continue;
		}
		queue<pair<lld, lld>> nextCastles;
		nextCastles.push(coordinate_of_letter[parentLetter]);
		while (captured_castle.find(nextCastles.front()) != captured_castle.end()) {
			auto [x, y] = nextCastles.front();
			nextCastles.pop();
			forn(o, 4) {
				nextCastles.push({x+d4i[o], y+d4j[o]});
			}
		}
		captured_castle.insert(nextCastles.front());
		coordinate_of_letter[Letter] = nextCastles.front();

		for (auto i : pos_of_letters[Letter]) {
			if (i > 0 and coordinate_of_letter.find(s[i-1]) == coordinate_of_letter.end()) {
				tobe.push({s[i-1], Letter});	
			}
			if (i + 1 < n and coordinate_of_letter.find(s[i+1]) == coordinate_of_letter.end()) {
				tobe.push({s[i+1], Letter});	
			}
		}
	}

	lld mxX = 105, mxY = 105;
	forn(i, 26) {
		if (coordinate_of_letter.find(char(i + 'a')) == coordinate_of_letter.end()) {
			coordinate_of_letter[char(i + 'a')] = {mxX++, mxY++};
		}
		auto [x, y] = coordinate_of_letter[char(i + 'a')];
		// cout << char(i + 'a') << " ";
		cout << x << " " << y << "\n";
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
	// cin >> _T0T4;

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
