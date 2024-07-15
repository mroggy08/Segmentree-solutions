#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n,q,u,v,type;
long long x;
long long a[N],tree[4*N];
void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = a[l];
        return;
    }
    else
    {
        int mid = (r + l) / 2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id] = tree[id*2] + tree[id*2+1];
    }
}
long long get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && v >= r) return tree[id];
    int mid = (r+l)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}
void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r) return;
    if (l == r)
    {
        tree[id] = val;
        return;
    }
    int m = (l+r)/2;
    update(id*2,l,m,pos,val);
    update(id*2+1,m+1,r,pos,val);
    tree[id] = tree[id*2] + tree[id*2+1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) a[i] = 0;
    build(1,1,n);
    while (q--)
    {
        cin >> type >> u >> v;
        if (type == 1) update(1,1,n,u,v);
        else
        {
            x = get(1,1,n,u,v);
            cout << x << '\n';
        }

    }
    return 0;
}
