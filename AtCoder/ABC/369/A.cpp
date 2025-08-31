#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y;
	cin >> x >> y;
	int ans = 0;
	for(int z = -300; z <= 300; ++z) {
		int a[3] = {x, y, z};
		sort(a, a + 3);
		bool flag = false;
		do
			if(a[2] - a[1] == a[1] - a[0])
				flag = true;
		while(!flag && next_permutation(a, a + 3));
		ans += flag;
	}
	cout << ans;
	cout.flush();
	return 0;
}