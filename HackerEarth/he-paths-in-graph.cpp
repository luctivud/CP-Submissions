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
 
typedef unsigned long long int lld;
// typedef unsigned long long int llu;
 
#define         TESTCASES()    cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define         _input(V3C)    for(auto &V3C_I7 : (V3C)) cin >> (V3C_I7)
#define   mems(A77AY, V4LU)    memset((A77AY), (V4LU), sizeof((A77AY)))
#define    CH3K(I7, E4, S7)    (((S7)<0) ? (I7)>(E4) : (I7)<(E4))
#define   for4(I7,S4,E4,S7)    for(lld I7=(S4); CH3K(I7,E4,S7); (I7)+=(S7))
 
 
 
void solveEachTest(lld T35TC453N = 1) {
    lld k; cin >> k;
    
    lld temp = k;
    lld nodes = 0ll;
    
    // 2 ** nodes <= k
    while (temp > 0) {
        temp >>= 1;
        nodes++;
    }


    nodes *= 2;
    cout << nodes << " ";

    k -= 1ll << (nodes/2-1);
    // cout << k ;
    
    vector<vector<bool>> graph(nodes, vector<bool> (nodes, false));

    // lld edges = 4ll;
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[nodes-2][nodes-1] = 1;
    graph[nodes-3][nodes-1] = 1;
    
    lld powerful = 1ll << (nodes/2-1);
    // // cout << k << " "  << powerful;
    powerful /= 2;
    if (powerful <= k) {
        k -= powerful;
        graph[1][2] = 1;
        // edges++;
    }

    powerful /= 2;
    lld lastNode = 4;
    while (k > 0 and powerful > 0) {
        // cout << k << " "  << powerful << "\n";

        if (powerful <= k) {
            graph[0][lastNode] = 1;
            // edges++;
            k -= powerful;
        }
        lastNode += 2;
        powerful /= 2;
        // cout << k << "\n";
    }
    // cout << edges;
    for4(i, 2ll, nodes, 2ll) {
        lld n1 = i + 2;
        lld n2 = n1 - 1;
        graph[i][n1] = 1;
        graph[i][n2] = 1;
        graph[i-1][n1] = 1;
        graph[i-1][n2] = 1;
        // edges += 4;
    }

    // cout << edges << "\n";
    lld edges = 0ll;
    for4(i, 0ll, nodes, 1ll) {
        for4(j, 0ll, nodes, 1ll) {
            if (graph[i][j]) {
                // cout << i << " " << j << "\n";
                edges++;
            }
        }
    }

    cout << edges << "\n";

    for4(i, 0ll, nodes, 1ll) {
        for4(j, 0ll, nodes, 1ll) {
            if (graph[i][j]) {
                cout << i << " " << j << "\n";
                // edges++;
            }
        }
    }
 
    return;
}
 
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    lld T3X0 = 0, T353 = 1;
 
    // TESTCASES() 
        solveEachTest(T353 - T3X0);
    return 0;
}
// Random Thought :  null  1