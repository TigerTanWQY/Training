#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

bool used[68], flag;
int a[68], n, len, cnt;

int read() {
	char ch = cin.get();
	int res = 0;
	for(; ch < '0' || '9' < ch; ch = cin.get());
	for(; '0' <= ch && ch <= '9'; ch = cin.get())
		res = res * 10 + ch - '0';
	return res;
}

void dfs(const int& u, const int& cur, const int& start) {
	if(flag)
		return;
	if(u > cnt) {
		cout << len << '\n';
		flag = true;
		return;
	} if(cur == len) {
		dfs(u + 1, 0, 1);
		return;
	}
	for(int i = start; i <= n; ++i) {
		if(used[i] || cur + a[i] > len)
			continue;
		used[i] = true;
		dfs(u, cur + a[i], i + 1);
		used[i] = false;
		if(cur == 0 || cur + a[i] == len)
			return;
		for(; i < n && a[i] == a[i + 1]; ++i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while((n = read())) {
		int tot = 0;
		for(int i = 1; i <= n; ++i) {
			a[i] = read();
			tot += a[i];
		}
		sort(a + 1, a + n + 1, greater<int>());
		for(len = a[1]; ; ++len) {
			if(tot % len)
				continue;
			cnt = tot / len;
			dfs(1, 0, 1);
		}
		flag = false;
	}
	return 0;
}