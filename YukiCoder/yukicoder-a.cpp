
//             Author: Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)                  //


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define         _input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define             deb1(x)    cout << #x << "=" << (x) << "\n";
#define             deb2(x)    cout << #x << "=" << (x) << " ";



void solveEachTest(lld T35TC453N = 1) {
    long double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    long double fac = sqrt(((c*c)+(d*d)-(4*(e-f)*a)));
    cout << fac/(2*a);

    cout << "\n"; 

    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.precision(10);

    lld T3X0 = 0, T353 = 1;

    // TESTCASES() 
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought :  null  