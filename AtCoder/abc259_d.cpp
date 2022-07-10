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


class Circle {
public:
    lld Cx, Cy, r;
    Circle() {};
    Circle(lld a, lld b, lld c) : Cx(a), Cy(b), r(c) {
        
    }
};

bool checkIntersect(Circle A, Circle O) {
    lld c1c2 = (A.Cx - O.Cx) * (A.Cx - O.Cx) + (A.Cy - O.Cy) * (A.Cy - O.Cy);
    lld rs = (A.r + O.r) * (A.r + O.r);
    lld rd = (A.r - O.r) * (A.r - O.r);
    return (rd <= c1c2 && c1c2 <= rs);
}

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



    // create parent and rank at the place.



void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    vector<Circle> arr(n);
    lld sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    forn(i, n) {
        cin >> arr[i].Cx >> arr[i].Cy >> arr[i].r;
    }

    vector<lld> parent(n, 0);
    vector<lld> rank(n, 0);
    makeSet(n, parent, rank);
    
    forn(i, n) {
        for (lld j = i+1; j < n; j++) {
            if (checkIntersect(arr[i], arr[j])) {
                _____error_____(i, j);
                Union(i, j, parent, rank);
            }
        }
    }

    set<lld> wowie;

    forn(i, n) {
        if (checkIntersect(arr[i], Circle(sx, sy, 0ll))) {
            wowie.insert(find_repr(i, parent, rank));
        }
    }

    bool ok = false;

    forn(i, n) {
        if (checkIntersect(arr[i], Circle(tx, ty, 0ll))) {
            ok |= (wowie.find(find_repr(i, parent, rank)) != wowie.end());
        }
    }
    _____error_____(wowie);
    cout << (ok ? "Yes" : "No");
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
