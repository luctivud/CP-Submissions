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



typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


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





const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;






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



lld nc2(lld num) {
    return (num * (num + 1)) / 2;
}



/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, q; cin >> n >> q;

    vector<array<lld, 3>> edges(n-1);

    forn(i, n-1) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    // create par3t and ran4k at the place.
    vector<lld> par3t(n+1, 0);
    vector<lld> ran4k(n+1, 0);
    makeSet(n+1, par3t, ran4k);

    sort(all(edges), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    _____error_____(edges);



    vector<pair<lld, lld>> queries(q);
    forn(qq, q) {
        cin >> queries[qq].f1;
        queries[qq].s2 = qq;
    }

    sort(all(queries));
    _____error_____(queries);

    map<lld, lld> sizeOfComponent;
    forn1(i, n) {
        sizeOfComponent[i] = 1;
    }


    vector<lld> ansForQueries(q);
    lld indDoneFor = 0ll, res = 0ll;

    forn(qq, q) {
        while (indDoneFor < n-1 and edges[indDoneFor][2] <= queries[qq].f1) {
            lld sz1 = sizeOfComponent[find_repr(edges[indDoneFor][0], par3t, ran4k)];
            lld sz2 = sizeOfComponent[find_repr(edges[indDoneFor][1], par3t, ran4k)];
            res += nc2(sz1 + sz2) - nc2(sz1) - nc2(sz2);
            Union(edges[indDoneFor][0], edges[indDoneFor][1], par3t, ran4k);
            sizeOfComponent[find_repr(edges[indDoneFor][0], par3t, ran4k)] = sz2 + sz1;
            indDoneFor += 1;
        }
        ansForQueries[queries[qq].s2] = res;
    }


    forn(i, q) {
        cout << ansForQueries[i] << " ";
    }
    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
        freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    int _T0T4 = 1;
    // cin >> _T0T4; 
    
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }


    #ifdef LUCTIVUD
        // auto end_time = std::chrono::high_resolution_clock::now();
        // std::chrono::duration<double> diff = end_time - start_time;
        // cerr << "Finished in : " << diff.count() << "\n";
    #endif


    return 0; 
}




/*  ~~
    .?.?.?.
*/
