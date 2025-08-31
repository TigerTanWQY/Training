#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

pair<PII, PII> a[9];

double dis(const PII& A, const PII& B)
{ return sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second)); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, S, T;
	cin >> n >> S >> T;
	++n;
	for(int i = 1; i < n; ++i)
		cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
	sort(a + 1, a + n);
	double ans = 1e18;
	do
		for(int s = 0; s < 1 << n; ++s) {
			double tot = 0;
			for(int i = 1; i < n; ++i) {
				PII x, y;
				if(s & 1 << (i - 1))
					x = a[i - 1].second;
				else
					x = a[i - 1].first;
				if(s & 1 << i)
					y = a[i].first;
				else
					y = a[i].second;
				tot += dis(x, y) / S + dis(a[i].first, a[i].second) / T;
			}
			ans = min(ans, tot);
		}
	while(next_permutation(a + 1, a + n));
	cout << fixed << setprecision(7) << ans << endl;
	return 0;
}
