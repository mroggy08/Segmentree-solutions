#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define Vii vector <ii>
#define X first
#define Y second
#define INF INFINITY
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define pi 3.14
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define f0(i,n,m) for (int i=(n);i<(m);++i)
#define open freopen("TEXT.INP","r",stdin)
#define close freopen("TEXT.OUT","w",stdin)
#define Vi vector<int>
using namespace std;
const int N = 1e6;
int n,a[N],q,type,u,v,k;
vector <int> t[N*4];
void cal(Vi &a, Vi &b, Vi &c)
{
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j]) c.pb(a[i]),i++;
        else c.pb(b[j]),j++;
    }
    while (i < a.size()) c.pb(a[i]),i++;
    while (j < b.size()) c.pb(b[j]),j++;
}
void build(int id, int l, int r)
{
    if (l==r)
    {
        t[id].pb(a[l]);
        return;
    }
    int m = (r+l)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    cal(t[id*2],t[id*2+1],t[id]);
}
void upd(int id, int l, int r, int u, int v)
{
    if (u < l || u > r) return ;
    if (u >= l && r >= u)
    {
        t[id].erase(lower_bound(t[id].begin(),t[id].end(),a[u]));
        t[id].insert(lower_bound(t[id].begin(),t[id].end(),v),v);
        if (l == r)
            return;
    }
    int m = (r+l)>>1;
    upd(id*2,l,m,u,v);
    upd(id*2+1,m+1,r,u,v);
    //cal(t[id*2],t[id*2+1],t[id]);
}
int get(int id, int l, int r, int u, int v, int k)
{
    if (u > r || v < l) return 0;
    if (u <= l && v >= r) return t[id].end() - upper_bound(t[id].begin(),t[id].end(),k);
    int m = (r+l)/2;
    return get(id*2,l,m,u,v,k) + get(id*2+1,m+1,r,u,v,k);
}
int main()
{
    //open;
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    f1(i,1,n) cin >> a[i];
    build(1,1,n);
    cin >> q;
    while (q--)
    {
        cin >> type >> u >> v;
        if (type)
        {
            cin >> k;
            cout << get(1,1,n,u,v,k) << '\n';
        }
        else upd(1,1,n,u,v),a[u]=v;
    }
    return 0;
}
