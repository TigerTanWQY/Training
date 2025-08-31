#include <iostream>
using namespace std;

int cnt[603];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, w;
	cin >> n >> w;
	for(int i = 1, x; i <= n; ++i) {
		cin >> x;
		++cnt[x];
		int tot = 0;
		for(int j = 600; j >= 0; --j) {
			tot += cnt[j];
			if(tot >= max(1, i * w / 100)) {
				cout << j << ' ';
				break;
			}
		}
	}
	cout.flush();
	return 0;
}