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

//             Author: Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)                  //



#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T> using PBSET = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*  
    .insert(el) - set hai!
    .find_by_order(3) - returns an iterator to the k-th largest element (counting from zero)
    .order_of_key(6) - the number of items in a set that are strictly smaller than our item
*/

typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
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


const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


map<lld,lld> leekiee;
void precompute() {
    forn(i, lld(1e5)) {
        leekiee[(i * (i+1)) / 2] = i;
    }
    return;
}



void solveEachTest(lld _TestCase = 1) {
    // cout << "Case#" << _TestCase << ": ";
    
    // lld n; read(n);

    for4(n, 1, 100, 1) { //////////////////////
    
    if (n % 4 == 3 or n % 4 == 0) {
        lld thissum = (n * (n+1)) / 4;
        lld ans = 0ll;
        if (leekiee.find(thissum) != leekiee.end()) {
            lld temp = n - leekiee[thissum];
            lld temp2 = leekiee[thissum];
            ans += (temp * (temp-1)) / 2;
            ans += (temp2 * (temp2 - 1)) / 2;
        } else if (n % 24 == 20) {
        	ans += 1;
        }
        ans += n / 24;
        ans += (n + 3) / 4 + 1;
        if (n == 3) ans -= 1;
        println(n, ans);
    } else {
        println(n, "0");
    }

	} //////////////////////

    // cout << "\n"; 
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.precision(10); cout<<fixed;

    lld T3X0 = 0, T353 = 1;
    precompute();
    TESTCASES() 
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought :  null  


// #include<bits/stdc++.h> 
// using namespace std; 
  
// // Returns split point. If not possible, then 
// // return -1. 

// int ans = 0;
// int findSplitPoint(vector<int>&arr, int n) 
// { 
//     // traverse array element and compute sum 
//     // of whole array 
//     int leftSum = 0; 
//     for (int i = 0 ; i < n ; i++) 
//         leftSum += arr[i]; 
  
//     // again traverse array and compute right sum 
//     // and also check left_sum equal to right 
//     // sum or not 
//     int rightSum = 0; 
//     for (int i=n-1; i >= 0; i--) 
//     { 
//         // add current element to right_sum 
//         rightSum += arr[i]; 
  
//         // exclude current element to the left_sum 
//         leftSum -=  arr[i] ; 
  
//         if (rightSum == leftSum) 
//             return i ; 
//     } 
  
//     // if it is not possible to split array 
//     // into two parts. 
//     return -1; 
// } 
  
// // Prints two parts after finding split point using 
// // findSplitPoint() 
// void printTwoParts(vector<int> &arr, int n) 
// { 
//     int splitPoint = findSplitPoint(arr, n); 
  
//     if (splitPoint == -1 || splitPoint == n ) 
//     { 
//         // cout << "Not Possible" <<endl; 
//         return; 
//     } 
//     ans++;
// } 
  
// // driver program 

// #define all(arr) (arr).begin(), (arr).end()
// int main() 
// { 
//     int ssr; cin >> ssr;
//     for (int ss = 1; ss < ssr; ss++) {
//         ans = 0;
//         vector<int> arr(ss); 
//         iota(all(arr), 1);

//         // for(auto i : arr) {
//         //     cout << i << " ";
//         // }
//         // vector<int> arr {1, 2, 3, 4};
//         int n = int(arr.size());
//         for (int i = 0; i<n; i++) {
//             for (int j = i+1; j < n; j++) {
//                 vector<int> brr{arr};
//                 swap(brr[i], brr[j]);
//                 printTwoParts(brr, n); 
//             }
//         }
//         cout <<  "(" << ss << " " << ans <<  "), ";
//         if (ss % 4 == 0) cout << "\n";
//     }
//     return 0; 
// } 

// (1 0), (2 0), (3 2), (4 2), 
// (5 0), (6 0), (7 3), (8 3), 
// (9 0), (10 0), (11 4), (12 4), 
// (13 0), (14 0), (15 5), (16 5), 
// (17 0), (18 0), (19 6), (20 112), 
// (21 0), (22 0), (23 7), (24 8), 
// (25 0), (26 0), (27 9), (28 9), 
// (29 0), (30 0), (31 10), (32 10), 
// (33 0), (34 0), (35 11), (36 11), 
// (37 0), (38 0), (39 12), (40 12), 
// (41 0), (42 0), (43 13), (44 14), 
// (45 0), (46 0), (47 14), (48 15), 
// (49 0), (50 0), (51 16), (52 16), 
// (53 0), (54 0), (55 17), (56 17), 
// (57 0), (58 0), (59 18), (60 18), 
// (61 0), (62 0), (63 19), (64 19), 
// (65 0), (66 0), (67 20), (68 21), 
// (69 0), (70 0), (71 21), (72 22), 
// (73 0), (74 0), (75 23), (76 23), 
// (77 0), (78 0), (79 24), (80 24), 
// (81 0), (82 0), (83 25), (84 25), 
// (85 0), (86 0), (87 26), (88 26), 
// (89 0), (90 0), (91 27), (92 28), 
// (93 0), (94 0), (95 28), (96 29), 
// (97 0), (98 0), (99 30), (100 30), 
// (101 0), (102 0), (103 31), (104 31), 
// (105 0), (106 0), (107 32), (108 32), 
// (109 0), (110 0), (111 33), (112 33), 
// (113 0), (114 0), (115 34), (116 35), 
// (117 0), (118 0), (119 4116), (120 36), 
// (121 0), (122 0), (123 37), (124 37), 
// (125 0), (126 0), (127 38), (128 38), 
// (129 0), (130 0), (131 39), (132 39), 
// (133 0), (134 0), (135 40), (136 40), 
// (137 0), (138 0), (139 41), (140 42), 
// (141 0), (142 0), (143 43), (144 43), 
// (145 0), (146 0), (147 44), (148 44), 
// (149 0), (150 0), (151 45), (152 45), 
// (153 0), (154 0), (155 46), (156 46), 
// (157 0), (158 0), (159 47), (160 48), 
// (161 0), (162 0), (163 48), (164 49), 
// (165 0), (166 0), (167 50), (168 50), 
// (169 0), (170 0), (171 51), (172 51), 
// (173 0), (174 0), (175 52), (176 52), 
// (177 0), (178 0), (179 53), (180 53), 
// (181 0), (182 0), (183 54), (184 55), 
// (185 0), (186 0), (187 55), (188 56), 
// (189 0), (190 0), (191 57), (192 57), 
// (193 0), (194 0), (195 58), (196 58), 
// (197 0), (198 0), (199 59), (200 59), 
// (201 0), (202 0), (203 60), (204 60), 
// (205 0), (206 0), (207 61), (208 62), 
// (209 0), (210 0), (211 62), (212 63), 
// (213 0), (214 0), (215 64), (216 64), 
// (217 0), (218 0), (219 65), (220 65), 
// (221 0), (222 0), (223 66), (224 66), 
// (225 0), (226 0), (227 67), (228 67), 
// (229 0), (230 0), (231 68), (232 69), 
// (233 0), (234 0), (235 69), (236 70), 
// (237 0), (238 0), (239 71), (240 71), 
// (241 0), (242 0), (243 72), (244 72), 
// (245 0), (246 0), (247 73), (248 73), 
// (249 0), 