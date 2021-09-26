/*          J  A  I   S  H  R  E  E   R  A  M          */
#ifdef LUCTIVUD
    #include <mydebug.h>
    pprint:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #include <bits/stdc++.h>
    using namespace std;
    #define _____error_____(...)
#endif


using namespace std;

signed main() {

    #ifdef LUCTIVUD
        // const auto start_time = std::chrono::high_resolution_clock::now();
        freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
        freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    int n, k; cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    stack<pair<int, int>> st;

    for (int i = n-1; i >= 0; i--) {
        while ((int)st.size() and st.top().first < arr[i]) {
            st.pop();
        }
        if (st.empty() or (i+k > st.top().second and st.top().first < arr[i])) {
            ans += 1;
        }
        st.push({arr[i], i});
        // NonIterable.print(st);
    }

    cout << ans << endl;

    return 0;
}