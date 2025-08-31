#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 8e5 + 3;
char s[N];
int nxt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> (s + n + 2);
	s[n + 1] = '$';
	for(int i = 1, j = 2 * n + 1; i <= n; ++i, --j)
		s[i] = s[j];
	for(int i = 2, j = 0; i <= 2 * n + 1; ++i) {
		for(; j && s[j + 1] != s[i]; j = nxt[j]);
		if(s[j + 1] == s[i])
			++j;
		nxt[i] = j;
	}
	cout << n - nxt[2 * n + 1] << endl;
	return 0;
}
