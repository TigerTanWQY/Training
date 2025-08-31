#include <iostream>
using namespace std;
using LL = long long;

int a[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	LL T, tot = 0;
	cin >> n >> T;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		tot += a[i];
	}
	T %= tot;
	LL cnt = 0;
	for(int i = 0; i < n; cnt += a[i++])
		if(cnt + a[i] > T) {
			cout << i + 1 << ' ' << T - cnt;
			break;
		}
	return 0;
}