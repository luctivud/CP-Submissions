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










/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/



/*          D S U         */

void makeSet(lld n, vector<lld> &parent, vector<lld> &rank) {
    iota(all(parent), 0ll);
}

lld find_repr(lld x, vector<lld> &parent, vector<lld> &rank) {
    if (x != parent[x])
        parent[x] = find_repr(parent[x], parent, rank);
    return parent[x];
}

void Union(lld x, lld y, vector<lld> &parent, vector<lld> &rank) {
    x = find_repr(x, parent, rank);
    y = find_repr(y, parent, rank);

    if (x == y) return;

    if (rank[x] < rank[y]) {
        parent[x] = y;
    } else if (rank[x] > rank[y]) {
        parent[y] = x;
    } else {
        parent[y] = x;
        rank[x] = rank[x] + 1;
    }
    return;
}






void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, m; cin >> n >> m;
    vector<lld> d(n + 1, 0);
    forn1(i, n) cin >> d[i];

    bool ok = (accumulate(all(d), 0ll) == 2*(n-1));

    // create parent and rank at the place.
    vector<lld> parent(n + 1, 0);
    vector<lld> rank(n + 1, 0);
    makeSet(n + 1, parent, rank);

    forn1(i, m) {
        lld a, b; cin >> a >> b;
        d[a] -= 1;
        d[b] -= 1;
        Union(a, b, parent, rank);
    }

    multiset <pair<lld, lld>> ms;
    map<lld, lld> cnt;
    map<lld, multiset<pair<lld, lld>>> needOf;
    vector<pair<lld, lld>> ans;

    forn1(i, n) {
        cnt[find_repr(i, parent, rank)] += d[i];
        (needOf[find_repr(i, parent, rank)]).insert({d[i], i});
        ok &= (d[i] >= 0);
    }


    for (auto [ke, va] : cnt) {
        ms.insert({va, ke});
    }


    forn(i, n-m-1) {
        _____error_____(ms);
        auto [need1, node1] = *(ms.begin());
        ms.erase(ms.begin());
        if (need1 != 1 or ms.size() < 1) {
            ok = false;
            break;
        }
        auto [need2, node2] = *(ms.rbegin());
        ms.erase(ms.find({need2, node2}));
        Union(node1, node2, parent, rank);
        auto [n1, nod1] = *needOf[node1].begin();
        needOf[node1].erase(needOf[node1].begin());
        auto [n2, nod2] = *needOf[node2].begin();
        needOf[node2].erase(needOf[node2].begin());

        ans.push_back({nod1, nod2});
        if (need2 - 1) {
            ms.insert({need2-1, node2});
        }
    }

    if (!ok) {
        cout << "-1";
        return;
    }

    for (auto [a, b] : ans) {
        cout << a << " " << b << "\n";
    }

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    // cin.tie(0)->sync_with_stdio(0);
    // cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/udit/CPPrc/zinput.txt", "r", stdin);
    freopen("/home/udit/CPPrc/zoutput.txt", "w", stdout);
#endif


    int __NTestCases = 1;
    // cin >> __NTestCases;

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
*/
