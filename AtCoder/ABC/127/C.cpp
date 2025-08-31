#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int ansL = 0, ansR = 1e5 + 1;
	for(int i = 1, L, R; i <= m; ++i) {
		cin >> L >> R;
		ansL = max(ansL, L);
		ansR = min(ansR, R);
	}
	cout << max(0, ansR - ansL + 1);
	cout.flush();
	return 0;
}