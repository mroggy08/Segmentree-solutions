#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define Vii vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const int N = 1e6+3;
const int M = 1e3+3;
const int mod = 1e9+7;

int n,q,u,v,idx,a[N];
ll t[N*4];
void build(int id, int l, int r)
{
    if (l==r) {
        t[id]=a[l];return;
    }
    int m = (r+l)>>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id] = t[id*2] + t[id*2+1];
}
void up(int id, int l, int r, int u, int v)
{
    if (u<l||u>r) return;
    if (l==r)
    {
        t[id] += v;
        // a[id] += v;
        return;
    }
    int m = (r+l)>>1;
    up(id*2,l,m,u,v);
    up(id*2+1,m+1,r,u,v);
    t[id] = t[id*2] + t[id*2+1];
}
ll get(int id, int l, int r, int u, int v)
{
    if (v<l||u>r)return 0;
    if (u<=l&&v>=r)
    {
        // t[id] += v;
        return t[id];
    }
    int m = (r+l)>>1;
    return get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("TASK.INP","r",stdin);
    freopen("TASK.OUT","w",stdout);
    #endif // ONLINE_JUDGE
    fastIO;
    cin>>n>>q; f1(i,1,n) cin>>a[i]; build(1,1,n);
    while (q--) {
        cin >> idx >> u >> v;
        if (idx==1) {
            up(1,1,n,u,v);
            // cout << get(1,1,n,1,5) << '\n';
        }
        else cout << get(1,1,n,u,v) << '\n';
    }
    return (0^0);
}
