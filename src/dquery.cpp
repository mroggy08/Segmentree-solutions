#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> void debug(T &&t) {cerr << t;}
template<typename T, typename ...U> void debug(T &&t, U&&... u) {
    cerr << t << " ";
    debug(u...);
}
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define bug(...) cerr << "[", debug(__VA_ARGS__), cerr << "]\n"
#define timecerr cerr << "\n-=< Time: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms >=-\n";
#define author cerr << "Coded by QUQ - THPT Chuyen Ly Tu Trong";

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define tlll tuple<ll, ll, ll>
#define matrix vector<vector<int>>

#define endl '\n'
#define sp ' '
#define pb push_back
#define ins insert
#define ff first
#define ss second
#define ii make_pair
#define iii make_tuple
#define ALL(v) (v).begin(), (v).end()

#define sz(i) (int) (i.size())
#define sqr(a) ((ll)(a)*(a))
#define BIT(a) (1LL << (a))
#define bslow low = mid+1
#define bshigh high = mid-1
#define bsmid __typeof(low) mid = (high-low)/2 + low
#define rep(i, b) for (int i = 0, _b = (b); i <= _b; ++i)
#define fto(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define fdto(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define fec(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)

#define OO (ll) (1e18+7)
#define oo (int) (1e9+7)
#define maxM (int) (1e6+5)
#define maxN (int) (3e4+5)

vector<pii> q[maxN];
int n, k, a[maxN], nxt[maxN], bit[maxN], ans[(int)(2e5+5)], m[maxM];

void update(int i) {
    for (; i <= n; i += -i & i) bit[i]++;
}
int sum(int i) {
    int res = 0;
    for (; i > 0; i -= -i & i) res += bit[i];
    return res;
}
int query(int l, int r) {
//    cout << sum(r) << ' ' << sum(l-1) << '\n';
    return sum(r)-sum(l-1);
}
void solve() {
    cin >> n;
    fto(i, 1, n) cin >> a[i];

    fdto(i, n, 1) {
        if (!m[a[i]]) update(i);
        else nxt[m[a[i]]] = i;
        m[a[i]] = i;
    }
    cin >> k;
    fto(i, 1, k) {
        int l, r; cin >> l >> r;
        q[r].pb({l, i});
    }
    fdto(r, n, 1) {
        for (pii j : q[r]) {
            int l = j.ff, idx = j.ss;
            ans[idx] = query(l, r);
        }
        if (nxt[r]) update(nxt[r]);
    }

    fto(i, 1, k) cout << ans[i] << endl;
}
signed main() {
    fastio
    #ifndef ONLINE_JUDGE
//    #define TEST "TEST"
//    if (fopen(TEST".inp", "r"))
//        freopen(TEST".inp", "r", stdin),
//        freopen(TEST".out", "w", stdout);
    #endif

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }

    #ifndef ONLINE_JUDGE
        timecerr; author;
    #endif
    return 0;
}
