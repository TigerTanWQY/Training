#include <iostream>
#include <utility>
#include <queue>
using namespace std;

const int N = 200003;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q[N];
int v[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	for(int a, b, c, d; m--; ) {
		cin >> a >> b >> c >> d;
		while(!q[b].empty() && q[b].top().first <= a) {
			v[b] += q[b].top().second;
			q[b].pop();
		}
		if(v[b] < d)
			cout << "-1\n";
		else {
			v[b] -= d;
			q[b].push({a + c, d});
			cout << v[b] << '\n';
		}
	}
	return 0;
}