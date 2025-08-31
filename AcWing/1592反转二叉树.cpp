#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
#define L first
#define R second

const int N = 13;
pair<int, int> G[N];
bool vis[N];

void bfs(const int& root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << ' ';
		if(~G[u].R)
			q.push(G[u].R);
		if(~G[u].L)
			q.push(G[u].L);
	}
	cout << '\n';
}

void LTR(const int& u) {
	if(~G[u].R)
		LTR(G[u].R);
	cout << u << ' ';
	if(~G[u].L)
		LTR(G[u].L);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		char ch;
		cin >> ch;
		if(ch == '-')
			G[i].L = -1;
		else {
			G[i].L = ch - '0';
			vis[G[i].L] = true;
		}
		cin >> ch;
		if(ch == '-')
			G[i].R = -1;
		else {
			G[i].R = ch - '0';
			vis[G[i].R] = true;
		}
	}
	int root = 0;
	for(int i = 0; i < n; ++i)
		if(!vis[i])
			root = i;
	bfs(root);
	LTR(root);
	return 0;
}