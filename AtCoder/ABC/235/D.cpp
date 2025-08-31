#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int d[1000003], a, n;

void bfs() {
	memset(d, -1, sizeof d);
	d[n] = 0;
	queue<int> q;
	q.push(n);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if(x < 2)
			break;
		if(x % a == 0 && d[x / a] == -1) {
			d[x / a] = d[x] + 1;
			q.push(x / a);
		}
		if(x >= 10) {
			string s = to_string(x);
			int y = stoi(s.substr(1) + s[0]);
			if(s[1] != '0' && d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> n;
	bfs();
	cout << d[1];
	return 0;
}