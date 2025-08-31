#include <iostream>
using namespace std;
using LL = long long;

constexpr const int N = 19;
struct Node {
	LL tot;
	int last;
	Node() noexcept
	: tot(-1), last(0)
	{ }
	Node friend operator+(const Node& x, const Node& y) {
		Node res;
		res.tot = x.tot + y.tot;
		res.last = y.last;
		return res;
	}
	Node& operator+=(const Node& y) {
		*this = *this + y;
		return *this;
	}
} f[N + 3][N * 10 + 3][1'003], last;
int aL[N + 3], aR[N + 3], sL[N + 3], sR[N + 3], k;

Node dfs(const int x, const int y, const int z) {
	if(~f[x][y][z].tot)
		return f[x][y][z];
	Node& res = f[x][y][z];
	if(x == 1) {
		res.tot  = (y + z >= k)? 1: 0;
		res.last = (y + z >= k)? 0: y + z;
	} else {
		res = dfs(x - 1, y, z);
		for(int i = 1; i < 10; ++i)
			res += dfs(x - 1, y + i, res.last);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	LL L, R;
	cin >> L >> R >> k;
	for(int i = 1; i <= N; ++i) {
		aL[i] = L % 10; L /= 10;
		aR[i] = R % 10; R /= 10;
	}
	int m;
	for(m = N; m; --m)
		if(aL[m] != aR[m])
			break;
	++m;
	for(int i = N; i; --i) {
		sL[i] = sL[i + 1] + aL[i];
		sR[i] = sR[i + 1] + aR[i];
	}
	Node ans;
	ans.tot  = (sL[1] >= k)? 1: 0;
	ans.last = (sL[1] >= k)? 0: sL[1];
	for(int i = 2; i < m; ++i)
		for(int j = aL[i - 1] + 1; j < 10; ++j)
			ans += dfs(i - 1, sL[i] + j, ans.last);
	for(int i = aL[m - 1] + 1; i < aR[m - 1]; ++i)
		ans += dfs(m - 1, sL[m] + i, ans.last);
	for(int i = m - 1; i >= 2; --i)
		for(int j = 0; j < aR[i - 1]; ++j)
			ans += dfs(i - 1, sR[i] + j, ans.last);
	if(ans.last + sR[1] >= k)
		++ans.tot;
	cout << ans.tot << endl;
	return 0;
}