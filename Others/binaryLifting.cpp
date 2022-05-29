#include<bits/stdc++.h>
using namespace std;

class BinaryLifting {
    vector<vector<int>> p;
public:
    BinaryLifting(int n, vector<int> &par) {
        p.resize(n + 1, vector<int> (20, -1));
        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < n; i++) {
                if (j == 0) {
                    p[i][j] = par[i];
                    continue;
                }
                if (p[i][j - 1] == -1) break;
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }
    int getKthAncestor(int node, int K) {
        for (int i = 0; i < 20 && node != -1; i++) {
            if (K & (1 << i)) node = p[node][i];
        }
        return node;
    }
};


int main() {
    // int k = 13;
    // bitset<5> kbits{(unsigned int)k};
    // cout << kbits << "\n";

    // for (int i = 0; i < 5; i++) {
    //     cout << k << " " << (1 << i) << " ";
    //     cout << (k & (1 << i)) << "\n";
    // }
    return 0;
}