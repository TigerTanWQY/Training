#include <iostream>
using namespace std;

constexpr const int P = 10'000'007, N = 10'003;
int a[N], c[N];
long long ans = 0;

void mrge(const int L, const int R, const int M) {
	int i = L, j = M + 1, k = L;
	while(i <= M && j <= R)
		if(a[i] <= a[j]) {
			c[k++] = a[i++];
			ans += j - M - 1;
			ans %= P;
		} else
			c[k++] = a[j++];
	while(i <= M) {
		c[k++] = a[i++];
		ans += j - M - 1;
		ans %= P;
	}
	while(j <= R)
		c[k++] = a[j++];
	for(i = L; i <= R; ++i)
		a[i] = c[i];
}

void msort(const int L, const int R) {
	if(L >= R)
		return;
	int M = (L + R) / 2;
	msort(L, M);
	msort(M + 1, R);
	mrge(L, R, M);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int _ = 1, n; _ <= _T; cout.put('\n'), ++_) {
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		msort(1, n);
		cout << "Case " << _ << ": " << ans;
		ans = 0;
	}
	cout.flush();
	return 0;
}