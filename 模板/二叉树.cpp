#include <iostream>
#include <vector>
using namespace std;
using DataType = int;

const int N = 100003;
struct TreeNode {
	DataType v;
//	int fa;
	int L, R;
} a[N];
vector<int> ans;
int d[N];

void get_depth(const int& p) {
	if(a[p].L) {
		d[a[p].L] = d[p] + 1;
		get_depth(a[p].L);
	}
	if(a[p].R) {
		d[a[p].R] = d[p] + 1;
		get_depth(a[p].R);
	}
}

void TLR(const int& p) {
	ans.push_back(p);
	if(a[p].L)
		TLR(a[p].L);
	if(a[p].R)
		TLR(a[p].R);
}

void LTR(const int& p) {
	if(a[p].L)
		LTR(a[p].L);
	ans.push_back(p);
	if(a[p].R)
		LTR(a[p].R);
}

void LRT(const int& p) {
	if(a[p].L)
		LRT(a[p].L);
	if(a[p].R)
		LRT(a[p].R);
	ans.push_back(p);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1, u, v; i <= n; ++i) {
		cin >> u >> v;
		a[i].L = u;
		a[i].R = v;
//		a[u].fa = a[v].fa = i;
	}
	d[1] = 1;
	get_depth(1);
	for(int i = 1; i <= n; ++i)
		cout << d[i] << ' ';
	cout << '\n';
	ans.clear();
	TLR(1);
	for(const auto& p: ans)
		cout << p << ' ';
	cout << '\n';
	ans.clear();
	LTR(1);
	for(const auto& p: ans)
		cout << p << ' ';
	cout << '\n';
	ans.clear();
	LRT(1);
	for(const auto& p: ans)
		cout << p << ' ';
	cout << '\n';
	return 0;
}