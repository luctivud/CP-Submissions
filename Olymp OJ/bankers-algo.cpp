// NAME: UDIT GUPTA
// SEC: CSE_A
// ROLL NO: 1803210166
// DATE: 14_JUNE_2020

#include<iostream>
using namespace std;

signed main() {
    int n, m, i, j, k; 

    printf("Enter number of processes ");
    scanf("%d", &n);

    printf("\nEnter number of resources ");
    scanf("%d", &m);

    // Allocation Matrix;
    printf("Enter the allocated resources of each type\n");
    int alloc[n][m]; 
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            scanf("%d", &alloc[i][j]);
    
    // Maxm matrix;
    printf("enter maxm matrix\n");
    int max[n][m];
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            scanf("%d", &max[i][j]);
    
    //Available resources
    printf("Enter n available resources\n");
    int avail[n];
    for (i=0 ; i<m; i++)
        scanf("%d", &avail[i]);

    
  
    int f[n], ans[n], ind = 0; 

    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 

    int need[n][m]; 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    } 

    int y = 0; 
    for (k = 0; k < 5; k++) { 
        for (i = 0; i < n; i++) { 
            if (f[i] == 0) { 
                int flag = 0; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > avail[j]){ 
                        flag = 1; 
                        break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += alloc[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
  
    cout << "SAFE Sequence\n"; 
    for (i = 0; i < n - 1; i++) 
        printf(" p%d ->", ans[i]);
    printf(" p%d \n", ans[n-1]);
  
    return 0;
}