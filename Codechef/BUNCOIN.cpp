/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIVUD
#include <buggyBaby.hpp>
pretty:: PrettyPrinter NonIterable;
#define cerr cout
#else
#define _____error_____(...)
#endif
#pragma GCC optimize "trapv"


/*:::::::::::::::::::SNIPS::::::::::::::::::::::::::::*/

typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second


/*::::::::::::::::::/SNIPS::::::::::::::::::::::::::::*/
/*:::::::::::::::::::UTILS::::::::::::::::::::::::::::*/


const long double EPS = 1e-6;
lld MOD = int(1e9) + 7;
lld &mod = MOD;

#define MAXN 200001
#define lld long long

lld INF = 1e9;
lld n, k;

struct Tnode {lld sum, maxprefix, maxsuffix, maxsum;} T[4 * MAXN];
lld a[MAXN];

Tnode combine(Tnode &node1, Tnode &node2) {
    Tnode resnode;
    resnode.sum = node1.sum + node2.sum;
    resnode.maxprefix = max(node1.maxprefix, node1.sum + node2.maxprefix);
    resnode.maxsuffix = max(node1.maxsuffix + node2.sum, node2.maxsuffix);
    resnode.maxsum = max((node1.maxsuffix + node2.maxprefix), max(node1.maxsum , node2.maxsum));
    return resnode;
}

void BuildTree(lld v, lld tl, lld tr) {
    if (tl == tr) {
        T[v] = { a[tl], a[tl], a[tl], a[tl] }; //відрізок з одного елемента
        return;
    }
    lld tm = (tl + tr) / 2;
    BuildTree(2 * v + 1, tl, tm);
    BuildTree(2 * v + 2, tm + 1, tr);

    T[v] = combine(T[2 * v + 1] , T[2 * v + 2]);
}

void modify(lld v, lld tl, lld tr, lld x, lld val) {
    if (x < tl || tr < x) return;
    if (tl == tr) {
        T[v] = { val, val, val, val };
        return;
    }
    lld tm = (tl + tr) / 2;
    modify(2 * v + 1, tl, tm, x, val);
    modify(2 * v + 2, tm + 1, tr, x, val);
    T[v] = combine(T[2 * v + 1], T[2 * v + 2]);
}

Tnode getquery(lld v, lld tl, lld tr, lld L, lld R) {
    if (R < tl || tr < L) return {0, -INF, -INF, -INF};
    if (L <= tl && tr <= R) {
        return T[v];
    }
    lld tm = (tl + tr) / 2;
    Tnode node1 = getquery(2 * v + 1, tl, tm, L, R);
    Tnode node2 = getquery(2 * v + 2, tm + 1, tr, L, R);
    return combine(node1, node2);
}


/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        cin >> n >> k;
        for (lld i = 1; i <= n; i++) {
            cin >> a[i];
        }

        BuildTree(0, 1, n);

        lld u, v;
        Tnode item;

        for (lld i = 1; i <= k; i++) {
            cin >> u >> v;
            modify(0, 1, n, u, v);
            item = getquery(0, 1, n, 1, n);
            cout << item.maxsum << "\n";
        }
    }

public:
    void ResetTestCase() {
        // cout << "\n";
    }
};



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
#endif


    int _T0T4 = 1;
    // cin >> _T0T4;

    Solution Aurora;
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        Aurora.SolveEachTest(_TestCase);
        Aurora.ResetTestCase();
    }


#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}

/*:::::::::::::::::::::/INVOC:::::::::::::::::::::::::*/
/*  ~~
Author   :  Udit "luctivud" Gupta
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/




