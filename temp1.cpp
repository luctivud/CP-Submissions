/*      ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     */


// [temp1.cpp] => [29-07-2020 @ 17:55:57] 
// Author & Template by : Udit "luctivud" Gupta
// https://www.linkedin.com/in/udit-gupta-1b7863135/


#include <bits/stdc++.h>
// #pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;


#define       TESTCASES()  cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define       _input(V3C)  for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define mems(A77AY, V4LU)  memset((A77AY), (V4LU), sizeof((A77AY)))
#define  CH3K(I7, E4, S7)  (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define for4(I7,S4,E4,S7)  for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define  FORE4CH(I7, V3C)  for(auto I7=(V3C).begin();I7!=(V3C).end();I7++)






void solveEachTest(lld T35TC453N = 1) {
    // auto S34t = chrono:: high_resolution_clock::now(); 

    lld n; cin >> n;
    vector<lld> a(n+1);
    for4(i, 1, n+1, 1) cin >> a[i];
    if(n<=2 or !(n&1)) {
        cout << "-1";
    } else {
        lld ans = 0LL;
        for4(i, n, 1, -1) {
            while (a[i] && (i & 1)) {
                lld pos = (i-1)/2;
                a[i]--;
                a[pos] = max(0LL, a[pos]-1);
                a[2*pos] = max(0LL, a[2*pos]-1);
                ans++;
            }
            while (a[i] && !(i % 2)) {
                lld pos = i/2;
                a[i]--;
                a[pos] -= (a[pos]) ? 1 : 0;
                a[2*pos+1] -= (a[2*pos+1]) ? 1 : 0;
                ans++;
            }
        }

        ans += a[1];
	    cout << ans;
    }

    cout << "\n"; 

    // auto S34p = chrono::high_resolution_clock::now(); 
    // auto D34n = chrono::duration_cast<chrono::microseconds>(S34p - S34t);
    // cout << "Time Elapsed: " << D34n.count() / (long double) 1e6 << " seconds" << endl; 
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    lld T3X0 = 0, T353 = 1;

    // TESTCASES()
        solveEachTest(T353 - T3X0);
    return 0;
}
