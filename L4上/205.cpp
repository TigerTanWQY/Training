#include <iostream>
using namespace std;

const int P = 9999971;
const int BASE1 = 383;
const int BASE2 = 101;
const int N = 200003;
char s[N];
int ha1[N], hb1[N], ha2[N], hb2[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, ans = 0;
	cin >> n >> m >> s + 1;
	for(int i = 1; i <= n; ++i) {
		ha1[i] = (1LL * ha1[i - 1] * BASE1 + s[i]) % P;
		ha2[i] = (1LL * ha2[i - 1] * BASE2 + s[i]) % P;
	}
	cin >> s + 1;
	for(int i = 1; i <= m; ++i) {
		hb1[i] = (1LL * hb1[i - 1] * BASE1 + s[i]) % P;
		hb2[i] = (1LL * hb2[i - 1] * BASE2 + s[i]) % P;
	}
	int base1 = 1, base2 = 1;
	for(int _ = 0; _ < m; ++_) {
		base1 = base1 * BASE1 % P;
		base2 = base2 * BASE2 % P;
	}
	for(int i = 1; i + m - 1 <= n; ++i)
		if((ha1[i + m - 1] - 1LL * ha1[i - 1] * base1 % P + P) % P == hb1[m] && (ha2[i + m - 1] - 1LL * ha2[i - 1] * base2 % P + P) % P == hb2[m])
			++ans;
	cout << ans;
	return 0;
}