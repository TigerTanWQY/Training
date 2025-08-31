#include <iostream>
#include <atcoder/modint>
using namespace std;
using LL = long long;
using mint = atcoder::modint1000000007;

constexpr const int N = 300'003;
LL a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	mint ans = 0;
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
			ans += a[i] ^ a[j];
	cout << ans.val();
	cout.flush();
	return 0;
}