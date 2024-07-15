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
const int N = 1e5+5;
int n,q,a[N],idx;
ll x;
struct sv{
    ll val,lazy;
};
sv t[N*4];
void push(int id, int l, int r){
    if (t[id].lazy){
        int m = (r+l)>>1;
        t[id*2].val += (m-l+1)*t[id].lazy;
        t[id*2+1].val += t[id].lazy*(r-m);
        t[id*2].lazy += t[id].lazy;
        t[id*2+1].lazy += t[id].lazy;
        t[id].lazy = 0;
    }
}
void build(int id, int l, int r){
    if(l==r){
        t[id].val=a[l];
        return;
    }
    int m = (r+l)>>1;
    build(id*2,l,m);build(id*2+1,m+1,r);
    t[id].val = t[id*2].val + t[id*2+1].val;
}
void upd(int id, int l, int r, int u, int v, int x){
    if (u>r||v<l) return;
    if (u<=l&&v>=r){
        t[id].val+= x*(r-l+1);
        t[id].lazy += x;
        return;
    }
    int m = (r+l)>>1;
    push(id,l,r);
    upd(id*2,l,m,u,v,x);
    upd(id*2+1,m+1,r,u,v,x);
    t[id].val = t[id*2].val + t[id*2+1].val;
}
ll get(int id,int l, int r, int u, int v){
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r){
        return t[id].val;
    }
    push(id,l,r);
    int m = (r+l)>>1;
    return get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v);
}
int tknp(ll x){
    int res = -1, l = 1,r = n;
    while (l<=r){
        int m = (r+l)>>1;
        if (get(1,1,n,1,m) - get(1,1,n,1,m-1) >= x){
            res = m;
            r = m-1;
        } else l = m+ 1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("1");
    cin >> n;
    f1(i,1,n) cin >> a[i];
    sort(a+1,a+n+1);
    build(1,1,n);
    cin >> q;
    while (q--){
        cin >> x;
        idx = tknp(x);
        if (idx!=-1){
            cout << n-idx + 1 << '\n';
            upd(1,1,n,idx,n,-1);
        } else  cout << "0\n";
    }
    return 0;
}


