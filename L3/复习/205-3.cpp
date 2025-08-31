#include <iostream>
using namespace std;

const int N = 1027;
int a[N], b[N], d[N];

void dfs(const int& L1, const int& R1, const int& L2, const int& R2) {
	if(L2 > R2)
		return;
	int x = d[b[R2]];
	cout << b[R2] << ' ';
	dfs(L1, x - 1, L2, L2 + x - 1 - L1);
	dfs(x + 1, R1, L2 + x - L1, R2 - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		d[a[i]] = i;
	}
	for(int i = 1; i <= n; ++i)
		cin >> b[i];
	dfs(1, n, 1, n);
	return 0;
}