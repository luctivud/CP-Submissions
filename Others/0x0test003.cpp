#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    vector <vector<int>> matr(n + 1, vector<int> (3, 0));
    for (int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        if (x <= n and x > 0 and y <= 3 and y >= 0)
        {
            matr[x][y] = 1;
        }
    }
    long long int t_1 = 0, t_2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (matr[i][1])
        {
            t_1 += t_1 + 1;
        }
        else
        {
            t_1 += 1;
        }
        if (matr[i][2])
        {
            t_2 += t_2 + 1;
        }
        else
        {
            t_2 += 1;
        }
    }

    if (t_2 == t_1)
    {
        cout << "Draw";
    }
    else if (t_2 < t_1)
    {
        cout << "Second";
    }
    else
    {
        cout << "First";
    }
}