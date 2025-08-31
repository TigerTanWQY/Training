#include <iostream>
#include <algorithm>
using namespace std;

int a[1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i < n; ++i) {
		for(int j = i; j <= i + 1; ++j)
			for(int k = j + 1; k <= n; ++k)
				if(a[k] < a[j]) // 选择排序
					swap(a[k], a[j]);
		ans += (a[i + 1] += a[i]);
	}
	cout << ans;
	return 0;
}