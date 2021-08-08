// CPP program to Count number of occurrence of
// smallest element in range L-R
#include <bits/stdc++.h>
using namespace std;

#define int long
const int inf  = 1e18;



#define N 100005
// predefines the tree with nodes
// storing min and count
struct node {
    int min, cnt;
    int min2 = inf, cnt2 = 0;
} tree[5 * N];

// function to construct the tree
void buildtree(int low, int high, int pos, int a[])
{
    // base condition
    if (low == high) {

        // leaf node has a single element
        tree[pos].min = a[low];
        tree[pos].cnt = 1;
        tree[pos].cnt2 = 0;
        return;
    }

    int mid = (low + high) >> 1;
    // left-subtree
    buildtree(low, mid, 2 * pos + 1, a);

    // right-subtree
    buildtree(mid + 1, high, 2 * pos + 2, a);

    // left subtree has the minimum element
    if (tree[2 * pos + 1].min < tree[2 * pos + 2].min) {
        if (tree[2*pos+1].min2 < tree[2*pos+2].min) {
            tree[pos].min2 = tree[2*pos+1].min2;
            tree[pos].cnt2 = tree[2*pos+1].cnt2;
        } else if (tree[2*pos+1].min2 > tree[2*pos+2].min) {
            tree[pos].min2 = tree[2*pos+2].min;
            tree[pos].cnt2 = tree[2*pos+2].cnt;
        } else {
            tree[pos].min2 = tree[2*pos+2].min;
            tree[pos].cnt2 = tree[2*pos+2].cnt + tree[2*pos+1].cnt2;
        }
        tree[pos].min = tree[2 * pos + 1].min;
        tree[pos].cnt = tree[2 * pos + 1].cnt;
    }

    // right subtree has the minimum element
    else if (tree[2 * pos + 1].min > tree[2 * pos + 2].min) {
        if (tree[2*pos+1].min < tree[2*pos+2].min2) {
            tree[pos].min2 = tree[2*pos+1].min;
            tree[pos].cnt2 = tree[2*pos+1].cnt;
        } else if (tree[2*pos+1].min2 > tree[2*pos+2].min) {
            tree[pos].min2 = tree[2*pos+2].min2;
            tree[pos].cnt2 = tree[2*pos+2].cnt2;
        } else {
            tree[pos].min2 = tree[2*pos+2].min2;
            tree[pos].cnt2 = tree[2*pos+2].cnt2 + tree[2*pos+1].cnt;
        }
        tree[pos].min = tree[2 * pos + 2].min;
        tree[pos].cnt = tree[2 * pos + 2].cnt;
    }

    // both subtree has the same minimum element
    else {
        if (tree[2*pos+1].min2 < tree[2*pos+2].min2) {
            tree[pos].min2 = tree[2*pos+1].min2;
            tree[pos].cnt2 = tree[2*pos+1].cnt2;
        } else if (tree[2*pos+1].min2 > tree[2*pos+2].min2) {
            tree[pos].min2 = tree[2*pos+2].min2;
            tree[pos].cnt2 = tree[2*pos+2].cnt2;
        } else {
            tree[pos].min2 = tree[2*pos+2].min2;
            tree[pos].cnt2 = tree[2*pos+2].cnt2 + tree[2*pos+1].cnt2;
        }
        tree[pos].min = tree[2 * pos + 1].min;
        tree[pos].cnt = tree[2 * pos + 1].cnt + tree[2 * pos + 2].cnt;
    }
}

// function that answers every query
node query(int s, int e, int low, int high, int pos)
{
    node dummy;
    // out of range
    if (e < low or s > high) {
        dummy.min = dummy.cnt = INT_MAX;
        return dummy;
    }

    // in range
    if (s >= low and e <= high) {
        return tree[pos];
    }

    int mid = (s + e) >> 1;

    // left-subtree
    node ans1 = query(s, mid, low, high, 2 * pos + 1);

    // right-subtree
    node ans2 = query(mid + 1, e, low, high, 2 * pos + 2);

    node ans;
    ans.min = min(ans1.min, ans2.min);

    // add count when min is same of both subtree
    if (ans1.min == ans2.min)
        ans.cnt = ans2.cnt + ans1.cnt;

    // store the minimal's count
    else if (ans1.min < ans2.min)
        ans.cnt = ans1.cnt;

    else
        ans.cnt = ans2.cnt;

    return ans;
}

// function to answer query in range l-r
int answerQuery(int a[], int n, int l, int r)
{
    // calls the function which returns a node
    // this function returns the count which
    // will be the answer
    return query(0, n - 1, l - 1, r - 1, 0).cnt;
}

// Driver Code
int main()
{
    int a[] = { 1, 1, 2, 4, 3, 3 };

    int n = sizeof(a) / sizeof(a[0]);
    buildtree(0, n - 1, 0, a);
    int l = 1, r = 4;

    // answers 1-st query
    cout << answerQuery(a, n, l, r) << endl;

    l = 2, r = 6;
    // answers 2nd query
    cout << answerQuery(a, n, l, r) << endl;
    return 0;
}
