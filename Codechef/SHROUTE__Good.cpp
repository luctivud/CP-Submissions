#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <limits.h>

typedef long long ll;

using namespace std;

void solve()
{
 int ans(0), sum(0), cnt(0);

 ll n, m; cin >> n >> m;

 int a[n + 1]; //a[0] = -1;
 for (int i = 1; i <= n; i++)
  cin >> a[i];

 int b[m + 1];
 for (int i = 1; i <= m; i++)
  cin >> b[i];

 int right[n + 1];
 int left[n + 1]; 
 
 for (int i = 1; i <= n; i++)
 { 
  left[i] = -1;

  int j = i;
  while (j >= 1 && a[j] != 1)
   j--;

  if (j >= 1)
   left[i] = j;
 }

 for (int i = n; i >= 1; i--)
 {
  right[i] = -1;

  int j = i;
  while (j <= n && a[j] != 2)
   j++;

  if (j <= n)
   right[i] = j;
 }

 // for (int i = 1; i <= n; i++)
 // {
 //  // cout << left[i] << " " << right[i] << endl;
 // }

 int c[m + 1];
 for (int iz = 1; iz <= m; iz++)
 {
  int i = b[iz];
  if (right[i] == -1 && left[i] == -1)
   c[iz] = -1;

  else if (right[i] != -1 && left[i] == -1)
   c[iz] = right[i] - b[iz];

  else if (right[i] == -1 && left[i] != -1)
   c[iz] = b[iz] - left[i];

  else
   c[iz] = min(right[i] - b[iz], b[iz] - left[i]);
 } 

 for (int i = 1; i <= m; i++)
  cout << c[i] << " ";

 cout << endl;

 return;
}

int main()
{
  #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif
 ll t;
 cin >> t;

 while (t--)
  solve();

 return 0;
}