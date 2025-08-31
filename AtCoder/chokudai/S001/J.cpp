#include <iostream>
using namespace std;

constexpr const int N = 100'003;
int a[N], c[N];
long long ans = 0;

void mrge(const int& L, const int& R, const int& M) {
	int i = L, j = M + 1, k = L;
	while(i <= M && j <= R)
		if(a[i] <= a[j]) {
			c[k++] = a[i++];
			ans += j - M - 1;
		} else
			c[k++] = a[j++];
	while(i <= M) {
		c[k++] = a[i++];
		ans += j - M - 1;
	}
	while(j <= R)
		c[k++] = a[j++];
	for(i = L; i <= R; ++i)
		a[i] = c[i];
}

void mSort(const int& L, const int& R) {
	if(L >= R)
		return;
	int M = (L + R) / 2;
	mSort(L, M);
	mSort(M + 1, R);
	mrge(L, R, M);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	mSort(1, n);
	cout << ans;
	cout.flush();
	return 0;
}