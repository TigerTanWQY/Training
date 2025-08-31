#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if((long long)i * j + 1 <= n)
				++ans;
			else
				break;
	cout << ans;
	cout.flush();
	return 0;
}