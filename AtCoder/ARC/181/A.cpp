#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 200'003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; ) {
		cin >> n;
		a[0] = 0x3f3f3f3f;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			if(a[i] < a[i - 1])
				++cnt;
		cout << n - cnt - 1 << '\n';
	}
	cout.flush();
	return 0;
}