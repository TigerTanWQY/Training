#include <iostream>
using namespace std;

const int d[2][4]{{0, -1, 1, 0}, {-1, 0, 0, 1}};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w, r, c, ans = 0;
	cin >> h >> w >> r >> c;
	for(int i = 0; i < 4; ++i) {
		int tx = r + d[0][i], ty = c + d[1][i];
		if(1 <= tx && tx <= h && 1 <= ty && ty <= w)
			++ans;
	}
	cout << ans;
	return 0;
}