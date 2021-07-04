#include <bits/stdc++.h>
using namespace std;

#ifdef LUCTIVUD
    #include <buggyBaby.hpp>
    pretty:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #define _____error_____(...)
#endif

int main() {
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        long long int a, b, n; 
        cin >> n >> a >> b;
        set<long long int> elements;
        elements.insert(1);
        set<long long int> :: iterator it = elements.begin();
        while (it != elements.end() && *it < b) {
            if (*it * a <= b)
                elements.insert(*it * a);
            it++;
        }

        bool ok = false;

        for (it = elements.begin(); it != elements.end(); it++) {
            if ((n - *it) % b == 0) {
                ok = true;
            }
        }

        _____error_____(elements);

        if (ok) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << "\n";
    }
    return 0;
}
