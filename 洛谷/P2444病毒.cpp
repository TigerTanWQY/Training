#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int N = 30003;
const int M = 2;
struct Node {
	int nxt[M], go[M], fail = 0;
	bool is_end = false, vis = false, ins = false;
} AC[N];
vector<int> bfn;
int tot = 0;

void ist(const string& s) {
	int now = 0;
	for(const auto& ch: s) {
		if(!AC[now].nxt[ch - '0'])
			AC[now].nxt[ch - '0'] = ++tot;
		now = AC[now].nxt[ch - '0'];
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

bool AC_query(const int& u) {
	AC[u].vis = AC[u].ins = true;
	for(int i = 0; i < M; ++i) {
		int v = AC[u].go[i];
		if(AC[v].is_end)
			continue;
		if(!AC[v].vis) {
			if(AC_query(v))
				return true;
		} else if(AC[v].ins)
			return true;
	}
	AC[u].ins = false;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(string s; n--; ) {
		cin >> s;
		ist(s);
	}
	build();
	for(const auto& u: bfn)
		AC[u].is_end |= AC[AC[u].fail].is_end;
	if(AC_query(0))
		cout << "TAK";
	else
		cout << "NIE";
	cout << endl;
	return 0;
}