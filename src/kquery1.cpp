#include <bits/stdc++.h>

using namespace std;

const int N = 100007;
int n, m, l, r, k, a[N];
vector <int> tree[N * 4];

void cal(vector <int> &a, vector <int> &b, vector <int> &s)
{
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
                if (a[i] < b[j])
                        s.push_back(a[i]), i++;
                else
                        s.push_back(b[j]), j++;

        }
        while (i < a.size())
                s.push_back(a[i]), i++;
        while (j < b.size())
                s.push_back(b[j]), j++;
}

void build(int l, int r, int id)
{
        if (l == r)
        {
                tree[id].push_back(a[l]);
                return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, id * 2);
        build(mid + 1, r, id * 2 + 1);
        cal(tree[id * 2], tree[id * 2 + 1], tree[id]);
}

int get(int l ,int r, int u, int v, int k, int id)
{
        if (v < l || r < u)
                return 0;
        if (u <= l && r <= v)
                return tree[id].end() - upper_bound(tree[id].begin(), tree[id].end(), k);
        int mid = (l + r) >> 1;
        return get(l, mid, u, v, k, id * 2) + get(mid + 1, r, u, v, k, id * 2 + 1);
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin >> n;
        for (int i = 1; i <= n; i++)
                cin >> a[i];
        build(1, n, 1);
        cin >> m;
        while(m--)
        {
                cin >> l >> r >> k;
                cout << get(1, n, l, r, k, 1) << "\n";
        }
        return 0;
}
