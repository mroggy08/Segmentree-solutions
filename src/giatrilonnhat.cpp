#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
struct sv{
    int val,lz;
};
const int N = 5e4+5;
int n,q,loai,u,v,w;
sv t[N*4];
void push(int id){
    if(t[id].lz){
        t[id*2].val += t[id].lz;
        t[id*2+1].val += t[id].lz;
        t[id*2].lz += t[id].lz;
        t[id*2+1].lz += t[id].lz;
        t[id].lz = 0;
    }
}
void up(int id, int l, int r,int u, int v, int va){
    if (u>r||v<l) return;
    if (u<=l&&v>=r){
        t[id].val += va;
        t[id].lz += va; return;
    }
    int m = (r+l)/2;
    push(id);
    up(id*2,l,m,u,v,va); up(id*2+1,m+1,r,u,v,va);
    t[id].val = max(t[id*2].val,t[id*2+1].val);
}
int get(int id, int l, int r, int u, int v){
    if (u>r||v<l) return INT_MIN;
    if (u<=l&&v>=r) return t[id].val;
    int m = (r+l)/2;
    push(id);
    return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    while (q--){
        cin >> loai;
        if (loai){
            cin >> u >> v;
            cout << get(1,1,n,u,v) << '\n';
        }
        else {
            cin >> u >> v >> w;
            up(1,1,n,u,v,w);
        }
    }


    return 0;
}
