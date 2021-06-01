#include<bits/stdc++.h>
using namespace std;

void solve();
int main()
{
#ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif

int t;  cin>>t;
while(t--)
{
   solve();
}

return 0;
}

void solve()
{
int k;
cin>>k;

    string s;
    bool flag=true,c1=false,c2=false,c3=false,c4=false;
    for(int i=0;i<k;k++)
    {   
        cin>>s;
         flag=true;c1=false;c2=false;c3=false;
         if((s[0]>='A' && s[0]<='M') || ( s[0]>='n' && s[0]<='z' ) )
         {    c1=true;
              cout<<"NO\n" ;
              return;
              //break;
         }
         else if(s.size()==1 && ( (s[0]>='A' && s[0]<='M') || ( s[0]>='n' && s[0]<='z' ) ) )
         {
              c4=true;
              cout<<"NO\n" ;
              return;
         }
         else if(s[0]>='a' && s[0]<='m') {
              for(int j=0;j<s.size();j++)
              {
                   if(s[j]<'a' && s[j]>'m') {
                    // flag=false;
                    c2=true;
                     cout<<"NO\n" ;
                     return;
                    //break;
                    }
              }
         }
         else if(s[0]>='N' && s[0]<='Z') {
                for(int j=0;j<s.size();j++)
                {
                   if(s[j]<'N' && s[j]>'Z') {
                     //flag=false;
                     c3=true;
                     cout<<"NO\n" ;
                     return;
                    // break;
                   }
              }
         }
        

     //   flag ? cout<<"YES\n" : cout<<"NO\n" ;


        
    }
    if(!c1 || !c2 || !c3 || !c4)
    cout<<"YES\n";
    }