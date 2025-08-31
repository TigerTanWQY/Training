#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int N = 1000003;
stack<int> x;
bool flag[N];
int a[N], son[N][2], opt[N], val[N], num[N];

void dfs1(const int& p) {
	if(opt[p] >= 1)
		num[p] = val[opt[p]];
	else if(opt[p] == -1) {
		dfs1(son[p][0]);
		num[p] = !num[son[p][0]];
	} else if(opt[p] == -2) {
		dfs1(son[p][0]);
		dfs1(son[p][1]);
		num[p] = num[son[p][0]] | num[son[p][1]];
	} else {
		dfs1(son[p][0]);
		dfs1(son[p][1]);
		num[p] = num[son[p][0]] & num[son[p][1]];
	}
}

void dfs2(const int& p) {
	if(opt[p] >= 1)
		flag[opt[p]] = true;
	else if(opt[p] == -1)
		dfs2(son[p][0]);
	else if(opt[p] == -3) {
		if(num[son[p][0]] == 1 && num[son[p][1]] == 1) {
			dfs2(son[p][0]);
			dfs2(son[p][1]);
		} else if(num[son[p][0]] == 1 && !num[son[p][1]])
			dfs2(son[p][1]);
		else if(!num[son[p][0]] && num[son[p][1]] == 1)
			dfs2(son[p][0]);
		else
			return;
	} else {
		if(!num[son[p][0]] && !num[son[p][1]]) {
			dfs2(son[p][0]);
			dfs2(son[p][1]);
		} else if(num[son[p][0]] == 1 && !num[son[p][1]])
			dfs2(son[p][0]);
		else if(!num[son[p][0]] && num[son[p][1]] == 1)
			dfs2(son[p][1]);
		else
			return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool ok = true;
	int n, q, cnt = 0;
	for(string s; cin >> s && ok; ) {
		if(s == "!")
			a[++cnt] = -1;
		else if(s == "|")
			a[++cnt] = -2;
		else if(s == "&")
			a[++cnt] = -3;
		else {
			int y = 0;
			for(const auto& c: s)
				if('0' <= c && c <= '9')
					y = y * 10 + c - '0';
			if(s[0] == 'x')
				a[++cnt] = y;
			else {
				n = y;
				ok = false;
				break;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
		cin >> val[i];
	for(int i = 1; i <= cnt; ++i) {
		opt[i] = a[i];
		if(a[i] >= 1)
			x.push(i);
		else if(a[i] == -1) {
			int y = x.top();
			x.pop();
			son[i][0] = y;
			x.push(i);
		} else {
			int y1 = x.top();
			x.pop();
			int y2 = x.top();
			x.pop();
			son[i][0] = y1;
			son[i][1] = y2;
			x.push(i);
		}
	}
	int root = x.top();
	dfs1(root);
	dfs2(root);
	cin >> q;
	for(int y; q--; ) {
		cin >> y;
		if(flag[y])
			cout << !num[root] << '\n';
		else
			cout << num[root] << '\n';
	}
	return 0;
}