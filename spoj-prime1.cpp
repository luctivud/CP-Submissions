/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:,'..'xXWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO. .:kOo.,kNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO. .lNWWo..lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MNOxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxMMMMWKxoloxKWNc  .:xxd;  ,dxxxkXMXkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxMM
MKc''''''''''''''''.  ..'''''.   .''''.  .''MMMWx..,:. .xXo''.  .''.  ..'';kMk;'''''.  .'.''.  .''''''.  ..''.   .''MM
MWNXNNNNNNNNNNNNNNNO' ;KNNNNNKo. cKNNNd. lXNMMMK; ,0Wx. :NWXXl .dNNO' ;KNNNWMWNNNNNXc .kNNNNx. cXNNNNNO' ;KNN0; 'ONNMM
MMMMMMMMMMMMMMMMMWM0' :NMMMMWMX: .OMWWx. oWMMMMWx. ';. .dNMWWo .xMM0' :NWWMMMMMMMMWWl .OMMMWk. lWWMMWM0' ;XMMX: ,KMMMM
MMMMMMWMWkccccccccc;. :NMWNNNKd. :XMMWx. oWMMMWKo. .',. .,ldx; .dMM0' :NMMMMMMMNNWMWl .OMMMWk. lWMMMMM0' ;XMMX: ,0MMMM
MMWXKNWMWxcc,. .;cc;. :XMk,''..'lKWMMWx. oWMNx:. .lONNKxl.     .xMM0' :NMMMMMM0:,oKO' ,KMMMMk. lWWNkoc,. .;::;. ,KMMMM
MMXc.lXMMWWWNd..xWM0' :NM0;  ;kXWMMMWNl  oWMK:.;xXWWMWXx:. ,c' .dMM0' :NMMMMMMKc. ...;kWMMMMk. lWWc .:;. .clc:. ,KMMMM
MWWx. lXMWMMMK, lWM0' :NMMNx'.,ldxxoc'   oWMWNKNWWWN0o' .:kNWo .dMM0' :NMMMMMMMNO;  ,OWWWMMMk. lWM' lXx. lNMMX: ,KMMMM
MMMWk'.,xKNX0c..kWM0' :NMMMMNkl;,'',:l:  oWMMMMMWMWO' 'l0WMWWo .xMM0' :NMMMMMMMMMNd. .oXWMMMk. lWMd.....;0WMMX: ,KMMMM
MMMMWKo'...'..:kWMM0' :NMMMMMMMWWNNWWWx. oWMMMMMMMMWOxXWMWMWWo .xMM0' :NMMMMMMMMMMMKl. ,kNMMk. lWMWKkxx0NMWMMX: ,KMMMM
MMMMMMMN0kxk0XNWMMWKl;xNMMMMMMMMMMMMWM0c;kWMMMMMMMMMMMWWMMMMWk;:OMMXl,dNMMMMMMMMMMMMWO; .dNM0c;kWWMMMMMMMMMMMNd,oXMMMM
MMMMMMMMWWMWMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMWWMMWMMMMMMMMMMMMMMNkxKWMMWWMMMMMMMMMMMMMMWMMWMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM*/

//             Author: Udit "luctivud" Gupta @ (https://www.linkedin.com/in/udit-gupta-1b7863135/)                  //


#include <bits/stdc++.h>
#pragma GCC optimize "trapv"

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template <typename T> using FSET = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)>0) ? (I7)<(E4) : (I7)>(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define        EACH(I7, A7)    for (auto& I7: A7)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  pb    push_back
#define             deb1(x)    cout << #x << " = "; println(x);
#define             deb2(x)    cout << #x << " = "; print(x); cout << " ";
#define                  f1    first
#define                  s2    second



#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); huehue(_it, args); cout << "\n";}

void huehue(istream_iterator<string> it) {}
template<typename T, typename... Args>
void huehue(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << ", ";
	huehue(++it, args...);
}

void read() { return; }
void print() { return; }
void println() { return; }
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


const int d4i[4] = { -1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = { -1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/* This part should be outside the main in global paradigm. */

const long long MAXN = (lld)(1e5) + 1ll; // MAXN Size

vector<long long >isPrime(MAXN , true); // checkIfPrime
vector<long long >prime_numbers; // List of prime numbers
vector<long long >smallest_prime_factor(MAXN); // smallest_prime_factor of a number


void manipulated_seive() {
	isPrime[0] = isPrime[1] = false ;

	prime_numbers.push_back(2);
	smallest_prime_factor[2] = 2ll;

	for (long long int i = 4; i < MAXN ; i += 2) {
		isPrime[i] = false;
		smallest_prime_factor[i] = 2ll;
	}

	for (long long int i = 3; i < MAXN ; i += 2) {
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



bool isvalid(lld i, lld n) {
	return i >= 0 and i < n;
}


void solveEachTest(lld _TestCase = 1) {
	// cout << "Case#" << _TestCase << ": ";
	lld l, r; read(l, r);

	vector<bool> arr(r - l + 1, true);

	EACH(i, prime_numbers) {
		if (i > r) break;
		lld start = ((l + i - 1) / i) * i;
		lld end = (r / i) * i;
		// error(start, end, i);
		if (start == i) start += i;
		while (start <= end) {
			if (isvalid(start - l, r - l + 1)) {
				arr[start - l] = false;
			}
			start += i;
		}
	}

	for4(i, 0, r - l + 1, 1) {
		if (arr[i] and i + l != 1) {
			println(i + l);
		}
	}

	println("", "");


	// cout << "\n";
	return;
}


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.precision(10);

	/* This should be called inside main. */
	manipulated_seive();
	lld T3X0 = 0, T353 = 1;

	TESTCASES()
	solveEachTest(T353 - T3X0);
	return 0;
}
// Random Thought :  null