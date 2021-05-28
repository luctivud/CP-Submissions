//  J A I  S H R E E  R A M  //

// part of code taken from https://www.geeksforgeeks.org/counting-inversions/

#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
// #pragma GCC optimize ("Ofast")
// // #pragma GCC target ("fpmath=sse,sse2")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("-ffloat-store")


using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cout << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << H << ", "; dbg_out(T...);}
#define _____error_____(...) cout << #__VA_ARGS__ << " : ", dbg_out(__VA_ARGS__)

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/


// this part taken from gfg;

lld _mergeSort(lld arr[], lld temp[], lld left, lld right);
lld merge(lld arr[], lld temp[], lld left, lld mid,
          lld right);
 
lld mergeSort(lld arr[], lld array_size) {
    lld temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 

lld _mergeSort(lld arr[], lld temp[], lld left, lld right) {
    lld mid, inv_count = 0;
    if (right > left) {
        /* Divide the array lldo two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;
 
        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 

lld merge(lld arr[], lld temp[], lld left, lld mid, lld right) {
    lld i, j, k;
    lld inv_count = 0;
 
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}




void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    	
	string s; cin >> s;
	lld n = len(s);

	map<char, vector<lld>> pos;
	forn(i, n) {
		pos[s[i]].push_back(i);
	}


	string Machka;
	for (auto [ke, va] : pos) {
		Machka += ke;
	}

	sort(all(Machka));

	string ans = s;
	lld Max_inv = 0ll;

	// ae /////
	do {
		lld currArr[n], ind = 0ll;
		for (auto ch : Machka) {
			for (auto puss : pos[ch]) {
				// currArr.push_back(puss);
				currArr[ind++] = puss;
			}
		}
		lld thisInv = mergeSort(currArr, n);
		// _____error_____(thisInv);
		if (thisInv > Max_inv) {

			// ans = string bana 
			string thisAns;
			for (auto ch : Machka) {
				forn(xx, len(pos[ch])) {
					// currArr.push_back(puss);
					thisAns += ch;
				}
			}
			ans = thisAns;
			Max_inv = thisInv;
		}
	} while (next_permutation(all(Machka)));

	// cout << Max_inv << " "; 
	cout << ans;
    
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    MOD = mod = lld(1e9) + 7ll;
    lld _T0T4 = 1;
    cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n"; 
    }


    #ifdef LUCTIVUD
      // auto end_time = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double> diff = end_time - start_time;
      // cerr << "Finished in : " << diff.count() << "\n";
    #endif

    return 0; 
}


/*  ~~
Author   :  Udit "luctivud" Gupta 
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
