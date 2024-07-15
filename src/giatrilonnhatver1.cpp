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
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FON(i,a,b) for (int i = (a); i >= (b); i--)
#define open freopen("TEXT.INP","r",stdin)
#define close freopen("TEXT.OUT","w",stdin)

using namespace std;
const int N = 1e6;
int n,q,u,v,a[N];
struct node
{
    int v,lazy;
};
node t[N*4];
void build(int id, int l, int r)
{
    if (l==r)
    {
        t[id].v = a[l];
        t[id].lazy = a[l];
        return;
    }
    int m = (r+l)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id].v = t[id*2].v + t[id*2+1].v;
}
void push(int id)
{
    if (t[id].lazy)
    {
        t[id*2+1].v += t[id].lazy;
        t[id*2].v += t[id].lazy;
        t[id*2+1].lazy += t[id].lazy;
        t[id*2].lazy += t[id].lazy;
        t[id].lazy = 0;
    }
}
void upd(int id, int l, int r, int u,int v,int x)
{
    if (v < l || u > r) return;
    if (u <= l && v >= r)
    {
        t[id].lazy += x;
        t[id].v += x;
        return;
    }
    int m = (r+l)/2;
    push(id);
    upd(id*2,l,m,u,v,x);
    upd(id*2+1,m + 1,r,u,v,x);
    t[id].v = max(t[id*2].v ,t[id*2+1].v);
}
int get2(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return -INFINITY;
    if (u <= l && v >= r) return t[id].v;
    int m = (r+l)/2;
    push(id);
    return max(get2(id*2,l,m,u,v),get2(id*2+1,m+1,r,u,v));
}
int main()
{
    //freopen("TEXT.INP","r",stdin);
   // freopen("TEXT.OUT","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    FOR(i,1,n) a[i] = 0;
    build(1,1,n);
    int k,u,v,x;
    while (q--)
    {
        cin >> u >> v >> x;
        upd(1,1,n,u,v,x);
    }
    cin >> k;
    while (k--)
    {
        cin >> u >> v;
        cout << get2(1,1,n,u,v) << '\n';
    }
    return 0;
}
