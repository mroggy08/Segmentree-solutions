#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define vi2 vector<ii>
#define X first
#define Y second
#define pri priority_queue <ii,Vii, greater<ii>>
#define pb push_back
#define f1(i,n,m) for (int i=(n);i<=(m);++i)
#define fastIO ios_base::sync_with_stdio(0)

using namespace std;

const int N = 1e6+3;
const int MOD = 1e9+7;
int n,q,tc,l,r; ll A,B;
struct node
{
    ll lazyA,lazyB,val;
};
node t[N*4];
ll cal(ll add, int l, int r, ll A, ll B)
{
    return (add + A*(r+l)*(r-l+1)/2 + B*(r-l+1))%MOD;
}
void push(int id, int l, int m, int r)
{
    ll A = t[id].lazyA, B = t[id].lazyB;
        t[id*2].val = cal(t[id*2].val,l,m,A,B);
        t[id*2].lazyA += A;
        t[id*2].lazyB += B;
        t[id*2+1].val = cal(t[id*2+1].val,m+1,r,A,B);
        t[id*2+1].lazyA += A;
        t[id*2+1].lazyB += B;
        t[id].lazyA = t[id].lazyB = 0;
}
void up(int id, int l, int r,int u,int v, ll A, ll B)
{
    if (u>r||v<l) return;
    if (u<=l&&v>=r)
    {
        t[id].val = cal(t[id].val,l,r,A,B);
        t[id].lazyA += A;
        t[id].lazyB += B;
        return;
    }
    int m = (r+l)>>1;
    push(id,l,m,r);
    up(id*2,l,m,u,v,A,B);
    up(id*2+1,m+1,r,u,v,A,B);
    t[id].val = (t[id*2].val + t[id*2+1].val)%MOD;
}
ll get(int id, int l, int r, int u, int v)
{
    if (u>r||v<l) return 0;
    if (u<=l&&v>=r) return t[id].val;
    int m = (r+l)>>1;
    push(id,l,m,r);
    return (get(id*2,l,m,u,v) + get(id*2+1,m+1,r,u,v))%MOD;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("TASK.INP","r",stdin);
    freopen("TASK.OUT","w",stdout);
    fastIO;
    #endif // ONLINE_JUDGE
    cin >> n >> q;
    while (q--)
    {
        cin >> tc >> l >> r;
        if (tc==1)
        {
            cin >> A >> B;
            up(1,1,n,l,r,A,B-A*l);
        }
        else cout << get(1,1,n,l,r) << '\n';
    }
    return 0;
}
