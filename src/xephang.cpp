#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int LG = 16;
const int N = 5e4+9;
int n,a[N],q,u,v;
int ma[N][LG+2],mi[N][LG+2];
int GM(int l, int r){
    int k = __lg(r-l+1);
    return max(ma[l][k],ma[r-(1<<k)+1][k]);
}
int GMI(int l, int r){
    int k = __lg(r-l+1);
    return min(mi[l][k],mi[r-(1<<k)+1][k]);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        ma[i][0] = a[i];
        mi[i][0] = a[i];
    }
    for (int j = 1; j <= LG; j++){
        for (int i = 1; i + (1<<j)-1<=n; i++){
            ma[i][j] = max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
            mi[i][j] = min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
        }
    }
    while (q--){
        cin >> u >> v;
        cout << GM(u,v) - GMI(u,v) << '\n';
    }
    cerr << "Time: " << fixed << setprecision(4) << (double)(1000*clock()/CLOCKS_PER_SEC) << " ms\n";
    return 0;
}
