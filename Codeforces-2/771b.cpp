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








/*          D S U         */

void makeSet(lld n, vector<lld> &par3t, vector<lld> &ran4k) {
    iota(all(par3t), 0ll);
}

lld find_repr(lld x, vector<lld> &par3t, vector<lld> &ran4k) {
    if (x != par3t[x])
        par3t[x] = find_repr(par3t[x], par3t, ran4k);
    return par3t[x];
}

void Union(lld x, lld y, vector<lld> &par3t, vector<lld> &ran4k) {
    x = find_repr(x, par3t, ran4k);
    y = find_repr(y, par3t, ran4k);

    if (x == y) return;

    if (ran4k[x] < ran4k[y]) { 
        par3t[x] = y; 
    } else if (ran4k[x] > ran4k[y]) { 
        par3t[y] = x; 
    } else { 
        par3t[y] = x; 
        ran4k[x] = ran4k[x] + 1; 
    } 
    return;
}



    





/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, k; cin >> n >> k;

    vector<string> yesno(n-k+1);
    forn(i, n-k+1) {
        cin >> yesno[i];
    }

    vector<string> newNames;
    string allLetters;
    forn(i, 9) {
        allLetters.push_back((char)('a' + i));
    }

    while ((lld)newNames.size() < n) {
        newNames.push_back(allLetters);
        next_permutation(all(allLetters));
    }

    _____error_____(newNames);


    // create par3t and ran4k at the place.
    vector<lld> par3t(n, 0);
    vector<lld> ran4k(n, 0);
    makeSet(n, par3t, ran4k);


    vector<string> ans = newNames;
    forn(i, n-k+1) {
        if (yesno[i] == "YES") {
            // forn(j, k) {
            //     if (ans[i+j] == "") {
            //         oneDone = true;
            //         ans[i+j] = newNames[ind++];
            //     }
            // }
        } else {    
            Union(i, i+k-1, par3t, ran4k);
        }
    }

    _____error_____(ans);

    // if (!oneDone) {
    //     ans[0] = newNames[ind++];
    // }

    // string temp = "";
    // forn(i, n) {
    //     if (temp != "" and ans[i] == "") {
    //         ans[i] = temp;
    //     }
    //     temp = ans[i];
    // }

    // temp = "";


    // forn(i, n) {
    //     if (temp != "" and ans[n-i-1] == "") {
    //         ans[n-1-i] = temp;
    //     }
    //     temp = ans[n-1-i];
    // }

    forn(i, n) {
        ans[i] = ans[find_repr(i, par3t, ran4k)];
    }

    _____error_____(ans);



    forn(i, n) {
        ans[i][0] = char(ans[i][0] - 'a' + 'A');
        cout << ans[i] << " ";
    }

    // set<string> se;
    // forn(i, n-k-1) {

    // }
    
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
