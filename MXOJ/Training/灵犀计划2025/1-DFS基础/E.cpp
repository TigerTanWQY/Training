#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n, r;

void dfs(int i) {
	if(a.size() >= r) {
		for(const auto& x: a)
			cout << setw(3) << x;
		cout.put('\n');
		return;
	}
	for(int x = i + 1; x <= n; ++x) {
		a.push_back(x);
		dfs(x);
		a.pop_back();
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> r;
	a.reserve(n + 3);
	dfs(0);
	cout.flush(); return 0;
}
