#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
#define bit(i,x) ((x>>i)&1)
#define bp __builtin_popcount
#define inf INT_MAX
using namespace std;
const int N = 2e5+3;
int n,q,a[N],u,v,t[N*4];
void build(int id, int l, int r)
{
    if (l==r)
    {
        t[id]=a[l]; return;
    }
    int m = (r+l)>>1;
    build(id*2,l,m); build(id*2+1,m+1,r);
    t[id]=min(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (u>r || v<l) return INT_MAX;
    if (u<=l && v>=r) return t[id];
    int m = (r+l)>>1;
//    build(id*2,l,m); build(id*2+1,m+1,r);
//    t[id]=min(t[id*2],t[id*2+1]);
    return min(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define task "task"
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> q;
    f1(i,1,n) cin >> a[i];
    build(1,1,n);
    while (q--)
    {
        cin >> u >> v;
        cout << get(1,1,n,u,v) << '\n';
    }
    return 0;
}
