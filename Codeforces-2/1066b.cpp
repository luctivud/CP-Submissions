
/*          J  A  I   S  H  R  E  E   R  A  M          */



#include <bits/stdc++.h>
using namespace std;

#ifdef LUCTIVUD
#include <buggyBaby.hpp>
pretty:: PrettyPrinter NonIterable;
#define cerr cout
#else
#define _____error_____(...)
#endif

#pragma GCC optimize("O3,unroll-loops,trapv")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"






/*  Snips   */


typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second



/*  Utils   */


const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



signed pleaseAC(void) {

#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}


void IAmJustice(void) {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/IO/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/IO/Zoutput.txt", "w", stdout);
#endif

    return;
}














/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, r; cin >> n >> r;

    lld arr[n+1] = {0};
    vector<lld> posOfOne{-inf};
    forn1(i, n) {
        cin >> arr[i];
        if (arr[i]) {
            posOfOne.push_back(i);
        }
    }

    posOfOne.push_back(inf);

    lld pos = 0ll, ans = 0ll;
    while (pos < n) {
        bool found = false;

        // for (lld i = min(n, pos + r); i >= max(1ll, pos - r) ; i--) {
        //     if (arr[i]) {
        //         found = true;
        //         pos = i + r - 1;
        //         break;
        //     }
        // }

        lld hi = min(n, pos+r), lo = max(1ll, pos - r);

        lld poswa = *(--upper_bound(all(posOfOne), hi));

        if (poswa >= lo and poswa <= hi and (poswa + r - 1) != pos) {
            pos = poswa + r - 1;
            found = true;
        }

        if (!found or pos <= 0) {
            cout << "-1";
            return;
        }
        ans += 1;
    }

    cout << ans;

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    IAmJustice();

    int _T0T4 = 1;
    // cin >> _T0T4;

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }

    return pleaseAC();
}




/*  ~~
    .?.?.?.
*/



// // ------------------------------------------------------------------- //
// /*

//       Author :  Udit "luctivud" Gupta
//     Linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
//       Github :  https://github.com/luctivud

// */
// // ------------------------------------------------------------------- //



// /*          J  A  I   S  H  R  E  E   R  A  M          */



// #include <bits/stdc++.h>
// using namespace std;

// #ifdef LUCTIVUD
// #include <buggyBaby.hpp>
// pretty:: PrettyPrinter NonIterable;
// #define cerr cout
// #else
// #define _____error_____(...)
// #endif

// #pragma GCC optimize("O3,unroll-loops,trapv")
// #pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// // #pragma GCC optimize "trapv"






// /*  Snips   */


// typedef long long lld; typedef unsigned long long llu;

// #define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
// #define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
// #define        len(v) ((int)((v).size()))
// #define        all(x) (x).begin(), (x).end()
// #define       rall(x) (x).rbegin(), (x).rend()
// #define            f1 first
// #define            s2 second



// /*  Utils   */


// const lld MOD = int(1e9) + 7;
// const lld &mod = MOD;

// const long double EPS = 1e-6;

// const lld inf = 2e18;


// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };



// signed pleaseAC(void) {

// #ifdef LUCTIVUD
//     // auto end_time = std::chrono::high_resolution_clock::now();
//     // std::chrono::duration<double> diff = end_time - start_time;
//     // cerr << "Finished in : " << diff.count() << "\n";
// #endif

//     return 0;
// }


// void IAmJustice(void) {

//     ios_base::sync_with_stdio(false); cin.tie(0);
//     cout.precision(10); cout << fixed;

// #ifdef LUCTIVUD
//     // const auto start_time = std::chrono::high_resolution_clock::now();
//     freopen("/home/luctivud/CPPractice/IO/Zinput.txt", "r", stdin);
//     freopen("/home/luctivud/CPPractice/IO/Zoutput.txt", "w", stdout);
// #endif

//     return;
// }














// /*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





// void solveEachTest(int _TestCase) {
//     // cout << "Case #" << _TestCase << ": ";
//     lld n, r; cin >> n >> r;

//     r -= 1;

//     lld pos = -r+1, ans = 0ll;
//     // vector<lld> onesWhere;
//     vector<lld> lastWhere(n + 1, 0);
//     forn1(i, n) {
//         lld temp;
//         cin >> temp;
//         if (temp) {
//             // onesWhere.push_back(i+1);
//             lastWhere[i] = i;
//         } else {
//             lastWhere[i] = lastWhere[i - 1];
//         }

//     }

//     _____error_____(lastWhere);

//     while (pos < n) {
//         lld newPos = upper_bound(all(onesWhere), pos+r) - onesWhere.begin();
//         if (newPos <= pos) {
//             break;
//         }
//         pos = newPos;
//         ans += 1;
//     }

//     // _____error_____(pos);

//     // if (pos + r < n) {
//     //     ans = -1;
//     // }
//     // cout << ans;


//     return;
// }



// /*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


// signed main() {

//     IAmJustice();

//     int _T0T4 = 1;
//     // cin >> _T0T4;

//     for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
//         solveEachTest(_TestCase);
//         cout << "\n";
//     }

//     return pleaseAC();
// }




// /*  ~~
//     Speed Solving

// */