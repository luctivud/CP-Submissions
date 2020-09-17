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
#define              len(v)    ((lld)((v).size()))
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


const lld d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const lld d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const long double EPS = 1e-5;

struct Meetings {
	long double timeToMeet;
	lld p1;
	lld p2;
};


bool cmp (const Meetings &a, const Meetings &b) {
	return a.timeToMeet < b.timeToMeet;
}


void UtilShowMeetings(vector<Meetings> meets) {
	for (auto i : meets) {
		println("Person", i.p1, "and Person", i.p2, "met at", i.timeToMeet);
	}
}


void solveEachTest(lld _TestCase) {
	// cout << "Case#" << _TestCase << ": ";
	lld n; read(n);
	vector<lld> arr(n + 1);

	forn(i, n) {
		read(arr[i + 1]);
	}


	vector<Meetings> meets;

	// O(N^2)
	for4(i, 1, n + 1, 1) {
		for4(j, i + 1, n + 1, 1) {
			long double posDiff = (long double)(j - i);
			long double velDiff = (long double)(arr[i] - arr[j]);
			if (velDiff > 0) {
				long double timeMet = (posDiff / velDiff) ;
				Meetings thisMeet;
				thisMeet.p1 = i, thisMeet.p2 = j, thisMeet.timeToMeet = timeMet;
				meets.pb(thisMeet);
			}
		}
	}

	// (N^2 log N)
	sort(all(meets), cmp);
	// UtilShowMeetings(meets);

	lld minAns = n, maxAns = 1ll;

	// O(N^2 (log N^2)^2)
	for4( i, 1ll, n + 1, 1ll) {
		set<lld> infectedSet;
		infectedSet.insert(i);
		auto it1 = meets.begin();
		while (it1 != meets.end()) {
			// error((*it1).timeToMeet);
			set<lld> thisMeetPersons;
			thisMeetPersons.insert((*it1).p1);
			thisMeetPersons.insert((*it1).p2);
			vector<lld> intersec;
			// auto it2 = it1;
			// while (it2 != meets.end() and (abs((*it2).timeToMeet - (*it1).timeToMeet)) < EPS) {
			// 	thisMeetPersons.insert((*it2).p1);
			// 	thisMeetPersons.insert((*it2).p2);
			// 	it2++;
			// }
			set_intersection(all(thisMeetPersons), all(infectedSet), back_inserter(intersec));

			if (len(intersec) > 0) {
				EACH(it, thisMeetPersons) {
					infectedSet.insert(it);
				}
			}


			it1++;
			// if (it1 == meets.end()) break;
			// it1++;
		}

		// error(i, len(infectedSet));
		minAns = min(minAns, len(infectedSet));
		maxAns = max(maxAns, len(infectedSet));
	}

	println(minAns, maxAns);

	// cout << "\n";
	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed;

	lld T3X0 = 0, T353 = 1;

	TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}
// Random Thought :  Why such constraints? The only potential problem could be precision error.
/*
        No, I move slow
        I want to stop time
        I'll sit here 'til I find the problem
*/
// Message : If you get the anime reference in this code, we're friends and we can talk about LIFE.