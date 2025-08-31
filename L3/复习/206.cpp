#include <iostream>
using namespace std;

const int N = 1003;
struct TreeNode
{ int L, R, v; }
a[N];

int dfs(const int& u) {
	int res = a[u].v;
	if(a[u].L)
		res += dfs(a[u].L);
	if(a[u].R)
		res += dfs(a[u].R);
	return res;
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
	for(int i = 1; i <= n; ++i)
		cout << dfs(i) << ' ';
	return 0;
}