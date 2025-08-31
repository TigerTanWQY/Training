#include <iostream>
using namespace std;

constexpr const int N = 500'003;
int a[N], c[N];
long long ans;

void mrge(const int& L, const int& R, const int& M) {
	int i = L, j = M + 1, k = L;
	while(i <= M && j <= R)
		if(a[i] <= a[j])
			c[k++] = a[i++];
		else {
			c[k++] = a[j++];
			ans += M - i + 1;
		}
	while(i <= M)
		c[k++] = a[i++];
	while(j <= R)
		c[k++] = a[j++];
	for(i = L; i <= R; ++i)
		a[i] = c[i];
}

void msort(const int& L, const int& R) {
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
	for(int n; cin >> n && n; ans = 0LL) {
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		msort(1, n);
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}