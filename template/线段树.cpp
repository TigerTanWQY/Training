#include <iostream>
using namespace std;

constexpr const int N = 200'003;
struct Node
{ int L, R, val; }
tree[N * 4];
int a[N];

void update(const int& u) {
	tree[u].val = min(tree[u * 2].val, tree[u * 2 + 1].val);
}

void build(const int& u, const int& L, const int& R) {
	tree[u].L = L;
	tree[u].R = R;
	if(L == R) { // 叶子节点
		tree[u].val = a[L];
		return;
	}
	int M = (L + R) / 2;
	build(u * 2, L, M);
	build(u * 2 + 1, M + 1, R);
	update(u);
}

void modify(const int& u, const int& x, const int& val) { // 单点修改
	if(tree[u].L == tree[u].R) { // 叶子节点
		tree[u].val = val;
		return;
	}
	int M = (tree[u].L + tree[u].R) / 2;
	if(x <= M)
		modify(u * 2, x, val);
	else
		modify(u * 2 + 1, x, val);
	update(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	build(1, 1, n);
	cout.flush();
	return 0;
}