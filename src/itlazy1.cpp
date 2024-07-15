#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int inf = 1e9+7;
long long a[N], t[4*N],lazy[4*N];
int n,q,l,r,type,x;

void build(int id, int l, int r)
{
    if (l == r)
    {
        t[id] = a[l];
        return;
    }
    long m = (l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id] = max(t[id*2],t[id*2+1]);
}

void push(int id)
{
    if (lazy[id])
    {
        t[id*2] += lazy[id];
        lazy[id*2] += lazy[id];
        t[id*2+1] += lazy[id];
        lazy[id*2+1] += lazy[id];
        lazy[id] = 0;
    }
}

long long get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return -INFINITY;
    if (u <= l && v >= r ) return t[id];
    long m = (l+r)/2;
    push(id);
    long long get1 = get(id*2,l,m,u,v);
    long long get2 = get(id*2+1,m+1,r,u,v);
    return max(get1,get2);
}

void update(int id, int l, int r, int u, int v, int x)
{
    if (u > r || v < l) return;
    if (u <= l && v >= r)
    {
        lazy[id] += x;
        t[id] += x;
        return;
    }
    push(id);
    long m = (l+r)/2;
    update(id*2,l,m,u,v,x);
    update(id*2+1,m+1,r,u,v,x);
    t[id] = max(t[id*2],t[id*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n ;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    cin >> q;
    while (q--)
    {
        cin >> type >> l >> r;
        if (type == 1)
        {
            cin >> x;
            update(1,1,n,l,r,x);
        }
        else
            cout << get(1,1,n,l,r) << '\n';
    }
    return 0;
}
