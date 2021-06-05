// first ever solution submitted by luctivud
// https://www.codechef.com/viewsolution/23416619

#include <stdio.h>
int max(int pos, int neg, int zer);
int min(int pos, int neg, int zer);
int main(void) {
    // your code goes here
    int t,n,a;
    scanf("%d",&t);
    while(t--)
    {
        int pos=0,neg=0,zer=0;
        scanf("%d",&n);
        while(n--)
       {
        scanf("%d",&a);
        if(a>0)  pos++;
        if(a<0)  neg++;
        if(a==0) zer++;
        
       }
       
       printf("%d %d \n",max(pos,neg,zer),min(pos,neg,zer));
    }
    return 0;
}

int max (int pos, int neg , int zer){
    if(pos>neg)
    return (pos+zer);
    else
    return (neg+zer);
}

int min (int pos, int neg, int zer){
    int c,num[3],s;
    num[0]=pos;
    num[1]=neg;
    num[2]=zer;
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = i + 1; j < 3; ++j)
        {
            if (num[i] > num[j]) 
            {
                    s =  num[i];
                    num[i] = num[j];
                    num[j] = s;
            }
        }
    }
   
    for (int i=0;i<3;i++)
  {
    if (num[i]!=0)
    {
     c=num[i];
     break;
    }
  }
  return c;
  
}