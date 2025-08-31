#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;
using LL = long long;
#define L first
#define R second

const int N = 200003;
PII a[N];
int n;
LL s;

bool check(const LL& x) {
	vector<int> f{-1};
	int cnt1 = 0, cnt2 = 0;
	LL tot = 0;
	for(int i = 1; i <= n; ++i)
		if(a[i].R < x) {
			tot += a[i].L;
			++cnt1;
		} else if(a[i].L > x) {
			tot += a[i].L;
			++cnt2;
		} else
			f.push_back(i);
	if(cnt1 > (n >> 1) || cnt2 > (n >> 1))
		return false;
	for(int i = 1; i <= (n >> 1) - cnt1; ++i)
		tot += a[f[i]].L;
	tot += 1LL * x * ((n >> 1) - cnt2 + 1);
	return tot <= s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(; T--; ) {
		cin >> n >> s;
		for(int i = 1; i <= n; ++i)
			cin >> a[i].L >> a[i].R;
		sort(a + 1, a + n + 1);
		LL L = a[(n >> 1) + 1].L, R = 1LL * s / ((n >> 1) + 1);
		for(LL M = L + R >> 1; L <= R; M = L + R >> 1)
			if(check(M))
				L = M + 1;
			else
				R = M - 1;
		cout << L - 1 << '\n';
	}
	return 0;
}