#include <iostream>
#include <bitset>
using namespace std;

constexpr const int dxy[4][2]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
constexpr const int dh[8][2]{{-1, -2}, {1, -2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};
constexpr const int N = 10 + 1;
bitset<N> vis[N], ins[N];
int n, k;
long long ans = 0;

void dfs(const int x, const int y, const int cnt) {
	if(cnt == k) {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(ins[i][j])
					for(int l = 0; l < 8; ++l) {
						int tx = i + dh[l][0], ty = j + dh[l][1];
						if(1 <= tx && tx <= n && 1 <= ty && ty <= n && ins[tx][ty])
							return;
					}
		++ans;
		return;
	}
	for(int i = 0; i < 4; ++i) {
		int tx = x + dxy[i][0], ty = y + dxy[i][1];
		if(1 <= tx && tx <= n && 1 <= ty && ty <= n && !vis[tx][ty]) {
			vis[tx][ty] = ins[tx][ty] = true;
			dfs(tx, ty, cnt + 1);
			ins[tx][ty] = false;
			dfs(tx, ty, cnt);
			vis[tx][ty] = false;
		}
	}
}

int main() {
	for(int i = 1; i <= 10; ++i)
		for(int j = 0; j <= i * i; ++j) {
			n = i; k = j;
			dfs(0, 1, 0);
			cout << '"' << ans / 2 + !!(ans & 1) << "\",";
			ans = 0;
//			for(int l = 0; l < N; ++l)
//				vis[l].reset();
		}
	return 0;
}