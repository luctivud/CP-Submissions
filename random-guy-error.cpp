#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll findmin(vector<ll>arr1)
{
    int MIN=INT_MAX;
    ll ind=-1;
    for(int i=0;i<arr1.size()-1;i++)
    {
    	
        if(arr1[i]<MIN)
        {
            MIN=arr1[i];
            ind=i;
        }
    }
return ind;
}
ll findmax(vector<ll>arr1)
{
    int max=INT_MIN;
    ll ind=-1;
    for(int i=0;i<arr1.size()-1;i++)
    {
    	cout << "er" << i << "\n";
        if(arr1[i]>max)
        {
            max=arr1[i];
            ind=i;
        }
    }
return ind;
}
int main() {
	// your code goes here

	ll n,m;
	cin>>n>>m;
    vector<ll>arr1;
     vector<ll>arr2;

	for(int i=0;i<n;i++)
	{ll a;
	cin>>a;
	arr1.push_back(a);
	}
	
	for(int i=0;i<m;i++)
	{ll a;
	cin>>a;
	arr2.push_back(a);
	}
  
  	// for(int i=0; i<n; i++) {
  	// 	cout << arr1[i] << " ";
  	// }
   //  for(int i=0; i<m; i++) {
  	// 	cout << arr2[i] << " ";
  	// }
   ll maxind=findmax(arr1);
   ll minind=findmin(arr2);
	// cout << maxind << arr1[maxind];
	for(int i=0;i<m;i++)
	cout<<maxind<<" "<<i<<endl;
	for(int i=0;i<n;i++)
	{if(i==maxind)
	continue;
	cout<<i<<" "<<minind<<endl;
	}
	

	return 0;
}
