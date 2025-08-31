#include <iostream>
#include <vector>
using namespace std;

constexpr const int N = 2e5 + 3;
vector<int> G[N], a2, a3;
int d[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int _ = 1, u, v; _ < n; ++_) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		++d[u]; ++d[v];
	}
	for(int i = 1; i <= n; ++i)
		if(d[i] == 2)
			a2.push_back(i);
		else if(d[i] == 3)
			a3.push_back(i);
	;
	cout << endl;
	return 0;
}