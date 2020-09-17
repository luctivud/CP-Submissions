/*     <<<  J A I ~ S H R E E ~ R A M  >>>     */

// Title: cf-1372-b.cpp
// dated: 11-07-2020 20:49:32
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
typedef unsigned long long int llu;
typedef vector<int> v_int;
typedef vector<lld> v_lld;
typedef pair<int, int> p_int;
typedef pair<lld, lld> p_lld;


#define                   GREED_FOR_SPEED   ios_base::sync_with_stdio(false); cin.tie(0)
#define             TESTCASES_ARE_THERE()   _SC4N(Test0xcs); TotalT35tC4ses = Test0xcs; while(Test0xcs--)
#define                  mems(A77AY,V4LU)   memset((A77AY), V4LU, sizeof((A77AY)))
#define   FOR4WD(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = ST47T; IT7T < E9xD; IT7T += St3P)
#define   FOR8WD(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = ST47T; IT7T > E9xD; IT7T -= St3P)
#define  FOR4NGE(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = ST47T;((St3P<0) ? IT7T>E9xD : IT7T<E9xD); IT7T += St3P)
#define                              endl   "\n"
#define            FORE4CH(V3CT07_, IT7T)   for(auto IT7T = V3CT07_.begin(); IT7T != V3CT07_.end(); IT7T++)
#define                    INP4T(V3CT07_)   for(auto &V3CT07____IT7T : V3CT07_) _SC4N(V3CT07____IT7T)
#define                                PI   3.1415926535897932384626433832795
#define                          INF1N1TY   1000000000000000005LL;
#define                    A47L(V3CT07_t)   V3CT07_t.begin(), V3CT07_t.end()
#define             L3N(V3CT07_x, Typ30F)   (Typ30F) V3CT07_x.size()
#define                            un_map   unordered_map
#define                            un_set   unordered_set


template<typename T> void _SC4N(T &x) { 
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
    lld n; _SC4N(n);
    lld first = 1;
    lld i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            first = i;
            break;
        }
        i++;
    }

    if (first == 1) {
        cout << "1 " << n-1;
    } else {
        cout << n/first << " " << n - (n/first);
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

    TESTCASES_ARE_THERE()
        solveEach(TotalT35tC4ses - Test0xcs);
    return 0;
}

/*
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
SOME PARTS OF THE CODE MAY HAVE BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)ch|=spacelo &=_up change case
5 1 4
7 1 6
9 3 6
11 1 10
13 1 12
15 5 10
17 1 16
19 1 18
21 7 14
23 1 22
25 5 20
27 9 18
29 1 28
31 1 30
33 11 22
35 7 28
37 1 36
39 13 26
41 1 40
43 1 42
45 15 30
47 1 46
49 7 42
51 17 34
53 1 52
55 11 44
57 19 38
59 1 58
61 1 60
63 21 42
65 13 52
67 1 66
69 23 46
71 1 70
73 1 72
75 25 50
77 11 66
79 1 78
81 27 54
83 1 82

*/