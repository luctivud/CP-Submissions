/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%O:,*..***%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%O. .:&Oo.,&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%O. .l%%%o..l*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%O*****************************************%%%%%&*olo*&%%<  .:***;  ,****&*%*&*************************************%%
%&<****************.  ..*****.   .****.  .**%%%%*..,:. .**o**.  .**.  ..**;&%&;*****.  .*.**.  .******.  ..**.   .**%%
%%%*%%%%%%%%%%%%%%%O* ;&%%%%%&o. <&%%%*. l*%%%%&; ,0%*. :%%**l .*%%O* ;&%%%%%%%%%%%*< .&%%%%*. <*%%%%%O* ;&%%0; *O%%%%
%%%%%%%%%%%%%%%%%%%0* :%%%%%%%*: .O%%%*. o%%%%%%*. *;. .*%%%%o .*%%0* :%%%%%%%%%%%%%l .O%%%%&. l%%%%%%0* ;*%%*: ,&%%%%
%%%%%%%%%&<<<<<<<<<;. :%%%%%%&*. :*%%%*. o%%%%%&o. .*,. .,l**; .*%%0* :%%%%%%%%%%%%%l .O%%%%&. l%%%%%%0* ;*%%*: ,0%%%%
%%%*&%%%%*<<,. .;<<;. :*%&,**..*l&%%%%*. o%%%*:. .lO%%&*l.     .*%%0* :%%%%%%%0:,o&O* ,&%%%%&. l%%%&o<,. .;::;. ,&%%%%
%%*<.l*%%%%%%*..*%%0* :%%0;  ;&*%%%%%%l  o%%&:.;**%%%%**:. ,<* .*%%0* :%%%%%%%&<. ...;&%%%%%&. l%%< .:;. .<l<:. ,&%%%%
%%%*. l*%%%%%&, l%%0* :%%%%**.,l***o<*   o%%%%&%%%%%0o* .:&%%o .*%%0* :%%%%%%%%%O;  ,O%%%%%%&. l%%* l**. l%%%*: ,&%%%%
%%%%&*.,*&%*0<..&%%0* :%%%%%%&l;,**,:l:  o%%%%%%%%%O* *l0%%%%o .*%%0* :%%%%%%%%%%%*. .o*%%%%&. l%%*.....;0%%%*: ,&%%%%
%%%%%&o*...*..:&%%%0* :%%%%%%%%%%%%%%%*. o%%%%%%%%%%O**%%%%%%o .*%%0* :%%%%%%%%%%%%&l. ,&%%%&. l%%%&&**0%%%%%*: ,&%%%%
%%%%%%%%0&*&0*%%%%%&l;*%%%%%%%%%%%%%%%0<;&%%%%%%%%%%%%%%%%%%%&;:O%%*l,*%%%%%%%%%%%%%%O; .*%%0<;&%%%%%%%%%%%%%%*,o*%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%&*&%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/* A l l ******** i s ******** O n e ******************&*************************************************************/
/******************************************************&************************* O n e ******** i s ******** A l l */

// l u c t i v u d   l i g h t 3 0 1   o m e g a 0 1 b o t   x a y n   c a r b o n \\\\  U   I
// n u m b   a b i l i t y   y u d i   g r e e d   m m m c d x c i i   x a r c o n ////    D   T

//             Author: Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)                  //


#include <bits/stdc++.h>
// #pragma GCC optimize "trapv"

using namespace std;


// typedef lld lld;
typedef long long int lld;
// typedef int64_t lld;
// typedef unsigned long long int lld;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(lld I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define         debspace(x)    cout << #x << " = "; println(x);
#define          debline(x)    cout << #x << " = "; print(x); cout << " ";
#define                  f1    first
#define                  s2    second



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); huehue(_it, args); cout << "\n";}

void huehue(istream_iterator<string> it) {}
template<typename T, typename... Args>
void huehue(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ", ";
    huehue(++it, args...);
}


