#include <iostream>
using namespace std;
// apt -t unstable install gnome-tweaks
constexpr const int N = 2e5 + 3;
int a[N], t[N << 2];

auto ls = [](int res){ return res << 1; };
auto rs = [](int res){ return res << 1 | 1; };

void pushup(int id)
{ t[id] = max(t[ls(id)], t[rs(id)]); }

void build(int id, int L, int R) {
	if(L == R) {
		t[id] = a[L];
		return;
	}
	int M = (L + R) >> 1;
	build(ls(id), L, M);
	build(rs(id), M + 1, R);
	pushup(id);
}

int qry(int id, int L, int R, int pos) {
	if(t[id] < pos)
		return 0;
	else if(L == R) {
		t[id] = t[id] - pos;
		return L + 1;
	}
	int M = (L + R) >> 1, res;
	if(t[ls(id)] >= pos)
		res = qry(ls(id), L, M, pos);
	else
		res = qry(rs(id), M + 1, R, pos);
	pushup(id);
	return res;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, _q;
	cin >> n >> _q;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	build(1, 0, n - 1);
	for(int k; _q--; cout.put(' ')) {
		cin >> k;
		cout << qry(1, 0, n - 1, k);
	}
	cout << endl;
	return 0;
}
