#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int P = 998244353, N = 2e5 + 3;
int n, m;
struct Matrix {
	LL c[3][3]{};
	friend Matrix operator*(const Matrix& A, const Matrix& B) {
		Matrix C;
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j)
				for(int k = 0; k < 3; ++k)
					C.c[i][j] = (C.c[i][j] + A.c[i][k] * B.c[k][j]) % P;
		return C;
	}
	void chg() {
		LL S = 1LL * (n - 1) * n / 2;
		c[0][0] = (S - 2 * m) % P;
		c[0][1] = 2 * m;
		c[0][2] = 0;
		c[1][0] = n - m - 1;
		c[1][1] = (S - n + 2) % P;
		c[1][2] = m - 1;
		c[2][0] = 0;
		c[2][1] = 2 * (n - m);
		c[2][2] = (S - 2 * (n - m)) % P;
	}
} base, res;
void qpow(int ep) {
    if(ep == 1) {
        res = base;
        return;
    }
    qpow(ep >> 1);
    res = res * res;
    if(ep & 1)
        res = res * base;
}
pair<int, int> a[N];
bool vis[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
	int k;
	cin >> n >> k;
	int s00 = n - 1, s01 = 0, s11 = 0;
	for(int i = 1; i <= n; ++i) {
        cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	LL ans = 0;
	for(int i = 1; i < n; ++i) {
		m = i;
		int id = a[i].second;
		if(id > 1)
			if(!vis[id - 1]) {
				--s00;
				++s01;
			} else {
				--s01;
				++s11;
			}
		if(id < n)
			if(!vis[id + 1]) {
				--s00;
				++s01;
			} else {
				--s01;
				++s11;
			}
		vis[id] = true;
		base.chg();
		qpow(k);
		ans = (ans + res.c[0][1] * s00) % P;
		ans = (ans + res.c[1][1] * s01) % P;
		ans = (ans + res.c[2][1] * s11) % P;
	}
    cout << ans << endl;
	return 0;
}
