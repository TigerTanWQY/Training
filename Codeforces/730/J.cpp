#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 20;
int n, m, f[10020], sum, ans[10020];
struct Node {
    int a, b;
} c[N];
inline int read() {
    char ch = getchar();
    int ans = 0, cf = 1;

    while (ch < '0' || ch > '9') {
        if (ch == '-')
            cf = -1;

        ch = getchar();
    }

    while (ch >= '0' && ch <= '9') {
        ans = (ans << 1) + (ans << 3) + (ch ^ 48);
        ch = getchar();
    }

    return ans * cf;
}
bool cmp1(Node a, Node b) {
    if (a.a != b.a)
        return a.a > b.a;
    else
        return a.b > b.b;
}
int main() {
    n = read();

    for (int i = 1; i <= n; i += 1)
        c[i].a = read(), m += c[i].a;

    for (int i = 1; i <= n; i += 1)
        c[i].b = read(), sum += c[i].b;

    sort(c + 1, c + n + 1, cmp1);
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;

    for (int i = 1; i <= n; i += 1) {
        for (int j = sum; j >= c[i].b; j -= 1) {
            if (f[j - c[i].b] + 1 < f[j] || (f[j - c[i].b] + 1 == f[j] && (ans[j - c[i].b] + c[i].a) > ans[j])) {
			   f[j] = f[j - c[i].b] + 1;
                ans[j] = ans[j - c[i].b] + c[i].a;
            }
            if (j > m) {
                if (f[m] > f[j] || (f[m] == f[j] && ans[j] > ans[m])) {
                    f[m] = f[j];
                    ans[m] = ans[j];
                }
            }
        }
    }

    printf("%d %d\n", f[m], m - ans[m]);
    return 0;
}
