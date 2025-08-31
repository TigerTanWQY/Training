#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

const int N = 70;
bool b[N];
int a[N], n;

int read() {
	char ch = getchar();
	int res = 0;
	for(; ch < '0' || '9' < ch; ch = getchar());
	for(; '0' <= ch && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

void dfs(const int& t, const int& lst, const int& v, const int& l) {
	if(t == 0) {
		printf("%d", l);
		exit(0);
		return;
	} if(v == 0) {
		dfs(t - 1, 0, l, l);
		return;
	}
	int last = -1;
	for(int i = lst + 1; i <= n; ++i) {
		if(!b[i] && a[i] != last && v - a[i] >= 0) {
			last = a[i];
			b[i] = true;
			dfs(t, i, v - a[i], l);
			b[i] = false;
			if(v == l || v - a[i] == 0)
				return;
		}
	}
}

int main() {
	n = read();
	int sum = 0, maxn = 0;
	for(int i = 1; i <= n; ++i) {
		a[i] = read();
		sum += a[i];
		maxn = max(maxn, a[i]);
	}
//	sort(a + 1, a + n + 1, greater<int>());
	sort(a + 1, a + n + 1, [](const int& x, const int& y){ return x > y; });
	for(int i = maxn; i <= sum; ++i)
		if(sum % i == 0)
			dfs(sum / i, 0, i, i);
	return 0;
}