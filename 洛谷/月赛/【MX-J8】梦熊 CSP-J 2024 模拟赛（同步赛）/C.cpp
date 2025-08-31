#include <iostream>
#include <algorithm>
using namespace std;

constexpr const int N = 3003;
int a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H, W, n, m, k;
	cin >> H >> W >> n >> m >> k;
	for(int x1, y1, x2, y2; n--; ) {
		cin >> x1 >> y1 >> x2 >> y2;
		for(int x = x1; x <= x2; ++x)
			for(int y = y1; y <= y2; ++y)
				a[x][y] = -1;
	}
	for(int t, x, y; m--; ) {
		cin >> t >> x >> y;
	}
	cout << endl;
	return 0;
}