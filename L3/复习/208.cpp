#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1003;
struct TreeNode
{ int L, R, fa; }
a[N];
int b[N], c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, u, v;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].L >> a[i].R;
		if(a[i].L)
			a[a[i].L].fa = i;
		if(a[i].R)
			a[a[i].R].fa = i;
	}
	cin >> u >> v;
	int l1 = 0, l2 = 0;
	for(; u != 1; u = a[u].fa)
		b[++l1] = u;
	b[++l1] = 1;
	for(int i = 1, j = l1; i < j; ++i, --j)
		swap(b[i], b[j]);
	for(; v != 1; v = a[v].fa)
		c[++l2] = v;
	c[++l2] = 1;
	for(int i = 1, j = l2; i < j; ++i, --j)
		swap(c[i], c[j]);
	int x = 0;
	for(int i = 1; i <= l1 && i <= l2; ++i)
		if(b[i] == c[i])
			x = b[i];
		else
			break;
	cout << x;
	return 0;
}