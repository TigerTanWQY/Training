#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 60000
#define LL long long
const int Delta = 30001;

struct Tree
{
    int l, r;
    LL maxv;
    LL tag;
};
Tree tree[4 * MAXN];
pair<int, int> a[15000];
int s, w, n;
void build(int p, int l, int r)
{
    tree[p].l = l;
    tree[p].r = r;
    tree[p].tag = 0;
    if (l == r)
    {
        tree[p].maxv = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    tree[p].maxv = max(tree[2 * p].maxv, tree[2 * p + 1].maxv);
}
void pushdown(int p)
{
    int l = 2 * p, r = 2 * p + 1;
    if (tree[p].tag != 0)
    {
        tree[l].tag += tree[p].tag;
        tree[l].maxv += tree[p].tag;
        tree[r].tag += tree[p].tag;
        tree[r].maxv += tree[p].tag;
        tree[p].tag = 0;
    }
}
void update(int p, int l, int r, LL v)
{
    if (l <= tree[p].l && tree[p].r <= r)
    {
        tree[p].tag += v;
        tree[p].maxv += v;
        return;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    if (l <= mid)
        update(2 * p, l, r, v);
    if (r >= mid + 1)
        update(2 * p + 1, l, r, v);
    tree[p].maxv = max(tree[2 * p].maxv, tree[2 * p + 1].maxv);
}
LL ask(int p, int l, int r)
{
    if (l <= tree[p].l && tree[p].r <= r)
        return tree[p].maxv;
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    LL ret = 0;
    if (l <= mid)
        ret = max(ret, ask(2 * p, l, r));
    if (r >= mid + 1)
        ret = max(ret, ask(2 * p + 1, l, r));
    return ret;
}
int main()
{
    cin >> s >> w;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    build(1, -30000 + Delta, 30000 + Delta);
    sort(a, a + n); // sorting of pair array is accord '.first' from small to big
    int l = 0, r = -1;
    int ans = 0;
    for (int x = -30000; x <= 30000; x++)
    {
        int xx = x + s;
        while (l < n && a[l].first < x)
        {
            update(1, a[l].second + Delta, a[l].second + w + Delta, -1);
            l++;
        }
        while (r + 1 < n && a[r + 1].first <= xx)
        {
            update(1, a[r + 1].second + Delta, a[r + 1].second + w + Delta, 1);
            r++;
        }
        int tmp = tree[1].maxv;
        ans = max(ans, tmp);
        // cout << "ok" << x << " ";
    }
    printf("%d\n", ans);
    return 0;
}
