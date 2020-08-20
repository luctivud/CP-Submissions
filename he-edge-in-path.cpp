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


// lld solve(lld start, lld end, vector<lld> adj[], vector<bool> &visited) {
// 	if (start == end) return 1;
// 	lld res = 0ll;
// 	lld cnt = 0ll;
// 	for (auto i : adj[start]) {
// 		if (!visited[i]) {
// 			visited[i] = true;
// 			lld temp = solve(i, end, adj, visited);
// 			if (temp > 0) {
// 				cnt += 1;
// 				res += temp;
// 			}
// 		}
// 	}
// 	if (cnt > 1) {
// 		return 0;
// 	}
// 	return 1 + res;
// }

bool found_wo = false;
lld found_ans = 0ll;

lld modified_bfs(lld start, vector<lld> adj[], vector<bool> &visited, vector<bool> nodes_in_cycle, lld edges, lld stop) {
	// deb1(start+1);
	if (start == stop) {
		found_wo = true;
		found_ans = edges;
		return edges;
	}
	if (nodes_in_cycle[start]) return edges;
	visited[start] = true;
	lld res = 0ll;
	for (lld i : adj[start]) {
		if (!visited[i]) {
			visited[i] = true;
			res += modified_bfs(i, adj, visited, nodes_in_cycle, edges+1, stop);
		}
	}
	return res;
}



lld cycle_wala(lld start, lld stop, vector<lld> adj[], vector<bool> &visited, lld n) {
	lld res = 0ll;
	vector<lld> degree(n, 0);
	queue<lld> q;
	for4(i, 0ll, n, 1) {
		degree[i] = len(adj[i]);
		if (degree[i] == 1) {
			q.push(i);
			visited[i] = true;
		}
	}

	while(!q.empty()) {
		lld start = q.front();
		q.pop();
		for(auto i : adj[start]) {
			if (!visited[i]) {
				if (--degree[i] == 1) {
					visited[i] = true;
					q.push(i);
				}
			}
		}
	}

	vector<bool> nodes_in_cycle(n, false);
	for4(i, 0ll, n, 1ll) {
		if (!visited[i]) {
			nodes_in_cycle[i] = true;
		}
	}
	// //commment heere
	// for4(i, 0, n, 1) {
	// 	if (nodes_in_cycle[i]) {
	// 		cout << i+1 << ",";
	// 	}
	// } cout << "\n";

	if (nodes_in_cycle[start] && nodes_in_cycle[stop]) {
		return res;
	} else if (nodes_in_cycle[start] or nodes_in_cycle[stop]) {
		fill(all(visited), false);
		if (nodes_in_cycle[start]) {
			// cout << "here" << stop << "\n";
			res += modified_bfs(stop, adj, visited, nodes_in_cycle, 0, start);
		} else {
			res += modified_bfs(start, adj, visited, nodes_in_cycle, 0, stop);
		}
	} else {
		fill(all(visited), false);
		lld temp = modified_bfs(stop, adj, visited, nodes_in_cycle, 0, start);
		if (found_wo) {
			res += found_ans;
		} else {
			res += temp;
			res += modified_bfs(start, adj, visited, nodes_in_cycle, 0, stop);
		}
	}

	return res;
}





lld bfs(lld start, lld stop, vector<lld> adj[], vector<bool> &visited, lld edges) {
	// deb1(start+1);
	if (start == stop) return edges;
	lld res = 0ll;
	for (lld i : adj[start]) {
		if (!visited[i]) {
			visited[i] = true;
			res += bfs(i, stop, adj, visited, edges + 1);
		}
	}
	return res;
}

void solveEachTest(lld T35TC453N = 1) {
    lld n, m; cin >> n >> m;
    lld a, b, A, B; cin >> A >> B;
    --A; --B;
    vector<lld> adj[n];
    for4(i, 0ll, m, 1ll) {
    	cin >> a >> b;
    	a--; b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    vector <bool> visited(n, false);
    // if (m+1 == n) {
    // 	cout  << bfs(A, B, adj, visited, 0);
    // } else {
        if (A == B) {
            cout << "0";
            return;
        }
    	cout << cycle_wala(A, B, adj, visited, n);
    // }

    cout << "\n"; 

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