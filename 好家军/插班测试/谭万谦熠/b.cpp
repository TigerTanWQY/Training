#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int k, s;
	cin >> k >> s;
	int ans = 0;
	for(int x = 0; x <= k; ++x)
		for(int y = 0; y <= k; ++y) {
			int z = s - x - y;
			if(0 <= z && z <= k)
				++ans;
		}
	cout << ans;
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}