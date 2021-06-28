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
// #define            f1 first
// #define            s2 second


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
        int n, s; cin >> n >> s;
        // if ((9ll * n) < s or s < 1) {
        //     if (n == 1 and s == 0) {
        //         cout << "0";
        //         return;
        //     }
        //     cout << "NO";
        //     return;
        // }
        string n1, n2;
        // forn(i, n) {
        //     n1.push_back('0');
        //     n2.push_back('0');
        // }
        // lld s1 = s, s2 = s;
        // forn(i, n) {
        //     lld mn1 = min(s1, 9ll);
        //     n1[i] = char(mn1 + '0');
        //     s1 -= mn1;
        // }
        // n2[0] = '1';
        // s2 -= 1;
        // for (lld i = n - 1; i > 0; i--) {
        //     lld mn2 = min(9ll, s2);
        //     n2[i] = char(mn2 + '0');
        //     s2 -= mn2;
        // }
        // // _____error_____(s2);
        // n2[0] = char(s2 + '1');

        n1 = findLargest(n, s);
        n2 = findSmallest(n, s);

        if (n1 == "-1" or n2 == "-1") {
            cout << "NO";
            return;
        }

        _____error_____(n1, n2);

        // vector<lld> ans(n, 0);
        // for (lld i = n - 1; i >= 0; i--) {
        //     lld thisNum1 = n1[i] - '0';
        //     lld thisNum2 = n2[i] - '0';
        //     if (thisNum1 < thisNum2) {
        //         thisNum1 += 10;
        //         n1[i - 1]--;
        //     }
        //     ans[i] = (thisNum1 - thisNum2);
        // }
        // lld ind = 0ll;
        // while (ind < n - 1 and ans[ind] == 0) {
        //     ind++;
        // }
        // while (ind < n) {
        //     cout << ans[ind++];
        // }

        string ans = findDiff(n1, n2);
        if (ans == "") {
            ans = "0";
        }
        cout << ans;

    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
    string findLargest(int m, int s)
    {
        // If sum of digits is 0, then a nuber is possible
        // only if number of digits is 1.
        if (s == 0)
        {
            return (m == 1 ? "0" : "-1");
        }

        // Sum greater than the maximum possible sum.
        if (s > 9 * m)
        {
            return "-1";
        }

        // Create an array to store digits of result
        string res;
        forn(i, m) {
            res.push_back('0');
        }

        // Fill from most significant digit to least
        // significant digit.
        for (int i = 0; i < m; i++)
        {
            // Fill 9 first to make the number largest
            if (s >= 9)
            {
                res[i] = '9';
                s -= 9;
            }

            // If remaining sum becomes less than 9, then
            // fill the remaining sum
            else
            {
                res[i] = s + '0';
                s = 0;
            }
        }

        return res;
    }

    string findSmallest(int m, int s)
    {
        // If sum of digits is 0, then a number is possible
        // only if number of digits is 1.
        if (s == 0)
        {
            return (m == 1 ? "0" : "-1");
        }

        // Sum greater than the maximum possible sum.
        if (s > 9 * m)
        {
            return "-1";
        }

        // Create an array to store digits of result
        string res;
        forn(i, m) {
            res.push_back('0');
        }

        // deduct sum by one to account for cases later
        // (There must be 1 left for the most significant
        //  digit)
        s -= 1;

        // Fill last m-1 digits (from right to left)
        for (int i = m - 1; i > 0; i--)
        {
            // If sum is still greater than 9,
            // digit must be 9.
            if (s > 9)
            {
                res[i] = '9';
                s -= 9;
            }
            else
            {
                res[i] = s + '0';
                s = 0;
            }
        }

        // Whatever is left should be the most significant
        // digit.
        res[0] = (s + 1) + '0';  // The initially subtracted 1 is
        // incorporated here.

        return res;
    }
    string findDiff(string str1, string str2)
    {
        // Before proceeding further, make sure str1
        // is not smaller
        // if (isSmaller(str1, str2))
        //     swap(str1, str2);

        // Take an empty string for storing result
        string str = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();

        // Reverse both of strings
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        int carry = 0;

        // Run loop till small string length
        // and subtract digit of str1 to str2
        for (int i = 0; i < n2; i++) {
            // Do school mathematics, compute difference of
            // current digits

            int sub
                = ((str1[i] - '0') - (str2[i] - '0') - carry);

            // If subtraction is less then zero
            // we add then we add 10 into sub and
            // take carry as 1 for calculating next step
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }

        // subtract remaining digits of larger number
        for (int i = n2; i < n1; i++) {
            int sub = ((str1[i] - '0') - carry);

            // if the sub value is -ve, then make it positive
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }

        while (len(str) and str.back() == '0') {
            str.pop_back();
        }

        // reverse resultant string
        reverse(str.begin(), str.end());

        return str;
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

