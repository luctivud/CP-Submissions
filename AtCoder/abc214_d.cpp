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
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4,popcnt,lzcnt")
// #pragma GCC optimize "trapv"






/*  Snips   */


typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
// #define        len(v) ((int)((v).sz()))
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


// Declaring sz array globally
int sz[300005];
int freq[300004];

vector<pair<int, pair<int, int> > > edges;

// Initializing DSU data structure
void initialize(int Arr[], int N)
{
    for (int i = 0; i < N; i++) {
        Arr[i] = i;
        sz[i] = 1;
    }
}

// Function to find the root of ith
// node in the disjoint set
int root(int Arr[], int i)
{
    while (Arr[i] != i) {
        i = Arr[i];
    }
    return i;
}

// Weighted union using Path Compression
void weighted_union(int Arr[],
                    int sz[], int A, int B)
{
    int root_A = root(Arr, A);
    int root_B = root(Arr, B);

    // sz of set A is small than sz of set B
    if (sz[root_A] < sz[root_B]) {
        Arr[root_A] = Arr[root_B];
        sz[root_B] += sz[root_A];
    }

    // sz of set B is small than sz of set A
    else {
        Arr[root_B] = Arr[root_A];
        sz[root_A] += sz[root_B];
    }
}

// Function to add an edge in the tree
void AddEdge(int a, int b, int w)
{
    edges.push_back({ w, { a, b } });
}








/*:::::::::::::::::::::: LOGIC :::::::::::::::::::::::::*/





void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;
    forn(i, n - 1) {
        lld a, b, w; cin >> a >> b >> w;
        AddEdge(a, b, w);
    }

    initialize(freq, n);
    lld result = 0ll;
    // Sorting the edges with respect to its weight
    sort(edges.begin(), edges.end());

    // Start iterating in decreasing order of weight
    for (int i = 0; i < n-1; i++) {

        // Determine Current edge values
        int curr_weight = edges[i].first;
        int Node1 = edges[i].second.first;
        int Node2 = edges[i].second.second;

        // Calculate root of each node
        // and sz of each set
        int Root1 = root(freq, Node1);
        int Set1_size = sz[Root1];
        int Root2 = root(freq, Node2);
        int Set2_size = sz[Root2];

        // Using the formula
        _____error_____(curr_weight);
        
        int prod = Set1_size * Set2_size;
        int Product = curr_weight * prod; //power(curr_weight, prod, mod);

        // Calculating final result
        result += Product;

        // Weighted union using Path Compression
        weighted_union(freq, sz, Node1, Node2);
    }

    cout << result;

    return;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/


signed main() {

    IAmJustice();

    int _T0T4 = 1;
    // cin >> _T0T4;

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
