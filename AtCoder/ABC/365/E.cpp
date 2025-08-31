#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 200'003;
int a[N], s[N];
// 求一个正整数序列的所有连续子序列的异或和
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	LL ans = 0;
	for(int L = 1; L < n; ++L)
		for(int R = L + 1; R <= n; ++R)
			ans += s[R] ^ s[L - 1];
	cout << ans;
	cout.flush();
	return 0;
}