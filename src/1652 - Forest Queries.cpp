#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e3+3;
int n,q,b[N][N],s[N][N],l,r,u,v;
char a[N][N];
int get(int l, int r, int u, int v){
    return s[u][v] - s[l-1][v] - s[u][r-1] + s[l-1][r-1];
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
        if (a[i][j]!='.') b[i][j]=1;
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + b[i][j];
    }
    while (q--){
        cin >> l >> r >> u >> v;
        cout << get(l,r,u,v) << '\n';
    }

    return 0;
}
