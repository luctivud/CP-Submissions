/*          J  A  I   S  H  R  E  E   R  A  M          */
#ifdef LUCTIVUD
    #include <mydebug.h>
    pprint:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #include <bits/stdc++.h>
    using namespace std;
    #define _____error_____(...)
#endif


#pragma GCC optimize("O3,unroll-loops,trapv")
// #pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
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
        static const uint64_t FIXED_RANDOM = 
            chrono::steady_clock::now().time_since_epoch().count();
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



    // create par3t and ran4k at the place.
    



/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    set<lld> firstSet, secondSet;
    vector<lld> indegree(n+1, 0ll);

    bool ok = true;

    set<pair<lld, lld>> dominos;
    forn(i, n) {
        lld u, v;
        cin >> u >> v;
        indegree[u] += 1;
        indegree[v] += 1;
        ok &= (max(indegree[u], indegree[v]) <= 2);
        ok &= (u != v);
        if (u > v) {
            swap(u, v);
        }
        if (dominos.find({u, v}) == dominos.end()) {
            dominos.insert({u, v});
        } else {
            dominos.erase({u, v});
        }
    }

    vector<lld> par3t(n+1, 0);
    vector<lld> ran4k(n+1, 0);
    makeSet(n+1, par3t, ran4k);

    for (auto [a, b] : dominos) {
        Union(a, b, par3t, ran4k);
    }

    set<lld> repr;
    for (auto [a, b] : dominos) {
        repr.insert(find_repr(a, par3t, ran4k));
        repr.insert(find_repr(b, par3t, ran4k));
    }

    ok &= (repr.size() <= 1);


    // sort(all(dominos));

    // forn(i, n) {
    //     auto [a, b] = dominos[i];
    //     bool in1 = 
    //             (firstSet.find(a) == firstSet.end()) && 
    //             (firstSet.find(b) == firstSet.end()) && 
    //             (a != b);
    //     bool in2 = 
    //             (secondSet.find(a) == secondSet.end()) && 
    //             (secondSet.find(b) == secondSet.end()) && 
    //             (a != b);
    //     if (in1) {
    //         firstSet.insert(a);
    //         firstSet.insert(b);
    //     } else if (in2) {
    //         secondSet.insert(a);
    //         secondSet.insert(b);
    //     } else {
    //         ok = false;
    //     }
    // }

    cout << (ok ? "YES" : "NO");


    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/udit/CPPrc/zinput.txt", "r", stdin);
        freopen("/home/udit/CPPrc/zoutput.txt", "w", stdout);
    #endif


    int __NTestCases = 1;
    cin >> __NTestCases; 
    
    for (int _TestCase = 1; _TestCase <= __NTestCases; _TestCase++) {
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

7
4
1 2
4 3
2 1
3 4
6
1 2
4 5
1 3
4 6
2 3
5 6
2
1 1
2 2
2
1 2
2 1
8
2 1
1 2
4 3
4 3
5 6
5 7
8 6
7 8
8
1 2
2 1
4 3
5 3
5 4
6 7
8 6
7 8

6
1 2 
3 6
4 1
5 2
3 4
5 6
*/
