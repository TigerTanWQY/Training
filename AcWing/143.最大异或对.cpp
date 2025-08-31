#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100003;
int a[N], trie[N * 31][2], idx = 0;

void ist(const int& x) {
	int now = 0;
	for(int i = 30; i >= 0; --i) {
		int j = x >> i & 1;
		if(!trie[now][j])
			trie[now][j] = ++idx;
		now = trie[now][j];
	}
}

int qry(const int& x) {
	int res = 0, now = 0;
	for(int i = 30; i >= 0; --i) {
		int j = x >> i & 1;
		if(trie[now][!j]) {
			res += 1 << i;
			now = trie[now][!j];
		} else
			now = trie[now][j];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		ist(a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, qry(a[i]));
	cout << ans;
	return 0;
}