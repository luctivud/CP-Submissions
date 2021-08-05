// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

int getMid(int s, int e)
{
    return (s + (e - s) / 2);
}

int getGcdUtil(int* st, int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && qe >= se)
        return st[si];

    if (se < qs || ss > qe)
        return 0;

    int mid = getMid(ss, se);
    return __gcd(getGcdUtil(st, ss, mid, qs, qe, 2 * si + 1),
                getGcdUtil(st, mid + 1, se, qs, qe, 2 * si + 2));
}

void updateValueUtil(int* st, int ss, int se, int i, int diff, int si)
{
    if (i < ss || i > se)
        return;
    st[si] = st[si] + diff;
    if (se != ss) {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
        updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
    }
}

void updateValue(int arr[], int* st, int n, int i, int new_val)
{
    if (i < 0 || i > n - 1) {
        cout << "Invalid Input";
        return;
    }

    int diff = new_val - arr[i];

    arr[i] = new_val;

    updateValueUtil(st, 0, n - 1, i, diff, 0);
}

int getGcd(int* st, int n, int qs, int qe)
{

    if (qs < 0 || qe > n - 1 || qs > qe) {
        cout << "Invalid Input";
        return -1;
    }

    return getGcdUtil(st, 0, n - 1, qs, qe, 0);
}
int constructGcdUtil(int arr[], int ss, int se, int* st, int si)
{
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }

    int mid = getMid(ss, se);
    st[si] = __gcd(constructGcdUtil(arr, ss, mid, st, si * 2 + 1),
                constructGcdUtil(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}

int* constructGcd(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    int* st = new int[max_size];
    constructGcdUtil(arr, 0, n - 1, st, 0);
    return st;
}

int main()
{
    int arr[] = { 1, 3, 6, 9, 9, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int* st = constructGcd(arr, n);

    cout << getGcd(st, n, 1, 3) << endl;

    updateValue(arr, st, n, 1, 10);

    cout << getGcd(st, n, 1, 3) << endl;

    return 0;
}
