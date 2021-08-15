// C++ Implementation of above approach
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// Function to return (x^y) mod p
int power(int x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;

    while (y > 0) {

        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Declaring size array globally
int size[300005];
int freq[300004];
vector<pair<int, pair<int, int> > > edges;

// Initializing DSU data structure
void initialize(int Arr[], int N)
{
    for (int i = 0; i < N; i++) {
        Arr[i] = i;
        size[i] = 1;
    }
}

// Function to find the root of ith
// node in the disjoint set
int root(int Arr[], int i)
{
    while (Arr[i] != i) {
        i = Arr[i];
    }
    return i;
}

// Weighted union using Path Compression
void weighted_union(int Arr[],
                    int size[], int A, int B)
{
    int root_A = root(Arr, A);
    int root_B = root(Arr, B);

    // size of set A is small than size of set B
    if (size[root_A] < size[root_B]) {
        Arr[root_A] = Arr[root_B];
        size[root_B] += size[root_A];
    }

    // size of set B is small than size of set A
    else {
        Arr[root_B] = Arr[root_A];
        size[root_A] += size[root_B];
    }
}

// Function to add an edge in the tree
void AddEdge(int a, int b, int w)
{
    edges.push_back({ w, { a, b } });
}

// Build the tree
void MakeTree()
{
    AddEdge(1, 2, 10);
    // AddEdge(1, 3, 3);
    AddEdge(2, 3, 20);
}

// Function to return the required product
int MinProduct()
{
    int result = 1;

    // Sorting the edges with respect to its weight
    sort(edges.begin(), edges.end());

    // Start iterating in decreasing order of weight
    for (int i = edges.size() - 1; i >= 0; i--) {

        // Determine Current edge values
        int curr_weight = edges[i].first;
        int Node1 = edges[i].second.first;
        int Node2 = edges[i].second.second;

        // Calculate root of each node
        // and size of each set
        int Root1 = root(freq, Node1);
        int Set1_size = size[Root1];
        int Root2 = root(freq, Node2);
        int Set2_size = size[Root2];

        // Using the formula
        int prod = Set1_size * Set2_size;
        int Product = power(curr_weight, prod, mod);

        // Calculating final result
        result = ((result % mod) *
                            (Product % mod)) % mod;

        // Weighted union using Path Compression
        weighted_union(freq, size, Node1, Node2);
    }
    return result % mod;
}

// Driver code
int main()
{
    int n = 3;

    initialize(freq, n);

    MakeTree();

    cout << MinProduct();
}
