#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define vi2 vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0)

using namespace std;

const int N = 200003;
const int base = -1e9;
int n,q,u,v,a[N];
struct edm
{
    ll sum,best,pre,suf;
}t[N*4];
edm cal(edm a, edm b)
{
    edm kq;
    kq.sum = a.sum + b.sum;
    kq.pre = max(a.pre, b.pre + a.sum);
    kq.suf = max(b.suf, a.suf + b.sum);
    kq.best = max({a.best,b.best,a.suf + b.pre});
    return kq;
}
void build(int id, int l, int r)
{
    if (l==r)
    {
        t[id] = {a[l],a[l],a[l],a[l]};
        return;
    }
    int m = (r+l)>>1;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id] = cal(t[id*2],t[id*2+1]);
}
void up(int id, int l, int r,int u, int val){
    if (u<l||u>r) return;
    if (u<=l&&u>=r) {
        t[id]={val,val,val,val};
        return;
    }
    int m = (r+l)>>1;
    up(id*2,l,m,u,val);
    up(id*2+1,m+1,r,u,val);
    t[id] = cal(t[id*2],t[id*2+1]);
}
edm get(int id, int l, int r,int u, int v)
{
    if (u>r||v<l) return {0,base,base,base};
    if (u<=l&&v>=r) return t[id];
    int m = (r+l)>>1;
    edm t1 = get(id*2,l,m,u,v);
    edm t2 = get(id*2+1,m+1,r,u,v);
    return cal(t1,t2);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    f1(i,1,n) cin >> a[i];
    build(1,1,n);
    while (q--)
    {
        cin >> u >> v;
        up(1,1,n,u,v);
        cout << max(0LL,get(1,1,n,1,n).best) << '\n';
    }
    return 0;
}
