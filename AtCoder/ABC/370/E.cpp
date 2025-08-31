// https://www.onlinemictest.com/zh/tone-generator/
#include <iostream>
#include <map>
#include <atcoder/modint>
using namespace std;
using LL = long long;
using mint = atcoder::modint998244353;

constexpr const int N = 2e5 + 3;
map<LL, mint> cnt;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	LL k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	cnt[0] = 1;
	mint precnt = 1, ans = 0;
	LL pretot = 0;
	for(int i = 1; i <= n; ++i) {
		pretot += a[i];
		ans = precnt - cnt[pretot - k];
		cnt[pretot] += ans;
		precnt += ans;
	}
	cout << ans.val() << endl;
	return 0;
}