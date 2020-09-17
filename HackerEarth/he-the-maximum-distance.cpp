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

typedef long long int lld;
typedef unsigned long long int llu;

#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define         _input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define   for4(I7,S4,E4,S7)    for(auto I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define             deb1(x)    cout << #x << "=" << (x) << "\n";
#define             deb2(x)    cout << #x << "=" << (x) << " ";


// struct Factor {
// 	lld add = 0ll;
// 	// long double product = 1ll;
// 	// long double toDiv = 1ll;
// };

// const long double EPSILON = 1e-9;

void solveEachTest(lld T35TC453N = 1) {
    lld n; cin >> n;
    vector<lld> arr(n);
    _input(arr);
    lld q; cin >> q;
    // first.first == product first.second, second == add
    vector<lld> factor(n+1, 0ll);
    // for4(i, 0, n+1, 1) {
    // 	factor.emplace_back(1, 0);
    // }

    for4(qq, 0, q, 1) {
    	int queryType; cin >> queryType;
    	if (queryType == 1) {
    		lld l, r, x; cin >> l >> r >> x;
    		l--;
    		factor[l] += x;
    		factor[r] -= x;
    		// // comment here
    		// lld addu = 0ll;
    		// for4(i, 0ll, n, 1) {
    		// 	addu += factor[i].add;
    		// 	lld thisElement = arr[i]+ addu;
    		// 	cout << thisElement << " ";
    		// } cout << "\n";
    		// lld prod = 1ll;
    		// lld addu = 0ll;
    		// deb2(queryType);
    		// for4(i, 0ll, n, 1) {
    		// 	prod *= factor[i].product;
    		// 	addu += factor[i].add;
    		// 	deb2(factor[i].add); deb1(factor[i].product);
    		// 	lld thisElement = arr[i] * prod + addu;
    		// 	cout << thisElement << " ";
    		// } cout << "\n";
    	} else if (queryType == 2) {
    		lld l, r, x; cin >> l >> r >> x;
    		l--;
    		lld addu = 0ll;
    		for4(i, 0, n, 1) {
    			addu += factor[i];
    			arr[i] += addu;
    			factor[i] = 0;
    			if (i >= l and i < r)
    				arr[i] *= x;
    		}
    		// // comment here
    		// addu = 0ll;
    		// for4(i, 0ll, n, 1) {
    		// 	addu += factor[i].add;
    		// 	lld thisElement = arr[i]+ addu;
    		// 	cout << thisElement << " ";
    		// } cout << "\n";
    		// factor[l].product *= x;
    		// // long double prev = factor[l].add;
    		// factor[l].add *= x;
    		// factor[r].product /= x;
    		// factor[r].toDiv *= x;
    		// lld prod = 1ll;
    		// lld addu = 0ll;
    		// deb2(queryType);
    		// for4(i, 0ll, n, 1) {
    		// 	prod *= factor[i].product;
    		// 	addu /= factor[i].toDiv;
    		// 	addu += factor[i].add;
    		// 	deb2(factor[i].add); deb2(factor[i].product); deb1(factor[i].toDiv);
    		// 	// if (i == 2) {
    		// 	// 	deb2(addu); deb2(prod);
    		// 	// }
    		// 	lld thisElement = arr[i] * prod + addu;
    		// 	cout << thisElement << " ";
    		// } cout << "\n";
    	} else {
    		lld z; cin >> z;
    		lld start = n;
    		lld end = 0;
    		lld addu = 0ll;
    		for4(i, 0ll, n, 1) {
    			addu += factor[i];
    			lld thisElement = arr[i] + addu;
    			// cout << thisElement << " ";
    			if (thisElement == z) {
    				start = min(start, i);
    				end = max(end, i);
    			}
    		}

    		cout << ((start > end) ? -1 : (end-start + 1) );
    		cout << "\n"; 
    	}
    }


    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.precision(10);

    lld T3X0 = 0, T353 = 1;

    // TESTCASES() 	
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought :  null  