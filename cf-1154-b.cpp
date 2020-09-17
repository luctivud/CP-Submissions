/*     <<<  J A I ~ S H R E E ~ R A M  >>>     */
// Title: cf-1154-b.cpp
// dated: 11-07-2020 12:40:40
// Creator & Template by : Udit Gupta @luctivud


// #include "bits/stdc++.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

const long long int MOD_JOHAN {1000000007};
const long long int MOD_LIGHT {998244353};
const long long int MAXN_EYEPATCH = 1e6 + 1LL;
const long long int MAXN_FULLMETAL = 501LL;

typedef long long int lld;
typedef vector<int> v_int;
typedef vector<lld> v_lld;
typedef pair<int, int> p_int;
typedef pair<lld, lld> p_lld;


#define                   GREED_FOR_SPEED   ios_base::sync_with_stdio(false); cin.tie(0)
#define             TESTCASES_ARE_THERE()   _scan(Test0xcs); TotalT35tC4ses = Test0xcs; while(Test0xcs--)
#define                  mems(A77AY,V4LU)   memset((A77AY), V4LU, sizeof((A77AY)))
#define   FORFWD(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = ST47T; IT7T < E9xD; IT7T += St3P)
#define   FORBWD(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = ST47T; IT7T > E9xD; IT7T -= St3P)
#define  FORANGE(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = ST47T;((St3P<0) ? IT7T>E9xD : IT7T<E9xD); IT7T += St3P)
#define                              endl   "\n"
#define            FOREACH(V3CT07_, IT7T)   for(auto IT7T = V3CT07_.begin(); IT7T != V3CT07_.end(); IT7T++)
#define                    INP4T(V3CT07_)   for(auto &V3CT07____IT7T : V3CT07_) _scan(V3CT07____IT7T)
#define                                PI   3.1415926535897932384626433832795
#define                              INFF   1000000000000000005LL;
#define                     ALL(V3CT07_t)   V3CT07_t.begin(), V3CT07_t.end()
#define             LEN(V3CT07_x, Typ30F)   (Typ30F) V3CT07_x.size()
#define                            un_map   unordered_map
#define                            un_set   unordered_set


template<typename T> void _scan(T &x) { 
    x = 0; bool neg = 0; 
    register T c = getchar();
    if (c == '-') neg = 1, c = getchar();
    while ((c < 48) || (c > 57)) c = getchar();
    for ( ; c < 48||c > 57 ; c = getchar());
    for ( ; c > 47 && c < 58; c = getchar() ) x= (x << 3) + ( x << 1 ) + ( c & 15 );
    if (neg) x *= -1;
}


void printYesNo(bool Expr, int YNType = 1, string FirstChoice = "Ud", string SecondChoice = "Ud") { 
    if (YNType == 1) puts(Expr ? "YES" : "NO");
    else if (YNType == 2) puts(Expr ? "Yes" : "No");
    else if (YNType == 3) puts(Expr ? "yes" : "no");
    else if (YNType == 4) cout << (Expr ? FirstChoice : SecondChoice);
}



void solveEach(lld TestCaseNumber = 1) {
    lld n; _scan(n);
    v_int arr(n); INP4T(arr);
    sort(ALL(arr));
    arr.resize(unique(ALL(arr))-arr.begin());
    lld sz = LEN(arr, lld);
    if (sz == 1) {
        cout << "0";
    } else if (sz == 2) {
        if ((arr[1] - arr[0])%2) {
            cout << arr[1] - arr[0];
        } else {
            cout << (arr[1] - arr[0]) / 2;
        }
    } else if (sz == 3) {
        if (arr[1] - arr[0] != arr[2] - arr[1]) {
            cout << "-1";
        } else {
            cout << arr[1] - arr[0];
        }
    } else {
        cout << "-1";
    }
    
    cout << "\n"; 
    return;
}


signed main() {

    // GREED_FOR_SPEED;

    lld Test0xcs = 0, TotalT35tC4ses = 1;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    // TESTCASES_ARE_THERE()
        solveEach(TotalT35tC4ses - Test0xcs);
    return 0;
}

/*
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
SOME PARTS OF THE CODE MAY HAVE BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)ch|=spacelo &=_up change case
*/