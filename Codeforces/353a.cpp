// ************************.- J A I  S H R E E  R A M -.*************************


/* 
      ::: All is One ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

          Author   :  Udit "luctivud" Gupta 

          linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
          github   :  https://github.com/luctivud

      :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: One is All :::
*/


#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
#pragma GCC optimize ("Ofast")
// #pragma GCC target ("fpmath=sse,sse2")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")


using namespace std;



typedef long long int lld;
typedef unsigned long long int llu;
// #define int lld

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define         debhairu(x)    cout << #x << " = "; Print_Valueln(x);
#define         debspace(x)    cout << #x << " = "; Print_Value(x); cout << " ";
#define                  f1    first
#define                  s2    second
#define           PLEASE_AC    return



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



void Read_Int() { return; }
void Print_Value() { return; }
void Print_Valueln() { cout << "\n"; return; }
template<class T> T Read_Int(T& x)   { cin >> x; return x; }
template<class T> void Print_Value(T a)   { cout << a; }
template<class T> void Print_Valueln(T a) { cout << a << "\n"; }

template<class T> void Read_Int(vector<T> &arr)   { EACH(i, arr) cin >> (i); }
template<class T> void Print_Value(vector<T> arr)   { EACH(i, arr) {cout << i << " ";} }
template<class T> void Print_Valueln(vector<T> arr) { EACH(i, arr) {cout << i << " ";} cout << "\n"; }

template<class T> void Read_Int(vector<vector<T>> &arr)   { EACH(i, arr) Read_Int(i); }
template<class T> void Print_Value(vector<vector<T>> arr)   { EACH(i, arr) Print_Valueln(i); }
template<class T> void Print_Valueln(vector<vector<T>> arr) { EACH(i, arr) Print_Valueln(i); }

template<typename T, typename... Args> void Read_Int(vector<T> &arr, Args &... args)   { Read_Int(arr); Read_Int(args...);}
template<typename T, typename... Args> void Read_Int(vector<vector<T>> &arr, Args &... args)   { Read_Int(arr); Read_Int(args...);}
template<typename T, typename... Args> void Read_Int(T &a, Args &... args) { cin >> (a); Read_Int(args...); }
template<typename T, typename... Args> void Print_Value(vector<T> &arr, Args &... args)   { Print_Value(arr); Print_Value(args...);}
template<typename T, typename... Args> void Print_Value(T a, Args... args) { cout << a << " "; Print_Value(args...); };
template<typename T, typename... Args> void Print_Valueln(vector<T> &arr, Args &... args)   { Print_Value(arr); Print_Valueln(args...);}
template<typename T, typename... Args> void Print_Valueln(T a, Args... args) { cout << a << " "; Print_Valueln(args...); };


const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};



const auto start_time = std::chrono::high_resolution_clock::now();

signed light() {

    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    return 0; 
}


signed luctivud() {

    #ifdef LUCTIVUD
      auto end_time = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> diff = end_time - start_time;
      cerr << "Finished in : " << diff.count() << "\n";
    #endif

  return 0; 
}



const lld MOD = lld(1e9) + 7ll;
const lld mod = MOD;
lld TempVar;

const long double EPS = 1e-6;

const lld INFll = inf<lld>();
const int INFi = inf<int>();


void add_undirected_edge(lld a, lld b, vector<lld> adj[]) {
    adj[a].pb(b);
    adj[b].pb(a);
    return;
}



/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/




int One = 1;
int Zero = 0;


void SolveEachTest(int _TestCase) {

    int Num; Read_Int(Num);

    bool Flag = false;
    int SumA = Zero, SumB = Zero;

    for (int Itr = Zero; Itr < Num; Itr++) {
    	int ANum, BNum; Read_Int(ANum, BNum);
    	if ((ANum & One) ^ (BNum & One))
    		Flag = true;
    	SumA += ANum, SumB += BNum;
    	SumA &= One, SumB &= One;
    }

    char OnePossible[] = "1", NotPossible[] = "-1", AlreadyPossible[] = "0";

    if (!SumA & !SumB) Print_Value(AlreadyPossible, "\n");
    else if (SumA & SumB)
    	if (Flag) Print_Value(OnePossible, "\n");
    	else Print_Value(NotPossible, "\n");
    else Print_Value(NotPossible, "\n");

    return;
}


signed main() {
    light(); int T3X0 = 0, T353 = 1;
    // TESTCASES() 
        SolveEachTest(T353 - T3X0);
    PLEASE_AC luctivud(); 
}

/*        0.2s   Domain Expansion:  
                            SELF EMBODIMENT OF PERFECTION     */
