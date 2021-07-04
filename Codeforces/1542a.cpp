#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        int odd = 0;
        for (int i = 0; i < 2*n; i++) {
            int a;
            cin >> a;
            odd += (a & 1);
        }
        if (odd == n) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << "\n";
    }
    return 0;
}
