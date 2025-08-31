#include <iostream>
using namespace std;

constexpr const int N = 103;
int a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
			cin >> a[i][j];
	int ans = 1;
	for(int j = 1; j <= n; ++j)
		if(ans >= j)
			ans = a[ans][j];
		else
			ans = a[j][ans];
	cout << ans;
	cout.flush();
	return 0;
}