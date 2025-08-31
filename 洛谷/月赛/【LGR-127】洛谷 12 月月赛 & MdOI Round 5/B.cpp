#include <iostream>
using namespace std;

char f[1'000'005];
int a[100'005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m >> (f + 1);
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(f[a[i] - ans] == '1')
			++ans;
	}
	cout << ans;
	cout.flush();
	return 0;
}