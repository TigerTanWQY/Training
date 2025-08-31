#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

constexpr const int N = 2e5 + 3;
LL s[N], t[N], c[N], ans = 0;

void mrge(const int L, const int R, const int M) {
	int i = L, j = M + 1, k = L;
	while(i <= M && j <= R)
		if(t[i] <= t[j]) {
			c[k++] = t[i++];
			ans += j - M - 1;
		} else
			c[k++] = t[j++];
	while(i <= M) {
		c[k++] = t[i++];
		ans += j - M - 1;
	}
	while(j <= R)
		c[k++] = t[j++];
	for(i = L; i <= R; ++i)
		t[i] = c[i];
}

void msort(const int L, const int R) {
	if(L >= R)
		return;
	const int M = (L + R) >> 1;
	msort(L, M);
	msort(M + 1, R);
	mrge(L, R, M);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, p;
	cin >> n >> p;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
		s[i] %= p;
		t[i] = s[i];
	}
	msort(1, n);
	ans *= p;
	for(int i = 0; i <= n; ++i)
		ans += (n - (n - i) * 2) * s[i];
	cout << ans << endl;
	return 0;
}