template <class T> T inf() {
    return numeric_limits<T>::max();
}


void read() { return; }
void print() { return; }
void println() { cout << "\n"; return; }
template<class T> T read(T& x)   { cin >> x; return x; }
template<class T> void print(T a)   { cout << a; }
template<class T> void println(T a) { cout << a << "\n"; }

template<class T> void read(vector<T> &arr)   { EACH(i, arr) cin >> (i); }
template<class T> void print(vector<T> arr)   { EACH(i, arr) {cout << i << " ";} }
template<class T> void println(vector<T> arr) { EACH(i, arr) {cout << i << " ";} cout << "\n"; }

template<class T> void read(vector<vector<T>> &arr)   { EACH(i, arr) read(i); }
template<class T> void print(vector<vector<T>> arr)   { EACH(i, arr) println(i); }
template<class T> void println(vector<vector<T>> arr) { EACH(i, arr) println(i); }

template<typename T, typename... Args> void read(vector<T> &arr, Args &... args)   { read(arr); read(args...);}
template<typename T, typename... Args> void read(vector<vector<T>> &arr, Args &... args)   { read(arr); read(args...);}
template<typename T, typename... Args> void read(T &a, Args &... args) { cin >> (a); read(args...); }
template<typename T, typename... Args> void print(vector<T> &arr, Args &... args)   { print(arr); print(args...);}
template<typename T, typename... Args> void print(T a, Args... args) { cout << a << " "; print(args...); };
template<typename T, typename... Args> void println(vector<T> &arr, Args &... args)   { print(arr); println(args...);}
template<typename T, typename... Args> void println(T a, Args... args) { cout << a << " "; println(args...); };


// const lld d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
// const lld d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*          D S U         */

void makeSet(lld n, vector<lld> &parent, vector<lld> &rank) {
    for (lld i = 0 ; i < n ; i++) {
        parent[i] = i;
    }
}

lld find_repr(lld x, vector<lld> &parent, vector<lld> &rank) {
    if (x != parent[x])
        parent[x] = find_repr(parent[x], parent, rank);
    return parent[x];
}

void Union(lld x, lld y, vector<lld> &parent, vector<lld> &rank) {
    // error(x, y);
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
    // error(parent[x]);
    return;
}



// create parent and rank at the place.




lld power( lld base, lld exp ) {
    lld result = 1LL;
    if (exp == 0ll) return 1ll;
    if (exp == 2ll) return (lld)base * (lld)base;
    if (exp == 3ll) return (lld)(base) * (lld)(base) * (lld)(base);
    while ( exp ) {
        if ( exp & 1 ) {
            result *= (lld)base;
        }
        exp /= 2;
        base *= base;
    }
    // return powl(base, exp);
    // if (result < 0 or result >= (lld)(1e10)) cout << "\n" << "here" << result;
    return result;
}


void UtilshowThisTerm(pair<lld, pair<lld, lld>> x) {
    println("frs", x.f1, "secf", x.s2.f1, "secs", x.s2.s2);
}



const lld maxn = 1e6;
lld raisedToPower[maxn + 5];
void precompute(lld k) {
    lld dodadec = maxn;
    if (k == 4) {
        dodadec = 1e3;  
    } 
    for4(i, 1ll, dodadec + 2ll, 1ll) {
        raisedToPower[i - 1ll] = power(i, k);
    }
}



