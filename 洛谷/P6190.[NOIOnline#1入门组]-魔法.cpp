#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 103;
int n;
struct Mat {
	LL a[N][N]{};
	Mat operator*(const Mat& A) const {
		Mat res;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) {
				res.a[i][j] = 1e18;
				for(int k = 0; k < n; ++k)
					res.a[i][j] = min(res.a[i][j], a[i][k] + A.a[k][j]);
			}
		return res;
	}
	Mat operator^(int k) const {
		Mat res, x = *this;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				res.a[i][j] = (i == j? 0LL: 1e18);
		for(; k; x = x * x, k >>= 1)
			if(k & 1)
				res = res * x;
		return res;
	}
};
struct Edge
{ int u, v, w; }
e[2503];
LL G[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int m, K;
	cin >> n >> m >> K;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			G[i][j] = (i == j? 0: 1e18);
	for(int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		--u; --v;
		e[i] = {u, v, w};
		G[u][v] = w;
	}
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	if(K == 0) {
		cout << G[0][n - 1] << endl;
		return 0;
	}
	Mat ans;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j) {
			ans.a[i][j] = G[i][j];
			for(int k = 0; k < m; ++k)
				ans.a[i][j] = min(ans.a[i][j], G[i][e[k].u] - e[k].w + G[e[k].v][j]);
		}
	ans = ans ^ K;
	cout << ans.a[0][n - 1] << endl;
	return 0;
}
