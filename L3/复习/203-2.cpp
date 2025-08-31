#include <iostream>
#include <utility>
using namespace std;
#define L first
#define R second

const int N = 1027;
pair<int, int> G[N];
int d[N];

void get_depth(const int& p) {
	if(G[p].L) {
		d[G[p].L] = d[p] + 1;
		get_depth(G[p].L);
	}
	if(G[p].R) {
		d[G[p].R] = d[p] + 1;
		get_depth(G[p].R);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> G[i].L >> G[i].R;
	d[1] = 1;
	get_depth(1);
	for(int i = 1; i <= n; ++i)
		cout << d[i] << ' ';
	return 0;
}