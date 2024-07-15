#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define ll long long
#define l2 pair<ll,ll>
#define vi vector<int>
#define vi2 vector<ii>
#define vil vector<il>
#define vl2 vector<l2>
#define lb lower_bound
#define ub upper_bound
#define li pair<ll,int>
#define il pair<int,ll>
#define vli vector<lli>
#define i2 pair<int,int>
#define ALL(a) a.begin(),a.end()
#define fd(i,n) for (int i = n; i > 0; i--)
#define f1(i,n,m) for (int i = n; i <= m; i++)
#define file(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
const int N = 2e5+5;
int n,q,a[N],k,u,v,x;
struct sv
{
    ll gt,lazy;
};
sv t[N*4];
void build(int id, int l,int r){
    if (l==r){
        t[id].gt=a[l];
        return;
    }
    int m=(r+l)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id].gt=max(t[id*2].gt,t[id*2+1].gt);
}
void push(int id, int l, int r){
    if (t[id].lazy){
        int m = (r+l)/2;
        t[id*2].gt += t[id].lazy;
        t[id*2+1].gt += t[id].lazy;
        t[id*2].lazy += t[id].lazy;
        t[id*2+1].lazy += t[id].lazy;
        t[id].lazy = 0;
    }
}
void upd(int id, int l, int r, int u, int v,int x){
    if (u>r||v<l) return;
    if (u<=l&&v>=r) {
        t[id].gt+=x;
        t[id].lazy += x;
        return;
    }
    push(id,l,r);
    int m = (r+l)/2;
    upd(id*2,l,m,u,v,x);
    upd(id*2+1,m+1,r,u,v,x);
    t[id].gt=max(t[id*2].gt,t[id*2+1].gt);
}
ll get(int id, int l, int r, int u, int v){
    if (u>r||v<l) return -1e18;
    if (u<=l&&v>=r) {
        return t[id].gt;
    }
    push(id,l,r);
    int m = (r+l)/2;
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("1");
    cin >> n >> q;
    f1(i,1,n) cin>>a[i];
    build(1,1,n);
    while (q--){
        cin >> k >> u;
        if (k==2){
            cout << get(1,1,n,u,u) << '\n';
        } else {
            cin >> v >> x;
            upd(1,1,n,u,v,x);
        }
    }
    return 0;
}
