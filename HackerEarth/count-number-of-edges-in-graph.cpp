// C++ program for Number of paths 
// from one vertex to another vertex 
// in a Directed Acyclic Graph 
#include <bits/stdc++.h> 
using namespace std; 
#define MAXN 1000005 
// #define int long long int


// to make graph 
vector<int> v[MAXN]; 

// function to add edge in graph 
void add_edge(int a, int b, int fre[]) 
{ 
	// there is path from a to b. 
	v[a].push_back(b); 
	fre[b]++; 
} 

// function to make topological sorting 
vector<long long int> topological_sorting(int fre[], int n) 
{ 
	queue<long long int> q; 

	// insert all vertices which 
	// don't have any parent. 
	for (int i = 0; i < n; i++) 
		if (!fre[i]) 
			q.push(i); 

	vector<long long int> l; 

	// using kahn's algorithm 
	// for topological sorting 
	while (!q.empty()) { 
		int u = q.front(); 
		q.pop(); 

		// insert front element of queue to vector 
		l.push_back(u); 

		// go through all it's childs 
		for (int i = 0; i < int(v[u].size()); i++) { 
			fre[v[u][i]]--; 

			// whenever the freqency is zero then add 
			// this vertex to queue. 
			if (!fre[v[u][i]]) 
				q.push(v[u][i]); 
		} 
	} 
	return l; 
} 

// Function that returns the number of paths 
long long int numberofPaths(int source, int destination, int n, int fre[]) 
{ 

// make topological sorting 
	vector<long long int> s = topological_sorting(fre, n); 

	// to store required answer. 
	long long int dp[n] = { 0 }; 

	// answer from destination 
	// to destination is 1. 
	dp[destination] = 1; 

	// traverse in reverse order 
	for (int i = s.size() - 1; i >= 0; i--) { 
		for (int j = 0; j < int(v[s[i]].size()); j++) { 
			dp[s[i]] += dp[v[s[i]][j]]; 
		} 
	} 

	return dp[source]; 
} 

// Driver code 
// 1972927638383
signed main() 
{ 

	// here vertices are numbered from 0 to n-1. 
	int n; cin >> n;
	int m; cin >> m;
	
	int source = 0, destination = n-1; 

	// to count number of vertex which don't 
	// have any parents. 
	int fre[n] = { 0 }; 

	// to add all edges of graph 
	for (int i =0; i<m; i++) {
		int a, b; cin >> a >> b;
		add_edge(a, b, fre); 
	}
	
	// add_edge(0, 2, fre); 
	// add_edge(0, 3, fre); 
	// add_edge(0, 4, fre); 
	// add_edge(2, 3, fre); 
	// add_edge(3, 4, fre); 

	// Function that returns the number of paths 
	cout << numberofPaths(source, destination, n, fre); 
	return 0;
} 
