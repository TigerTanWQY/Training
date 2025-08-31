#include <cstdio>
using namespace std;

int read() {
	int res = 0;
	bool flag = false;
	char ch = _getchar_nolock();
	for(; ('0' > ch || ch > '9') && ch != '-'; ch = _getchar_nolock());
	if(ch == '-') {
		flag = true;
		ch = _getchar_nolock();
	}
	for(; '0' <= ch && ch <= '9'; ch = _getchar_nolock())
		res = res * 10 + ch - '0';
	if(flag)
		res = -res;
	return res;
}

int main() {
	int n = read();
	int tot = 0;
	for(int i = 1; i <= n; ++i)
		tot += read();
	printf("%d\n", tot);
	return 0;
}
