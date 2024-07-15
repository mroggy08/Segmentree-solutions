#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 1e6+6;
int n,a,b;
ll A[N],kq=LLONG_MIN;
deque <int> dq;
int main()
{
    if(fopen("1.inp","r")){freopen("1.inp","r",stdin);freopen("1.out","w",stdout);}
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++){
        cin >> A[i];
        A[i]+=A[i-1];
    }
    for (int i = a; i <= n; i++){
        while (dq.size() && dq.front()<i-b+1) {
//            cout << dq.front() << '\n';
            dq.pop_front();
        }
        while (dq.size() && A[dq.back()-1] >= A[i-a]) {
//            cout << dq.back() << '\n';
            dq.pop_back();
        }
        dq.push_back(i-a+1);
        if (dq.size()) kq=max(kq,A[i]-A[dq.front()-1]);
    }
    cout << kq;
    return 0;
}
