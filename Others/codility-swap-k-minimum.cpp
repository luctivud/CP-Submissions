/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::::::::::::J A I  S H R E E  R A M::::::::::::::::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::*/

#include <bits/stdc++.h>
using namespace std;
#ifdef LUCTIVUD
    #include <buggyBaby.hpp>
    pretty:: PrettyPrinter NonIterable;
    #define cerr cout
#else
    #define _____error_____(...)
#endif
#pragma GCC optimize "trapv"

/*:::::::::::::::::::SNIPS::::::::::::::::::::::::::::*/

typedef long long lld; typedef unsigned long long llu;

#define  forn(I7, E4) for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define forn1(I7, E4) for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define        len(v) ((int)((v).size()))
#define        all(x) (x).begin(), (x).end()
#define       rall(x) (x).rbegin(), (x).rend()
#define            f1 first
#define            s2 second

/*::::::::::::::::::/SNIPS::::::::::::::::::::::::::::*/
/*:::::::::::::::::::UTILS::::::::::::::::::::::::::::*/

const long double EPS = 1e-6;
lld MOD = int(1e9) + 7;
lld &mod = MOD;






/*:::::::::::::::::::::/UTILS:::::::::::::::::::::::::*/
/*::::::::::::::::::::::LOGIC:::::::::::::::::::::::::*/


void build(int node,int start,int end,int tree[],int a[]) 
{
   if(start==end)
   {    
    tree[node]=a[start];
   }
   else
   {
    int mid=(start+end)/2;
    build(2*node+1,start,mid,tree,a);
    build(2*node+2,mid+1,end,tree,a);
    tree[node]=min(tree[2*node+1],tree[2*node+2]);
   }
 }

void update(int node,int start,int end,int idx,int val,int tree[],int a[])
{

    if(start==end)
    {
       a[idx]=val;
       tree[node]=val;
    }

    else
   {
      int mid=(start+end)/2;
      if(idx>=start&&idx<=mid)
      {    
         update(2*node+1,start,mid,idx,val,tree,a);
      }
      else
      {    
       update(2*node+2,mid+1,end,idx,val,tree,a);
      }
     tree[node]=min(tree[2*node+1],tree[2*node+2]);
   }
}
int query(int node,int start,int end,int l,int r,int tree[])
{
  if(l>end||start>r)
  {     
    return INT_MAX;
  }
  if(l<=start&&r>=end)
  {    
   return tree[node];
  }
int q1,q2;
int mid=(start+end)/2;
q1=query(2*node+1,start,mid,l,r,tree);
q2=query(2*node+2,mid+1,end,l,r,tree);
return(min(q1,q2));
}


string solution(string &s, int K) {
    int inf = 28;
    set<int> used;
    int n = len(s);
    int a[n], tree[4*n+1];
    forn(i, n) {
      a[i] = s[i] - 'a';
    }
    build(0,0,n-1,tree,a);
    string ans = "";
    int l = 0ll, delta = 0ll;
    forn(i, n) {
      if (len(used)) {
        if (*(used.begin()) == i) {
          used.erase(used.begin());
          delta -= 1;
        }
      }
      int pos = query()
    }
    return ans;
}



/*:::::::::::::::::::::/LOGIC:::::::::::::::::::::::::*/
/*::::::::::::::::::::::INVOC:::::::::::::::::::::::::*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    MOD = mod = lld(1e9) + 7ll;
    int _T0T4 = 1;
    // cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        string s = "decade";
        cout << solution(s, 4);
        cout << "\n"; 
    }


    #ifdef LUCTIVUD
      // auto end_time = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double> diff = end_time - start_time;
      // cerr << "Finished in : " << diff.count() << "\n";
    #endif

    return 0; 
}


/*:::::::::::::::::::::/INVOC:::::::::::::::::::::::::*/
/*  ~~
Author   :  Udit "luctivud" Gupta 
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
