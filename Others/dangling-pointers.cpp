#include<bits/stdc++.h>
using namespace std;

int *fun_ok() {
    static int x_ok = 3;
    return &x_ok;
}

int *fun() {
    int x = 3;
    return &x;
}

int main() {
    int *ptr1 = (int *)malloc(sizeof(int));
    *ptr1 = 4;
    free(ptr1);
    cout << *ptr1 << endl; 

    // when function returns address
    // of local variable
    int *ptr2 = fun();
    cout << *ptr2 << endl; 
    
    // variable address
    // which is out of scope
    int *ptr3;
    {
        int x = 4;
        ptr3 = &x;
    }
    cout << *ptr3 << endl;
    
    // problem with pointer2 
    // can be solved by static
    int *ptr2_ok = fun_ok();
    cout << *ptr2_ok << endl;
}