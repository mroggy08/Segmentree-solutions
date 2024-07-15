#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<int,int>
#define f first
#define s second
#define vi vector<int>
const int N = 1e6,M = 1e3;
int n,q,u,v,a[N];

int main()
{
    fastIO;
    #ifndef ONLINE_JUDGE
    freopen("TEXT.INP","r",stdin);
    #endif // ONLINE_JUDGE
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <int> p(n+1);
    for (int i = 1; i <= n; i++) p[i] = p[i-1] ^ a[i];
    //for (int i = 1; i <= n; i++) cout << p[i] << ' ';

    while (q--)
    {
        cin >> u >> v;
        cout << (p[v] ^ p[u-1]) << '\n';
    }
    return 0;
}
