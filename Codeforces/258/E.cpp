#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
#define meow(cat...) fprintf(stderr, cat)

const int MaxN = 2e5 + 10;

struct edge
{
    int next, to;
} e[MaxN << 1];

struct node
{
    int l, r;
    int sum, len;
};

struct query
{
    int pos, l, r, c;
} Q[MaxN << 2];

int n, m, q, cnt, now, dfscnt, ans[MaxN];
int head[MaxN], dfn[MaxN], siz[MaxN];

struct SegmentTree
{
    node t[MaxN << 2];
    void build(int id, int l, int r)
    {
        t[id].l = l, t[id].r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
    }
    void pushup(int id)
    {
        int l = t[id].l, r = t[id].r;
        if (t[id].sum) t[id].len = r - l + 1;
        else
            t[id].len = t[id << 1].len + t[id << 1 | 1].len;
    }
    void modify(int id, int l, int r, int val)
    {
        if (t[id].r < l || r < t[id].l)
            return;
        if (l <= t[id].l && t[id].r <= r)
        {
            t[id].sum += val, pushup(id);
            return;
        }
        modify(id << 1, l, r, val);
        modify(id << 1 | 1, l, r, val), pushup(id);
    }
} T;

int cmp(query a, query b) { return a.pos < b.pos; }

void add(int a, int b, int l, int r)
{
    Q[++q] = (query){a, l, r, 1};
    Q[++q] = (query){b + 1, l, r, -1};
    // meow("$ %d %d %d %d\n", a, b, l, r);
}

void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}


void dfs(int u, int fa)
{
    dfn[u] = ++dfscnt, siz[u] = 1;
    for(int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, u), siz[u] += siz[v];
    }
}

signed main()
{
    n = read(), m = read(), T.build(1, 1, n);
    for(int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        add_edge(u, v), add_edge(v, u);
    }
    dfs(1, 0);
    for(int i = 1; i <= m; i++)
    {
        int a, b, l, r;
        a = read(), b = dfn[a] + siz[a] - 1, a = dfn[a];
        l = read(), r = dfn[l] + siz[l] - 1, l = dfn[l];
        add(a, b, a, b), add(a, b, l, r);
        add(l, r, a, b), add(l, r, l, r);
    }
    std::sort(Q + 1, Q + q + 1, cmp), now = 1;
    for(int i = 1; i <= n; i++)
    {
        while(now <= q && Q[now].pos == i)
            T.modify(1, Q[now].l, Q[now].r, Q[now].c), ++now;
        ans[i] = T.t[1].len, ans[i] ? --ans[i] : 0;
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[dfn[i]]);
    return 0;
}
