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
    const lld inf = 1e18;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ":";
        lld n; cin >> n;
        lld arr[n];
        forn(i, n) {
            cin >> arr[i];
            arr[i] %= n;
        }
        lld brr[n];
        forn(i, n) {
            cin >> brr[i];
            brr[i] %= n;
        }
        queue<array<lld, 3>> q;
        lld minfirst = inf, startInd = 0;
        forn(i, n) {
            if (((arr[0] + brr[i]) % n) < minfirst) {
                queue<array<lld, 3>> tq;
                swap(q, tq);
                minfirst = (arr[0] + brr[i]) % n;
                q.push({(i + 1) % n, 1, i});
                startInd = i;
            } else if (((arr[0] + brr[i]) % n) == minfirst) {
                q.push({(i + 1) % n, 1, i});
            }
        }

        // _____error_____(startInd);
        // NonIterable.print(q);



        vector<lld> visited(2 * n + 1, 0);
        while (q.size() > 1) {
            queue<array<lld, 3>> tq;
            minfirst = inf;
            while (!q.empty()) {
                auto [el, pos, id] = q.front(); q.pop();
                minfirst = min(minfirst, (arr[pos] + brr[el]) % n);
                tq.push({el, pos, id});
            }

            while (!tq.empty()) {
                auto [el, pos, id] = tq.front(); tq.pop();
                if ((arr[pos] + brr[el]) % n == minfirst) {
                    if (!visited[el]) {
                        visited[el] = 1;
                        startInd = id;
                        q.push({(el + 1) % n, (pos + 1) % n, id});
                    }
                }
            }
        }

        _____error_____(visited);
        
        // NonIterable.print(q);

        if (q.size()) {
            startInd = q.front()[2];
        }

        forn(i, n) {
            cout << ((arr[i] + brr[(startInd + i) % n]) % n) << " ";
        }

    }

public:
    void ResetTestCase() {
        cout << "\n";
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

