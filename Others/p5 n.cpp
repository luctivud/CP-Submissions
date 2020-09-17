#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    for(int i=0; i<=50; i++){
        if((a+i)==(a^i)){
            cout<<i<<" ";
        }
    }
    return 0;
}
