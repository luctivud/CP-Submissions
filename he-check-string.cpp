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
 
// no dp used here. just testing logic. remember to add dp .!!!!???????????
 
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
 
vector<lld> dp(4000);
string s;
 
bool solve(lld indx, lld red, lld blue,  vector<lld> values, lld balance, vector<pair<lld, lld>> stored, vector<lld> startpair) {
    if (indx == -1) return true;
    if (balance == 0) {
        red = 0; 
        blue = 0;
    }
 
    if (s[indx] == '(') {
        balance += 1;
    } else if (s[indx] == ')'){
        balance -= 1;
    }

    if (dp[indx] != -1) return dp[indx];
    stored[indx].first = red;
    stored[indx].second = blue;
 
    if (s[indx] == '(') {
        bool flag1 = false, falg2 = false;

        if (red - stored[startpair[indx]].first < values[indx]) {
            flag1 = solve(indx-1, values[indx], blue, values, balance, stored, startpair);
        }
 
        if (blue - stored[startpair[indx]].second < values[indx]) {
            falg2 = solve(indx-1, red, values[indx], values, balance, stored, startpair);
        }
 
        return (dp[indx] = (flag1 | falg2));
    } else if (s[indx] == ')') {
        return (dp[indx] = solve(indx-1, red, blue, values, balance, stored, startpair));
    } else {
        return (dp[indx] = (solve(indx-1, red + values[indx], blue, values, balance, stored, startpair) |
                        solve(indx-1, red, blue + values[indx], values, balance, stored, startpair)));
    }
    return 0;
}
 
 
void solveEachTest(lld T35TC453N = 1) {
    lld n; cin >> n;
    cin >> s;
 
    lld x = 0ll, y = 0ll;
    for (auto i : s) {
        if (i == '(') {
            y += 1;
        } else if (i == '#') {
            x += 1;
        }
    }
 
    vector<lld> values(n, 0);
    for4(i, 0ll, x, 1ll) {
        lld idx, val; cin >> idx >> val;
        idx--;
        values[idx] = val;
    }
    fill(dp.begin(), dp.end(), -1);
    vector<lld> startpair(n, -1);
    vector<bool> parentheses(n, false);
    vector<pair<lld, lld>> stored(n);
    for4(i, 0ll, y, 1ll) {
        lld idx1, idx2, val; cin >> idx1 >> idx2 >> val;
        idx1--;
        idx2--;
        values[idx1] = val;
        parentheses[idx1] = true;
        startpair[idx1] = idx2;
    }
 
    bool ok = solve(n-1, 0, 0, values, 0, stored, startpair);
 
    cout << (ok ? "Yes" : "No");
    cout << "\n"; 
 
    return;
}
 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    lld T3X0 = 0, T353 = 1;
 
    // TESTCASES() 
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought :  null  