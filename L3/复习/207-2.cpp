#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1000003;
struct TreeNode
{ int L, R, v; }
a[N];
int d[N];

void bfs(const int& root) {
	queue<int> c;
	c.push(root);
	vector<int> q;
	while(!c.empty()) {
		int u = c.front();
		c.pop();
		q.push_back(u);
		if(a[u].L) {
			c.push(a[u].L);
			q.push_back(a[u].L);
		}
		if(a[u].R) {
			c.push(a[u].R);
			q.push_back(a[u].R);
		}
	}
	for(auto cit = q.crbegin(); cit != q.crend(); ++cit) {
		int v = *cit;
		d[v] = a[v].v;
		if(a[v].L)
			d[v] += d[a[v].L];
		if(a[v].R)
			d[v] += d[a[v].R];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].L >> a[i].R;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].v;
	bfs(1);
	for(int i = 1; i <= n; ++i)
		cout << d[i] << ' ';
	return 0;
}