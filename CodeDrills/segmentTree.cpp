#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;

void build(vector<lld> &arr, vector<lld> &tree, lld v, lld tl, lld tr, lld n) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        lld tm = (tl + tr) / 2;
        build(arr, tree, v*2, tl, tm, n);
        build(arr, tree, v*2+1, tm+1, tr, n);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

lld sum(vector<lld> &t, int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(t, v*2, tl, tm, l, min(r, tm))
           + sum(t, v*2+1, tm+1, tr, max(l, tm+1), r);
}

signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    lld n; cin >> n;
    vector<lld> arr(n);
    for (lld i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<lld> tree(4*n, 0ll);
    build(arr, tree, 1, 0, n-1, n);

    for (lld i = 0; i < 4*n; i++) {
        cout << tree[i] << " ";
    }

    cout << sum(tree, )
    
    return 0;
}
