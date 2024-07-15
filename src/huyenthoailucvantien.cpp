#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll,ll>
#define Vii vector <ii>
#define X first
#define Y second
#define INF INFINITY
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define pi 3.14
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FON(i,a,b) for (int i = (a); i >= (b); i--)
#define open freopen("TEXT.INP","r",stdin)
#define close freopen("TEXT.OUT","w",stdin)

using namespace std;
const int N = 1e6;
int q,n,k,a[N];
int t[4*N];
void build(int id,int l, int r)
{
    if (l==r)
    {
        t[id] = a[l];
        return;
    }
    int m = (r+l)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id] = min(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return INF;
    if (u <= l && v >= r) return t[id];
    int m = (l + r)/2;
    return min(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int main()
{
    //open;
   // freopen("TEXT.OUT","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        FOR(i,1,n) cin >> a[i];
        build(1,1,n);
        FOR(i,1,n-k+1)
        {
            cout << get(1,1,n,i,i+k-1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
