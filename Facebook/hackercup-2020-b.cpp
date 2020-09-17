#include <iostream>

using namespace std;

int main() {
    long int Test; cin >> Test;

    for (long int T = 1L; T <= Test; T++) {
        cout << "Case #" << T << ": ";

        long int n; cin >> n;
        long int a = 0L, b  = 0L;

        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            if (c == 'A') a += 1;
            else if (c == 'B') b += 1;
        }

        if (labs(a-b) == 1) cout << "Y";
        else cout << "N";

        cout << "\n";
    }

    return 0;
}