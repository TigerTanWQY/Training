#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL a[1000003], b[1000003], cnt;

void mrge(int L, int R) {
	if(L >= R)
		return;
	const int M = (L + R) >> 1;
	mrge(L, M); mrge(M + 1, R);
	int i = L, j = M + 1, k = L;
	while(i <= M && j <= R)
		if(a[i] <= a[j]) {
			b[k++] = a[i++];
			cnt += j - M - 1;
		} else
			b[k++] = a[j++];
	while(i <= M) {
		b[k++] = a[i++];
		cnt += j - M - 1;
	}
	while(j <= R)
		b[k++] = a[j++];
	for(i = L; i <= R; ++i)
		a[i] = b[i];
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	s = '$' + s;
	const int m = 2 * n;
	int ca = 0, cb = 0;
	for(int i = 1; i <= m; ++i)
		if(s[i] == 'A') {
			a[i] = 2LL * ca;
			++ca;
		} else {
			a[i] = 2LL * cb + 1;
			++cb;
		}
	mrge(1, m);
	LL res = cnt; cnt = 0;
	ca = cb = 0;
	for(int i = 1; i <= m; ++i)
		if(s[i] == 'A') {
			a[i] = 2LL * ca + 1;
			++ca;
		} else {
			a[i] = 2LL * cb;
			++cb;
		}
	mrge(1, m);
	cout << min(res, cnt) << endl;
	return 0;
}
