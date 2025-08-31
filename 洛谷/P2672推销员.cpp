#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100003;
struct Home
{
	int s, v;
	bool operator<(const Home &A) const
	{ return v > A.v; }
} a[N];
int q[N], h[N], qm[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].s;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].v;
	sort(a + 1, a + n + 1);
	/* ‘§¥¶¿Ì */
	for(int i = n; i; --i)
		h[i] = max(h[i + 1], 2 * a[i].s + a[i].v);
	for(int i = 1; i <= n; ++i)
		qm[i] = max(qm[i - 1], a[i].s);
	for(int i = 1; i <= n; ++i)
		q[i] = q[i - 1] + a[i].v;
	for(int i = 1; i <= n; ++i)
		cout << max(q[i - 1] + h[i], q[i] + 2 * qm[i]) << '\n';
	return 0;
}