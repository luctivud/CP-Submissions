/*```````````````````````````````````````
    **      **  *******  * *  ******
    **      **  **   **  ***    **
    **      **  **    *  * *    **
    ******* **  *******  * *    **
`````````````````````````````````````````*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;
typedef long long int ll;

#define TESTCASES() llu TestCases; cin>>TestCases; while(TestCases--)
#define pb push_back
#define MOD 1000000007
#define FORI(start,end) for(llu i=start; i<end; i++)

int main(){
    llu input;
    vector<double> vec;
    while(cin>>input)
        vec.pb((double)sqrt(input));
    for (auto it= vec.rbegin(); it!=vec.rend(); ++it){
        printf("%.4f\n",*it);
    }
    return 0;
}
