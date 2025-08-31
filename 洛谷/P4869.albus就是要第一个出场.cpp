#include <bits/stdc++.h>
using namespace std;

constexpr const int P = 10086;
unsigned b[103], cnt = 1U;

void ist(unsigned x) {
	for(int i = 30; i >= 0; --i) {
		if(!(x >> i & 1U))
			continue;
		else if(!b[i]) {
			b[i] = x;
			break;
		}
		x ^= b[i];
		if(!x) {
			(cnt <<= 1) %= P;
			break;
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		unsigned x;
		cin >> x;
		ist(x);
	}
	cin >> m;
	unsigned tot = 0, mul = 1;
	for(int i = 0; i <= 30; ++i)
		if(b[i]) {
			if(m >> i & 1U)
				tot |= mul;
			mul <<= 1;
		}
	tot %= P;
	cout << (tot * cnt + 1) % P << endl;
	return 0;
}
