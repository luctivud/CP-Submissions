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




#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using PBSET = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
    .insert(el) - set hai!
    .find_by_order(3) - returns an iterator to the k-th largest element (counting from zero)
    .order_of_key(6) - the number of items in a set that are strictly smaller than our item
*/





/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
    const long long inf = 1e18 + 100;
public:
    Solution() {
    }
public:
    void SolveEachTest(int _TestCase) {
        cout << "Case #" << _TestCase << ": ";
        long long n, m; cin >> n >> m;
        PBSET<pair<long long, long long>> oset;
        for (int i = 0; i < n; i++) {
            long long l, r; cin >> l >> r;
            oset.insert({l, r});
        }
        // _____error_____(oset);
        for (int i = 0; i < m; i++) {
            long long elem; cin >> elem;
            long long ans = binaryFind(oset, elem);
            // _____error_____(ans);
            cout << ans <<  " ";
        }
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
    long long binaryFindPos(PBSET<pair<long long, long long>> &oset, long long &elem) {
        long long l = 0, r = oset.size() - 1;
        long long ans = r + 1;
        while (l <= r) {
            long long mid = (r - l) / 2 + l;
            pair<long long, long long> yeye = *(oset.find_by_order(mid));
            if (yeye.first >= elem and yeye.second <= elem) {
                return mid;
            } else if (elem < yeye.first) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    long long binaryFind(PBSET<pair<long long, long long>> &oset, long long &elem) {
        long long pos = binaryFindPos(oset, elem);
        // _____error_____(pos);

        pair<lld, lld> yeye2 = {inf, inf};
        if (pos < (long long)oset.size()) {
            yeye2 = *(oset.find_by_order(pos));
        }
        auto [l, r] = yeye2;
        if (elem >= l and elem <= r and r != inf) {
            oset.erase({l, r});
            if (elem - 1 >= l) {
                oset.insert({l, elem - 1});
            }
            if (elem + 1 <= r) {
                oset.insert({elem + 1, r});
            }
            return elem;
        }
        pair<long long, long long> yeye1 = {inf, inf};
        if (pos - 1 >= 0) {
            yeye1 = *(oset.find_by_order(pos - 1));
        }
        if (pos - 1 >= 0) {
            auto [l1, r1] = *(oset.find_by_order(pos - 1));
            if (elem >= l1 and elem <= r1) {
                oset.erase({l1, r1});
                if (elem - 1 >= l1) {
                    oset.insert({l1, elem - 1});
                }
                if (elem + 1 <= r1) {
                    oset.insert({elem + 1, r1});
                }
                return elem;
            }
        }

        if (llabs(elem - yeye1.second) <= llabs(elem - l) and yeye1.second != inf) {
            oset.erase(yeye1);
            if (yeye1.second - 1 >= yeye1.first) {
                oset.insert({yeye1.first, yeye1.second - 1});
            }
            return yeye1.second;
        } else if (l != inf) {
            oset.erase({l, r});
            if (l + 1 <= r) {
                oset.insert({l + 1, r});
            }
            return l;
        } else {
            oset.erase(yeye1);
            if (yeye1.second - 1 >= yeye1.first) {
                oset.insert({yeye1.first, yeye1.second - 1});
            }
            return yeye1.second;
        }

        //  else if (elem > r and pos+1 < ((long long)oset.size())) {
        //     auto [l1, r1] = *(oset.find_by_order(pos+1));
        //     return {l1, r1};
        // } else if (pos-1 >=0) {
        //     auto [l1, r1] = *(oset.find_by_order(pos-1));
        //     return {l1, r1};
        // }

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

