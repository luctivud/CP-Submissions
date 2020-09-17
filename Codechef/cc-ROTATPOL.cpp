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

// l u c t i v u d   l i g h t 3 0 1   o m e g a 0 1 b o t   x a y n   c a r b o n \\\\  /U\   /I\   /
// n u m b   a b i l i t y   y u d i   g r e e d   m m m c d x c i i   x a r c o n //// /   \D/   \T/

//             Author: Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)                  //




// unoptimised solution just to check logic.

#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;



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

const long double EPS = 1e-8;

lld n; 
map<long double, lld> XYRatio_Up;
map<long double, lld> XYRatio_Low;
lld flag_X_Pos, flag_Y_pos, flag_Y_neg, flag_X_Neg;
vector<pair<lld,lld>> arr;
vector<pair<lld,lld>> DirectedVectors;
lld ANS_X, ANS_Y;
bool ok = false;



void UtilPrintThis(vector<pair<lld,lld>> nope) {
	EACH(it, nope) {
		println("F", it.f1, "S", it.s2, "ratio", -(double)it.s2 / (double)it.f1, "chosen", 2*it.f1-it.s2);
	}
}

void UtilPrintThisBound(map<long double, lld> nope) {
    EACH(it, nope) {
        println("F", it.f1, "S", it.s2);
    }
}


void set_bounds(lld ind) {
    if ((ind) == n-1 or ind == 0) return;
    pair<lld, lld> hairu = DirectedVectors[ind];
    if (hairu.f1 == 0 or hairu.s2 == 0) {
        if (hairu.f1 == 0) {
            if (hairu.s2 < 0) {
                flag_Y_neg += 1;
            } else {
                flag_Y_pos += 1;
            }
        } else {
            if (hairu.f1 < 0) {
                flag_X_Neg += 1;
            } else {
                flag_X_Pos += 1;
            }
        }
    } else {
        if (hairu.f1 > 0) {
            XYRatio_Low[-(long double)(hairu.s2)/(long double)(hairu.f1)] += 1;
        } else {
            if (hairu.s2 > 0) {
                XYRatio_Up[(long double)(hairu.s2)/(long double)(-hairu.f1)] += 1;
            } else {
                XYRatio_Up[(long double)(-hairu.s2)/(long double)(hairu.f1)] += 1;
            }
        }
    }
}


bool isValidBound() {
    if ((flag_X_Pos and flag_X_Neg) or (flag_Y_pos and flag_Y_neg)) {
        return false;
    }

    if ((len(XYRatio_Up) == 0) or (len(XYRatio_Low) == 0)) {
        return true;
    }

    if (flag_X_Pos and flag_Y_pos and (*XYRatio_Up.begin()).f1 < 0) {
        return false;
    } 

    if (flag_Y_neg and flag_X_Neg and ((*XYRatio_Low.rbegin()).f1) > 0) {
        return false;
    }


    if ((*XYRatio_Low.rbegin()).f1 > (*XYRatio_Up.begin()).f1) {
        return false;
    }

    // println("eh");
    return true;

}



void Set_Ans() {

    long double X_temp ;
    ANS_Y = lld(1e8);


    if (len(XYRatio_Low) > 0) {
        X_temp = (*XYRatio_Low.rbegin()).f1 + EPS;
    } else if (len(XYRatio_Up) > 0) {
        X_temp = (*XYRatio_Up.begin()).f1 - EPS;
    } else {
        if (flag_X_Neg) {
            ANS_X = -1; 
        } else {
            ANS_X = 1;
        }
        if (flag_Y_neg) {
            ANS_Y = -1;
        } else {
            ANS_Y = 1;
        }
        return;
    }


    ANS_X = (lld)((long double)(ANS_Y) * (X_temp));
    lld gcdTemp = __gcd(ANS_Y, ANS_X);
    ANS_Y /= gcdTemp;
    ANS_X /= gcdTemp;
}



void solve() {
    if (ok) return;
    if (isValidBound()) {
        ok = true;
        Set_Ans();
    }

}





void solveEachTest(lld _TestCase) {
    // cout << "Case#" << _TestCase << ": ";
    read(n);

    arr.resize(n);
    DirectedVectors.resize(n);


    flag_X_Pos = 0, flag_Y_pos = 0, flag_Y_neg = 0, flag_X_Neg = 0;

    XYRatio_Low.clear();
    XYRatio_Up.clear();

    forn(i, n) {
    	lld a, b; read(a,b);
    	arr[i] = {a, b};
    }

    forn(i, n) {
    	DirectedVectors[i] = {(arr[(i+1) % n].f1 - arr[i].f1), (arr[(i+1) % n].s2 - arr[i].s2)};
        set_bounds(i);
    }

    // UtilPrintThis(arr);
    UtilPrintThis(DirectedVectors);

    // UtilPrintThisBound(XYRatio_Up);
    // println("ok", isValidBound());
    // UtilPrintThisBound(XYRatio_Low);

    ok = false;
    ANS_Y = 0ll, ANS_X = 0ll;
    solve();

    println(ANS_X, ANS_Y);




    // cout << "\n"; 
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.precision(8); cout<<fixed;

    lld T3X0 = 0, T353 = 1;

    TESTCASES() 
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought :  null  
/*

*/
// Message : If you get the anime reference in this code, we're friends and we can talk about LIFE. 