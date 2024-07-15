#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+5;
int n,q,a[N],t[N*4],x;
void build(int id, int l, int r){
    if (l==r) {
        t[id]=a[l];return;
    }
    int m = (r+l)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=max(t[id*2],t[id*2+1]);
}
void up(int id, int l, int r, int x){
    if (l==r){
        t[id]-=x;
        cout << l << ' ';
        return;
    }
    int m = (r+l)/2;
    if (t[id*2]>=x) up(id*2,l,m,x);
    else up(id*2+1,m+1,r,x);
    t[id]=max(t[id*2],t[id*2+1]);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    while (q--){
        cin >> x;
        if (t[1] < x) cout << "0 ";
        else up(1,1,n,x);
    }


    return 0;
}
