#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 2e5 + 3;
int a[N], cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < 3; ++j)
			++cnt[(a[i] - 1 - i + j + n) % n];
	cout << *max_element(cnt, cnt + n) << endl;
	return 0;
}