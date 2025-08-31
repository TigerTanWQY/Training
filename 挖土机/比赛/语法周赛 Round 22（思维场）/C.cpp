#include <iostream>
using namespace std;

const int N = 1003;
char s[N];
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n >> (s + 1);
	for(int L, R, P; n--; ) {
		cin >> L >> R >> P;
		int r = 0;
		for(int i = 1; i <= R - L + 1; ++i)
			r = (r * 10LL + s[L + i - 1] - '0') % P;
		cout << r << '\n';
	}
	cout << flush;
	return 0;
}