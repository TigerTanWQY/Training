#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 103;
vector<int> a[N], ans;
int d[N], n;

void topSort() {
	queue<int> q;
	for(int i = 1; i <= n; ++i)
		if(!d[i]) {
			q.push(i);
			ans.push_back(i);
		}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
//		ans.push_back(u);
		for(const auto& v: a[u])
			if(!--d[v]) {
				q.push(v);
				ans.push_back(v);
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int x; cin >> x && x; ) {
			a[i].push_back(x);
			++d[x];
		}
	topSort();
	for(const auto& x: ans)
		cout << x << ' ';
	return 0;
}