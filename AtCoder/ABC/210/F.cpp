#include <iostream>
#include <utility>
#include <algorithm>
#include <atcoder/twosat>
using namespace std;

pair<int, int> a[30003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first >> a[i].second;
		ans1 = __gcd(ans1, a[i].first);
		ans1 = __gcd(ans1, a[i].second);
		ans2 = __gcd(ans2, a[i].first);
		ans2 = __gcd(ans2, a[i].second);
	}
	if(ans1 == 1 || ans2 == 1)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}