#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using Vec = vector<LL>;
using Mat = vector<Vec>;

constexpr const int P = 1e9 + 7;
int v[100003], cnt[103];

Mat qpow(const Mat& A, const Mat& B) {
	int n = A.size();
	Mat C(n, Vec(n, 0));
	for(int i = 0; i < n; ++i) {
		for(int k = 0; k < n; ++k) {
			if(A[i][k] == 0)
				continue;
			for(int j = 0; j < n; ++j)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % P;
		}
	}
	return C;
}

Vec qpow(const Mat& A, const Vec& vec) {
	int n = A.size();
	Vec res(n, 0);
	for(int i = 0; i < n; ++i)
		for(int k = 0; k < n; ++k)
			res[i] = (res[i] + A[i][k] * vec[k]) % P;
	return res;
}

int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	LL k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	for(int i = 0; i < n; ++i)
		if(1 <= v[i] && v[i] <= 100)
			++cnt[v[i]];
	Vec base(103, 0);
	base[0] = base[1] = 1;
	if(k == 0) {
		cout.put('1') << endl;
		return 0;
	}
	Mat mat(103, Vec(103, 0));
	mat[0][0] = 1;
	for(int j = 1; j <= 100; ++j) {
		mat[0][j] = cnt[j];
		mat[1][j] = cnt[j];
	}
	for(int i = 2; i <= 100; ++i)
		mat[i][i - 1] = 1;
	Vec res = base;
	for(; k; mat = qpow(mat, mat), k >>= 1)
		if(k & 1)
			res = qpow(mat, res);
	cout << res[0] % P << endl;
	return 0;
}
