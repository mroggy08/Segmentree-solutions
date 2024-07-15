#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+5;
int n,q,a[N],T,u,v,x;
struct sv{
    ll val,lazy1,lazy2;
};
sv t[N*4];
void build(int id, int l, int r){
    if (l==r) {
        t[id].val = a[l];
        return;
    }
    int m = (r+l)>>1;
    build(id*2,l,m); build(id*2+1,m+1,r);
    t[id].val = t[id*2].val + t[id*2+1].val;
}
void push(int id, int l, int r){
    int mid = (r+l)>>1;
    if (t[id].lazy2){
        ll khoa = t[id].lazy2;
        t[id*2].val =  1LL*khoa*(mid-l+1);
        t[id*2+1].val = 1LL*khoa*(r-mid);
        t[id*2+1].lazy1 = t[id*2].lazy1 = 0;
        t[id*2+1].lazy2 = t[id*2].lazy2 = khoa;
        t[id].lazy2 = 0;
    }
    if (t[id].lazy1){
        ll khoa = t[id].lazy1;
        t[id*2].val +=  1LL*khoa*(mid-l+1);
        t[id*2+1].val += 1LL*khoa*(r-mid);
        t[id*2+1].lazy1 += khoa;
        t[id*2].lazy1 += khoa;
        t[id].lazy1 = 0;
    }
}
void up1(int id, int l, int r, int u, int v, int gt){
    if (u>r||v<l) return;
    if (u<=l&&v>=r){
        t[id].val += 1LL*(r-l+1)*gt;
        t[id].lazy1 += gt;
        return;
    }
    push(id,l,r);
    int m = (r+l)>>1;
    up1(id*2,l,m,u,v,gt); up1(id*2+1,m+1,r,u,v,gt);
    t[id].val = t[id*2].val + t[id*2+1].val;
}
void up2(int id, int l, int r, int u, int v, int gt){
    if (u>r||v<l) return;
    if (u<=l&&v>=r){
        t[id].val = 1LL*(r-l+1)*gt;
        t[id].lazy1 = 0;
        t[id].lazy2 = gt;
        return;
    }
    push(id,l,r);
    int m = (r+l)>>1;
    up2(id*2,l,m,u,v,gt); up2(id*2+1,m+1,r,u,v,gt);
    t[id].val = t[id*2].val + t[id*2+1].val;
}
ll get(int id, int l, int r, int u, int v){
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r){
        return t[id].val;
    }
    push(id,l,r);
    int m = (r+l)>>1;
    return get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1,1,n);
    while (q--){
        cin >> T;
        if (T==1){
            cin >> u >> v >> x;
            up1(1,1,n,u,v,x);
        } else if (T==2){
            cin >> u >> v >> x;
            up2(1,1,n,u,v,x);
        } else {
            cin >> u >> v;

            cout << get(1,1,n,u,v) << '\n';
        }
    }
    return 0;
}
