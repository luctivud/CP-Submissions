// Efficient C++ program to find n-th palindrome
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "trapv"

// Construct the nth binary palindrome with the
// given group number, aux_number and operation
// type
#define int long long
int constructNthNumber(int group_no, int aux_num, int op)
{
    int INT_SIZE = 60 ;
    int a[INT_SIZE] = { 0 };
    int num = 0, len_f;
    int i = 0;
    
    // No need to insert any bit in the middle
    if (op == 2)
    {
        
        // Length of the final binary representation
        len_f = 2 * group_no;

        // Fill first and last bit as 1
        a[len_f - 1] = a[0] = 1;

        // Start filling the a[] from middle,
        // with the aux_num binary representation
        while (aux_num)
        {
            
            // Get the auxiliary number's ith bit and
            // fill around middle
            a[group_no + i]
                = a[group_no - 1 - i]
                = aux_num & 1;
            aux_num = aux_num >> 1;
            i++;
        }
    }

    // Insert bit 0 in the middle
    else if (op == 0)
    {
        
        // Length of the final binary representation
        len_f = 2 * group_no + 1;

        // Fill first and last bit as 1
        a[len_f - 1] = a[0] = 1;
        a[group_no] = 0;

        // Start filling the a[] from middle, with
        // the aux_num binary representation
        while (aux_num)
        {
            
            // Get the auxiliary number's ith bit
            // and fill around middle
            a[group_no + 1 + i]
                = a[group_no - 1 - i]
                = aux_num & 1;
            aux_num = aux_num >> 1;
            i++;
        }
    }
    
    // Insert bit 1 in the middle
    else
    {
        
        // Length of the final binary representation
        len_f = 2 * group_no + 1;

        // Fill first and last bit as 1
        a[len_f - 1] = a[0] = 1;
        a[group_no] = 1;

        // Start filling the a[] from middle, with
        // the aux_num binary representation
        while (aux_num)
        {
            
            // Get the auxiliary number's ith bit
            // and fill around middle
            a[group_no + 1 + i]
                = a[group_no - 1 - i]
                = aux_num & 1;
            aux_num = aux_num >> 1;
            i++;
        }
    }

    // Convert the number to decimal from binary
    for(i = 0; i < len_f; i++)
        num += (1 << i) * a[i];
        
    return num;
}

// Will return the nth binary palindrome number
int getNthNumber(int n)
{
    int group_no = 0, group_offset;
    int count_upto_group = 0, count_temp = 1;
    int op, aux_num;

    // Add number of elements in all the groups,
    // until the group of the nth number is found
    while (count_temp < n)
    {
        group_no++;

        // Total number of elements until this group
        count_upto_group = count_temp;
        count_temp += 3 * (1ll << (group_no - 1));
    }

    // Element's offset position in the group
    group_offset = n - count_upto_group - 1;

    // Finding which bit to be placed in the
    // middle and finding the number, which we
    // will fill from the middle in both
    // directions
    if ((group_offset + 1) <= (1ll << (group_no - 1)))
    {
        
        // No need to put extra bit in middle
        op = 2;

        // We need to fill this auxiliary number
        // in binary form the middle in both directions
        aux_num = group_offset;
    }
    else
    {
        if (((group_offset + 1) -
        (1 << (group_no - 1))) % 2)
        
            // Need to Insert 0 at middle
            op = 0;
        else
        
            // Need to Insert 1 at middle
            op = 1;
        aux_num = ((group_offset) -
                (1ll << (group_no - 1))) / 2;
    }
    return constructNthNumber(group_no, aux_num, op);
}

// Driver code
signed main()
{   
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif
    int n = 96969;
    cout << "[";
    for (int i = 1; i < n; i++) {
        cout << getNthNumber(i) << ", ";
    }
    cout << "]";

    // Function Call
    return 0;
}

// This code is contributed by Khushboogoyal499
