#include <iostream>
using namespace std;

const int N = 200003;
struct Point
{ int x, y; }
a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
			ans += dist(a[i].x, a[i].y);
	return 0;
}