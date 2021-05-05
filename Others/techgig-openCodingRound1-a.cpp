#include <iostream>
#include <vector>
#pragma GCC optimize "trapv"

using namespace std;

typedef long long int lld;

signed main() {
	
	// Input - Output and optimization
	
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout.precision(10); cout << fixed;

    #ifdef LUCTIVUD
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

    string virus; cin >> (virus);

    lld n, szVirus = (virus).size(); cin >> (n);

    for (int xx = 0; xx < n; ++xx) {
    	string person; cin >> (person);
    	lld i = 0, j = 0, szPerson = (person).size();
    	while (i < szVirus and j < szPerson) {
    		if (virus[i] == person[j]) {
    			j++;
    		}
    		i++;
    	}
    	cout << (j == szPerson ? "POSI" : "NEGA") << "TIVE\n";
    }

    return 0;
}
