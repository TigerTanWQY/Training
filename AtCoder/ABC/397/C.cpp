#include <iostream>
#include <unordered_map>
using namespace std;

int a[300003];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.flush();
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	unordered_map<int, int> cnt1, cnt2;
	for(int i = 1; i <= n; ++i)
		++cnt1[a[i]];
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		++cnt2[a[i]]; --cnt1[a[i]];
		if(!cnt1[a[i]])
			cnt1.erase(a[i]);
		ans = max(ans, (int) (cnt1.size() + cnt2.size()));
	}
	cout << ans << endl;
	return 0;
}
