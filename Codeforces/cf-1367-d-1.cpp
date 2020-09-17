//                           जय श्री राम

#include <bits/stdc++.h>
using namespace std;

const long long int UGLYMOD {1000000007};
const long long int SEXYMOD {998244353};
const long int MAXN = (long int) 1e6;

typedef long long int ll;

#define LUCILLE_IS_THIRSTY()       ios_base::sync_with_stdio(false); cin.tie(0)
#define TESTCASES_ARE_THERE()      long int Test; cin>>Test; while(Test--)
#define mems(arr,val)              memset((arr), val, sizeof((arr)))
#define endl                       "\n"

inline int readint() {
    int res = 0; char c = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = res*10+c-'0', c = getchar();
    return res;
}


void solveEach() {
    string s; cin >> s;

    int m; cin >> m;
    vector <int> arr(m);
    for (int i =0; i<m; i++)
        cin >> arr[i];

    vector <char> ans (m);

    int count[26] = {0};
    for (auto i: s) {
        count[i-'a'] += 1;
    }

    int temp = m;
    int pos = 25;
    while (temp) {
        vector<int> zero;
        for (int i = 0; i < m; ++i) {
            if (arr[i] == 0) {
                zero.push_back(i);
                arr[i] = -1;
            }
        }
        int sz = zero.size();
        while (count[pos] < sz) pos--;

        for (auto ind : zero) {
            ans[ind] = (char)(pos+'a');
            for (int i=0; i<m; i++) {
                if (arr[i] != -1) {
                    arr[i] -= abs(i-ind);
                }
            }
        }

        temp -= sz;
        pos -= 1;
    }

    for (auto i: ans) cout << i;

    cout << endl;
    return;
}

signed main() {

    LUCILLE_IS_THIRSTY();

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    TESTCASES_ARE_THERE()
        solveEach();
    return 0;
}
/*
THE LOGIC AND APPROACH IS BY ME @luctivud ( UDIT GUPTA )
SOME PARTS OF THE CODE HAS BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)
>>> DO NOT PLAGIARISE.
TESTCASES:
*/