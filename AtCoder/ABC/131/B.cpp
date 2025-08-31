#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, L;
	cin >> n >> L;
	int minn = 0x3f3f3f3f, mini = 0;
	for(int i = 1; i <= n; ++i)
		if(minn > abs(L + i - 1)) {
			minn = abs(L + i - 1);
			mini = i;
		}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		if(i != mini)
			ans += L + i - 1;
	cout << ans;
	return 0;
}