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





#define int lld



/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
    vector<vector<int>>v;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld n, k, s; cin >> n >> k >> s;
        lld arr[n];
        forn(i, n) cin >> arr[i];
        vector<lld> parent(n + 1, n);
        lld ind1 = 0ll, ind2 = 0ll, currSum = 0ll;
        while (ind1 < n) {
            while (ind2 < n and currSum + arr[ind2] <= s) {
                currSum += arr[ind2++];
            }
            // _____error_____(currSum);
            parent[ind1] = ind2;
            currSum -= arr[ind1];
            ind1++;
        }
        _____error_____(parent);
        TreeAncestor(n + 1, parent);
        // cout << getKthAncestor(0, k+10);

        lld ans = 0ll;
        forn(i, n) {
            ans = max(ans, getKthAncestor(i, k) - i);
        }

        cout << ans;
    }

public:

    void ResetTestCase() {
        cout << "\n";
    }
    void TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> par(n, vector<int>(20));
        for (int i = 0; i < n; i++) par[i][0] = parent[i];
        for (int j = 1; j < 20; j++) {
            for (int i = 0; i < n; i++) {
                if (par[i][j - 1] == -1) par[i][j] = -1;
                else par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
        swap(v, par);
    }
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if ((k >> i) & 1) {
                node = v[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
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
    cin >> _T0T4;

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

