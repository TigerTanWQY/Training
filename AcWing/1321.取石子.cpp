#include <iostream>
using namespace std;

const int N = 53;
int a[N], f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _T;
	cin >> _T;
	for(int n; _T--; ) {
		cin >> n;
		bool ans = (n & 1);
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			ans ^= (a[i] & 1);
		}
		if(ans)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	cout.flush();
	return 0;
}