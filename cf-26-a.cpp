/*     <<<  J A I ~ S H R E E ~ R A M  >>>     */

// Title: cf-26-a.cpp
// created on: 19-07-2020 at 17:59:14
// Creator & Template : Udit Gupta "@luctivud"
// https://github.com/luctivud
// https://www.linkedin.com/in/udit-gupta-1b7863135/


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

const long long int MOD_JOHAN {1000000007};
const long long int MOD_LIGHT {998244353};
const long long int MAXN_EYEPATCH = 1e6 + 1LL;
const long long int MAXN_HAIRUIHEHI = 1e9+1LL;
const long long int MAXN_FULLMETAL = 501LL;
const long double EPSILON_AMON = 1e-9; 

typedef long long int lld;
typedef unsigned long long int llu;
typedef vector<int> v_int;
typedef vector<lld> v_lld;
typedef vector<llu> v_llu;
typedef vector<string> v_str;
typedef pair<int, int> p_int;
typedef pair<lld, lld> p_lld;


#define                   GREED_FOR_SPEED   ios_base::sync_with_stdio(false); cin.tie(0)
#define             TESTCASES_ARE_THERE()   cin >> (Test0xcs); TotalT35tC4ses = Test0xcs; while(Test0xcs--)
#define                  _INP14T(V3CT07_)   for(auto &V3CT07____IT7T : (V3CT07_)) cin >> (V3CT07____IT7T)
#define                  mems(A77AY,V4LU)   memset((A77AY), (V4LU), sizeof((A77AY)))
#define   FOR4WD(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = (ST47T); IT7T < (E9xD); IT7T += (St3P))
#define   FOR8WD(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = (ST47T); IT7T > (E9xD); IT7T -= (St3P))
#define  FOR4NGE(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = (ST47T);(((St3P)<0) ? (IT7T)>(E9xD) : (IT7T)<(E9xD)); (IT7T) += (St3P))
#define            FOR34CH(IT7T, V3CT07_)   for(auto IT7T = (V3CT07_).begin(); IT7T != (V3CT07_).end(); IT7T++)
#define           FORAL7L(IT7T, V3CT07_s)   for (auto IT7T : (V3CT07_s))
#define                  ALL47L(V3CT07_t)   (V3CT07_t).begin(), (V3CT07_t).end()
#define                  RAL47L(V3CT07_t)   (V3CT07_t).rbegin(), (V3CT07_t).rend()
#define            LEN3(V3CT07_x, Typ30F)   (Typ30F) ((V3CT07_x).size())
#define                GRE3V3R53D(Typ30F)   greater<Typ30F>()
#define                              endl   "\n"
#define                            un_map   unordered_map
#define                            un_set   unordered_set


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


// POWM0D(a, b, mod)
template <typename Type30F1> 
Type30F1 POWM0D(Type30F1 a, Type30F1 b, Type30F1 mod) {
    Type30F1 res = 1;
    a %= mod; 
    assert(b>=0); 
    for(; b ; b >>= 1) { 
        if(b & 1) res = res * a % mod; 
        a = a * a % mod; 
    } 
    return res;
}


// GCD
template <typename Type30F1> 
Type30F1 gcd(Type30F1 a,Type30F1 b) { 
    return b ? gcd(b, a % b) : a; 
}

// INFINITY && -INFINITY 
// INF1N1TY<lld>
template <typename Type30F1> 
Type30F1 INF1N1TY  = numeric_limits<Type30F1>::max(); 

// PI = 3.1415926535897932384626433832795L 
// PI_HIKARI<long double>;
template<class Type30F1> 
constexpr Type30F1 PI_HIKARI = Type30F1(acos(-1)); 


void printYesNo(bool Expr, int YNType = 1, string FirstChoice = "Ud", string SecondChoice = "Ud") { 
    if (YNType == 1) puts(Expr ? "YES" : "NO");
    else if (YNType == 2) puts(Expr ? "Yes" : "No");
    else if (YNType == 3) puts(Expr ? "yes" : "no");
    else if (YNType == 4) cout << (Expr ? FirstChoice : SecondChoice);
}



void solveEach(lld T35TC453N = 1) {
    

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
*/