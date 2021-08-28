// C++ program to demonstrate LCA of n-ary tree
// in constant time.
#include "bits/stdc++.h"
using namespace std;
#define sz 101



void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(int argc, char const *argv[])
{
    // constructing the described tree
    int numberOfNodes = 8;
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(2,6);
    addEdge(3,7);
    addEdge(3,8);

    // performing required precalculations
    preprocess();

    // doing the Euler walk
    ptr = 0;
    memset(FAI,-1,sizeof(FAI));
    dfs(1,0,0);

    // creating depthArray corresponding to euler[]
    makeArr();

    // building sparse table
    buildSparseTable(depthArr.size());

    cout << "LCA(6,7) : " << LCA(6,7) << "\n";
    cout << "LCA(6,4) : " << LCA(6,4) << "\n";

    return 0;
}
