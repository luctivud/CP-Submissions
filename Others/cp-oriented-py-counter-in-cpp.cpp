/*     <<<  J A I ~ S H R E E ~ R A M  >>>     */

// Title: Implementation-of-python-counter-in-c++.cpp
// dated: 12-07-2020 17:16:47
// Creator & Template by : Udit Gupta @luctivud


#include "bits/stdc++.h"

using namespace std;

template <typename Type30F1, typename Type30F2> class _C0UN73R {

    public: map <Type30F1, Type30F2> CountOfElements;

    private: static bool asc(pair<Type30F1, Type30F2>& a, pair<Type30F1, Type30F2>& b) {
        return (a.second < b.second); 
    } 

    private: static bool dsc(pair<Type30F1, Type30F2>& a, pair<Type30F1, Type30F2>& b) {
         return (a.second > b.second); 
    }

    public: _C0UN73R(vector<Type30F1> ArrayToCountValues) {
        for (auto elementInArray : ArrayToCountValues) {
            CountOfElements[elementInArray]++;
        }
    }

    map <Type30F1, Type30F2> getCountAsMap() {
        return CountOfElements;
    }

    vector<pair<Type30F1, Type30F2>> getSortedVectorPair(bool reverse = false) { 
        vector<pair<Type30F1, Type30F2>> SortedVector; 
        for (auto& it : CountOfElements) SortedVector.push_back(it);
        if (reverse) {
            sort(SortedVector.begin(), SortedVector.end(), dsc);
        } else {
            sort(SortedVector.begin(), SortedVector.end(), asc);
        }
        return SortedVector;
    } 
};


signed main() {

   #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
   #endif 

    // vector <int> arr = {1, 2, 1, 3, 4, 5, 1 ,2};
    vector <string> arr;

    string s; 
    while (cin >> s) {
        arr.push_back(s);
    }

    // for (auto i : arr) cout << i << "\n";
    _C0UN73R <string , int> Obj(arr);
    map<string, int> count =  Obj.getCountAsMap();
    vector<pair<string, int>> sorted_count = Obj.getSortedVectorPair();
    // // cout << typeid(Obj).name();
    

    for (auto i : sorted_count) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}

