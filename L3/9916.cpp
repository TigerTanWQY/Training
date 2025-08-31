#include <bits/stdc++.h>
using namespace std;

struct Home
{
	int s, v;
	bool operator<(const Home &A) const
	{ return v > A.v; }
} a[100003];
int q[100003], h[100003], qm[100003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i].s);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i].v);
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; --i)
		h[i] = max(h[i + 1], 2 * a[i].s + a[i].v);
	for(int i = 1; i <= n; ++i)
		qm[i] = max(qm[i - 1], a[i].s);
	for(int i = 1; i <= n; ++i)
		q[i] = q[i - 1] + a[i].v;
	for(int i = 1; i <= n; ++i)
		printf("%d\n", max(q[i - 1] + h[i], q[i] + 2 * qm[i]));
	return 0;
}