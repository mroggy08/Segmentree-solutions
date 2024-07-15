#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 5e5+5;
const int lg = 19;
int n,k;
ll x,a[N][lg+2],kq;
ll gcd(ll a, ll b){
    return __gcd(a,b);
}
ll Max(ll a, ll b){
    if (a>b) return a; return b;
}
ll get(int l, int r){
    int k = __lg(r-l+1);
    return gcd(a[l][k],a[r-(1<<k)+1][k]);
}
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> x;
        a[i][0] = x;
    }
    for (int j = 1; j <= lg; j++){
        for (int i = 1; i + (1<<j)-1 <= n; i++){
            a[i][j] = gcd(a[i][j-1],a[i+(1<<(j-1))][j-1]);
        }
    }
    for (int i=k;i<=n;i++){
        kq = Max(kq,get(i-k+1,i));
    }
    cout << kq;
    return 0;
}
