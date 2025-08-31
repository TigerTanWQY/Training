#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>
using namespace std;

unordered_map<int, deque<int>> d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	d.reserve(1000003);
	int q, a, x;
	cin >> q;
	for(string op; q--; ) {
		cin >> op >> a;
		if(op == "push_back") {
			cin >> x;
			d[a].push_back(x);
		} else if(op == "pop_back") {
			if(!d[a].empty())
				d[a].pop_back();
		}
		else if(op == "push_front") {
			cin >> x;
			d[a].push_front(x);
		} else if(op == "pop_front") {
			if(!d[a].empty())
				d[a].pop_front();
		}
		else if(op == "size")
			cout << d[a].size() << '\n';
		else if(op == "front") {
			if(!d[a].empty())
				cout << d[a].front() << '\n';
		}
		else if(op == "back") {
			if(!d[a].empty())
				cout << d[a].back() << '\n';
		}
	}
	return 0;
}