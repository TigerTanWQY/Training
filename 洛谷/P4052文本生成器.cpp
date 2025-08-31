#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int P = 10007;
const int N = 6003;
const int M = 26;
struct Node {
	int nxt[M], go[M], fail = 0;
	bool is_end = false;
} AC[N];
vector<int> bfn;
int f[103][N][2], m, cnt = 0;

void add(int& x, const int& y) {
	x += y;
	if(x >= P)
		x -= P;
}

void ist(const string& s) {
	int now = 0;
	for(const auto& ch: s) {
		if(!AC[now].nxt[ch - 'A'])
			AC[now].nxt[ch - 'A'] = ++cnt;
		now = AC[now].nxt[ch - 'A'];
	}
	AC[now].is_end = true;
}

void build() {
	queue<int> q;
	q.push(0);
	bfn.push_back(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < M; ++i)
			if(AC[u].nxt[i]) {
				q.push(AC[u].nxt[i]);
				bfn.push_back(AC[u].nxt[i]);
				AC[u].go[i] = AC[u].nxt[i];
				if(u == 0)
					AC[AC[u].nxt[i]].fail = 0;
				else
					AC[AC[u].nxt[i]].fail = AC[AC[u].fail].go[i];
			} else
				if(u == 0)
					AC[u].go[i] = 0;
				else
					AC[u].go[i] = AC[AC[u].fail].go[i];
	}
}

int AC_query() {
	for(const auto& u: bfn)
		AC[u].is_end |= AC[AC[u].fail].is_end;
	f[0][0][0] = 1;
	for(int i = 0; i < m; ++i)
		for(int u = 0; u <= cnt; ++u)
			for(int j = 0; j < 2; ++j)
				if(f[i][u][j])
					for(int k = 0; k < M; ++k)
						add(f[i + 1][AC[u].go[k]][j | AC[AC[u].go[k]].is_end], f[i][u][j]);
	int res = 0;
	for(int u = 0; u <= cnt; ++u)
		add(res, f[m][u][1]);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> m;
	for(string s; n--; ) {
		cin >> s;
		ist(s);
	}
	build();
	cout << AC_query();
	cout << endl;
	return 0;
}