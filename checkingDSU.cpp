int dsu[MAX];
int ranks[MAX];
void create(int n)
{
    for(int i = 0 ;i  <= n ; i++)
    {
        dsu[i] = i;
        ranks[i] = 0;
    }
}
int find_set(int v)
{
    if(v == dsu[v])
        return v;
    return dsu[v] = find_set(dsu[v]);
}
void merge(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a == b)
        return;
    if (ranks[a] < ranks[b])
        swap(a, b);
    dsu[b] = a;
    if (ranks[a] == ranks[b])
        ranks[a]++;
}