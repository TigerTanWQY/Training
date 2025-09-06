#include <bits/stdc++.h>
using namespace std;

constexpr const int N = 1.1e7 + 3;
char s[N], t[N * 2];
int p[N * 2];

int manacher() {
	int n = strlen(s), m = 0;
	t[++m] = '$';
	for(int i = 0; i < n; ++i)
	{ t[++m] = s[i]; t[++m] = '$'; }
	int M = 0, R = 0;
	for(int i = 1; i <= m; ++i) {
		if(i > R)
			p[i] = 1;
		else
			p[i] = min(p[2 * M - i], R - i + 1);
		for(; i > p[i] && i + p[i] <= m && t[i - p[i]] == t[i + p[i]]; ++p[i]);
		if(i + p[i] - 1 > R)
		{ M = i; R = i + p[i] - 1; }
	}
	return *max_element(p + 1, p + m + 1) - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s;
	cout << manacher() << endl;
	return 0;
}
/*

*/
