#include <iostream>
#include <vector>
using namespace std;
using LL = long long;

const int N = 200003;
const int P = 998244353;
vector<int> G[N];
int d[N][5], mx[5], mv[5], idx, blc = -1, num, cnt;

void dfs(const int& u, const int& fa) {
	if (fa == -1)
		d[u][idx] = 0;
	else
		d[u][idx] = d[fa][idx] + 1;
	if (mx[idx] < d[u][idx]) {
		mx[idx] = d[u][idx];
		mv[idx] = u;
	}
	if (d[u][idx] == num)
		++cnt;
	for(const auto& v: G[u])
		if(v != blc && d[v][idx] < 0)
			dfs(v, u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, u, v;
	vector<int> a;
	LL x, ans;
	for(int i = 0; i < 5; ++i) {
		for(int j = 0; j < N; ++j)
			d[j][i] = -1;
		mx[i] = -1;
	}
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		G[u - 1].push_back(v - 1);
		G[v - 1].push_back(u - 1);
	}
	idx = 0;
	dfs(0, -1);
	idx = 1;
	dfs(mv[0], -1);
	idx = 2;
	dfs(mv[1], -1);
	if (mx[1] % 2 == 1) {
		for(int i = 0; i < n; ++i) {
			if ((d[i][1] == (mx[1] / 2)) && (d[i][2] == (mx[1] / 2) + 1))
				u = i;
			if ((d[i][2] == (mx[1] / 2)) && (d[i][1] == (mx[1] / 2) + 1))
				v = i;
		}
		idx = 3;
		num = mx[1] / 2;
		blc = v;
		cnt = 0;
		dfs(u, -1);
		a.push_back(cnt);
		blc = u;
		cnt = 0;
		dfs(v, -1);
		a.push_back(cnt);
	} else {
		for(int i = 0; i < n; ++i)
			if ((d[i][1] == (mx[1] / 2)) && (d[i][2] == (mx[1] / 2)))
				u = i;
		idx = 3;
		num = (mx[1] / 2) - 1;
		blc = u;
		for(const auto& k: G[u]) {
			cnt = 0;
			dfs(k, -1);
			a.push_back(cnt);
		}
	}
	ans = 1;
	for(int i = 0; i < a.size(); ++i) {
		x = a[i] + 1;
		ans = ans * x % P;
	}
	for(int i = 0; i < a.size(); ++i) {
		x = a[i];
		ans = (ans + P - x) % P;
	}
	ans = (ans + P - 1) % P;
	cout << ans;
	return 0;
}