#include <iostream>
#include <algorithm>
using namespace std;

int v[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, d;
	cin >> n >> d;
	for(int i = 1; i < n; ++i)
		cin >> v[i];
	long long ans = 0, tot = 0;
	int minn = 0x3f3f3f3f;
	for(int i = 1, a; i < n; ++i) {
		cin >> a;
		tot += v[i];
		minn = min(minn, a);
		if(tot > 0) {
			ans += (tot + d - 1) / d * minn;
			tot -= (tot + d - 1) / d * d;
		}
	}
	cout << ans << endl;
	return 0;
}