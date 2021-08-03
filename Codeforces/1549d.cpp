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




// #define int lld



/* This part should be outside the main in global paradigm. */

const long long MAXN = (lld)(1e5) + 1ll; // MAXN Size

vector<long long >isPrime(MAXN , true); // checkIfPrime
vector<long long >prime_numbers; // List of prime numbers
vector<long long >smallest_prime_factor(MAXN); // smallest_prime_factor of a number


void manipulated_seive() {
    isPrime[0] = isPrime[1] = false ;
    
    prime_numbers.push_back(2);
    smallest_prime_factor[2] = 2ll;

    for (long long int i=4; i < MAXN ; i+=2) {
        isPrime[i] = false;
        smallest_prime_factor[i] = 2ll;
    }

    for (long long int i = 3; i < MAXN ; i+=2) {
        if (isPrime[i]) {
            prime_numbers.push_back(i);
            smallest_prime_factor[i] = i;
        }

        for (long long int j = 0; j < (int)prime_numbers.size() && i * prime_numbers[j] < MAXN && prime_numbers[j] <= smallest_prime_factor[i]; j++) {
            isPrime[i * prime_numbers[j]] = false;
            smallest_prime_factor[i * prime_numbers[j]] = prime_numbers[j] ;
        }
    }
}


/* This should be called inside main. */





/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/

class Solution {
    static const int maxN = int(1e5) + 2;
    const lld inf = 1e18;
public:
    Solution() {
        manipulated_seive();
    }
public:
    void SolveEachTest(int _TestCase) {
        // cout << "Case #" << _TestCase << ": ";
        lld n; cin >> n;
        int arr[n];
        forn(i, n) {
            cin >> arr[i];
        }

        // _____error_____(prime_numbers.size());
        lld ans = 1ll;
        forn(i, 501) {
            lld res = 0ll, prv = -1ll;
            forn(j, n) {
                if (prv == arr[j] % prime_numbers[i]) {
                    res += 1;
                } else {
                    res = 1;
                }
                prv = arr[j] % prime_numbers[i];
                ans = max(ans, res);
            }
        }

        cout << ans;

        // int *st = constructST(arr, n);

        // lld lo = 1, hi = n;
        // lld ans = 1;

        // while (lo <= hi) {

        // }

        // RMQ(st, n, qs, qe)
    }

public:
    void ResetTestCase() {
        cout << "\n";
    }
    int minVal(int x, int y) { return (x < y) ? x : y; }
    int getMid(int s, int e) { return s + (e - s) / 2; }

    int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
    {
        // If segment of this node is a part
        if (qs <= ss && qe >= se)
            return st[index];

        // If segment of this node
        // is outside the given range
        if (se < qs || ss > qe)
            return INT_MAX;

        // If a part of this segment
        // overlaps with the given range
        int mid = getMid(ss, se);
        return minVal(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1),
                      RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2));
    }

// Return minimum of elements in range
// from index qs (query start) to
// qe (query end). It mainly uses RMQUtil()
    int RMQ(int *st, int n, int qs, int qe)
    {
        // Check for erroneous input values
        if (qs < 0 || qe > n - 1 || qs > qe)
        {
            return -1;
        }

        return RMQUtil(st, 0, n - 1, qs, qe, 0);
    }

// A recursive function that constructs
// Segment Tree for array[ss..se].
// si is index of current node in segment tree st
    int constructSTUtil(int arr[], int ss, int se,
                        int *st, int si)
    {
        // If there is one element in array,
        // store it in current node of
        // segment tree and return
        if (ss == se)
        {
            st[si] = arr[ss];
            return arr[ss];
        }

        // If there are more than one elements,
        // then recur for left and right subtrees
        // and store the minimum of two values in this node
        int mid = getMid(ss, se);
        st[si] = minVal(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
                        constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
        return st[si];
    }

    /* Function to construct segment tree
    from given array. This function allocates
    memory for segment tree and calls constructSTUtil() to
    fill the allocated memory */
    int *constructST(int arr[], int n)
    {
        // Allocate memory for segment tree

        //Height of segment tree
        int x = (int)(ceil(log2(n)));

        // Maximum size of segment tree
        int max_size = 2 * (int)pow(2, x) - 1;

        int *st = new int[max_size];

        // Fill the allocated memory st
        constructSTUtil(arr, 0, n - 1, st, 0);

        // Return the constructed segment tree
        return st;
    }

    int getGcdUtil(int* st, int ss, int se, int qs, int qe, int si)
    {
        // If segment of this node is a part of given range
        // then return the gcd of the segment
        if (qs <= ss && qe >= se)
            return st[si];

        // If segment of this node is outside the given range
        if (se < qs || ss > qe)
            return 0;

        // If a part of this segment overlaps with the given range
        int mid = getMid(ss, se);
        return __gcd(getGcdUtil(st, ss, mid, qs, qe, 2 * si + 1),
                     getGcdUtil(st, mid + 1, se, qs, qe, 2 * si + 2));
    }

    int getGcd(int* st, int n, int qs, int qe)
    {

        // Check for erroneous input values
        if (qs < 0 || qe > n - 1 || qs > qe) {
            return -1;
        }

        return getGcdUtil(st, 0, n - 1, qs, qe, 0);
    }

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
    int constructGcdUtil(int arr[], int ss, int se, int* st, int si)
    {
        // If there is one element in array, store it in current node of
        // segment tree and return
        if (ss == se) {
            st[si] = arr[ss];
            return arr[ss];
        }

        // If there are more than one element then recur for left and
        // right subtrees and store the sum of values in this node
        int mid = getMid(ss, se);
        st[si] = __gcd(constructGcdUtil(arr, ss, mid, st, si * 2 + 1),
                       constructGcdUtil(arr, mid + 1, se, st, si * 2 + 2));
        return st[si];
    }

// Function to construct segment tree from given array. This function
// allocates memory for segment tree and calls constructSTUtil() to
// fill the allocated memory
    int* constructGcd(int arr[], int n)
    {
        // Allocate memory for the segment tree

        // Height of segment tree
        int x = (int)(ceil(log2(n)));

        // Maximum size of segment tree
        int max_size = 2 * (int)pow(2, x) - 1;

        // Allocate memory
        int* st = new int[max_size];

        // Fill the allocated memory st
        constructGcdUtil(arr, 0, n - 1, st, 0);

        // Return the constructed segment tree
        return st;
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

