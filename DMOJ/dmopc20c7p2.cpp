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
        lld n; cin >> n;
        set<pair<lld, lld>> edgesSet;
        vector<pair<lld, lld>> edges;
        forn(i, n) {
            lld a, b; cin >> a >> b;
            // if sq or oct
            // add vertices
            if (findPolygon(llabs(a), llabs(b))) {
                addEdgesSq(a, b, edges, edgesSet);
            } else {
                addEdgesOc(a, b, edges, edgesSet);
            }
        }
        // NonIterable.print(edges);
        sort(all(edges), [](auto &a, auto &b) {
            return (a.f1 == b.f1 ? a.s2 < b.s2 : a.f1 < b.f1);
        });
        pair <lld, lld> edgewa = edges[0];
        _____error_____(edgewa);
        vector<pair<lld, lld>> ans;
        // travelBB(edgewa, ans, edgesSet);
        goUp(edgewa, ans, edgesSet);
        goDown(edgewa, ans, edgesSet);
        cout << len(ans) << "\n";
        for (auto &[a, b] : ans) {
            cout << a << " " << b << "\n";
        }

    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
    bool findPolygon(lld a, lld b) {
        return ((a % 4) == (b % 4));
    }
    void addEdgesSq(lld a, lld b, vector<pair<lld, lld>> &edges, set<pair<lld, lld>> &edgesSet) {
        edges.push_back({a, b});
        edges.push_back({a, b+1});
        edges.push_back({a+1, b+1});
        edges.push_back({a+1, b});
        edgesSet.insert({a, b});
        edgesSet.insert({a, b+1});
        edgesSet.insert({a+1, b+1});
        edgesSet.insert({a+1, b});
    }
    void addEdgesOc(lld a, lld b, vector<pair<lld, lld>> &edges, set<pair<lld, lld>> &edgesSet) {
        edges.push_back({a-1, b});
        edges.push_back({a-1, b+1});
        edges.push_back({a, b+2});
        edges.push_back({a+1, b+2});
        edges.push_back({a+2, b+1});
        edges.push_back({a+2, b});
        edges.push_back({a+1, b-1});
        edges.push_back({a, b-1});
        edgesSet.insert({a-1, b});
        edgesSet.insert({a-1, b+1});
        edgesSet.insert({a, b+2});
        edgesSet.insert({a+1, b+2});
        edgesSet.insert({a+2, b+1});
        edgesSet.insert({a+2, b});
        edgesSet.insert({a+1, b-1});
        edgesSet.insert({a, b-1});
    }

    void goUp(pair<lld, lld> &edgewa, vector<pair<lld, lld>> &ans, set<pair<lld, lld>> &edgesSet) {
        lld dx[] = {0, 1, 1,  1},
            dy[] = {1, 1, 0, -1};
        while (edgesSet.find(edgewa)!= edgesSet.end()) {
            pair<lld, lld> newEdgewa = edgewa;
            edgesSet.erase(edgewa);
            ans.push_back(edgewa);
            forn(i, 4) {
                newEdgewa.f1 = edgewa.f1 + dx[i];
                newEdgewa.s2 = edgewa.s2 + dy[i];
                if (edgesSet.find(newEdgewa) != edgesSet.end()) {
                    break;
                }
            }
            edgewa = newEdgewa;
        }
    }
    void goDown(pair<lld, lld> &edgewa, vector<pair<lld, lld>> &ans, set<pair<lld, lld>> &edgesSet) {
        lld dx[] = { 0, -1, -1, -1},
            dy[] = {-1, -1,  0,  1};
        forn(i, 4) {
            pair<lld, lld> newEdgewa = edgewa;
            newEdgewa.f1 = edgewa.f1 + dx[i];
            newEdgewa.s2 = edgewa.s2 + dy[i];
            if (edgesSet.find(newEdgewa) != edgesSet.end()) {
                edgewa = newEdgewa;
                break;
            }
        }
        while (edgesSet.find(edgewa)!= edgesSet.end()) {
            pair<lld, lld> newEdgewa = edgewa;
            edgesSet.erase(edgewa);
            ans.push_back(edgewa);
            forn(i, 4) {
                newEdgewa.f1 = edgewa.f1 + dx[i];
                newEdgewa.s2 = edgewa.s2 + dy[i];
                if (edgesSet.find(newEdgewa) != edgesSet.end()) {
                    break;
                }
            }
            edgewa = newEdgewa;
        }
        // _____error_____(edgewa);
        // NonIterable.print(edgewa);
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

