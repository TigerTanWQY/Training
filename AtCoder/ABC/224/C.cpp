#include <iostream>
#include <cmath>
#include <utility>
using namespace std;
using PII = pair<int, int>;
#define x first
#define y second

PII a[303];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	int ans = 0;
	for(int i = 1; i < n - 1; ++i)
		for(int j = i + 1; j < n; ++j)
			for(int k = j + 1; k <= n; ++k)
				if((0LL + a[j].x - a[i].x) * (0LL + a[k].y - a[i].y) - (0LL + a[k].x - a[i].x) * (0LL + a[j].y - a[i].y) != 0)
					++ans;
	cout << ans;
	return 0;
}