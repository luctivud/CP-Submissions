
// Problem : E. Two Teams
// Contest : Codeforces - Codeforces Round #552 (Div. 3)
// URL : https://codeforces.com/contest/1154/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Creation Time : $%D%$/$%M%$/$%Y%$ @ $%h%$:$%m%$:$%s%$
// Author & Template by : Udit "$%U%$" Gupta
// https://www.linkedin.com/in/udit-gupta-1b7863135/

/*      ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     */




#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <sstream>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <time.h>
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;
typedef vector<int> v_int;
typedef vector<lld> v_lld;
typedef vector<llu> v_llu;
typedef pair<int, int> p_int;
typedef pair<lld, lld> p_lld;


#define   INDEPENDENT_CASES()  cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define         _INP14T(V3C0)  for(auto &V3C0_IT7 : (V3C0)) cin >> (V3C0_IT7)
#define     mems(A77AY, V4LU)  memset((A77AY), (V4LU), sizeof((A77AY)))
#define   CH3K(IT7, EN4, S7P)  (((S7P)<0) ? (IT7)>(EN4) : (IT7)<(EN4))
#define for4(IT7,ST4,EN4,S7P)  for(auto IT7=(ST4); CH3K(IT7,EN4,S7P); (IT7)+=(S7P))
#define    FORE4CH(IT7, V3C0)  for(auto IT7=(V3C0).begin(); IT7!=(V3C0).end(); IT7++)
#define    FORALL7(IT7, V3C0)  for (auto IT7 : (V3C0))
#define           ALL7L(V3C0)  (V3C0).begin(), (V3C0).end()
#define           RAL7L(V3C0)  (V3C0).rbegin(), (V3C0).rend()
#define                  endl  "\n"
#define                un_map  unordered_map
#define                un_set  unordered_set


// template<typename T> void _SC4N(T &x) { 
//     x = 0; bool neg = 0; 
//     register T c = getchar();
//     if (c == '-') neg = 1, c = getchar();
//     while ((c < 48) || (c > 57)) c = getchar();
//     for ( ; c < 48||c > 57 ; c = getchar());
//     for ( ; c > 47 && c < 58; c = getchar() ) x= (x << 3) + ( x << 1 ) + ( c & 15 );
//     if (neg) x *= -1;
// }


// _PRi14T(arr);
template<typename Typ30f1> 
void _PRi14T(vector <Typ30f1> arr,  bool newline = false, string sep = " ") {
    for (auto item: arr) cout << item << sep;
    if (newline) cout << "\n";
}


void printYesNo(bool Expr, int YNType = 1, string FirstChoice = "Ud", string SecondChoice = "Ud") { 
    if (YNType == 1) puts(Expr ? "YES" : "NO");
    else if (YNType == 2) puts(Expr ? "Yes" : "No");
    else if (YNType == 3) puts(Expr ? "yes" : "no");
    else if (YNType == 4) cout << (Expr ? FirstChoice : SecondChoice);
}



void solveEachTest(lld T35TC453N = 1) {
    auto S34t = chrono:: high_resolution_clock::now(); 
	
	lld n; cin >> n;
	lld k; cin >> k;
	
	v_lld arr(n+1); 
	vector <bool> visited(n+1, false);
	lld mex = n;
	vector<lld> pos(n+1);
	
	for4(i, 1, n+1, 1) {
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	
	v_int ans (n+1, 5);
	
	int turn = 0;
	
	while (mex > 0) {
		cout << mex << " " << turn << " ";
		lld thispos = pos[mex];
		// cout << thispos << "ok" << mex << "\n";
		visited[thispos] = true;
		ans[thispos] = turn;
		for4(j, 1, k+1, 1) {
			if (thispos+j > n or visited[thispos+j]) break;
			visited[thispos+j] = true; ans[thispos+j] = turn;
			// cout << thispos+j ;
		}
		for4(j, 1LL, k+1, 1LL) {
			if (thispos-j < 1 or visited[thispos-j]) break;
			visited[thispos-j] = true; ans[thispos-j] = turn;
		}
		while (visited[pos[mex]]) mex--;
		turn = (turn+1) % 2;
	}	
	
	for4(i, 1LL, n+1LL, 1LL) cout << ans[i]+1;
    

    cout << "\n"; 

    auto S34p = chrono::high_resolution_clock::now(); 
    auto D34n = chrono::duration_cast<chrono::microseconds>(S34p - S34t);
    // cout << "Time Elapsed: " << D34n.count() / (long double) 1e6 << " seconds" << endl; 
    return;
}


signed main() {

    // ios_base::sync_with_stdio(false); cin.tie(0);

    lld T3X0 = 0, T353 = 1;

    // INDEPENDENT_CASES()
        solveEachTest(T353 - T3X0);
    return 0;
}
