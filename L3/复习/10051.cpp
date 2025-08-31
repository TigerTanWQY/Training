#include <iostream>
#include <unordered_map>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	unordered_map<int, int> cnt;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	cout << endl;
	return 0;
}