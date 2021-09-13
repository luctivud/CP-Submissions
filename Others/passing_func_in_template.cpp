#include<bits/stdc++.h>
using namespace std;

template <class F>
struct Test {
    F func;
    Test() { };
    Test(F m_func) : func(m_func) { }
    int query(int a, int b) {
        return func(a, b);
    }
};

int find_min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    Test <int(*)(int, int)> obj(find_min);
    cout << obj.query(2, 3);
    cout << endl;
    cout << obj.query(5, 4);
    return 0;
}