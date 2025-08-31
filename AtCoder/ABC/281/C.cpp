#include <iostream>
using namespace std;
using LL = long long;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	LL t, tot = 0, cnt = 0;
	cin >> n >> t;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		tot += a[i];
	}
	const LL rem = t % tot;
	for(int i = 0; i < n; cnt += a[i++])
		if(cnt + a[i] > rem) {
			cout << i + 1 << ' ' << rem - cnt;
			return 0;
		}
	return 0;
}