#include <iostream>
using namespace std;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	long long ans = 0, tot = 0;
	for(int L = 1, R = 0; L <= n; ++L) {
		while(tot < k)
			if(R >= n)
				break;
			else
				tot += a[++R];
		if(tot < k)
			break;
		ans += n - R + 1;
		tot -= a[L];
	}
	cout << ans;
	return 0;
}