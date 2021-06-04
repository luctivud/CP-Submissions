//  J A I  S H R E E  R A M  //

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize "trapv"



#ifdef LUCTIVUD
    #include <buggyBaby.hpp>
    pretty:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #define _____error_____(...)
#endif



typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second



const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/


class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    	MOD = (int) 1e9 + 7;
    	horizontalCuts.push_back(0);
    	horizontalCuts.push_back(h);
    	verticalCuts.push_back(0);
    	verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        lld maxHorz = 0ll, maxVert = 0ll;

        for (int i = 0; i < (int)horizontalCuts.size(); i++) {
        	if (i + 1 >= (int)horizontalCuts.size()) break;
        	maxHorz = max(maxHorz, horizontalCuts[i+1] - horizontalCuts[i]);
        }

        for (int i = 0; i < (int)verticalCuts.size(); i++) {
        	if (i + 1 >= (int)verticalCuts.size()) break;
        	maxVert = max(maxHorz, verticalCuts[i+1] - verticalCuts[i]);
        }

        return (maxHorz * maxVert) % MOD;
    }
};







// signed main() {
//     ios_base::sync_with_stdio(false); cin.tie(0);
//     // cout.precision(10); cout << fixed;
//     #ifdef LUCTIVUD
//       // const auto start_time = std::chrono::high_resolution_clock::now();
//       freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
//       freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
//     #endif


//     int _T0T4 = 1;
//     // cin >> _T0T4; 
    
//     Solution Wrath;
//     for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
//         Wrath.maxArea();
//         // Wrath.reset_test();
//     }


//     #ifdef LUCTIVUD
//       // auto end_time = std::chrono::high_resolution_clock::now();
//       // std::chrono::duration<double> diff = end_time - start_time;
//       // cerr << "Finished in : " << diff.count() << "\n";
//     #endif

//     return 0; 
// }


// /*  ~~
// Author   :  Udit "luctivud" Gupta 
// linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
// */

