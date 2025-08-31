#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define L first
#define R second

const int N = 100003;
pair<int, int> T[N];
int fa[N];

void mkTree(const int& u, const int& f) {
	if(T[u].L) {
		fa[T[u].L] = u;
		mkTree(T[u].L, u);
	}
	if(T[u].R) {
		fa[T[u].R] = f;
		mkTree(T[u].R, f);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int u = 1; u <= n; ++u)
		cin >> T[u].L >> T[u].R;
	mkTree(1, 0);
	for(int i = 2; i <= n; ++i)
		cout << fa[i] << ' ';
	return 0;
}