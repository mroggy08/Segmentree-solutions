#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sv{
    int lz,val;
};
sv t[1000003];
int n,m,u,v,tp;
void push(int id, int l, int r, int m){
    int tmp = t[id].lz;
    if (tmp%2!=0) t[id*2].val = - t[id*2].val + (m-l+1);
    if (tmp%2!=0) t[id*2+1].val = - t[id*2+1].val + (r-m);
    t[id*2].lz += tmp;
    t[id*2+1].lz += tmp;
    t[id].lz = 0;
}
void up(int id, int l, int r, int u, int v){
    if (u>r || v<l) return;
    if (u<=l && v>=r){
        t[id].lz++;
        t[id].val = (r-l+1) - t[id].val;
        return;
    }
    int m = (r+l)/2;
    push(id,l,r,m);
    up(id*2,l,m,u,v);
    up(id*2+1,m+1,r,u,v);
    t[id].val=t[id*2].val+t[id*2+1].val;
}
int get(int id, int l, int r, int u, int v){
    if (u>r || v<l) return 0;
    if (u<=l && v>=r){
        return t[id].val;
    }
    int m = (r+l)/2;
    push(id,l,r,m);
    return get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while (m--){
        cin >> tp >> u >> v;
        if (tp){
            cout << get(1,1,n,u,v) << '\n';
        } else up(1,1,n,u,v);
    }

    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
