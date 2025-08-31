#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int N = 100003;
pair<int, int> a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		cin >> a[i].second >> a[i].first;
	sort(a + 1, a + m + 1);
	long long ans = 0;
	for(int i = 0; i < N; ++i) {
		int x = a[i].first, y = a[i].second;
		m = __gcd(n, y);
		ans += 1LL * (n - m) * x;
		n = m;
	}
	if(n == 1)
		cout << ans;
	else
		cout << "-1";
	return 0;
}