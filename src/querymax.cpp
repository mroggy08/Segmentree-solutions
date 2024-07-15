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
const int N = 1e5+3;
struct sv
{
    ll val, lazy;
};
sv t[N*4];
int n,q,tr,u,v;
ll x,a[N];
void build(int id, int l, int r)
{
    if (l==r)
    {
        t[id].val=a[l]; return;
    }
    int m = (r+l)>>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id].val=max(t[id*2].val,t[id*2+1].val);
}
void push(int id)
{
    if (t[id].lazy)
    {
        t[id*2].val += t[id].lazy;
        t[id*2+1].val += t[id].lazy;
        t[id*2].lazy += t[id].lazy;
        t[id*2+1].lazy += t[id].lazy;
        t[id].lazy = 0;
    }
}
void upd(int id, int l, int r, int u, int v, ll x)
{
    if (u>r||v<l) return;
    if (u<=l && v>=r) {
        t[id].val += x;
        t[id].lazy += x;
        return;
    }
    int m = (r+l)>>1;
    push(id);
    upd(id*2,l,m,u,v,x);
    upd(id*2+1,m+1,r,u,v,x);
    t[id].val = max(t[id*2].val,t[id*2+1].val);
}
ll  get(int id, int l, int r, int u, int v)
{
    if (u>r||v<l) return INT_MIN;
    if (u<=l && v>=r) {
        return t[id].val;
    }
    int m = (r+l)>>1;
    push(id);
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
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
        cin >> tr >> u >> v;
        if (tr==1) {
            cin>>x;
            upd(1,1,n,u,v,x);
        }
        else cout << get(1,1,n,u,v) << '\n';
    }
    return 0;
}
