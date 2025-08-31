#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define L first
#define R second

const int N = 1027;
pair<int, int> G[N];
int d[N];

void get_depth(const int& root) {
	queue<int> q;
	q.push(root);
	d[root] = 1;
	while(!q.empty()) {
		int fa = q.front();
		q.pop();
		if(G[fa].L) {
			d[G[fa].L] = d[fa] + 1;
			q.push(G[fa].L);
		}
		if(G[fa].R) {
			d[G[fa].R] = d[fa] + 1;
			q.push(G[fa].R);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> G[i].L >> G[i].R;
	get_depth(1);
	for(int i = 1; i <= n; ++i)
		cout << d[i] << ' ';
	return 0;
}