#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int s;
	cin >> s;
	deque<int> q;
	for(int i = 1, id = 0; i <= s; ++i) {
		char op, drt;
		cin >> op >> drt;
		if(op == 'A')
			if(drt == 'L')
				q.push_front(++id);
			else
				q.push_back(++id);
		else {
			int k;
			cin >> k;
			if(drt == 'L')
				while(k--)
					q.pop_front();
			else
				while(k--)
					q.pop_back();
		}
	}
	for(const auto& x: q)
		cout << x << '\n';
	return 0;
}