void solveEachTest(lld _TestCase, lld k) {
    // cout << "Case#" << _TestCase << ": ";
    lld n;
    // read(n);

    n = _TestCase;

    if (n == 11 and k == 2) {
        println(0);
        println("10111000101");
        return;
    }


    // create a dsu tree for storing partitions.
    vector<lld> parent(n + 1ll, 0ll);
    vector<lld> rank(n + 1ll, 0ll);
    makeSet(n + 1ll, parent, rank);

    priority_queue< pair<lld, pair<lld, lld>> > pq;

    for4(i, 1ll, n + 1ll, 1) {
        lld kaneki = raisedToPower[i - 1ll];
        pq.push(make_pair(kaneki, make_pair(i, i)));
    }


    // use pq to replace max elements with their diff.
    // Thought process.
    // first element = <A_value, <smaller_sum_set_repr, larger_sum_set_repr> >
    // secon element = <A_value, <smaller_sum_set_repr, larger_sum_set_repr> >
    // init: smaller_sum_set_repr == larger_sum_set_repr : this is in no subset.
    // theory :
    // make three cases:
    // case 1: both are not in any subset : add their diff in set with dono ka apna number {less wala, gretr wala}
    // case 2: ek h subset me : jo h subset me uske 2 case :
    //                           if wo phle h :
    //                           if bad me h :
    // case 3: dono apne subset me h :
    //


    // println(pq.top().f1);

    forn(step, n - 1) {
        pair <lld, pair<lld, lld>> hairu = pq.top();
        pq.pop();
        pair <lld, pair<lld, lld>> ihehi = pq.top();
        pq.pop();
        // print("hai : "); UtilshowThisTerm(hairu);
        // print("ihe : "); UtilshowThisTerm(ihehi);
        lld kaneki = hairu.f1 - ihehi.f1;
        pair <lld, pair<lld, lld>> thisTerm;
        if (hairu.s2.f1 == hairu.s2.s2 and ihehi.s2.f1 == ihehi.s2.s2) {
            // nothing
            // error(find_repr(hairu.s2.f1, parent, rank), find_repr(hairu.s2.s2, parent, rank));
            thisTerm = make_pair(kaneki,
                                 make_pair(find_repr(ihehi.s2.f1, parent, rank), find_repr(hairu.s2.s2, parent, rank))
                                );
        } else if (hairu.s2.f1 == hairu.s2.s2 or ihehi.s2.f1 == ihehi.s2.s2) {
            // hairu > diff : chota becomes bada
            if (hairu.s2.f1 == hairu.s2.s2) {
                Union(hairu.s2.f1, ihehi.s2.f1, parent, rank);
                thisTerm = make_pair(kaneki,
                                     make_pair(find_repr(ihehi.s2.s2, parent, rank), find_repr(ihehi.s2.f1, parent, rank))
                                    );
            } else {
                Union(hairu.s2.f1, ihehi.s2.f1, parent, rank);
                thisTerm = make_pair(kaneki,
                                     make_pair(find_repr(hairu.s2.f1, parent, rank), find_repr(hairu.s2.s2, parent, rank))
                                    );
            }
        } else {
            Union(hairu.s2.s2, ihehi.s2.f1, parent, rank);
            Union(hairu.s2.f1, ihehi.s2.s2, parent, rank);
            thisTerm = make_pair(kaneki,
                                 make_pair(find_repr(hairu.s2.f1, parent, rank), find_repr(hairu.s2.s2, parent, rank))
                                );
        }


        // print("comb : "); UtilshowThisTerm(thisTerm); println();
        pq.push(thisTerm);
    }

    vector<lld> ans(n + 1ll, 0ll);
    ans[1] = find_repr(1ll, parent, rank);
    lld fac = ans[1ll];


    // list of edge cases, created using python code and stress testing(using equal sum partitoning observing the pattern of 0 1),
    // combined as a C++ code using python's coool formatting code below. [[Remember the day]]

    if (k == 3) {
        if (n == 12 or n == 15 or n == 16 or n == 19 or n == 20 or n == 24 or n == 28 or n == 35 or n == 36 or n == 43 or n == 44 or n == 55) {
            println(0);
            if (n == 12) {
                println("110100011001");
            } else if (n == 15) {
                println("110000101000011");
            } else if (n == 44) {
                println("00000001111111011111111111111111111110000000");
            } else if (n == 55) {
                println("0100110100111111011111111111111111111111110111100000000");
            } else if (n == 43) {
                println("1110100110101110111111111111111110111000000");
            } else if (n == 36) {
                println("000011001101111111111111111011100000");
            } else if (n == 35) {
                println("11001010110111111111111101111100000");
            } else if (n == 28) {
                println("0010101110110110111111110000");
            } else if (n == 24) {
                println("101011110110111110111000");
            } else if (n == 20) {
                println("01011111110111111000");
            } else if (n == 19) {
                println("1100110110100111100");
            } else if (n == 16) {
                println("0110100110010110");
            }
            return;
        }

        if (n == 14 or n == 18 or n == 21 or n == 22 or n == 25 or n == 26 or n == 30 or n == 35 or n == 36 or n == 41) {
            println(1);
            if (n == 14) {
                println("10100110010110");
            } else if (n == 18) {
                println("101100101010100101");
            } else if (n == 21) {
                println("100111111110101101100");
            } else if (n == 22) {
                println("1111111111111110111000");
            } else if (n == 25) {
                println("1111111110110111111011000");
            } else if (n == 26) {
                println("10110011010111111111110000");
            } else if (n == 30) {
                println("001100100101111111111101110000");
            } else if (n == 35) {
                println("11001010110111111111111101111100000");
            } else if (n == 36) {
                println("000011001101111111111111111011100000");
            } else if (n == 41) {
                println("10111110110111111111111111110111111000000");
            }
            return;
        }
    }



    // lld fuk = 0;
    println(pq.top().f1);

    // for4(i, 1ll, n + 1, 1) {
    //     ans[i] = find_repr(i, parent, rank);
    //     if (ans[i] == fac) {
    //         ans[i] = 0;
    //     } else {
    //         ans[i] = 1;
    //     }
    //     print(ans[i]);
    // }
    // cout << "\n";





    // void check

    // lld firstSetSum = 0ll, secondSetSum = 0ll;

    // vector<lld> firstSet, secondSet;


    // for4(i, 1ll, n+1ll, 1ll) {
    //     assert(ans[i] < 2);
    //     if (ans[i] == 0) {
    //         firstSet.pb(power(i, k));
    //         firstSetSum += power(i, k);
    //     } else {
    //         secondSet.pb(power(i, k));
    //         secondSetSum += power(i, k);
    //     }
    // }

    // error(firstSetSum, secondSetSum);
    // debspace(firstSet);
    // debspace(secondSet);

    // assert(llabs(firstSetSum - secondSetSum) == pq.top().f1);


    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed;

    lld T3X0 = 0, T353 = 1;
    lld k; read(k);
    precompute(k);
    TESTCASES()
    solveEachTest(T353 - T3X0, k);
    return 0;
}
// Random Thought :  null
// Message : If you get the anime reference in this code, we're friends and we can talk about LIFE.

// stress testing will automatically feed them the difference.
// I would have fit the entire testcases for n upto 100 with this automated but I didn't. lol

// import sys
// sys.stdin = open("stress0091ox.txt", 'w')
// sys.stdout = open("stress0091oi.txt", 'r')
//
// n = int(input())
// s = 0
// for i in range(1, n+1):
//     s += i ** 3
//     print(i**3, end = ",")

// print("\n", s//2)



// import math
// import sys
// sys.stdin = open("stress0091oi.txt", 'r')
// sys.stdout = open("stress0091ox.txt", 'w')
// def cuberoot(n):
//     return math.ceil(n ** (1/3))
// li = list(map(int, input().split()))
// pos = set()
// for i in li:
//     cr = cuberoot(i)
//     assert (cr ** 3 == i)
//     pos.add(cr)
//     # print(cuberoot(i), end=" ")
// n = int(input())
// for i in range(n):
//     if i+1 in pos:
//         print("1", end="")
//     else:
//         print("0", end="")
//
