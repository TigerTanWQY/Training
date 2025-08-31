#include <iostream>
using namespace std;

const int N = 1000003;
struct TreeNode
{ int L, R, v; }
a[N];
int d[N];

int dfs(const int& u) {
	if(d[u])
		return d[u];
	d[u] = a[u].v;
	if(a[u].L)
		d[u] += dfs(a[u].L);
	if(a[u].R)
		d[u] += dfs(a[u].R);
	return d[u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].L >> a[i].R;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].v;
	dfs(1);
	for(int i = 1; i <= n; ++i)
		cout << d[i] << ' ';
	return 0;
}