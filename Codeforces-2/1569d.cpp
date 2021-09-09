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





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, m, k; cin >> n >> m >> k;

    set<lld> horRoads, verRoads;
    horRoads.insert(-inf);
    horRoads.insert(inf);
    verRoads.insert(-inf);
    verRoads.insert(inf);
    forn(i, n) {
        lld temp; cin >> temp;
        horRoads.insert(temp);
    }

    forn(i, m) {
        lld temp; cin >> temp;
        verRoads.insert(temp);
    }

    _____error_____(horRoads);
    _____error_____(verRoads);

    vector<array<lld, 3>> points(k);

    vector<lld> onlyHor, onlyVer;
    forn(i, k) {
        lld x, y; cin >> x >> y;
        points[i][0] = x, points[i][1] = y, points[i][2] = i;
        bool b1 = (horRoads.find(x) != horRoads.end());
        bool b2 = (verRoads.find(y) != verRoads.end());
        if (b1 && b2) {
            continue;
        } else if (b1) {
            onlyVer.push_back(i);
        } else if (b2) {
            onlyHor.push_back(i);
        }
    }

    sort(all(onlyHor), [&](auto &a, auto &b) {
        return points[a][0] < points[b][0];
    });

    sort(all(onlyVer), [&](auto &a, auto &b) {
        return points[a][1] < points[b][1];
    });

    _____error_____(onlyHor);
    _____error_____(onlyVer);


    lld ans = 0ll;

    auto it_first = horRoads.begin();
    auto it_second = next(it_first);

    lld ind = 0ll;

    while (it_second != horRoads.end()) {
        map<lld, lld> cnt;
        lld total_in = 0ll;
        while (ind < len(onlyHor) and points[onlyHor[ind]][0] < *it_second) {
            cnt[points[onlyHor[ind++]][1]] += 1;
            total_in += 1;
        }

        if (len(cnt)) {
            _____error_____(*it_first, *it_second);
            _____error_____(cnt);
        }

        for (auto [ke, va] : cnt) {
            ans += (total_in - va) * va;
        }

        it_first = it_second;
        it_second = next(it_first);
    }

    _____error_____("");

    it_first = verRoads.begin();
    it_second = next(it_first);

    ind = 0ll;

    while (it_second != verRoads.end()) {
        map<lld, lld> cnt;
        lld total_in = 0ll;
        while (ind < len(onlyVer) and points[onlyVer[ind]][1] < *it_second) {
            cnt[points[onlyVer[ind++]][0]] += 1;
            total_in += 1;
        }


        if (len(cnt)) {
            _____error_____(*it_first, *it_second);
            _____error_____(cnt);
        }

        for (auto [ke, va] : cnt) {
            ans += (total_in - va) * va;
        }

        it_first = it_second;
        it_second = next(it_first);
    }


    cout << ans / 2;


    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    cin.tie(0)->sync_with_stdio(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
        freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
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
*/
