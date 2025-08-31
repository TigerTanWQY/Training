#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL f[1'000'003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L, R;
	cin >> L >> R;
	LL ans = 0;
	for(int i = R; i >= 2; --i) {
		const int w = R / i - ceil((L - 1) / i);
		f[i] = (LL)w * w;
		for(int j = i + i; j <= R; j += i)
			f[i] -= f[j];
		ans += f[i];
	}
	for(int i = L; i <= R; ++i) {
		if(i == 1)
			continue;
		ans -= R / i * 2 - 1;
	}
	cout << ans << endl;
	return 0;
}
