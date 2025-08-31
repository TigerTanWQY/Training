#include <iostream>
using namespace std;

constexpr const int N = 10'003;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for(; ; ++ans) {
		bool flag = false;
		for(int i = 1; i <= n; ++i)
			if(!(a[i] & 1)) {
				a[i] >>= 1;
				flag = true;
				break;
			}
		if(!flag)
			break;
	}
	cout << ans << endl;
	return 0;
}