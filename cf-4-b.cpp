/*  Created by: @luctivud  at 2020-07-11 09:11:52  */

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

const long long int UGLYMOD {1000000007};
const long long int SEXYMOD {998244353};
const long long int MAXN = 1e6 + 1LL;

typedef string STR;
typedef long long int lld;
typedef vector<int> v_int;
typedef vector<lld> v_lld;
typedef pair<int, int> p_int;
typedef pair<lld, lld> p_lld;


#define                 GREED_FOR_SPEED   ios_base::sync_with_stdio(false); cin.tie(0)
#define           TESTCASES_ARE_THERE()   lld Test; _scan(Test); while(Test--)
#define                   mems(arr,val)   memset((arr), val, sizeof((arr)))
#define   FORFWD(itr, start, end, step)   for(lld itr = start; itr < end; itr += step)
#define   FORBWD(itr, start, end, step)   for(lld itr = start; itr > end; itr -= step)
#define                            endl   "\n"
#define            FOREACH(___vec, itr)   for(auto itr = ___vec.begin(); itr != ___vec.end(); itr++)
#define                   INPUT(___vec)   for(auto &___vec___itr : ___vec) _scan(___vec___itr)
#define                              PI   3.1415926535897932384626433832795
#define                            INFF   1000000000000000005LL;
#define                    ALL(___vect)   ___vect.begin(), ___vect.end()
#define              LEN(___vecx, Type)   (Type) ___vecx.size()
#define                          un_map   unordered_map
#define                          un_set   unordered_set


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


void solveEach() {
    lld n, sumTime;
    cin >> n >> sumTime ;
    v_lld minTime(n), maxTime(n);
    lld l = 0, r = 0;
    FORFWD(i, 0, n, 1) {
        lld x, y;
        cin >> x >> y;
        minTime[i] = x; maxTime[i] = y;
        l += x; r += y;
    }

    printYesNo(sumTime <= r and sumTime >= l);

    if (sumTime <= r and sumTime >= l) {
        v_lld ans(n);
        lld currSum = 0;
        FORFWD(i, 0, n, 1) {
            ans[i] = minTime[i];
            currSum += minTime[i];
        }
        lld remTime = sumTime - currSum;
        lld day = 0;
        while (remTime > 0) {
            ans[day] += min(remTime, maxTime[day] - minTime[day]);
            remTime -= min(remTime, maxTime[day] - minTime[day]);
            day++ ;
        }

        FOREACH(ans, i) cout << *i << " ";
    }

    return;
}


signed main() {

    // GREED_FOR_SPEED;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    // TESTCASES_ARE_THERE()
        solveEach();
    return 0;
}

/*
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
SOME PARTS OF THE CODE MAY HAVE BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)ch|=spacelo &=_up change case
*/