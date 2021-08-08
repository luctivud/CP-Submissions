// ------------------------------------------------------------------- //
/*

      Author :  Udit "luctivud" Gupta
    Linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
      Github :  https://github.com/luctivud

*/
// ------------------------------------------------------------------- //



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
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,bmi,bmi2,lzcnt")
// #pragma GCC optimize "trapv"






/*  Snips   */


typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second



/*  Utils   */


const lld MOD = int(1e9) + 7;
const lld &mod = MOD;

const long double EPS = 1e-6;

const lld inf = 2e18;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



signed pleaseAC(void) {

#ifdef LUCTIVUD
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff = end_time - start_time;
    // cerr << "Finished in : " << diff.count() << "\n";
#endif

    return 0;
}


void IAmJustice(void) {
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

#ifdef LUCTIVUD
    // const auto start_time = std::chrono::high_resolution_clock::now();
    freopen("/home/luctivud/CPPractice/IO/Zinput.txt", "r", stdin);
    freopen("/home/luctivud/CPPractice/IO/Zoutput.txt", "w", stdout);
#endif

    return;
}



#define int lld




#define N 100005
// predefines the tree with nodes
// storing min and count
struct node {
    int min, cnt;
    int min2 = inf, cnt2 = 0;
} tree[5 * N];

// function to construct the tree
void buildtree(int low, int high, int pos, int a[])
{
    // base condition
    if (low == high) {

        // leaf node has a single element
        tree[pos].min = a[low];
        tree[pos].cnt = 1;
        tree[pos].cnt2 = 0;
        return;
    }

    int mid = (low + high) >> 1;
    // left-subtree
    buildtree(low, mid, 2 * pos + 1, a);

    // right-subtree
    buildtree(mid + 1, high, 2 * pos + 2, a);

    // left subtree has the minimum element
    if (tree[2 * pos + 1].min < tree[2 * pos + 2].min) {
        if (tree[2*pos+1].min2 < tree[2*pos+2].min) {
            tree[pos].min2 = tree[2*pos+1].min2;
            tree[pos].cnt2 = tree[2*pos+1].cnt2;
        } else if (tree[2*pos+1].min2 > tree[2*pos+2].min) {
            tree[pos].min2 = tree[2*pos+2].min;
            tree[pos].cnt2 = tree[2*pos+2].cnt;
        } else {
            tree[pos].min2 = tree[2*pos+2].min;
            tree[pos].cnt2 = tree[2*pos+2].cnt + tree[2*pos+1].cnt2;
        }
        tree[pos].min = tree[2 * pos + 1].min;
        tree[pos].cnt = tree[2 * pos + 1].cnt;
    }

    // right subtree has the minimum element
    else if (tree[2 * pos + 1].min > tree[2 * pos + 2].min) {
        if (tree[2*pos+1].min < tree[2*pos+2].min2) {
            tree[pos].min2 = tree[2*pos+1].min;
            tree[pos].cnt2 = tree[2*pos+1].cnt;
        } else if (tree[2*pos+1].min2 > tree[2*pos+2].min) {
            tree[pos].min2 = tree[2*pos+2].min2;
            tree[pos].cnt2 = tree[2*pos+2].cnt2;
        } else {
            tree[pos].min2 = tree[2*pos+2].min2;
            tree[pos].cnt2 = tree[2*pos+2].cnt2 + tree[2*pos+1].cnt;
        }
        tree[pos].min = tree[2 * pos + 2].min;
        tree[pos].cnt = tree[2 * pos + 2].cnt;
    }

    // both subtree has the same minimum element
    else {
        if (tree[2*pos+1].min2 < tree[2*pos+2].min2) {
            tree[pos].min2 = tree[2*pos+1].min2;
            tree[pos].cnt2 = tree[2*pos+1].cnt2;
        } else if (tree[2*pos+1].min2 > tree[2*pos+2].min2) {
            tree[pos].min2 = tree[2*pos+2].min2;
            tree[pos].cnt2 = tree[2*pos+2].cnt2;
        } else {
            tree[pos].min2 = tree[2*pos+2].min2;
            tree[pos].cnt2 = tree[2*pos+2].cnt2 + tree[2*pos+1].cnt2;
        }
        tree[pos].min = tree[2 * pos + 1].min;
        tree[pos].cnt = tree[2 * pos + 1].cnt + tree[2 * pos + 2].cnt;
    }
}

// function that answers every query
node query(int s, int e, int low, int high, int pos)
{
    node dummy;
    // out of range
    if (e < low or s > high) {
        dummy.min = dummy.cnt = inf;
        return dummy;
    }

    // in range
    if (s >= low and e <= high) {
        return tree[pos];
    }

    int mid = (s + e) >> 1;

    // left-subtree
    node ans1 = query(s, mid, low, high, 2 * pos + 1);

    // right-subtree
    node ans2 = query(mid + 1, e, low, high, 2 * pos + 2);

    node ans;
    ans.min = min(ans1.min, ans2.min);

    // add count when min is same of both subtree
    if (ans1.min == ans2.min)
        ans.cnt = ans2.cnt + ans1.cnt;

    // store the minimal's count
    else if (ans1.min < ans2.min)
        ans.cnt = ans1.cnt;

    else
        ans.cnt = ans2.cnt;

    return ans;
}

// function to answer query in range l-r
int answerQuery(int a[], int n, int l, int r)
{
    // calls the function which returns a node
    // this function returns the count which
    // will be the answer
    node res = query(0, n - 1, l - 1, r - 1, 0);
    if (res.cnt > 1) {
        return (res.cnt * (res.cnt - 1)) / 2;
    } else {
        return res.cnt2;
    }
}





/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n, q; cin >> n >> q;
    lld arr[n];
    forn(i, n) {
        cin >> arr[i];
    }

    lld ans = 0ll;
    forn(qq, q) {
        lld t, x, y; cin >> t >> x >> y;
        --x;
        if (t == 1) {
            arr[x] = y;
        } else {
            lld cntMin1 = 0ll, cntMin2 = 0ll, min2 = inf, min1 = inf;
            for (lld i = x; i < y; i++) {
                if (arr[i] < min1) {
                    min2 = min1;
                    cntMin2 = cntMin1;
                    min1 = arr[i];
                    cntMin1 = 1;
                } else if (arr[i] == min1) {
                    cntMin1 += 1;
                } else if (arr[i] < min2) {
                    min2 = arr[i];
                    cntMin2 = 1;
                } else if (arr[i] == min2) {
                    cntMin2 += 1;
                }
            } 
            // _____error_____(min1, min2, cntMin1, cntMin2);
            if (cntMin1 > 1) {
                (ans += ((cntMin1 * (cntMin1 - 1)) / 2)) %= mod;
            } else {
                (ans += (cntMin1 * cntMin2)) %= mod;
            }
        }
    }

    cout << ans;

    
    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    IAmJustice();

    int _T0T4 = 1;
    cin >> _T0T4; 
    
    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n";
    }

    return pleaseAC(); 
}




/*  ~~
    I ponder of something great
    My lungs will fill and then deflate
    They fill with fire, exhale desire
    I know it's dire my time today

    I have these thoughts, so often I ought
    To replace that slot with what I once bought
    'Cause somebody stole my car radio
    And now I just sit in silence

    Sometimes quiet is violent
    I find it hard to hide it
    My pride is no longer inside
    It's on my sleeve
    My skin will scream reminding me of
    Who I killed inside my dream
    I hate this car that I'm driving
    There's no hiding for me
    I'm forced to deal with what I feel
    There is no distraction to mask what is real
    I could pull the steering wheel

*/
