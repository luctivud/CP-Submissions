/*      ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     */

// Author : Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;


#define       TESTCASES()  cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define       _input(V3C)  for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define mems(A77AY, V4LU)  memset((A77AY), (V4LU), sizeof((A77AY)))
#define  CH3K(I7, E4, S7)  (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define for4(I7,S4,E4,S7)  for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))

lld a, b, c; 
vector<lld> dp;
set<lld> se;

lld solve(lld n) {

    // cout << n << "\n";
    if (n < 0) return -99999LL;

    if (n == 0) return 0;

    if (dp[n] == -1) {
        lld mx = -99999LL;
        for (auto elem : se) {
            mx = max(mx, solve(n-elem));
        }
        dp[n] = 1 + mx;
    }

    return dp[n];
}

void solveEachTest(lld T35TC453N = 1) {
    lld n;  
    cin >> n >> a >> b >> c;
    // cout << a << b << c;
    dp.resize(n+1);
    fill(dp.begin(), dp.end(), -1);
    se.clear();
    se.insert(a);
    se.insert(b);
    se.insert(c);
    // dp[a] = dp[b] = dp[c] = 1LL;

    cout << solve(n) << "\n";

    // for (auto i : dp) cout << i << " ";

    // cout << "\n"; 

    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    lld T3X0 = 0, T353 = 1;

    // TESTCASES() 
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought : stair  