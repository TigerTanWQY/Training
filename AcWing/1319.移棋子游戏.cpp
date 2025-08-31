#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;

const int N = 2003;
vector<int> G[N];
int sg[N];

int SG(const int& u) {
	if(~sg[u])
		return sg[u];
	unordered_set<int> s;
	for(const auto& v: G[u])
		s.insert(SG(v));
	for(int i = 0; ; ++i)
		if(!s.count(i)) {
			sg[u] = i;
			break;
		}
	return sg[u];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	for(int u, v; m--; ) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	memset(sg, -1, sizeof(sg));
	int ans = 0;
	for(int u; k--; ) {
		cin >> u;
		ans ^= SG(u);
	}
	if(ans)
		cout << "win";
	else
		cout << "lose";
	cout.flush();
	return 0;
}