#include <bits/stdc++.h>
using namespace std;

int read() {
	int res = 0;
	bool flg = false;
	char ch = getchar_unlocked();
	for(; ch != '-' && ('0' > ch || ch > '9'); ch = getchar_unlocked());
	if(ch == '-') {
		flg = true;
		ch = getchar_unlocked();
	}
	for(; '0' <= ch && ch <= '9'; ch = getchar_unlocked())
		res = res * 10 + ch - '0';
	return (flg? -1: 1) * res;
}

int main() {
	long long ans = 0;
	for(int n = read(); n--; )
		ans += read();
	printf("%lld\n", ans);
	return 0;
}
