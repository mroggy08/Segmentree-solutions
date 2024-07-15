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
int m,n,q;
struct sv{
    ll bit[N];
    sv(){memset(bit,0LL,sizeof bit);}
    void upd(int i, ll x){
        for (;i<=n;i+=i&-i) bit[i]+=x;
    }
    ll get(int i){
        ll res = 0;
        for (;i;i-=i&-i) res+=bit[i];
        return res;
    }
} f[2];
void add(int l, int r, ll x){
    f[0].upd(l,x);
    f[0].upd(r+1,-x);
    f[1].upd(l,x*(l-1));
    f[1].upd(r+1,-x*r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("1");
    cin >> m >> n >> q;
    f1(i,1,n){
        ll x; cin >> x;
        add(i,i,x);
    }
    while (q--){
        int k,l,r; ll x;
        cin >> k >> l >> r;
        if (k==1){
            cin >> x;
            add(l,r,x);
        } else {
            ll ans = ((f[0].get(r)*r - f[1].get(r)) - (f[0].get(l-1)*(l-1) - f[1].get(l-1)))%m;
            cout << ans << '\n';
        }
    }
    return 0;
}

