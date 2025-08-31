#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1, res = 0; i <= 31; ++i, res = 0)
		for(int j = 1; j <= n; ++j) {
			res += a[j];
			if(a[j] > i)
				res = 0;
			res = max(res, 0);
			ans = max(ans, res - i);
		}
	cout << ans;
	return 0;
}