#include <iostream>
using namespace std;

constexpr const int N = 100'003;
bool col[N], rev[N];
int L[N], R[N];

void pushdown(const int u) {
	if(rev[u]) {
		rev[u] ^= true;
		col[u] ^= true;
		rev[L[u]] ^= true;
		rev[R[u]] ^= true;
	}
}

void dfs(const int u) {
	if(u != 0) {
		pushdown(u);
		dfs(L[u]);
		dfs(R[u]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n;
	for(int i = 2, fa; i <= n; ++i) {
		cin >> fa;
		(L[fa]? R[fa]: L[fa]) = i;
	}
	char ch;
	for(int i = 1; i <= n; ++i) {
		cin >> ch;
		col[i] = ch - '0';
	}
	cin >> q;
	for(int u; q--; ) {
		cin >> u;
		pushdown(u);
		rev[u] ^= true;
	}
	dfs(1);
	for(int i = 1; i <= n; ++i)
		cout.put('0' + col[i]);
	cout.flush();
	return 0;
}