#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;

void dfs(int i, int tot) {
	if(tot == n) {
		if(a.size() > 1) {
			for(int j = 0; j < a.size() - 1; ++j)
				cout << a[j] << '+';
			cout << a.back() << '\n';
		}
		return;
	} else if(tot > n)
		return;
	for(int x = i + !i; x <= n; ++x) {
		a.push_back(x);
		dfs(x, tot + x);
		a.pop_back();
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	a.reserve(n << 1);
	dfs(0, 0);
	cout.flush(); return 0;
}
