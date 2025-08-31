#include <iostream>
using namespace std;

const int N = 100003;
int a[N], c[N];
long long ans = 0;

void mrge(const int& L, const int& R, const int& M) {
	int i = L, j = M + 1, k = L;
	while(i <= M && j <= R)
		if(a[i] <= a[j])
			c[k++] = a[i++];
		else {
			ans += 1LL + M - i;
			c[k++] = a[j++];
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
	int M = (L + R) >> 1;
	msort(L, M);
	msort(M + 1, R);
	mrge(L, R, M);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	msort(1, n);
	cout << ans;
	return 0;
}