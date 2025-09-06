#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL a[100003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	LL ans = 0;
	vector<pair<LL, LL>> lst;
	for(int R = 1; R <= n; ++R) {
		vector<pair<LL, LL>> nw;
		nw.push_back({a[R], R});
		for(const auto& [x, y]: lst) {
			LL g = gcd(x, a[R]);
			if(g == nw.back().first)
				nw.back().second = min(nw.back().second, y);
			else
				nw.push_back({g, y});
		}
		for(const auto& [x, y]: nw)
			ans = max(ans, (R - y + 1) * x);
		lst = nw;
	}
	cout << ans << endl;
	return 0;
}
