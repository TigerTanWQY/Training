#include <iostream>
using namespace std;

constexpr const char c[] = "#.";
char s[53][53];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1, j = 1, cnt = 0; cnt <= n / 2; ++i, ++j, ++cnt) {
		for(; j <= n - cnt; ++j)
			s[i][j] = c[cnt & 1];
		--j;
		for(++i; i <= n - cnt; ++i)
			s[i][j] = c[cnt & 1];
		--i;
		for(--j; j > cnt; --j)
			s[i][j] = c[cnt & 1];
		++j;
		for(--i; i > cnt; --i)
			s[i][j] = c[cnt & 1];
		++i;
	}
	for(int x = 1; x <= n; ++x)
		cout << (s[x] + 1) << '\n';
	cout.flush();
	return 0;
}
