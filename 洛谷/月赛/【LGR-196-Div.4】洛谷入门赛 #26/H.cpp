#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

constexpr const int N = 103;
int a[N][N][53], top[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k, t;
	cin >> n >> m >> k >> t;
	for(int id, x, y; t--; cout.put('\n')) {
		cin >> id >> x >> y;
		if(top[x][y] == k) {
			int minn = *min_element(a[x][y] + 1, a[x][y] + k + 1);
			cout << minn << ' ';
			stack<int> stk;
			while(top[x][y]) {
				int u = a[x][y][top[x][y]--];
				if(u == minn)
					break; // 被销毁的
				stk.push(u); // 移动的
			}
			cout << stk.size();
			while(!stk.empty()) {
				a[x][y][++top[x][y]] = stk.top(); // 移回去
				stk.pop();
			}
		} else
			cout << "-1";
		a[x][y][++top[x][y]] = id;
	}
	cout.flush();
	return 0;
}