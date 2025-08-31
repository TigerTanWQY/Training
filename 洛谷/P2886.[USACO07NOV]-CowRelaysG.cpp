#include <bits/stdc++.h>
using namespace std;

int id[1003], n = 0;
struct Matrix {
	int a[103][103];
	Matrix()
	{ memset(a, 0x3f, sizeof(a)); }
} G;
Matrix operator*(const Matrix& A, const Matrix& B) {
	Matrix res;
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				res.a[i][j] = min(res.a[i][j], A.a[i][k] + B.a[k][j]);
	return res;
}
Matrix& operator*=(Matrix& A, const Matrix& B) {
	A = A * B;
	return A;
}

Matrix qpow(Matrix A, int b) {
	Matrix res = A;
	for(--b; b; A *= A, b >>= 1)
		if(b & 1)
			res *= A;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int k, m, S, T;
	cin >> k >> m >> S >> T;
	for(int u, v, w; m--; ) {
		cin >> w >> u >> v;
		u = id[u]? id[u]: id[u] = ++n;
		v = id[v]? id[v]: id[v] = ++n;
		G.a[u][v] = G.a[v][u] = min(G.a[u][v], w);
	}
	S = id[S]; T = id[T];
	cout << qpow(G,k).a[S][T] << endl;
	return 0;
}
