#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, int> save;
int stk[500003], lst[500003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, pos = 0, now = 0;
	cin >> n;
	for(int i = 1, x; i <= n; ++i) {
		string opt;
		cin >> opt;
		if(opt == "ADD") {
			cin >> x;
			lst[++pos] = now;
			stk[pos] = x;
			now = pos;
		}
		else if(opt == "DELETE")
			now = lst[now];
		else if(opt == "SAVE") {
			cin >> x;
			save[x] = now;
		}
		else if(opt == "LOAD") {
			cin >> x;
			now = save[x];
		}
		cout << (stk[now]? stk[now]: -1) << '\n';
	}
	return 0;
}
