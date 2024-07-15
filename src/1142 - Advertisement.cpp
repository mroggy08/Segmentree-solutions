#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define f1(i,n,m) for (int i=n; i<=m; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2e5+3;
int n,a[N],r[N],l[N];
ll kq;
stack<int> st;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    cin >> n;
    a[0] = -1; a[n+1]=-1;
    f1(i,1,n) cin >> a[i];
    st.push(0);
    f1(i,1,n){
        while (st.size() && a[st.top()]>=a[i]) st.pop();
        if (st.size()) l[i]=st.top()+1;
        st.push(i);
    }
    while (st.size()) st.pop(); st.push(n+1);
    for (int i = n; i > 0; i--){
        while (st.size() && a[st.top()]>=a[i]) st.pop();
        if (st.size()) r[i]=st.top()-1;
        st.push(i);
    }
    f1(i,1,n){
        kq = max(kq,1LL*(r[i]-l[i]+1)*a[i]);
    }
    cout << kq;

    return 0;
}
