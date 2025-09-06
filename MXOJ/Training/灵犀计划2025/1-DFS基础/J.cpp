#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, T, m;
	cin >> n >> T >> m;
	vector<int> h(n);
	for(int i{}, a, b; i < m; ++i){
		cin >> a >> b;
		h[--b] |= 1U << --a;
	}
	cout << [dfs{[n, T, &h](auto&& f, vector<int>& t, int now) -> int {
		if(now == n)
			return size(t) == T;
		int ans{};
		for(auto&& x : t)
			if(!(x & h[now])){
				x ^= 1U << now;
				ans += f(f, t, now + 1);
				x ^= 1U << now;
			}
		if(size(t) < T){
			t.emplace_back(1U << now);
			ans += f(f, t, now + 1);
			t.pop_back();
		}
		return ans;
	}}, T]{
		vector<int> x;
		x.reserve(T);
		return dfs(dfs, x, 0);
	}() << endl;
	return 0;
}
